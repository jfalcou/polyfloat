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

  template<typename Options>
  struct log_abs_t : plf::elementwise_callable<log_abs_t, eve::log_abs_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_ABI constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(log_abs_t, log_abs_);
  };
  //======================================================================================================================
  //! @addtogroup math
  //! @{
  //!   @var log_abs
  //!   @brief return the natural logarithm of the absolute value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto log_abs(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the natural logarithm of absolute value ofz.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/math/log_abs.cpp}
  //======================================================================================================================

  inline constexpr auto log_abs = eve::functor<log_abs_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<typename T, eve::callable_options O> constexpr auto log_abs_(POLYFLOAT_DELAY(), O const&, T x) noexcept
  {
    return plf::log(plf::abs(x));
  }
}
