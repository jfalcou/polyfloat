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

    template<typename T> using result_t = expected_result_t<eve::functor<Func>, as<T>>;

    template<concepts::real T>
    constexpr T operator()(as<T> const& v) const
    requires(requires(base_callable const& b) { b(v); })
    {
      return base_callable::operator()(v);
    }

    template<concepts::polyfloat T>
    constexpr result_t<T> operator()(as<T> const&) const
    requires(requires(base_callable const& b) { b(plf::as_component<T>{}); })
    {
      return result_t<T>(base_callable::operator()(as_component<T>{}));
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
  //! @defgroup plf_allbits plf::allbits
  //! @ingroup constants
  //! @brief every bit set in the high part, the pattern of a quiet NaN, and the other parts zero, for the requested
  //!   polyfloat type.
  //! @{
  //!   @var allbits
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
  //! @}

  //! @defgroup plf_bitincrement plf::bitincrement
  //! @ingroup constants
  //! @brief the value whose high part has only its lowest bit set and whose other parts are zero, for the requested
  //!   polyfloat type, equal to plf::mindenormal.
  //! @{
  //!   @var bitincrement
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
  //! @}

  //! @defgroup plf_half plf::half
  //! @ingroup constants
  //! @brief one half, for the requested polyfloat type.
  //! @{
  //!   @var half
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
  //! @}

  //! @defgroup plf_maxexponent plf::maxexponent
  //! @ingroup constants
  //! @brief the largest exponent of a finite value of the base type, for the requested polyfloat type.
  //! @{
  //!   @var maxexponent
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
  //! @}

  //! @defgroup plf_maxexponentm1 plf::maxexponentm1
  //! @ingroup constants
  //! @brief plf::maxexponent minus one, for the requested polyfloat type.
  //! @{
  //!   @var maxexponentm1
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
  //! @}

  //! @defgroup plf_maxexponentp1 plf::maxexponentp1
  //! @ingroup constants
  //! @brief plf::maxexponent plus one, for the requested polyfloat type.
  //! @{
  //!   @var maxexponentp1
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
  //! @}

  //! @defgroup plf_mhalf plf::mhalf
  //! @ingroup constants
  //! @brief minus one half, for the requested polyfloat type.
  //! @{
  //!   @var mhalf
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
  //! @}

  //! @defgroup plf_mindenormal plf::mindenormal
  //! @ingroup constants
  //! @brief the smallest positive denormal of the base type in the high part, the other parts zero, for the requested
  //!   polyfloat type.
  //! @{
  //!   @var mindenormal
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
  //! @}

  //! @defgroup plf_minexponent plf::minexponent
  //! @ingroup constants
  //! @brief the smallest exponent of a normal value of the base type, for the requested polyfloat type.
  //! @{
  //!   @var minexponent
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
  //! @}

  //! @defgroup plf_mone plf::mone
  //! @ingroup constants
  //! @brief minus one, for the requested polyfloat type.
  //! @{
  //!   @var mone
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
  //! @}

  //! @defgroup plf_mzero plf::mzero
  //! @ingroup constants
  //! @brief negative zero, for the requested polyfloat type.
  //! @{
  //!   @var mzero
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
  //! @}

  //! @defgroup plf_one plf::one
  //! @ingroup constants
  //! @brief one, for the requested polyfloat type.
  //! @{
  //!   @var one
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
  //! @}

  //! @defgroup plf_smallestposval plf::smallestposval
  //! @ingroup constants
  //! @brief the smallest positive normal value, for the requested polyfloat type.
  //! @{
  //!   @var smallestposval
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
  //! @}

  //! @defgroup plf_false_ plf::false_
  //! @ingroup constants
  //! @brief the false logical value, for the requested polyfloat type.
  //! @{
  //!   @var false_
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
  //! @}

  //! @defgroup plf_true_ plf::true_
  //! @ingroup constants
  //! @brief the true logical value, for the requested polyfloat type.
  //! @{
  //!   @var true_
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
  //! @}

  //! @defgroup plf_zero plf::zero
  //! @ingroup constants
  //! @brief zero, for the requested polyfloat type.
  //! @{
  //!   @var zero
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
  //! @}

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
