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

  template<typename Options> struct is_negative_t : eve::elementwise_callable<is_negative_t, Options>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_FORCEINLINE constexpr eve::as_logical_t<plf::as_real_type_t<Z>> operator()(Z z) const noexcept
    {
     return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(is_negative_t, is_negative_);
  };
  //======================================================================================================================
  //! @addtogroup functions
  //! @{
  //!   @var is_negative
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
  //!      template<kyosu::concepts::polyfloat_like T> constexpr auto is_negative(T z) noexcept;
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
  //!  @godbolt{doc/is_negative.cpp}
  //======================================================================================================================

  inline constexpr auto is_negative = eve::functor<is_negative_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto minus_(POLYFLOAT_DELAY(), O const& , Z const& z) noexcept
  {
    return eve::is_negative(hi(z));
  }
}
}
