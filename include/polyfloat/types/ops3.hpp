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
#include <iostream>
namespace plf
{

  //====================================================================================================================
  //! @}
  //====================================================================================================================

  //====================================================================================================================
  //! @name Binary Operators  <  <=  >  >=
  //! @{
  //====================================================================================================================

  template<eve::value T1, eve::value T2>
  requires(concepts::polyfloat<T1> || concepts::polyfloat<T2>)
  POLYFLOAT_FORCEINLINE auto
  operator <(T1 const& a, T2 const& b) noexcept
  {
    return eve::is_ltz(plf::hi(a-b));
  }

  template<eve::value T1, eve::value T2>
  requires(concepts::polyfloat<T1> || concepts::polyfloat<T2>)
  POLYFLOAT_FORCEINLINE eve::common_logical_t<as_real_type_t<T1>, as_real_type_t<T2>>
  operator > (T1 const& a, T2 const& b) noexcept
  {
    return  eve::is_gtz(plf::hi(a-b));
  }

  template<eve::value T1, eve::value T2>
  requires(concepts::polyfloat<T1> || concepts::polyfloat<T2>)
  POLYFLOAT_FORCEINLINE eve::common_logical_t<as_real_type_t<T1>, as_real_type_t<T2>>
  operator <= (T1 const& a, T2 const& b) noexcept
  {
    return  eve::is_lez(plf::hi(a-b));
  }

  template<eve::value T1, eve::value T2>
  requires(concepts::polyfloat<T1> || concepts::polyfloat<T2>)
  POLYFLOAT_FORCEINLINE eve::common_logical_t<as_real_type_t<T1>, as_real_type_t<T2>>
  operator >= (T1 const& a, T2 const& b) noexcept
  {
    return eve::is_gez(plf::hi(a-b));
  }

  //====================================================================================================================
  //! @}
  //====================================================================================================================
}
