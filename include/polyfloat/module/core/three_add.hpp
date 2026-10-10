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
#include <type_traits>
#include <polyfloat/module/core/is_not_equal.hpp>
#include <polyfloat/details/graillat.hpp>

namespace plf
{

  template<typename Options>
  struct three_add_t : eve::strict_tuple_callable<three_add_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z>
    EVE_FORCEINLINE eve::zipped<Z, Z, Z> constexpr operator()(Z z0, Z z1, Z z2) const noexcept
    {
      return POLYFLOAT_CALL(z0, z1, z2);
    }

    POLYFLOAT_CALLABLE_OBJECT(three_add_t, three_add_);
  };
  //======================================================================================================================
  //! @addtogroup core_accuracy
  //! @{
  //!   @var three_add
  //!   @brief return the sum of the parameters with errors.
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <polyfloat/module/core.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace polyfloat
  //!   {
  //!      template<polyfloat::concepts::polyfloat_like Z1, polyfloat_like Z2, polyfloat_like Z3> constexpr auto three_add(Z1 z1, Z2 z2, Z3 z3) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z1`, `z2`, `z3`: Values to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the sum of the arguments and two errors .
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/core/three_add.cpp}
  //======================================================================================================================

  inline constexpr auto three_add = eve::functor<three_add_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<typename Z, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto three_add_(
    POLYFLOAT_DELAY(), O const&, Z const& x, Z const& y, Z const& z) noexcept
  {
    auto [xh, xl] = two_add(x, y);
    return cr_dw_fp_add_with_err(xl, xh, z);
  }
}
