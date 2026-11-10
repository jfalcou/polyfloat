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
    constexpr auto operator[](T t) const
    requires(requires(base_callable const& b) { b[t]; })
    {
      auto new_traits = base_callable::base::operator[](t);
      return constant_t<Func<decltype(new_traits)>>{new_traits};
    }

    template<concepts::real T>
    constexpr T operator()(as<T> const& v) const
    requires(requires(base_callable const& b) { b(v); })
    {
      return base_callable::operator()(v);
    }

    template<concepts::polyfloat T>
    constexpr T operator()(as<T> const&) const
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
  //! @addtogroup constants
  //! @{
  //====================================================================================================================

  //! @var allbits
  //! @brief every bit set in the high part, the pattern of a quiet NaN, and the other parts zero, for the requested
  //! polyfloat type.
  //!
  //! @groupheader{Header file}
  //!
  //! @code
  //! #include <polyfloat/polyfloat.hpp>
  //! @endcode
  //!
  //! @groupheader{Callable Signatures}
  //!
  //! @code
  //! namespace plf
  //! {
  //!   template<concepts::polyfloat_like T> constexpr T allbits(eve::as<T> t);
  //! }
  //! @endcode
  //!
  //! **Parameters**
  //!
  //!   * `t`: type wrapper of the result.
  //!
  //! **Return value**
  //!
  //!   Returns the constant in type `T`, in the high part and with the other parts zero for a polyfloat type.
  //!
  //! @groupheader{Example}
  //!
  //! @godbolt{doc/core/wrapped_constants.cpp}

  //! @var bitincrement
  //! @brief the value whose high part has only its lowest bit set and whose other parts are zero, for the requested
  //! polyfloat type, equal to plf::mindenormal.
  //!
  //! @groupheader{Header file}
  //!
  //! @code
  //! #include <polyfloat/polyfloat.hpp>
  //! @endcode
  //!
  //! @groupheader{Callable Signatures}
  //!
  //! @code
  //! namespace plf
  //! {
  //!   template<concepts::polyfloat_like T> constexpr T bitincrement(eve::as<T> t);
  //! }
  //! @endcode
  //!
  //! **Parameters**
  //!
  //!   * `t`: type wrapper of the result.
  //!
  //! **Return value**
  //!
  //!   Returns the constant in type `T`, in the high part and with the other parts zero for a polyfloat type.
  //!
  //! @groupheader{Example}
  //!
  //! @godbolt{doc/core/wrapped_constants.cpp}

  //! @var half
  //! @brief one half, for the requested polyfloat type.
  //!
  //! @groupheader{Header file}
  //!
  //! @code
  //! #include <polyfloat/polyfloat.hpp>
  //! @endcode
  //!
  //! @groupheader{Callable Signatures}
  //!
  //! @code
  //! namespace plf
  //! {
  //!   template<concepts::polyfloat_like T> constexpr T half(eve::as<T> t);
  //! }
  //! @endcode
  //!
  //! **Parameters**
  //!
  //!   * `t`: type wrapper of the result.
  //!
  //! **Return value**
  //!
  //!   Returns the constant in type `T`, in the high part and with the other parts zero for a polyfloat type.
  //!
  //! @groupheader{Example}
  //!
  //! @godbolt{doc/core/wrapped_constants.cpp}

  //! @var maxexponent
  //! @brief the largest exponent of a finite value of the base type, for the requested polyfloat type.
  //!
  //! @groupheader{Header file}
  //!
  //! @code
  //! #include <polyfloat/polyfloat.hpp>
  //! @endcode
  //!
  //! @groupheader{Callable Signatures}
  //!
  //! @code
  //! namespace plf
  //! {
  //!   template<concepts::polyfloat_like T> constexpr T maxexponent(eve::as<T> t);
  //! }
  //! @endcode
  //!
  //! **Parameters**
  //!
  //!   * `t`: type wrapper of the result.
  //!
  //! **Return value**
  //!
  //!   Returns the constant in type `T`, in the high part and with the other parts zero for a polyfloat type.
  //!
  //! @groupheader{Example}
  //!
  //! @godbolt{doc/core/wrapped_constants.cpp}

  //! @var maxexponentm1
  //! @brief plf::maxexponent minus one, for the requested polyfloat type.
  //!
  //! @groupheader{Header file}
  //!
  //! @code
  //! #include <polyfloat/polyfloat.hpp>
  //! @endcode
  //!
  //! @groupheader{Callable Signatures}
  //!
  //! @code
  //! namespace plf
  //! {
  //!   template<concepts::polyfloat_like T> constexpr T maxexponentm1(eve::as<T> t);
  //! }
  //! @endcode
  //!
  //! **Parameters**
  //!
  //!   * `t`: type wrapper of the result.
  //!
  //! **Return value**
  //!
  //!   Returns the constant in type `T`, in the high part and with the other parts zero for a polyfloat type.
  //!
  //! @groupheader{Example}
  //!
  //! @godbolt{doc/core/wrapped_constants.cpp}

  //! @var maxexponentp1
  //! @brief plf::maxexponent plus one, for the requested polyfloat type.
  //!
  //! @groupheader{Header file}
  //!
  //! @code
  //! #include <polyfloat/polyfloat.hpp>
  //! @endcode
  //!
  //! @groupheader{Callable Signatures}
  //!
  //! @code
  //! namespace plf
  //! {
  //!   template<concepts::polyfloat_like T> constexpr T maxexponentp1(eve::as<T> t);
  //! }
  //! @endcode
  //!
  //! **Parameters**
  //!
  //!   * `t`: type wrapper of the result.
  //!
  //! **Return value**
  //!
  //!   Returns the constant in type `T`, in the high part and with the other parts zero for a polyfloat type.
  //!
  //! @groupheader{Example}
  //!
  //! @godbolt{doc/core/wrapped_constants.cpp}

  //! @var mhalf
  //! @brief minus one half, for the requested polyfloat type.
  //!
  //! @groupheader{Header file}
  //!
  //! @code
  //! #include <polyfloat/polyfloat.hpp>
  //! @endcode
  //!
  //! @groupheader{Callable Signatures}
  //!
  //! @code
  //! namespace plf
  //! {
  //!   template<concepts::polyfloat_like T> constexpr T mhalf(eve::as<T> t);
  //! }
  //! @endcode
  //!
  //! **Parameters**
  //!
  //!   * `t`: type wrapper of the result.
  //!
  //! **Return value**
  //!
  //!   Returns the constant in type `T`, in the high part and with the other parts zero for a polyfloat type.
  //!
  //! @groupheader{Example}
  //!
  //! @godbolt{doc/core/wrapped_constants.cpp}

  //! @var mindenormal
  //! @brief the smallest positive denormal of the base type in the high part, the other parts zero, for the requested
  //! polyfloat type.
  //!
  //! @groupheader{Header file}
  //!
  //! @code
  //! #include <polyfloat/polyfloat.hpp>
  //! @endcode
  //!
  //! @groupheader{Callable Signatures}
  //!
  //! @code
  //! namespace plf
  //! {
  //!   template<concepts::polyfloat_like T> constexpr T mindenormal(eve::as<T> t);
  //! }
  //! @endcode
  //!
  //! **Parameters**
  //!
  //!   * `t`: type wrapper of the result.
  //!
  //! **Return value**
  //!
  //!   Returns the constant in type `T`, in the high part and with the other parts zero for a polyfloat type.
  //!
  //! @groupheader{Example}
  //!
  //! @godbolt{doc/core/wrapped_constants.cpp}

  //! @var minexponent
  //! @brief the smallest exponent of a normal value of the base type, for the requested polyfloat type.
  //!
  //! @groupheader{Header file}
  //!
  //! @code
  //! #include <polyfloat/polyfloat.hpp>
  //! @endcode
  //!
  //! @groupheader{Callable Signatures}
  //!
  //! @code
  //! namespace plf
  //! {
  //!   template<concepts::polyfloat_like T> constexpr T minexponent(eve::as<T> t);
  //! }
  //! @endcode
  //!
  //! **Parameters**
  //!
  //!   * `t`: type wrapper of the result.
  //!
  //! **Return value**
  //!
  //!   Returns the constant in type `T`, in the high part and with the other parts zero for a polyfloat type.
  //!
  //! @groupheader{Example}
  //!
  //! @godbolt{doc/core/wrapped_constants.cpp}

  //! @var mone
  //! @brief minus one, for the requested polyfloat type.
  //!
  //! @groupheader{Header file}
  //!
  //! @code
  //! #include <polyfloat/polyfloat.hpp>
  //! @endcode
  //!
  //! @groupheader{Callable Signatures}
  //!
  //! @code
  //! namespace plf
  //! {
  //!   template<concepts::polyfloat_like T> constexpr T mone(eve::as<T> t);
  //! }
  //! @endcode
  //!
  //! **Parameters**
  //!
  //!   * `t`: type wrapper of the result.
  //!
  //! **Return value**
  //!
  //!   Returns the constant in type `T`, in the high part and with the other parts zero for a polyfloat type.
  //!
  //! @groupheader{Example}
  //!
  //! @godbolt{doc/core/wrapped_constants.cpp}

  //! @var mzero
  //! @brief negative zero, for the requested polyfloat type.
  //!
  //! @groupheader{Header file}
  //!
  //! @code
  //! #include <polyfloat/polyfloat.hpp>
  //! @endcode
  //!
  //! @groupheader{Callable Signatures}
  //!
  //! @code
  //! namespace plf
  //! {
  //!   template<concepts::polyfloat_like T> constexpr T mzero(eve::as<T> t);
  //! }
  //! @endcode
  //!
  //! **Parameters**
  //!
  //!   * `t`: type wrapper of the result.
  //!
  //! **Return value**
  //!
  //!   Returns the constant in type `T`, in the high part and with the other parts zero for a polyfloat type.
  //!
  //! @groupheader{Example}
  //!
  //! @godbolt{doc/core/wrapped_constants.cpp}

  //! @var one
  //! @brief one, for the requested polyfloat type.
  //!
  //! @groupheader{Header file}
  //!
  //! @code
  //! #include <polyfloat/polyfloat.hpp>
  //! @endcode
  //!
  //! @groupheader{Callable Signatures}
  //!
  //! @code
  //! namespace plf
  //! {
  //!   template<concepts::polyfloat_like T> constexpr T one(eve::as<T> t);
  //! }
  //! @endcode
  //!
  //! **Parameters**
  //!
  //!   * `t`: type wrapper of the result.
  //!
  //! **Return value**
  //!
  //!   Returns the constant in type `T`, in the high part and with the other parts zero for a polyfloat type.
  //!
  //! @groupheader{Example}
  //!
  //! @godbolt{doc/core/wrapped_constants.cpp}

  //! @var smallestposval
  //! @brief the smallest positive normal value, for the requested polyfloat type.
  //!
  //! @groupheader{Header file}
  //!
  //! @code
  //! #include <polyfloat/polyfloat.hpp>
  //! @endcode
  //!
  //! @groupheader{Callable Signatures}
  //!
  //! @code
  //! namespace plf
  //! {
  //!   template<concepts::polyfloat_like T> constexpr T smallestposval(eve::as<T> t);
  //! }
  //! @endcode
  //!
  //! **Parameters**
  //!
  //!   * `t`: type wrapper of the result.
  //!
  //! **Return value**
  //!
  //!   Returns the constant in type `T`, in the high part and with the other parts zero for a polyfloat type.
  //!
  //! @groupheader{Example}
  //!
  //! @godbolt{doc/core/wrapped_constants.cpp}

  //! @var false_
  //! @brief the false logical value, for the requested polyfloat type.
  //!
  //! @groupheader{Header file}
  //!
  //! @code
  //! #include <polyfloat/polyfloat.hpp>
  //! @endcode
  //!
  //! @groupheader{Callable Signatures}
  //!
  //! @code
  //! namespace plf
  //! {
  //!   template<eve::value T> constexpr eve::as_logical_t<T> false_(eve::as<T> t) noexcept;
  //! }
  //! @endcode
  //!
  //! **Parameters**
  //!
  //!   * `t`: type wrapper of the result.
  //!
  //! **Return value**
  //!
  //!   Returns the logical value `false` of the logical type of `T`.
  //!
  //! @groupheader{Example}
  //!
  //! @godbolt{doc/core/wrapped_constants.cpp}

  //! @var true_
  //! @brief the true logical value, for the requested polyfloat type.
  //!
  //! @groupheader{Header file}
  //!
  //! @code
  //! #include <polyfloat/polyfloat.hpp>
  //! @endcode
  //!
  //! @groupheader{Callable Signatures}
  //!
  //! @code
  //! namespace plf
  //! {
  //!   template<eve::value T> constexpr eve::as_logical_t<T> true_(eve::as<T> t) noexcept;
  //! }
  //! @endcode
  //!
  //! **Parameters**
  //!
  //!   * `t`: type wrapper of the result.
  //!
  //! **Return value**
  //!
  //!   Returns the logical value `true` of the logical type of `T`.
  //!
  //! @groupheader{Example}
  //!
  //! @godbolt{doc/core/wrapped_constants.cpp}

  //! @var zero
  //! @brief zero, for the requested polyfloat type.
  //!
  //! @groupheader{Header file}
  //!
  //! @code
  //! #include <polyfloat/polyfloat.hpp>
  //! @endcode
  //!
  //! @groupheader{Callable Signatures}
  //!
  //! @code
  //! namespace plf
  //! {
  //!   template<eve::value T> constexpr T zero(eve::as<T> t) noexcept;
  //! }
  //! @endcode
  //!
  //! **Parameters**
  //!
  //!   * `t`: type wrapper of the result.
  //!
  //! **Return value**
  //!
  //!   Returns zero in type `T`.
  //!
  //! @groupheader{Example}
  //!
  //! @godbolt{doc/core/wrapped_constants.cpp}

  //====================================================================================================================
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

  inline constexpr auto maxexponent = _::as_constant<eve::maxexponent>;
  inline constexpr auto maxexponentp1 = _::as_constant<eve::maxexponentp1>;
  inline constexpr auto maxexponentm1 = _::as_constant<eve::maxexponentm1>;
  inline constexpr auto mone = _::as_constant<eve::mone>;
  inline constexpr auto mzero = _::as_constant<eve::mzero>;
  inline constexpr auto one = _::as_constant<eve::one>;
  inline constexpr auto smallestposval = _::as_constant<eve::smallestposval>;
}
