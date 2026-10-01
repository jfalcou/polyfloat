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

namespace plf::_
{
  template<typename Func> struct constant_t;

  template<template<typename> typename Func, typename Opts> struct constant_t<Func<Opts>> : Func<Opts>
  {
    using base_callable = Func<Opts>;

    template<typename T>
    POLYFLOAT_FORCEINLINE constexpr auto operator[](T t) const
    requires(requires(base_callable const& b) { b[t]; })
    {
      auto new_traits = base_callable::base::operator[](t);
      return constant_t<Func<decltype(new_traits)>>{new_traits};
    }

    template<concepts::real T>
    POLYFLOAT_FORCEINLINE constexpr T operator()(as<T> const& v) const
    requires(requires(base_callable const& b) { b(v); })
    {
      return base_callable::operator()(v);
    }

    template<concepts::polyfloat T>
    POLYFLOAT_FORCEINLINE constexpr T operator()(as<T> const&) const
    requires(requires(base_callable const& b) { b(plf::as_component<T>{}); })
    {
      return T{base_callable::operator()(as_component<T>{})};
    }

    POLYFLOAT_CALLABLE_OBJECT(constant_t, constant_);
  };

  template<auto Constant> inline constexpr constant_t<eve::tag_t<Constant>> as_constant = {};
}

//======================================================================================================================
// List of all EVE constants we re-propagate
//======================================================================================================================
namespace plf
{
  //====================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var allbits
  //!   @brief every bit set, which is the pattern of a quiet NaN for a floating point type, for the requested polyfloat type.
  //!
  //!   @var bitincrement
  //!   @brief the smallest increment representable in the type's bit pattern, for the requested polyfloat type.
  //!
  //!   @var half
  //!   @brief one half, for the requested polyfloat type.
  //!
  //!   @var inf
  //!   @brief positive infinity, for the requested polyfloat type.
  //!
  //!   @var mhalf
  //!   @brief minus one half, for the requested polyfloat type.
  //!
  //!   @var mindenormal
  //!   @brief the smallest denormal value, for the requested polyfloat type.
  //!
  //!   @var minexponent
  //!   @brief the smallest exponent of the type, for the requested polyfloat type.
  //!
  //!   @var minf
  //!   @brief negative infinity, for the requested polyfloat type.
  //!
  //!   @var mone
  //!   @brief minus one, for the requested polyfloat type.
  //!
  //!   @var mzero
  //!   @brief negative zero, for the requested polyfloat type.
  //!
  //!   @var nan
  //!   @brief a quiet NaN, for the requested polyfloat type.
  //!
  //!   @var one
  //!   @brief one, for the requested polyfloat type.
  //!
  //!   @var smallestposval
  //!   @brief the smallest positive normal value, for the requested polyfloat type.
  //!
  //!   @var false_
  //!   @brief the false logical value, for the requested polyfloat type.
  //!
  //!   @var true_
  //!   @brief the true logical value, for the requested polyfloat type.
  //!
  //!   @var zero
  //!   @brief zero, for the requested polyfloat type.
  //!
  //! @}
  //====================================================================================================================

  // Direct reuse
  using eve::false_;
  using eve::true_;
  using eve::zero;

  // Wrapping required
  // from eve::core
  inline constexpr auto allbits = _::as_constant<eve::allbits>;
  inline constexpr auto bitincrement = _::as_constant<eve::bitincrement>;
  inline constexpr auto half = _::as_constant<eve::half>;
  inline constexpr auto mhalf = _::as_constant<eve::mhalf>;
  inline constexpr auto mindenormal = _::as_constant<eve::mindenormal>;
  inline constexpr auto minexponent = _::as_constant<eve::minexponent>;
  inline constexpr auto mone = _::as_constant<eve::mone>;
  inline constexpr auto mzero = _::as_constant<eve::mzero>;
  inline constexpr auto one = _::as_constant<eve::one>;
  inline constexpr auto smallestposval = _::as_constant<eve::smallestposval>;
  //  inline constexpr auto sqrtsmallestposval = _::as_constant<eve::sqrtsmallestposval>;
  //  inline constexpr auto sqrtvalmax = _::as_constant<eve::sqrtvalmax>;

}
