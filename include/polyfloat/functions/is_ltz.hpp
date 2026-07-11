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

  template<typename Options> struct is_ltz_t : eve::elementwise_callable<is_ltz_t, Options>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_FORCEINLINE constexpr eve::as_logical_t<plf::as_real_type_t<Z>> operator()(Z z) const noexcept
    {
      return eve::is_ltz(hi(z));
    }

    POLYFLOAT_CALLABLE_OBJECT(is_ltz_t, is_ltz_);
  };
  //======================================================================================================================
  //! @addtogroup functions
  //! @{
  //!   @var is_eqz
  //!   @brief test the parameter for les than zero.
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
  //!      template<kyosu::concepts::polyfloat_like T> constexpr auto is_ltz(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the value of z < 0.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/is_ltz.cpp}
  //======================================================================================================================

  inline constexpr auto is_ltz = eve::functor<is_ltz_t>;
}
