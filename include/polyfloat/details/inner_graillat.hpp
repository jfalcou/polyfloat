/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

#include <polyfloat/details/callable.hpp>
#include <polyfloat/types/concepts.hpp>
#include <polyfloat/types/traits.hpp>
#include <type_traits>

///////////////////////////////////////////////////////////////////////////////////////
// https://hal.science/hal-04575249
///////////////////////////////////////////////////////////////////////////////////////

namespace plf::_
{
  template<typename T>
  constexpr auto is_n_1or3_t_p2(T x) noexcept // Graillat & Muller algorithm 5
  {
    using u_t = eve::underlying_type_t<T>;
    constexpr unsigned long Q = 1ul << (eve::nbmantissabits(eve::as(u_t()))-2);
    constexpr unsigned long P = Q+1;
    auto l = P*x;
    auto r = Q*x;
    return eve::is_not_equal(l-r, x);
  }

  template<typename T>
  constexpr auto inner_cr_dw_fp_add_with_err(T xh, T xl, T c) noexcept // Graillat & Muller algorithm 7
  // https://hal.science/hal-04575249
  {
    using u_t = eve::underlying_type_t<T>;
    constexpr u_t c9_8 = u_t(9)/8;
    constexpr u_t c7_8 = u_t(7)/8;
    auto [sh, sl] = eve::two_add(xh, c);
    auto [vh, vl] = eve::two_add(xl, sl);
    auto [wh, wl] = eve::two_add(vh, sh); // quick seems to be incorrectly called here in the original article as vh and sh can be in wrong order
    auto in =  is_n_1or3_t_p2(vh) || eve::is_eqz(vl);
    auto samsgn = eve::sign(vl) == eve::sign(vh);
    auto z = eve::if_else(in,
                     wh,
                          sh+eve::if_else(samsgn, c9_8, c7_8)*vh
                    );
    auto delta = eve::sub[in](wl, z-wh);
    return eve::zip(z, delta, vl); 
//    return eve::if_else(eve::is_nan(z), eve::zip(z, u_t(0),u_t(0)), eve::zip(z, delta, vl));
  }

  template<typename Z>
  POLYFLOAT_FORCEINLINE constexpr auto inner_three_add(Z const& x, Z const& y, Z const& z) noexcept
  {
    auto [xh, xl] = eve::two_add(x, y);
    return inner_cr_dw_fp_add_with_err(xh, xl, z);
  }
}
