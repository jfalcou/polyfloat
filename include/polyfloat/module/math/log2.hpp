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

  template<typename Options> struct log2_t : eve::elementwise_callable<log2_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(log2_t, log2_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var log2
  //!   @brief return the natural log2arithm value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto log2(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the base 2 logarithm of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/log2.cpp}
  //======================================================================================================================

  inline constexpr auto log2 = eve::functor<log2_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<typename T, eve::callable_options O> constexpr auto log2_(POLYFLOAT_DELAY(), O const&, T xx) noexcept
  {
    if constexpr (dimension_v<T> == 1) return eve::log2(xx);
    else
    {
      return plf::log(xx) * plf::invlog_2(eve::as(xx));
    }
  }
}
