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
#include <polyfloat/module/math/cosh.hpp>
#include <polyfloat/module/math/sinh.hpp>
#include <polyfloat/module/math/log.hpp>

namespace plf
{

  template<typename Options> struct acosh_t : eve::elementwise_callable<acosh_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(acosh_t, acosh_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var acosh
  //!   @brief return the inverse hyperbolic cosine value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto acosh(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the invese hyperbolic cosine of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/acosh.cpp}
  //======================================================================================================================

  inline constexpr auto acosh = eve::functor<acosh_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename T, eve::callable_options O> constexpr auto acosh_(POLYFLOAT_DELAY(), O const& o, T a0) noexcept
  {
    if constexpr (dimension_v<T> == 1) return eve::acosh[o](a0);
    else
    {
      auto r = plf::log(a0 + plf::sqrt(plf::dec(plf::sqr(a0))));
      return if_else(is_pinf(a0), a0, r);
    }
  }
}
