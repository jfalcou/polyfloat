//======================================================================================================================
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
#include <polyfloat/module/core/fma.hpp>
#include <polyfloat/module/core/nearest.hpp>
#include <polyfloat/module/core/quadrant.hpp>
#include <eve/traits/helpers.hpp>
#include <polyfloat/module/math/details/sincos_coefs.hpp>
#include <eve/traits/helpers.hpp>

namespace plf::_
{
  template<typename T> POLYFLOAT_FORCEINLINE constexpr auto cos_eval(T const& z2) noexcept
  {
    using e_t = eve::element_type_t<T>;
    return plf::reverse_horner(z2, eve::coefficients(cos_coefs<e_t>()));
  }

  template<typename T> POLYFLOAT_FORCEINLINE constexpr auto sin_eval(T const& z2, T const& z) noexcept
  {
    using e_t = eve::element_type_t<T>;
    return z * plf::reverse_horner(z2, eve::coefficients(sino_x_coefs<e_t>()));
  }

  template<typename T> POLYFLOAT_FORCEINLINE constexpr auto sinc_eval(T const& z2) noexcept
  {
    using e_t = eve::element_type_t<T>;
    return plf::reverse_horner(z2, eve::coefficients(sino_x_coefs<e_t>()));
  }

  //========================================================================

  template<typename T>
  POLYFLOAT_FORCEINLINE constexpr auto cos_finalize(T const& fn, T const& xr, T const& dxr = T(0)) noexcept
  {
    auto tmp = plf::one[fn >= T(2)](eve::as(xr));
    auto swap_bit = plf::is_nez(plf::fma(T(-2), tmp, fn));
    auto zz1 = plf::is_odd(fn + tmp);
    auto sign = plf::if_else(zz1, plf::mone(eve::as(xr)), plf::one(eve::as(xr)));
    T xr2 = plf::sqr(xr);
    T se = sin_eval(xr2, xr);
    T ce = cos_eval(xr2);
    auto z = plf::if_else(swap_bit, plf::fma(dxr, ce, se), plf::fnma(se, dxr, ce));
    return sign * z;
  }

  template<typename T>
  POLYFLOAT_FORCEINLINE constexpr auto sin_finalize(T const& a0, T const& fn, T const& xr, T const& dxr = T(0)) noexcept
  {
    auto tmp = plf::one[fn >= T(2)](eve::as(xr));
    auto swap_bit = plf::is_nez(plf::fma(T(-2), tmp, fn));
    auto sign = plf::signnz(a0);
    sign *= plf::if_else(plf::is_nez(tmp), plf::mone(eve::as(a0)), plf::one(eve::as(xr)));
    auto xr2 = plf::sqr(xr);
    auto se = sin_eval(xr2, xr);
    auto ce = cos_eval(xr2);
    auto z = plf::if_else(swap_bit, plf::fnma(se, dxr, ce), plf::fma(dxr, ce, se));
    return sign * z;
  }

  template<typename T>
  POLYFLOAT_FORCEINLINE constexpr auto sincos_finalize(T const& a0,
                                                       T const& fn,
                                                       T const& xr,
                                                       T const& dxr = T(0)) noexcept
  {
    auto tmp = plf::one[fn >= T(2)](plf::as(xr));
    auto swap = plf::is_nez(plf::fma(T(-2), tmp, fn));
    auto cos_sign = plf::if_else(plf::is_odd(fn + tmp), plf::mone(plf::as(xr)), plf::one(plf::as(xr)));
    auto sin_sign = plf::signnz(a0);
    sin_sign *= plf::if_else(plf::is_nez(tmp), plf::mone(plf::as(a0)), plf::one(plf::as(a0)));
    auto xr2 = plf::sqr(xr);
    auto se0 = sin_eval(xr2, xr);
    auto ce0 = cos_eval(xr2);
    auto ce = plf::fnma(se0, dxr, ce0);
    auto se = plf::fma(dxr, ce0, se0);
    return kumi::make_tuple((plf::if_else(swap, ce, se) * sin_sign), plf::if_else(swap, se, ce) * cos_sign);
  }
}
