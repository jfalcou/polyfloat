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

  template<typename Options>
  struct sinhcosh_t : eve::elementwise_callable<sinhcosh_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_FORCEINLINE constexpr eve::zipped<Z, Z> operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(sinhcosh_t, sinhcosh_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var sinhcosh
  //!   @brief return the hyperbolic sine and cosine values.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto sinhcosh(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the hyperbolic sine and cosine of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/sinhcosh.cpp}
  //======================================================================================================================

  inline constexpr auto sinhcosh = eve::functor<sinhcosh_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<typename T, eve::callable_options O> constexpr auto sinhcosh_(POLYFLOAT_DELAY(), O const& o, T a0) noexcept
  {
    if constexpr (dimension_v<T> == 1) return eve::sinhcosh(a0);
    else
    {
      using elt_t = eve::element_type_t<T>;
      elt_t ovflimit = plf::maxlog(as<elt_t>());
      elt_t hlf = plf::half(as<elt_t>());
      auto x = plf::abs(a0);
      auto h = plf::copysign(one(eve::as<T>()), a0);
      auto t = plf::expm1(x);
      auto inct = plf::inc(t);
      auto u = t / inct;
      auto z = plf::fnma(t, u, t);
      auto s = hlf * h * (z + t);
      auto invt = if_else(x > elt_t(22), eve::zero, plf::rec[eve::pedantic](inct));
      auto c = plf::average(inct, invt);
      auto test = x < ovflimit;
      if (eve::all(test)) return eve::zip(s, c);

      auto w = plf::exp[o](x * hlf);
      t = hlf * w;
      t *= w;

      s = plf::if_else(test, s, t * h);
      c = plf::if_else(test, c, t);
      return eve::zip(s, c);
    }
  }
}
