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
namespace plf
{

  template<typename Options> struct abs_t : eve::elementwise_callable<abs_t, Options>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    {
     return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(abs_t, abs_);
  };
  //======================================================================================================================
  //! @addtogroup functions
  //! @{
  //!   @var abs
  //!   @brief return the absolute value.
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
  //!      template<kyosu::concepts::polyfloat_like T> constexpr auto abs(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the absolute value of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/abs.cpp}
  //======================================================================================================================

  inline constexpr auto abs = eve::functor<abs_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto abs_(POLYFLOAT_DELAY(), O const& , Z const& z) noexcept
  {
    return minus[is_negative(z)](z);
  }
}
