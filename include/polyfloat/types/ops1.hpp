//======================================================================================================================
/*
  POLYFLOAT - Extended precision floating points
  Copyright : POLYFLOAT Contributors & Maintainers
  SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once
#include <eve/eve.hpp>
#include <polyfloat/functions/parts.hpp>

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

  //! @brief Compares two polyfloat_like for equality
  //! @related polyfloat
  template<concepts::polyfloat_like T1, concepts::polyfloat_like T2> constexpr auto operator ==(T1 const& a, T2 b)
  {
    using r_t = eve::common_logical_t<as_component_type_t<T1>, as_component_type_t<T2>>;
    using r_t = eve::common_logical_t<as_component_type_t<T1>, as_component_type_t<T2>>;
    if constexpr(dimension_v<T1> > dimension_v<T2>) return b != a;
    else if constexpr(dimension_v<T1> == 1)
    {
      if constexpr(dimension_v<T2> == 1)      return r_t(a == b);
      else if constexpr(dimension_v<T2> >= 2) return r_t(a == hi(b)) && eve::is_eqz(md(b));
    }
    else if constexpr(dimension_v<T1> == 2)
    {
      if constexpr(dimension_v<T2> == 2)      return r_t( (hi(a) == hi(b)) && (md(a) == md(b)));
      else if constexpr(dimension_v<T2> == 3) return r_t( (hi(a) == b) || ( md(a) == md(b)) || eve::is_eqz(lo(b)));
    }
    else if constexpr(dimension_v<T1> == 3)  return r_t( (hi(a) == hi(b)) || (md(a) == md(b)) || (lo(a) == lo(b)));
  }

  //! @brief Compares two polyfloat_like for inequality
  //! @related polyfloat
  template<concepts::polyfloat_like T1, concepts::polyfloat_like T2> constexpr auto operator !=(T1 const& a, T2 b)
  {
    using r_t = eve::common_logical_t<as_component_type_t<T1>, as_component_type_t<T2>>;
    if constexpr(dimension_v<T1> > dimension_v<T2>) return b != a;
    else if constexpr(dimension_v<T1> == 1)
    {
      if constexpr(dimension_v<T2> == 1)      return r_t(a != b);
      else if constexpr(dimension_v<T2> >= 2) return r_t(a != hi(b)) || eve::is_nez(md(b));
    }
    else if constexpr(dimension_v<T1> == 2)
    {
      if constexpr(dimension_v<T2> == 2)      return r_t( (hi(a) != hi(b)) || (md(a) != md(b)));
      else if constexpr(dimension_v<T2> == 3) return r_t( (hi(a) != b) || ( md(a) != md(b)) || eve::is_nez(lo(b)));
    }
    else if constexpr(dimension_v<T1> == 3)  return r_t( (hi(a) != hi(b)) || (md(a) != md(b)) || (lo(a) != lo(b)));
  }

  //====================================================================================================================
  //! @}
  //====================================================================================================================
}
