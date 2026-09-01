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

  template<typename Options> struct cosh_t : eve::elementwise_callable<cosh_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(cosh_t, cosh_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var cosh
  //!   @brief return the hyperbolic cosine value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto cosh(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the hyperbolicosine of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/cosh.cpp}
  //======================================================================================================================

  inline constexpr auto cosh = eve::functor<cosh_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<typename T, eve::callable_options O> constexpr auto cosh_(POLYFLOAT_DELAY(), O const& o, T a0) noexcept
  {
    if constexpr (dimension_v<T> == 1) return eve::cosh(a0);
    else
    {
      using u_t = eve::underlying_type_t<T>;
      auto inf = is_not_finite(a0);
      T ovflimitmln2 = maxlog(as(a0)) - log_2(as(a0));
      auto aa0 = plf::abs(a0);
      auto x = plf::if_else(inf, zero, aa0);
      auto t = plf::exp[o](x);
      auto invt = if_else(x > 22, eve::zero, plf::rec[pedantic](t));
      auto c = plf::average(t, invt);
      auto test = (x < ovflimitmln2) || inf;
      if (eve::all(test)) return if_else(inf, aa0, c);
      auto w = plf::exp[o](x * half(eve::as<T>()));
      t = eve::half(eve::as<u_t>()) * w;
      t *= w;
      c = if_else(test, c, t);
      return if_else(inf, aa0, c);
    }
  }
}
