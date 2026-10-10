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
#include <polyfloat/module/core/two_fma_approx.hpp>
#include <polyfloat/module/math/div_180.hpp>

namespace plf
{
  template<typename Options> struct rem180_t : eve::elementwise_callable<rem180_t, Options, pedantic_option, raw_option>
  {
    template<concepts::polyfloat_like T> constexpr POLYFLOAT_FORCEINLINE eve::zipped<T, T, T> operator()(T v) const
    {
      return POLYFLOAT_CALL(v);
    }

    POLYFLOAT_CALLABLE_OBJECT(rem180_t, rem180_);
  };

  inline constexpr auto rem180 = eve::functor<rem180_t>;
}

namespace plf::_
{
  template<typename T, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto rem180_(POLYFLOAT_DELAY(), O const&, T x) noexcept
  {
    auto xi = plf::nearest(2 * plf::div_180(x));
    auto fn = plf::quadrant(xi);
    if constexpr (O::contains(eve::pedantic))
    {
      auto [x_2, dx_2] = plf::two_fma_approx(xi, T(-90), x);
      auto xr = x_2;
      auto tst = x > 45;
      xr = plf::if_else(tst, xr - T(45), xr);
      tst = xr > 45;
      xr = plf::if_else(tst, xr - T(45), xr);
      tst = xr > 45;
      xr = plf::if_else(tst, x - T(45), xr);
      xr = plf::div_180(xr) * pi(as(xr));
      auto dxr = dx_2 * plf::pi(as(xr));
      return eve::zip(fn, xr, dxr);
    }
    else
    {
      auto x_2 = plf::fma(xi, T(-90), x);
      auto xr = x_2;
      auto tst = x > 45;
      xr = plf::if_else(tst, xr - T(45), xr);
      tst = xr > 45;
      xr = plf::if_else(tst, xr - T(45), xr);
      tst = xr > 45;
      xr = plf::if_else(tst, x - T(45), xr);
      xr = plf::div_180(xr) * pi(as(xr));
      auto dxr = plf::zero(eve::as(xr));
      return eve::zip(fn, xr, dxr);
    }
  }
}
