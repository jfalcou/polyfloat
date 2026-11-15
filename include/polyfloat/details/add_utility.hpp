/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

namespace plf::_
{

  POLYFLOAT_ABI void twoadd(auto a, auto b, auto& r0, auto& r1) noexcept
  {
    auto [x, y] = eve::two_add(a, b);
    r0 = x;
    r1 = y;
  }

  POLYFLOAT_ABI void fasttwoadd(auto a, auto b, auto& r0, auto& r1) noexcept
  {
    auto [x, y] = eve::two_add[eve::raw](a, b);
    r0 = x;
    r1 = y;
  }

  // This adding routine is used in the triple_real constructor
  // to avoid bad normalization
  template<typename T1, typename T> POLYFLOAT_ABI T1 a31(T1 self, T other) noexcept
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
    kumi::get<0>(self) = eve::if_else(test, aa, a);
    kumi::get<1>(self) = eve::if_else(test, eve::zero, b);
    kumi::get<2>(self) = eve::if_else(test, eve::zero, c);
    return self;
  }

}
