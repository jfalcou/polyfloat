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
#include <polyfloat/module/math/details/tancot_coefs.hpp>
#include <eve/traits/helpers.hpp>

namespace plf::_
{
  template<typename T> constexpr auto gauss(T z2, T z, int order)
  {
    // Gauss continued fraction of Rank order
    T a(order);
    for (int i = order - 2; i > 0; i -= 2)
    {
      auto div_step = z2 / a;
      a = i - div_step;
    }
    return z / a;
  }

  template<typename T> constexpr auto cos_eval(T const& z2) noexcept
  {
    using e_t = eve::element_type_t<T>;
    return plf::reverse_horner(z2, eve::coefficients(cos_coefs<e_t>()));
  }

  template<typename T> constexpr auto sin_eval(T const& z2, T const& z) noexcept
  {
    using e_t = eve::element_type_t<T>;
    return z * plf::reverse_horner(z2, eve::coefficients(sino_x_coefs<e_t>()));
  }

  template<typename T> constexpr auto sinc_eval(T const& z2) noexcept
  {
    using e_t = eve::element_type_t<T>;
    return plf::reverse_horner(z2, eve::coefficients(sino_x_coefs<e_t>()));
  }

  template<typename T> auto tancot_eval(T const& z) noexcept
  {
    using e_t = eve::element_type_t<T>;
    // here z is positive
    T z2 = eve::sqr(z);
    if constexpr (std::same_as<e_t, float>)
    {
      float num = plf::reverse_horner(z2, 1.0f, -0.11110803f, 0.00105762f);
      float den = plf::reverse_horner(z2, 1.0f, -0.44444137f, 0.01587148f);
      return z * (num / den);
    }
    else if constexpr (std::same_as<e_t, double>)
    {
      double num = plf::reverse_horner(z2, 2027025.0, -270270.0, 6930.0, -36.0);
      double den = plf::reverse_horner(z2, 2027025.0, -945945.0, 51975.0, -630.0, 1.0);
      return z * (num / den);
    }
    else if constexpr (std::same_as<e_t, plf::double_real_t<float>>)
    {
      kumi::tuple num_coefs{plf::_::from_pair(0x1p+0f, 0x0p+0f), plf::_::from_pair(-0x1.06b888p-3f, 0x1.f8471p-28f),
                            plf::_::from_pair(0x1.6fc02cp-9f, 0x1.8e0b8p-36f),
                            plf::_::from_pair(-0x1.f6161cp-18f, -0x1.70d7f6p-43f)};
      kumi::tuple den_coefs{plf::_::from_pair(0x1p+0f, 0x0p+0f), plf::_::from_pair(-0x1.d8b198p-2f, -0x1.ae8718p-27f),
                            plf::_::from_pair(0x1.7e7802p-6f, -0x1.0c8338p-31f),
                            plf::_::from_pair(-0x1.b51608p-13f, -0x1.12306p-38f)};
      auto num = plf::reverse_horner(z2, eve::coefficients(num_coefs));
      auto den = plf::reverse_horner(z2, eve::coefficients(den_coefs));
      return z * (num / den);
    }
    else if constexpr (std::same_as<e_t, plf::double_real_t<double>>)
    {
      return gauss(z2, z, 27);
    }
    else if constexpr (std::same_as<e_t, plf::triple_real_t<float>>)
    {
      return gauss(z2, z, 21);
    }
    else if constexpr (std::same_as<e_t, plf::triple_real_t<double>>)
    {
      return gauss(z2, z, 43);
    }
  }

  //========================================================================

  template<typename T> constexpr auto cos_finalize(T const& fn, T const& xr, T const& dxr = T(0)) noexcept
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

  template<typename T> constexpr auto sin_finalize(T const& a0, T const& fn, T const& xr, T const& dxr = T(0)) noexcept
  {
    auto tmp = plf::one[fn >= T(2)](eve::as(xr));
    auto swap_bit = plf::is_nez(plf::fma(T(-2), tmp, fn));
    auto sign = plf::signnz[eve::pedantic](a0);
    sign *= plf::if_else(plf::is_nez(tmp), plf::mone(eve::as(a0)), plf::one(eve::as(xr)));
    auto xr2 = plf::sqr(xr);
    auto se = sin_eval(xr2, xr);
    auto ce = cos_eval(xr2);
    auto z = plf::if_else(swap_bit, plf::fnma(se, dxr, ce), plf::fma(dxr, ce, se));
    return plf::if_else(plf::is_ltz(sign), -z, z);
  }

  template<typename T> constexpr auto sincos_finalize(T const& a0, T const& fn, T const& xr, T const& dxr) noexcept
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
    return eve::zip((plf::if_else(swap, ce, se) * sin_sign), plf::if_else(swap, se, ce) * cos_sign);
  }

  template<typename T> constexpr auto tan_finalize(T const& a0, T const& fn, T const& xr, T const& dxr) noexcept
  {
    auto aa0lteps = plf::abs(xr) < eps(as<T>());
    auto tmp = plf::one[fn >= T(2)](eve::as(xr));
    auto swap_bit = (plf::fma(T(-2), tmp, fn));
    auto test = plf::is_eqz(swap_bit);
    auto y = tancot_eval(xr);
    y = plf::if_else(test, y, -plf::rec[pedantic](y));
    y = plf::fma(dxr, plf::fma(y, y, plf::one(eve::as<T>())), y);
    y = plf::if_else(aa0lteps, xr, y);
    return plf::if_else(plf::is_negative(a0), -y, y);
  }

  template<typename T> constexpr auto cot_finalize(T a0, T fn, T xr, T dxr) noexcept
  {
    auto aa0lteps = plf::abs(xr) < plf::eps(as<T>());
    auto tmp = plf::one[fn >= T(2)](eve::as(xr));
    auto swap_bit = (plf::fma(T(-2), tmp, fn));
    auto test = plf::is_eqz(swap_bit);
    auto y = tancot_eval(xr);
    y = plf::if_else(test, plf::rec[eve::pedantic](y), -y);
    y = plf::fma(dxr, plf::fma(y, y, plf::one(eve::as<T>())), y);
    y = plf::if_else(aa0lteps, xr, y);
    return plf::if_else(plf::is_negative(a0), -y, y);
  }
}
