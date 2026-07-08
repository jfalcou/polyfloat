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
  template<typename T>                    inline constexpr unsigned int rank = 0;
  template<eve::floating_value T>         inline constexpr unsigned int rank<T> = 1;
  template<eve::integral_scalar_value T>  inline constexpr unsigned int rank<T> = 1;
}

namespace plf::concepts
{
  // Value of the polyfloat_like encompass reals and
  // actual polyfloat values
  template<typename T>
  concept polyfloat_like = _::rank<std::remove_cvref_t<T>> != 0;

  template<typename T>
  concept twofloat_like = polyfloat_like<T> && _::rank<std::remove_cvref_t<T>> <= 2;

  template<typename T>
  concept threefloat_like = polyfloat_like<T> && _::rank<std::remove_cvref_t<T>> <= 3;

  template<typename T>
  concept quadfloat_like = polyfloat_like<T>;

  /// General polyfloat concept
  template<typename T>
  concept polyfloat = polyfloat_like<T> &&  _::rank<std::remove_cvref_t<T>> > 1;

  template<typename T>
  concept scalar_polyfloat = polyfloat<T> && eve::scalar_value<T>;

  /// General real concept
  template<typename T>
  concept real = polyfloat_like<T> && _::rank<std::remove_cvref_t<T>> == 1;

  template<typename T>
  concept scalar_real = real<T> && eve::scalar_value<T>;

}
