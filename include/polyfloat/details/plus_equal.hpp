/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once
#include <polyfloat/details/add_utility.hpp>

namespace plf::_
{
  template<typename T1, typename T2>
  POLYFLOAT_ABI T1& plus_equal(T1& self, T2 other) noexcept
  requires(dimension_v<T1> == 2u) && (dimension_v<T2> == 1u)
  {
    auto [xhi, xlo] = self;
    auto [a, b] = eve::two_add(xhi, other);
    auto test = eve::is_not_finite(a + b);
    auto aa = a;
    auto c = xlo;
    fasttwoadd(a, c, a, c);
    fasttwoadd(a, b + c, a, b);
    self = plf::if_else(test, T1(aa), plf::_::from_pair(a, b));
    EVE_ASSERT(eve::all(plf::is_normalized(self)), "output of += is not normalized");
    return self;
  }

  template<typename T1, typename T2>
  POLYFLOAT_ABI T1& plus_equal(T1& self, T2 other) noexcept
  requires(dimension_v<T1> == 2u) && (dimension_v<T2> == 2u)
  {
    auto [xhi, xlo] = self;
    auto [yhi, ylo] = other;
    auto [a, b] = eve::two_add(xhi, yhi);
    auto test = eve::is_not_finite(a + b);
    auto aa = a;
    auto [c, d] = eve::two_add(xlo, ylo);
    fasttwoadd(a, c, a, c);
    fasttwoadd(a, (b + d) + c, a, b);
    self = plf::if_else(test, T1(aa), plf::_::from_pair(a, b));
    EVE_ASSERT(eve::all(plf::is_normalized(self)), "output of += is not normalized");
    return self;
  }

  template<typename T1, typename T2>
  POLYFLOAT_ABI T1& plus_equal(T1& self, T2 other) noexcept
  requires(dimension_v<T1> == 3u) && (dimension_v<T2> == 1u)
  {
    auto [xhi, xmd, xlo] = self;
    auto yhi = other;
    auto [a, b] = eve::two_add(xhi, yhi);
    auto aa = a;
    auto c = xmd;
    auto e = xlo;
    fasttwoadd(a, c, a, c);
    twoadd(b, c, b, c);
    fasttwoadd(a, b, a, b);
    fasttwoadd(b, c + e, b, c);
    fasttwoadd(a, b, a, b);
    fasttwoadd(b, c, b, c);
    auto test = eve::is_not_finite(a + b + c);
    self = plf::if_else(test, T1(aa), plf::_::from_triple(a, b, c));
    EVE_ASSERT(eve::all(plf::is_normalized(self)), "output of += is not normalized");
    return self;
  }

  template<typename T1, typename T2>
  POLYFLOAT_ABI T1& plus_equal(T1& self, T2 other) noexcept
  requires(dimension_v<T1> == 3u) && (dimension_v<T2> == 2u)
  {
    auto [xhi, xmd, xlo] = self;
    auto [yhi, ymd] = other;
    auto [a, b] = eve::two_add(xhi, yhi);
    auto aa = a;
    auto [c, d] = eve::two_add(xmd, ymd);
    auto e = xlo;
    fasttwoadd(a, c, a, c);
    twoadd(d, e, d, e);
    fasttwoadd(a, d, a, d);
    twoadd(b, c, b, c);
    twoadd(c + e, d, c, d);
    twoadd(b, c, b, c);
    fasttwoadd(a, b, a, b);
    fasttwoadd(b, c + d, b, c);
    fasttwoadd(a, b, a, b);
    fasttwoadd(b, c, b, c);
    auto test = eve::is_not_finite(a + b + c);
    self = plf::if_else(test, T1(aa), plf::_::from_triple(a, b, c));
    EVE_ASSERT(eve::all(plf::is_normalized(self)), "output of += is not normalized");
    return self;
  }

  template<typename T1, typename T2>
  POLYFLOAT_ABI T1& plus_equal(T1& self, T2 other) noexcept
  requires(dimension_v<T1> == 3u) && (dimension_v<T2> == 3u)
  {
    auto [xhi, xmd, xlo] = self;
    auto [yhi, ymd, ylo] = other;
    auto [a, b] = eve::two_add(xhi, yhi);
    auto aa = a;
    auto [c, d] = eve::two_add(xmd, ymd);
    auto [e, f] = eve::two_add(xlo, ylo);
    fasttwoadd(a, c, a, c);
    twoadd(d, e, d, e);
    fasttwoadd(a, d, a, d);
    twoadd(b + f, c, b, c);
    twoadd(c + e, d, c, d);
    twoadd(b, c, b, c);
    fasttwoadd(a, b, a, b);
    fasttwoadd(b, c + d, b, c);
    fasttwoadd(a, b, a, b);
    fasttwoadd(b, c, b, c);
    auto test = eve::is_not_finite(a + b + c);
    self = plf::if_else(test, T1(aa), plf::_::from_triple(a, b, c));
    EVE_ASSERT(eve::all(plf::is_normalized(self)), "output of += is not normalized");
    return self;
  }

}
