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
#include <polyfloat/module/core/dekker_prod.hpp>

namespace plf
{

  template<typename Options>
  struct three_fma_t : eve::strict_tuple_callable<three_fma_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z>
    EVE_FORCEINLINE eve::zipped<Z, Z, Z> constexpr operator()(Z z0, Z z1, Z z2) const noexcept
    {
      return POLYFLOAT_CALL(z0, z1, z2);
    }

    POLYFLOAT_CALLABLE_OBJECT(three_fma_t, three_fma_);
  };
  //======================================================================================================================
  //! @addtogroup core_accuracy
  //! @{
  //!   @var three_fma
  //!   @brief return the fma of the parameters with errors.
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
  //!      template<polyfloat::concepts::polyfloat_like Z1, polyfloat_like Z2, polyfloat_like Z3> constexpr auto three_fma(Z1 z1, Z2 z2, Z3 z3) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z1`, `z2`, `z3`: Values to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the fma of the arguments and two errors .
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/core/three_fma.cpp}
  //======================================================================================================================
  inline constexpr auto three_fma = eve::functor<three_fma_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<typename Z, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto three_fma_(
    POLYFLOAT_DELAY(), O const&, Z const& x, Z const& y, Z const& z) noexcept
  {
    auto [xh, xl] = dekker_prod(x, y);
    return cr_dw_fp_add_with_err(xl, xh, z);
  }
}
