//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

#include <eve/eve.hpp>
#include <polyfloat/types/polyfloat.hpp>
#include <polyfloat/types/traits.hpp>
#include <polyfloat/module/core/parts.hpp>

namespace plf
{
  //====================================================================================================================
  //! @addtogroup types
  //! @{
  //====================================================================================================================

  //====================================================================================================================
  //! @typedef double_real_t
  //! @brief Floating-point expansion of two values of type `T`, `plf::polyfloat<T, 2>`, and
  //! `eve::wide<plf::polyfloat<E, 2>>` when `T` is the register `eve::wide<E>`.
  //====================================================================================================================
  template<eve::floating_value T> using double_real_t = as_polyfloat_n_t<2, T>;

  namespace _
  {
    template<eve::floating_value T> double_real_t<T> from_pair(T h, T l)
    {
      double_real_t<T> z(h);
      lo(z) = l;
      return z;
    }
  }
  //====================================================================================================================
  //! @}
  //====================================================================================================================
}
