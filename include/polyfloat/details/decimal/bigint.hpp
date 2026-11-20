//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

#include <algorithm>
#include <bit>
#include <cstdint>
#include <string>
#include <vector>

// Unsigned integers of any size, with the operations the exact conversions of read.hpp and write.hpp use.
namespace plf::_::decimal
{
  // std::bit_width returns the unsigned type of its argument before LWG 3656.
  inline std::int64_t width(std::uint64_t v)
  {
    return static_cast<std::int64_t>(std::bit_width(v));
  }

  // Unsigned integer of any size, in 32-bit limbs, least significant first, without a leading zero limb.
  struct bigint
  {
    std::vector<std::uint32_t> limbs;

    bigint() = default;
    explicit bigint(std::uint64_t v)
    {
      for (; v != 0; v >>= 32) limbs.push_back(static_cast<std::uint32_t>(v));
    }

    bool is_zero() const { return limbs.empty(); }

    std::int64_t bits() const
    {
      return limbs.empty() ? 0 : 32 * static_cast<std::int64_t>(limbs.size() - 1) + width(limbs.back());
    }

    void trim()
    {
      while (!limbs.empty() && limbs.back() == 0) limbs.pop_back();
    }

    // *this = *this * m + a, for m > 0.
    void multiply_add(std::uint32_t m, std::uint32_t a = 0)
    {
      std::uint64_t carry = a;
      for (auto& x : limbs)
      {
        carry += static_cast<std::uint64_t>(x) * m;
        x = static_cast<std::uint32_t>(carry);
        carry >>= 32;
      }
      if (carry != 0) limbs.push_back(static_cast<std::uint32_t>(carry));
    }

    // *this = *this / d, and returns the remainder.
    std::uint32_t divide(std::uint32_t d)
    {
      std::uint64_t r = 0;
      for (auto i = limbs.size(); i-- > 0;)
      {
        r = (r << 32) | limbs[i];
        limbs[i] = static_cast<std::uint32_t>(r / d);
        r %= d;
      }
      trim();
      return static_cast<std::uint32_t>(r);
    }

    void halve()
    {
      std::uint32_t carry = 0;
      for (auto i = limbs.size(); i-- > 0;)
      {
        auto next = limbs[i] << 31;
        limbs[i] = (limbs[i] >> 1) | carry;
        carry = next;
      }
      trim();
    }

    void shift_left(std::int64_t n)
    {
      if (limbs.empty() || n == 0) return;
      if (auto b = n % 32; b != 0)
      {
        std::uint32_t carry = 0;
        for (auto& x : limbs)
        {
          auto next = x >> (32 - b);
          x = (x << b) | carry;
          carry = next;
        }
        if (carry != 0) limbs.push_back(carry);
      }
      limbs.insert(limbs.begin(), static_cast<std::size_t>(n / 32), 0u);
    }

    bigint& operator+=(bigint const& o)
    {
      limbs.resize(std::max(limbs.size(), o.limbs.size()), 0u);
      std::uint64_t carry = 0;
      for (std::size_t i = 0; i < limbs.size(); ++i)
      {
        carry += static_cast<std::uint64_t>(limbs[i]) + (i < o.limbs.size() ? o.limbs[i] : 0u);
        limbs[i] = static_cast<std::uint32_t>(carry);
        carry >>= 32;
      }
      if (carry != 0) limbs.push_back(static_cast<std::uint32_t>(carry));
      return *this;
    }

    // *this = *this - o, for o <= *this.
    bigint& operator-=(bigint const& o)
    {
      std::int64_t borrow = 0;
      for (std::size_t i = 0; i < limbs.size(); ++i)
      {
        std::int64_t v = static_cast<std::int64_t>(limbs[i]) - (i < o.limbs.size() ? o.limbs[i] : 0u) - borrow;
        borrow = v < 0 ? 1 : 0;
        limbs[i] = static_cast<std::uint32_t>(v + (borrow << 32));
      }
      trim();
      return *this;
    }

    friend int compare(bigint const& a, bigint const& b)
    {
      if (a.limbs.size() != b.limbs.size()) return a.limbs.size() < b.limbs.size() ? -1 : 1;
      for (auto i = a.limbs.size(); i-- > 0;)
        if (a.limbs[i] != b.limbs[i]) return a.limbs[i] < b.limbs[i] ? -1 : 1;
      return 0;
    }

    // The decimal digits, empty for zero. One division by 10^9, the largest power of 10 below 2^32, gives 9 digits.
    std::string decimal_digits() const
    {
      bigint x = *this;
      std::string s;
      while (!x.is_zero())
      {
        auto r = x.divide(1000000000u);
        for (int i = 0; i < 9; ++i, r /= 10) s.push_back(static_cast<char>('0' + r % 10));
      }
      while (!s.empty() && s.back() == '0') s.pop_back();
      std::reverse(s.begin(), s.end());
      return s;
    }

    // The hexadecimal digits, 8 to a limb, empty for zero.
    std::string hexadecimal_digits() const
    {
      std::string s;
      for (auto i = limbs.size(); i-- > 0;)
        for (int shift = 28; shift >= 0; shift -= 4) s.push_back("0123456789abcdef"[(limbs[i] >> shift) & 15]);
      return s.substr(std::min(s.find_first_not_of('0'), s.size()));
    }
  };

  inline bigint shifted(bigint x, std::int64_t n)
  {
    x.shift_left(n);
    return x;
  }

  // x 5^n, by factors of 5^13, the largest power of 5 below 2^32, then one factor for the rest.
  inline void multiply_by_power_of_5(bigint& x, std::int64_t n)
  {
    for (; n >= 13; n -= 13) x.multiply_add(1220703125u);
    std::uint32_t rest = 1;
    for (; n > 0; --n) rest *= 5;
    if (rest > 1) x.multiply_add(rest);
  }

  // The quotient of a by b, known to be below 2^bits, by binary long division: b 2^j for j from bits - 1 down to 0,
  // one copy of b 2^bits halved at each step. a becomes the remainder.
  inline std::uint64_t quotient(bigint& a, bigint const& b, std::int64_t bits)
  {
    bigint t = shifted(b, bits);
    std::uint64_t q = 0;
    for (auto j = bits - 1; j >= 0; --j)
    {
      t.halve();
      if (compare(a, t) >= 0)
      {
        a -= t;
        q |= std::uint64_t{1} << j;
      }
    }
    return q;
  }
}
