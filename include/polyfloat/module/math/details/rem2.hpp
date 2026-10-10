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

namespace plf
{
  template<typename Options> struct rem2_t : eve::elementwise_callable<rem2_t, Options, pedantic_option, raw_option>
  {
    template<concepts::polyfloat_like T> constexpr POLYFLOAT_FORCEINLINE eve::zipped<T, T, T> operator()(T v) const
    {
      return POLYFLOAT_CALL(v);
    }

    POLYFLOAT_CALLABLE_OBJECT(rem2_t, rem2_);
  };

  inline constexpr auto rem2 = eve::functor<rem2_t>;
}

namespace plf::_
{
  template<typename T, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto rem2_(POLYFLOAT_DELAY(), O const&, T x) noexcept
  {
    auto xi = plf::nearest(x + x);
    if constexpr (O::contains(eve::pedantic))
    {
      auto [x_2, dx_2] = plf::two_fma_approx(xi, plf::mhalf(eve::as<T>()), x);
      auto xr = x_2 * pi(eve::as<T>());
      auto dxr = dx_2 * pi(eve::as<T>());
      return eve::zip(plf::quadrant(xi), xr, dxr);
    }
    else
    {
      auto x_2 = plf::fma(xi, plf::mhalf(eve::as<T>()), x);
      auto xr = x_2 * pi(eve::as<T>());
      auto dxr = plf::zero(eve::as(xr));
      return eve::zip(plf::quadrant(xi), xr, dxr);
    }
  }
}
