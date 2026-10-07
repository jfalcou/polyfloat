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
  template<typename T> EVE_FORCEINLINE constexpr auto cos_eval(T const& z2) noexcept
  {
    using e_t = eve::element_type_t<T>;
    return plf::reverse_horner(z2, eve::coefficients(cos_coefs<e_t>()));
  }

  template<typename T> EVE_FORCEINLINE constexpr auto sin_eval(T const& z2, T const& z) noexcept
  {
    using e_t = eve::element_type_t<T>;
    return z * plf::reverse_horner(z2, eve::coefficients(sino_x_coefs<e_t>()));
  }

}
