//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

#include <polyfloat/details/decimal/bigint.hpp>
#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <limits>
#include <string>
#include <utility>

// Writing turns the exact sum of the parts, m 2^-k, into the decimal m 5^k 10^-k, rounds its digits to the precision
// asked, ties to even, and lays them out as printf does for %g, %f, and %e. For %a, m is written in hexadecimal. The
// flag `point` is the alternate form, printf's #, which keeps the point and the trailing zeros of %g.
namespace plf::_::decimal
{
  // The exact sum of finite parts, (-1)^negative m 2^e.
  struct dyadic
  {
    bool negative;
    bigint m;
    std::int64_t e;
  };

  template<std::size_t N> dyadic exact_sum(std::array<double, N> const& parts)
  {
    // A part is i 2^k, i its fraction scaled by 2^53 to an integer, and the sum counts in units of the smallest 2^k.
    std::array<std::uint64_t, N> i{};
    std::array<std::int64_t, N> k{};
    std::int64_t e = std::numeric_limits<std::int64_t>::max();
    for (std::size_t j = 0; j < N; ++j)
    {
      if (parts[j] == 0) continue;
      int exponent = 0;
      i[j] = static_cast<std::uint64_t>(std::ldexp(std::frexp(std::fabs(parts[j]), &exponent), 53));
      k[j] = exponent - 53;
      e = std::min(e, k[j]);
    }
    if (e == std::numeric_limits<std::int64_t>::max()) return {false, bigint{}, 0};

    bigint plus, minus;
    for (std::size_t j = 0; j < N; ++j)
    {
      if (parts[j] < 0) minus += shifted(bigint(i[j]), k[j] - e);
      if (parts[j] > 0) plus += shifted(bigint(i[j]), k[j] - e);
    }
    if (compare(plus, minus) >= 0) return {false, std::move(plus -= minus), e};
    return {true, std::move(minus -= plus), e};
  }

  // Keeps the first `keep` digits of s, rounded to nearest, ties to even, and returns whether a carry added a digit.
  inline bool round_digits(std::string& s, std::int64_t keep)
  {
    if (keep >= static_cast<std::int64_t>(s.size())) return false;
    if (keep < 0)
    {
      s.clear();
      return false;
    }
    auto k = static_cast<std::size_t>(keep);
    // Up above a half, and at a half when the last kept digit is odd.
    bool above = s[k] > '5' || (s[k] == '5' && s.find_first_not_of('0', k + 1) != std::string::npos);
    bool tie = s[k] == '5' && !above;
    bool up = above || (tie && k > 0 && (s[k - 1] - '0') % 2 == 1);
    s.resize(k);
    if (!up) return false;
    for (auto j = k; j-- > 0;)
    {
      if (s[j] != '9')
      {
        ++s[j];
        return false;
      }
      s[j] = '0';
    }
    s.insert(0, 1, '1');
    return true;
  }

  // %f: digits 10^-scale with `decimals` digits after the point.
  inline std::string fixed(std::string digits, std::int64_t scale, std::int64_t decimals, bool point)
  {
    if (decimals >= scale) digits.append(static_cast<std::size_t>(decimals - scale), '0');
    else round_digits(digits, static_cast<std::int64_t>(digits.size()) - (scale - decimals));
    auto d = static_cast<std::size_t>(decimals);
    if (digits.size() <= d) digits.insert(0, d + 1 - digits.size(), '0');
    if (d > 0 || point) digits.insert(digits.size() - d, 1, '.');
    return digits;
  }

  // %e: digits 10^-scale with one digit before the point and `decimals` after it.
  inline std::string scientific(std::string digits, std::int64_t scale, std::int64_t decimals, bool point)
  {
    std::int64_t e = digits.empty() ? 0 : static_cast<std::int64_t>(digits.size()) - 1 - scale;
    if (round_digits(digits, decimals + 1))
    {
      digits.pop_back();
      ++e;
    }
    digits.append(static_cast<std::size_t>(decimals + 1) - digits.size(), '0');
    if (decimals > 0 || point) digits.insert(1, 1, '.');
    auto power = std::to_string(e < 0 ? -e : e);
    if (power.size() < 2) power.insert(0, 1, '0');
    return digits + (e < 0 ? "e-" : "e+") + power;
  }

  // %g: %f or %e by the decimal exponent of the rounded value, without the trailing zeros of the fraction.
  inline std::string general(std::string const& digits, std::int64_t scale, std::int64_t precision, bool point)
  {
    auto p = std::max<std::int64_t>(precision, 1);
    std::int64_t e = 0;
    if (!digits.empty())
    {
      auto rounded = digits;
      e = static_cast<std::int64_t>(digits.size()) - 1 - scale + (round_digits(rounded, p) ? 1 : 0);
    }
    auto t = e >= -4 && e < p ? fixed(digits, scale, p - 1 - e, point) : scientific(digits, scale, p - 1, point);
    auto end = std::min(t.find('e'), t.size());
    if (!point && t.find('.') < end)
    {
      auto last = t.find_last_not_of('0', end - 1);
      if (t[last] == '.') --last;
      t.erase(last + 1, end - last - 1);
    }
    return t;
  }

  // %a: 0x1.f p e, the fraction f padded to whole hexadecimal digits and without trailing zeros.
  inline std::string hexadecimal(dyadic x, bool point)
  {
    if (x.m.is_zero()) return point ? "0x0.p+0" : "0x0p+0";
    auto fraction = x.m.bits() - 1;
    x.m.shift_left((4 - fraction % 4) % 4);
    auto d = x.m.hexadecimal_digits();
    d.erase(d.find_last_not_of('0') + 1);
    auto e = x.e + fraction;
    return "0x1" + (d.size() > 1 || point ? "." + d.substr(1) : "") + (e < 0 ? "p-" : "p+") +
           std::to_string(e < 0 ? -e : e);
  }

  // The sum of finite parts as printf writes a number for the conversion %g, %f, %e, or %a, the precision, and the
  // alternate form.
  template<std::size_t N>
  std::string to_text(std::array<double, N> const& parts, char conversion, std::int64_t precision, bool point)
  {
    auto x = exact_sum(parts);
    bool negative = x.m.is_zero() ? std::signbit(parts[0]) : x.negative;
    if (conversion == 'a') return (negative ? "-" : "") + hexadecimal(std::move(x), point);

    // m 2^-k = m 5^k 10^-k
    std::int64_t scale = 0;
    if (x.e >= 0) x.m.shift_left(x.e);
    else
    {
      scale = -x.e;
      multiply_by_power_of_5(x.m, scale);
    }
    auto digits = x.m.decimal_digits();
    std::string body = conversion == 'f'   ? fixed(digits, scale, precision, point)
                       : conversion == 'e' ? scientific(digits, scale, precision, point)
                                           : general(digits, scale, precision, point);
    return (negative ? "-" : "") + body;
  }
}
