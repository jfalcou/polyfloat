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
//! @brief The concepts POLYFLOAT constrains its functions with.
//! @{
//======================================================================================================================
namespace plf::concepts
{
  //! @brief Any value a POLYFLOAT function accepts: a real, or an actual polyfloat.
  template<typename T>
  concept polyfloat_like = _::rank<std::remove_cvref_t<T>> != 0;

  //! @brief A polyfloat_like of rank at most two, so a real or a double-real.
  template<typename T>
  concept doublereal_like = polyfloat_like<T> && _::rank<std::remove_cvref_t<T>> <= 2;

  //! @brief A polyfloat_like of rank at most three.
  template<typename T>
  concept triplereal_like = polyfloat_like<T> && _::rank<std::remove_cvref_t<T>> <= 3;

  //! @brief An actual polyfloat, of rank strictly greater than one, excluding plain reals.
  template<typename T>
  concept polyfloat = polyfloat_like<T> && _::rank<std::remove_cvref_t<T>> > 1;

  //! @brief A polyfloat that is a scalar rather than a SIMD value.
  template<typename T>
  concept scalar_polyfloat = polyfloat<T> && eve::scalar_value<T>;

  //! @brief A polyfloat_like of rank one, that is, a plain real.
  template<typename T>
  concept real = polyfloat_like<T> && _::rank<std::remove_cvref_t<T>> == 1;

  //! @brief A real that is a scalar rather than a SIMD value.
  template<typename T>
  concept scalar_real = real<T> && eve::scalar_value<T>;

}
//! @}
//======================================================================================================================
