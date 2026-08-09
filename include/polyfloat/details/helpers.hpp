//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

namespace plf::_
{
  constexpr unsigned int MAX_N = 3;

  template<typename T>
  constexpr auto three_add_pedantic(T a, T b, T c) noexcept
  {
    auto [t0, t1] = eve::two_add(a, b);
    auto [hi, t2] = eve::two_add(t0, c);
    auto [md, lo] = eve::two_add(t2, t1);
    auto [hi1, md1] = eve::two_add[eve::raw](hi, md);
    if constexpr( eve::platform::supports_infinites)
    {
      auto t = eve::is_not_finite(md) || eve::is_not_finite(lo) || eve::is_not_finite(t0);
      md1 = eve::if_else(t, eve::zero, md);
      lo  = eve::if_else(t, eve::zero, lo);
      hi1 = eve::if_else(eve::is_infinite(a), a, hi1);
    }
    hi1 = eve::if_else(eve::is_eqz(hi1), a, hi1); //this to keep -0.0 sign of the hi part
    return eve::zip(hi1, md1, lo);
  }

  template<typename T>
  constexpr auto three_add(T a, T b, T c) noexcept
  {
    auto [t0, t1] = eve::two_add(a, b);
    auto [hi, t2] = eve::two_add(t0, c);
    auto [md, lo] = eve::two_add(t2, t1);
    auto [hi1, md1] = eve::two_add[eve::raw](hi, md);
    return eve::zip(hi1, md1, lo);
  }

  template<typename T>
  constexpr auto four_add(T a, T b, T c, T d) noexcept
  {
    auto [t0, t1] = eve::two_add(a, b);
    auto [t2, t3] = eve::two_add(c, d);
    auto [hi, t4] = eve::two_add(t0, t2);
    auto [t5, lo] = eve::two_add(t1, t3);
    auto [hm, ml] = eve::two_add(t4, t5);
    auto [ml1, lo1] = eve::two_add[eve::raw](ml, lo);
    auto [hm1, ml2] = eve::two_add[eve::raw](hm, ml1);
    auto [hi1, hm2] = eve::two_add[eve::raw](hi,hm1);
    return eve::zip(hi1, hm2, ml2, lo1);
  }

}
