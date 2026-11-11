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
  //! @typedef triple_real_t
  //! @brief Floating-point expansion of three values of type `T`, `plf::polyfloat<T, 3>`, and
  //! `eve::wide<plf::polyfloat<E, 3>>` when `T` is the register `eve::wide<E>`.
  //====================================================================================================================
  template<eve::floating_value T> using triple_real_t = as_polyfloat_n_t<3, T>;

  namespace _
  {
    template<eve::floating_value T> triple_real_t<T> from_triple(T h, T m, T l)
    {
      triple_real_t<T> z(h);
      md(z) = m;
      lo(z) = l;
      return z;
    }
  }

  //====================================================================================================================
  //! @}
  //====================================================================================================================
}
