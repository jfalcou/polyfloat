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

namespace plf
{

  template<typename Options> struct asinh_t : eve::elementwise_callable<asinh_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(asinh_t, asinh_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var asinh
  //!   @brief return the inverse hyperbolic sine value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto asinh(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the inverse hyperbolic sine of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/asinh.cpp}
  //======================================================================================================================

  inline constexpr auto asinh = eve::functor<asinh_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<typename T, eve::callable_options O> constexpr auto asinh_(POLYFLOAT_DELAY(), O const& o, T a0) noexcept
  {
    if constexpr (dimension_v<T> == 1) return eve::asinh[o](a0);
    else
    {
      auto r = plf::log(a0 + plf::sqrt(plf::inc(plf::sqr(a0))));
      return if_else(is_pinf(a0), a0, r);
    }
  }
}
