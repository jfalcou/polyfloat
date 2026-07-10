//======================================================================================================================
/*
  POLYFLOAT - Extended precision floating points
  Copyright : POLYFLOAT Contributors & Maintainers
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once
#include <eve/eve.hpp>

namespace plf
{
  //====================================================================================================================
  //! @name Unary Operators
  //! @{
  //====================================================================================================================

  //! @brief Identity for polyfloat value
  //! @related polyfloat
  template<concepts::polyfloat Z> constexpr auto operator+(Z const& z) noexcept
  {
    return z;
  }

  //! @brief Compute the opposite of a given poly float value
  //! @related polyfloat
  template<concepts::polyfloat Z> constexpr auto operator-(Z const& z) noexcept
  {
    return Z{kumi::map([](auto m) { return -m; }, z)};
  }

  //====================================================================================================================
  //! @}
  //====================================================================================================================

  //====================================================================================================================
  //! @name Binary Operators + - ==  !=
  //! @{
  //====================================================================================================================

  //! @brief Returns the sum of two poly float values
  //! @related polyfloat
  template<eve::value T1, eve::value T2>
  requires(concepts::polyfloat<T1> || concepts::polyfloat<T2>)
    as_polyfloat_t<T1, T2> operator+(T1 const& a, T2 const& b) noexcept
  {
    using type = as_polyfloat_t<T1, T2>;
    type that(a);
    return that += b;
  }


  //! @brief  Returns the difference of a poly float and a floating point value
  //! @related polyfloat
  template<eve::value T1, eve::value T2>
  requires(concepts::polyfloat<T1> || concepts::polyfloat<T2>)
    as_polyfloat_t<T1, T2> operator-(T1 const& a, T2 const& b) noexcept
  {
    using type = as_polyfloat_t<T1, T2>;
    type that(a);
    return that -= b;
  }

  //! @brief Returns the product of two poly float values
  //! @related polyfloat
  template<eve::value T1, eve::value T2>
  requires(concepts::polyfloat<T1> || concepts::polyfloat<T2>)
    as_polyfloat_t<T1, T2> operator*(T1 const& a, T2 const& b) noexcept
  {
    using type = as_polyfloat_t<T1, T2>;
    type that(a); //{plf::convert(a, eve::as<eve::element_type_t<type>>())};
    return that *= b;
  }

  //! @brief Compares a poly float value and a real for equality
  //! @related polyfloat
  template<concepts::polyfloat T1, concepts::real T2> constexpr auto operator==(T1 const& a, T2 b)
  {
    using type = as_polyfloat_t<T1, T2>;
    return type{a} == type{b};
  }

  //! @brief Compares a real and a poly float value for equality
  //! @related polyfloat
  template<concepts::real T1, concepts::polyfloat T2> constexpr auto operator==(T1 const& a, T2 b)
  {
    using type = as_polyfloat_t<T1, T2>;
    return type{a} == type{b};
  }

  //! @brief Compares a poly float value and a real for inequality
  //! @related polyfloat
  template<concepts::polyfloat T1, concepts::real T2> constexpr auto operator!=(T1 const& a, T2 b)
  {
    using type = as_polyfloat_t<T1, T2>;
    return type{a} != type{b};
  }

  //! @brief Compares a real and a poly float value for inequality
  //! @related polyfloat
  template<concepts::real T1, concepts::polyfloat T2> constexpr auto operator!=(T1 const& a, T2 b)
  {
    using type = as_polyfloat_t<T1, T2>;
    return type{a} != type{b};
  }
  //====================================================================================================================
  //! @}
  //====================================================================================================================
}
