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
#include <polyfloat/module/math/expm1.hpp>

namespace plf
{

  template<typename Options> struct coth_t : eve::elementwise_callable<coth_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(coth_t, coth_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var coth
  //!   @brief return the hyperbolic cotangent value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto coth(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the  hyperbolic cotangent of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/coth.cpp}
  //======================================================================================================================

  inline constexpr auto coth = eve::functor<coth_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename T, eve::callable_options O> constexpr auto coth_(POLYFLOAT_DELAY(), O const& o, T a0) noexcept
  {
    if constexpr (dimension_v<T> == 1) return eve::coth[o](a0);
    else
    {
      auto x = plf::abs(a0 + a0);
      auto t = plf::rec[pedantic](plf::expm1(x));
      auto r = plf::fma(T(2), t, T(1));
      r = plf::if_else(plf::is_pinf(x), one(eve::as(x)), r);
      r = plf::if_else(plf::is_eqz(x), plf::inf(eve::as(x)), r);
      return plf::copysign(r, a0);
    }
  }
}
