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

namespace plf
{

  template<typename Options> struct expm1_t : eve::elementwise_callable<expm1_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(expm1_t, expm1_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var expm1
  //!   @brief return the the exponential minus one value.
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <polyfloat/core.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace polyfloat
  //!   {
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto expm1(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the exponential minus one  value of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/expm1.cpp}
  //======================================================================================================================

  inline constexpr auto expm1 = eve::functor<expm1_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<typename T, eve::callable_options O> constexpr auto expm1_(POLYFLOAT_DELAY(), O const&, T xx) noexcept
  {
    if constexpr (dimension_v<T> == 1) return eve::expm1(xx);
    else
    {
      return plf::dec(plf::exp(xx));
    }
  }
}
