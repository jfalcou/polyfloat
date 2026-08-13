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

  template<typename Options> struct is_positive_t : eve::elementwise_callable<is_positive_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_FORCEINLINE constexpr eve::as_logical_t<plf::as_component_type_t<Z>> operator()(Z z) const noexcept
    {
      return eve::is_positive(hi(z));
    }

    POLYFLOAT_CALLABLE_OBJECT(is_positive_t, is_positive_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var is_positive
  //!   @brief `elementwise callable` returning a logical true if and only if the element
  //!    has its sign bit unset
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto is_positive(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     returns true if and only if the bit of sign (most significant bit) is not set.
  //!     Of course the result on a NaN input is generally out of control.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/is_positive.cpp}
  //======================================================================================================================

  inline constexpr auto is_positive = eve::functor<is_positive_t>;
}
