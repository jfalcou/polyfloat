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
#include <polyfloat/functions/minus.hpp>
#include <polyfloat/functions/is_negative.hpp>

namespace plf
{

  template<typename Options> struct dec_t : eve::elementwise_callable<dec_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(dec_t, dec_);
  };
  //======================================================================================================================
  //! @addtogroup functions
  //! @{
  //!   @var dec
  //!   @brief return the  value minus one.
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <kyosu/functions.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace kyosu
  //!   {
  //!      template<kyosu::concepts::polyfloat_like T> constexpr auto dec(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the value of z-1.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/dec.cpp}
  //======================================================================================================================

  inline constexpr auto dec = eve::functor<dec_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto dec_(POLYFLOAT_DELAY(), O const& , Z const& z) noexcept
  {
    if constexpr(dimension_v<Z> == 1)
      return eve::dec(z);
    else
      return z-eve::one(eve::as(hi(z)));
  }
}
