//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

#include <eve/module/core.hpp>
#include <polyfloat/details/decimal/bigint.hpp>
#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <limits>
#include <optional>
#include <string_view>
#include <utility>

// Reading follows W. D. Clinger, "How to Read Floating Point Numbers Accurately", PLDI 1990. With the string as the
// exact rational num / den, a part is the quotient of num by den at the precision of the base type, rounded to
// nearest, ties to even, by the remainder. Clinger's AlgorithmM finds the scale of that quotient by a loop, which the
// bit lengths of num and den give here. Each next part reads the exact rest in the same way.
namespace plf::_::decimal
{
  // The N parts of the value s denotes, as double values that T holds, or no value when s is malformed. s is an
  // optional sign then inf, infinity, nan, or digits with an optional point and an optional exponent: e in decimal,
  // p for a power of 2 after 0x. Letters are read in either case. The separator, the digit separator of C++ by
  // default, may stand between two digits as in a C++ literal, the exponent included, and is skipped. A separator of
  // 0 allows none.
  template<typename T, std::size_t N>
  std::optional<std::array<double, N>> parse_parts(std::string_view s, char separator)
  {
    std::int64_t const precision = eve::nbmantissabits(eve::as<T>()) + 1;
    std::int64_t const lowest = eve::minexponent(eve::as<T>()) - eve::nbmantissabits(eve::as<T>());
    std::int64_t const top = eve::maxexponent(eve::as<T>()) + 1;
    double const inf = std::numeric_limits<double>::infinity();
    auto lower = [](char c) { return c >= 'A' && c <= 'Z' ? static_cast<char>(c - 'A' + 'a') : c; };
    auto is = [&](std::string_view word, std::string_view lowercase) {
      return std::ranges::equal(word, lowercase, [&](char a, char b) { return lower(a) == b; });
    };

    bool letter = lower(separator) >= 'a' && lower(separator) <= 'z';
    if (letter || (separator >= '0' && separator <= '9') || separator == '.' || separator == '+' || separator == '-')
      return std::nullopt;

    bool negative = !s.empty() && s[0] == '-';
    if (!s.empty() && (s[0] == '-' || s[0] == '+')) s.remove_prefix(1);

    // A value alone in the high part, with the sign of the string.
    auto alone = [&](double v) {
      std::array<double, N> parts{};
      parts[0] = negative ? -v : v;
      return parts;
    };
    if (is(s, "inf") || is(s, "infinity")) return alone(inf);
    if (is(s, "nan")) return alone(std::numeric_limits<double>::quiet_NaN());

    int base = 10;
    if (s.size() > 1 && s[0] == '0' && lower(s[1]) == 'x')
    {
      base = 16;
      s.remove_prefix(2);
    }
    auto digit = [&](char c) {
      c = lower(c);
      return c >= '0' && c <= '9' ? c - '0' : base == 16 && c >= 'a' && c <= 'f' ? c - 'a' + 10 : -1;
    };

    // Every part, and every midpoint between two values of a part, is a multiple of 2^(lowest - 1), so of
    // 10^(lowest - 1) as well. The leading digit of a value below 2^top sits at most at 10^L, L = floor(top log10 2),
    // so the digits that can decide a rounding are the L + 2 - lowest from 10^L down to 10^(lowest - 1), 1384 for
    // double, and in hexadecimal the (top - lowest) / 4 + 2 over the same bits. The digits past them count as one
    // nonzero digit when any of them is not zero, which keeps reading linear.
    std::int64_t const decade = top * 30103 / 100000;
    std::int64_t const keep = base == 10 ? decade + 2 - lowest : (top - lowest) / 4 + 2;

    // A separator stands between two digits of the same sequence, as in a C++ literal.
    auto separates = [&](std::size_t i, auto in_sequence) {
      return separator != 0 && s[i] == separator && i > 0 && i + 1 < s.size() && in_sequence(s[i - 1]) &&
             in_sequence(s[i + 1]);
    };
    auto is_digit = [&](char c) { return digit(c) >= 0; };

    // value = digits base^scale, before the exponent. The kept digits gather in blocks of 9 decimal or 7 hexadecimal
    // digits, so that base^count, the factor of a block, stays below 2^32, and the big integer takes one
    // multiplication per block.
    bigint digits;
    std::uint32_t block = 0, block_scale = 1;
    std::uint32_t const full_block = base == 10 ? 1000000000u : 1u << 28;
    auto flush = [&] {
      if (block_scale > 1) digits.multiply_add(block_scale, block);
      block = 0;
      block_scale = 1;
    };

    std::int64_t kept = 0, scale = 0;
    bool point = false, any = false, dropped = false;
    std::size_t i = 0;
    for (; i < s.size(); ++i)
    {
      if (s[i] == separator && separator != 0)
      {
        if (!separates(i, is_digit)) return std::nullopt;
        continue;
      }
      if (s[i] == '.' && !point)
      {
        point = true;
        continue;
      }
      int d = digit(s[i]);
      if (d < 0) break;
      any = true;
      if (kept == 0 && d == 0)
      {
        if (point) --scale;
      }
      else if (kept < keep)
      {
        block = block * static_cast<std::uint32_t>(base) + static_cast<std::uint32_t>(d);
        block_scale *= static_cast<std::uint32_t>(base);
        if (block_scale == full_block) flush();
        ++kept;
        if (point) --scale;
      }
      else
      {
        dropped = dropped || d != 0;
        if (!point) ++scale;
      }
    }
    flush();
    if (dropped)
    {
      digits.multiply_add(static_cast<std::uint32_t>(base), 1);
      ++kept;
      --scale;
    }

    std::int64_t exponent = 0;
    if (any && i < s.size() && lower(s[i]) == (base == 10 ? 'e' : 'p'))
    {
      bool minus = ++i < s.size() && s[i] == '-';
      if (i < s.size() && (s[i] == '-' || s[i] == '+')) ++i;
      auto decimal = [](char c) { return c >= '0' && c <= '9'; };
      auto first = i;
      // The exponent stops growing at 2^59, beyond what the digits of any string can offset, and with 10 times it
      // still an std::int64_t.
      for (; i < s.size() && (decimal(s[i]) || separates(i, decimal)); ++i)
        if (decimal(s[i]) && exponent < (std::int64_t{1} << 59)) exponent = 10 * exponent + (s[i] - '0');
      if (i == first) return std::nullopt;
      if (minus) exponent = -exponent;
    }
    if (!any || i != s.size()) return std::nullopt;
    if (digits.is_zero()) return alone(0.0);

    // value = digits 10^x, or digits 2^x after 0x. Every base type gives infinity above 10^400 or 2^1200, and zero
    // below 10^-400 or 2^-1200, before the powers of 5 and 2 are built.
    std::int64_t x = base == 10 ? scale + exponent : 4 * scale + exponent;
    std::int64_t leading = x + (base == 10 ? kept : digits.bits()) - 1;
    std::int64_t const limit = base == 10 ? 400 : 1200;
    if (leading > limit) return alone(inf);
    if (leading < -limit) return alone(0.0);

    // value = num / den in units of 2^lowest, the last bit of the smallest subnormal, 10^x being 5^x 2^x.
    bigint num = digits, den(1);
    if (base == 10 && x >= 0) multiply_by_power_of_5(num, x);
    if (base == 10 && x < 0) multiply_by_power_of_5(den, -x);
    if (x >= lowest) num.shift_left(x - lowest);
    else den.shift_left(lowest - x);

    std::array<double, N> parts{};
    for (std::size_t k = 0; k < N && !num.is_zero(); ++k)
    {
      // 2^e <= num / den < 2^(e + 1)
      std::int64_t e = num.bits() - den.bits();
      if (e >= 0 ? compare(num, shifted(den, e)) < 0 : compare(shifted(num, -e), den) < 0) --e;

      // The part is m 2^q units, 2^q being the place of its last bit, and m < 2^precision.
      std::int64_t q = std::max<std::int64_t>(e - precision + 1, 0);
      bigint unit = shifted(den, q);
      std::uint64_t m = quotient(num, unit, precision);

      int half = compare(shifted(num, 1), unit);
      bool up = half > 0 || (half == 0 && m % 2 == 1);
      if (up)
      {
        ++m;
        bigint rest = unit;
        rest -= num;
        num = std::move(rest);
      }

      if (m == 0)
      {
        if (k == 0) return alone(0.0);
        break;
      }
      if (width(m) + q + lowest > top) return alone(inf);
      double v = std::ldexp(static_cast<double>(m), static_cast<int>(q + lowest));
      parts[k] = negative ? -v : v;
      if (up) negative = !negative;
    }
    return parts;
  }
}
