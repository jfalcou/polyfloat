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

namespace plf::_
{
  template<typename T> POLYFLOAT_FORCEINLINE constexpr auto rem2(T x) noexcept
  {
    auto xi = plf::nearest(x + x);
    //    auto [x_2, dx_2] = plf::two_fma_approx(xi, plf::mhalf(eve::as<T>()), x);
    auto x_2 = plf::fma(xi, plf::mhalf(eve::as<T>()), x);
    auto xr = x_2 * pi(eve::as<T>());
    auto dxr = plf::zero(eve::as(xr));
    //    auto dxr         = dx_2* pi(eve::as<T>());
    return kumi::make_tuple(plf::quadrant(xi), xr, dxr);
  }
}
