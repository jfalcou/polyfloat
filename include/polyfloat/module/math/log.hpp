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
#include <polyfloat/module/core/minus.hpp>
#include <polyfloat/module/core/is_negative.hpp>



namespace plf
{

  template<typename Options> struct log_t : eve::elementwise_callable<log_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    {
     return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(log_t, log_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var log
  //!   @brief return the natural logarithm value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto log(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the expolute,natural logarithm of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/log.cpp}
  //======================================================================================================================

  inline constexpr auto log = eve::functor<log_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<typename T, eve::callable_options O>
  constexpr auto log_(POLYFLOAT_DELAY(), O const& , T xx) noexcept
  {
    if constexpr(dimension_v<T> == 1)
      return eve::log(xx);
    else
    {
      T r(eve::log[eve::pedantic](plf::hi(xx)));
      auto ex = plf::exp[eve::pedantic](-r);
      ex = if_else(eve::is_nan(ex), eve::zero, ex);
      r -=  plf::oneminus(xx*ex);
      if constexpr(dimension_v<T> == 3)
      {
        r -=  plf::oneminus( xx* plf::exp[pedantic](-r));
        r -=  plf::oneminus( xx* plf::exp[pedantic](-r));
      }
      r = if_else(is_ltz(xx) || is_nan(xx), eve::nan, r);
      r = if_else(is_infinite(xx), plf::inf(as(xx)), r);
      r = if_else(is_eqz(xx), plf::minf(as(xx)), r);
      return r;
    }
  }
}
