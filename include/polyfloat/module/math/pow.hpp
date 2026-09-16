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
#include <polyfloat/module/math/pow_abs.hpp>

namespace plf
{

  template<typename Options> struct pow_t : eve::elementwise_callable<pow_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z1, concepts::polyfloat_like Z2>
    POLYFLOAT_FORCEINLINE constexpr as_polyfloat_like_t<Z1, Z2> operator()(Z1 z1, Z2 z2) const noexcept
    {
      return POLYFLOAT_CALL(z1, z2);
    }

    POLYFLOAT_CALLABLE_OBJECT(pow_t, pow_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var pow
  //!   @brief return \f$x^y\f$.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constpowr auto pow(T x) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns \f$x^y\f$.
  //!
  //!       * pow(+0, y), where y is a negative odd integer, returns \f$+\infty\f$
  //!       * pow(-0, y), where y is a negative odd integer, returns \f$-\infty\f$
  //!       * pow(\f$\pm0\f$, y), where y is negative, finite, and is an even integer or a non-integer,
  //!         returns \f$+\infty\f$
  //!       * pow(\f$\pm0\f$, \f$-\infty\f$) returns \f$+\infty\f$
  //!       * pow(+0, y), where y is a positive odd integer, returns +0
  //!       * pow(-0, y), where y is a positive odd integer, returns -0
  //!       * pow(\f$\pm0\f$, y), where y is positive non-integer or a positive even integer, returns +0
  //!       * pow(-1,\f$\pm\infty\f$) returns 1
  //!       * pow(+1, y) returns 1 for any y, even when y is NaN
  //!       * pow(x, \f$\pm0\f$) returns 1 for any x, even when x is NaN
  //!       * pow(x, y) returns NaN if x is finite and less than 0 and y is finite and non-integer.
  //!       * pow(x, \f$-\infty\f$) returns \f$+\infty\f$ for any |x|<1
  //!       * pow(x, \f$-\infty\f$) returns +0 for any |x|>1
  //!       * pow(x, \f$+\infty\f$) returns +0 for any |x|<1
  //!       * pow(x, \f$+\infty\f$) returns \f$+\infty\f$ for any |x|>1
  //!       * pow(\f$-\infty\f$, y) returns -0 if y is a negative odd integer
  //!       * pow(\f$-\infty\f$, y) returns +0 if y is a negative non-integer or even integer
  //!       * pow(\f$-\infty\f$, y) returns \f$-\infty\f$ if y is a positive odd integer
  //!       * pow(\f$-\infty\f$, y) returns \f$+\infty\f$ if y is a positive non-integer or even integer
  //!       * pow(\f$+\infty\f$, y) returns +0 for any y less than 0
  //!       * pow(\f$+\infty\f$, y) returns \f$+\infty\f$ for any y greater than 0
  //!       * except where specified above, if any argument is NaN, NaN is returned
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/pow.cpp}
  //======================================================================================================================

  inline constexpr auto pow = eve::functor<pow_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<typename T, typename U, eve::callable_options O>
  constexpr auto pow_(POLYFLOAT_DELAY(), O const& o, T a, U b) noexcept
  {
    using r_t = as_polyfloat_like_t<T, U>;
    using e_t = eve::element_type_t<r_t>;
    //    using u_t = eve::underlying_type_t<r_t>;
    auto cvt = [](auto a) { return plf::convert(a, eve::as<e_t>()); };
    if constexpr (dimension_v<T> == 1) return eve::pow(a, b);
    else
    {
      auto x = cvt(a);
      auto y = cvt(b);
      if constexpr (O::contains(eve::raw))
      {
        return exp[o](y * log[o](x));
      }
      else
      {
        if constexpr (eve::scalar_value<T> && eve::scalar_value<U>)
        {
          if (a == plf::mone(eve::as(a)) && plf::is_infinite(b)) return plf::one(eve::as(x));
        }
        auto nega = plf::is_negative(a);
        auto z = plf::pow_abs(x, y);
        return minus[is_odd(b) && nega](z);
      }
    }
  }
}
