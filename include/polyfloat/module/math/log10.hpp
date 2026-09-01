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

  template<typename Options> struct log10_t : eve::elementwise_callable<log10_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(log10_t, log10_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var log10
  //!   @brief return the natural log10arithm value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto log10(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the base 10 logarithm of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/log10.cpp}
  //======================================================================================================================

  inline constexpr auto log10 = eve::functor<log10_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<typename T, eve::callable_options O> constexpr auto log10_(POLYFLOAT_DELAY(), O const&, T xx) noexcept
  {
    if constexpr (dimension_v<T> == 1) return eve::log10(xx);
    else
    {
      auto z = plf::log(xx);
      auto l10 = plf::invlog_10(eve::as(xx));
      auto vh = hi(z) * hi(l10);
      return plf::if_else(eve::is_infinite(vh), vh, plf::log(xx) * plf::invlog_10(eve::as(xx)));
    }
  }
}
