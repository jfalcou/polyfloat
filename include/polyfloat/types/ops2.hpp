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
  //! @name Binary Operator /
  //! @{
  //====================================================================================================================

  //! @brief Returns the ratio of two poly float values
  //! @related polyfloat
  template<eve::value T1, eve::value T2>
  requires(concepts::polyfloat<T1> || concepts::polyfloat<T2>)
  as_polyfloat_t<T1, T2> operator/(T1 const& a, T2 const& b) noexcept
  {
    using type = as_polyfloat_t<T1, T2>;
    return a*_::rec(b); 
  }

  //====================================================================================================================
  //! @}
  //====================================================================================================================
}
