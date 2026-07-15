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

  template<typename Options> struct is_nan_t : eve::elementwise_callable<is_nan_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_FORCEINLINE constexpr eve::as_logical_t<plf::as_real_type_t<Z>> operator()(Z z) const noexcept
    {
      return eve::is_nan(hi(z));
    }

    POLYFLOAT_CALLABLE_OBJECT(is_nan_t, is_nan_);
  };
  //======================================================================================================================
  //! @addtogroup functions
  //! @{
  //!   @var is_nan
  //!   @brief `elementwise callable` returning a logical true if and only if the element
  //!    has its sign bit set
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
  //!      template<kyosu::concepts::polyfloat_like T> constexpr auto is_nan(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     returns true if and only if the bit of sign (most significant bit) is set.
  //!     Of course the result on a NaN input is generally out of control.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/is_nan.cpp}
  //======================================================================================================================

  inline constexpr auto is_nan = eve::functor<is_nan_t>;
}
