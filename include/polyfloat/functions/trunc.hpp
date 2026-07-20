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
#include <polyfloat/functions/ceil.hpp>

namespace plf
{

  template<typename Options> struct trunc_t : eve::elementwise_callable<trunc_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(trunc_t, trunc_);
  };
  //======================================================================================================================
  //! @addtogroup functions
  //! @{
  //!   @var trunc
  //!   @brief return the truncolute value.
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
  //!      template<kyosu::concepts::polyfloat_like T> constexpr auto trunc(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the trunc value of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/trunc.cpp}
  //======================================================================================================================

  inline constexpr auto trunc = eve::functor<trunc_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto trunc_(POLYFLOAT_DELAY(), O const& , Z const& z) noexcept
  {
    if constexpr(dimension_v<Z> == 1)
      return eve::trunc(z);
    else
    {
      auto t = plf::is_positive(z);
      return minus[t](ceil(minus[t](z)));
    }
  }
}
