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

  template<typename O, typename T>
  constexpr auto three_add_pedantic(T a, T b, T c) noexcept // TODO To put in eve adding pedantic option for inf
  {
    auto [t0, t1] = eve::two_add(a, b);
    auto [hi, t2] = eve::two_add(t0, c);
    auto [md, lo] = eve::two_add(t2, t1);
    auto [hi1, md1] = eve::two_add[eve::raw](hi, md);
    if constexpr( eve::platform::supports_infinites)
    {
      auto t = is_not_finite(md) || is_not_finite(lo) || is_not_finite(t0);
      md1 = eve::if_else(t, eve::zero, md);
      lo  = eve::if_else(t, eve::zero, lo);
    }
    return eve::zip(hi1, md1, lo);
  }

  template<typename O, typename T>
  constexpr auto three_add(T a, T b, T c) noexcept // TODO To put in eve adding pedantic option for inf
  {
    auto [t0, t1] = eve::two_add(a, b);
    auto [hi, t2] = eve::two_add(t0, c);
    auto [md, lo] = eve::two_add(t2, t1);
    auto [hi1, md1] = eve::two_add[eve::raw](hi, md);
    return eve::zip(hi1, md1, lo);
  }

  template<typename T>
  constexpr auto four_add(T a, T b, T c, T d) noexcept  // TODO To put in eve adding pedantic option for inf
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
