//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

#include <eve/concept/scalar.hpp>
#include <eve/concept/value.hpp>
#include <eve/concept/same_lanes.hpp>
#include <eve/traits/element_type.hpp>
#include <type_traits>

namespace plf::_
{
  template<typename T> inline constexpr unsigned int rank = 0;
  template<eve::floating_value T> inline constexpr unsigned int rank<T> = 1;
  template<eve::integral_scalar_value T> inline constexpr unsigned int rank<T> = 1;
}

//======================================================================================================================
//! @defgroup concepts Concepts
//! @brief The concepts **POLYFLOAT** constrains its functions with.
//! @{
//======================================================================================================================
namespace plf::concepts
{
  //! @brief Any value a **POLYFLOAT** function accepts: a scalar integer, a floating-point scalar or register, or a
  //! polyfloat scalar or register.
  template<typename T>
  concept polyfloat_like = _::rank<std::remove_cvref_t<T>> != 0;

  //! @brief A polyfloat_like of dimension at most two, a real or a value of dimension 2.
  template<typename T>
  concept doublereal_like = polyfloat_like<T> && _::rank<std::remove_cvref_t<T>> <= 2;

  //! @brief A polyfloat_like of dimension at most three.
  template<typename T>
  concept triplereal_like = polyfloat_like<T> && _::rank<std::remove_cvref_t<T>> <= 3;

  //! @brief A polyfloat_like of dimension 2 or more, which excludes the reals.
  template<typename T>
  concept polyfloat = polyfloat_like<T> && _::rank<std::remove_cvref_t<T>> > 1;

  //! @brief A polyfloat that is a scalar rather than a SIMD value.
  template<typename T>
  concept scalar_polyfloat = polyfloat<T> && eve::scalar_value<T>;

  //! @brief A polyfloat_like of dimension one, a scalar integer or a floating-point scalar or register.
  template<typename T>
  concept real = polyfloat_like<T> && _::rank<std::remove_cvref_t<T>> == 1;

  //! @brief A real that is a scalar rather than a SIMD value.
  template<typename T>
  concept scalar_real = real<T> && eve::scalar_value<T>;

  //! @brief An Integral value.
  template<typename T>
  concept simd_integral = eve::integral_value<T> && eve::simd_value<T>;

}
//! @}
//======================================================================================================================
