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
#include <polyfloat/module/math/exp.hpp>

namespace plf
{

  template<typename Options> struct sinh_t : eve::elementwise_callable<sinh_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(sinh_t, sinh_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var sinh
  //!   @brief return the hyperbolic sine value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto sinh(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the hyperbolic sine of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/sinh.cpp}
  //======================================================================================================================

  inline constexpr auto sinh = eve::functor<sinh_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<typename T, eve::callable_options O> constexpr auto sinh_(POLYFLOAT_DELAY(), O const& o, T a0) noexcept
  {
    if constexpr (dimension_v<T> == 1) return eve::sinh(a0);
    else
    {
      using u_t = eve::underlying_type_t<T>;
      auto inf = is_not_finite(a0);
      auto x = plf::abs(a0);
      auto h = plf::if_else(is_gtz(a0), one(eve::as<u_t>()), mone);
      auto t = plf::exp(x) - 1; //plf::expm1(x);
      auto inct = plf::inc(t);
      auto u = t / inct;
      auto z = fnma(t, u, t);
      auto s = h * plf::average(z, t);

      s = if_else(is_eqz(a0), a0, s);
      auto test = x < maxlog(as<T>()) || inf;
      if (eve::all(test)) return if_else(inf, a0, s);
      auto w = exp[o](x * half(eve::as<u_t>()));
      t = half(eve::as<u_t>()) * w;
      t *= w;

      s = if_else(test, s, t * h);
      return if_else(inf, a0, s);
    }
  }
}
