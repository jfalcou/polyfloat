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
#include <polyfloat/module/math/expx2.hpp>

namespace plf
{

  template<typename Options>
  struct log_abs_t : eve::elementwise_callable<log_abs_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(log_abs_t, log_abs_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var log_abs
  //!   @brief return \f$\log|x|\f$.
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
  //!     Returns \f$\log|x|\f$.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/log_abs.cpp}
  //======================================================================================================================

  inline constexpr auto log_abs = eve::functor<log_abs_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename T, eve::callable_options O> constexpr auto log_abs_(POLYFLOAT_DELAY(), O const& o, T a0) noexcept
  {
    if constexpr (dimension_v<T> == 1) return eve::log_abs[o](a0);
    else return plf::log(plf::abs(a0));
  }
}
