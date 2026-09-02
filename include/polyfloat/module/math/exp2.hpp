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
#include <polyfloat/module/math/constants/log_2.hpp>

namespace plf
{

  template<typename Options> struct exp2_t : eve::elementwise_callable<exp2_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(exp2_t, exp2_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var exp2
  //!   @brief return \f$2^x\f$.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexp2r auto exp2(T x) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns \f$2^x\f$.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/exp2.cpp}
  //======================================================================================================================

  inline constexpr auto exp2 = eve::functor<exp2_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<typename T, eve::callable_options O> constexpr auto exp2_(POLYFLOAT_DELAY(), O const&, T xx) noexcept
  {
    if constexpr (dimension_v<T> == 1) return eve::exp2(xx);
    else
    {
      using u_t = eve::underlying_type_t<T>;
      auto negative = plf::is_ltz(xx);
      auto nan = plf::is_nan(xx);
      auto out_of_range = plf::is_greater(plf::abs(xx), plf::maxlog(eve::as<u_t>()));
      xx = plf::if_else(out_of_range, inf, xx);
      auto x = plf::if_else(out_of_range || nan, zero, xx);

      auto n = plf::hi(nearest(xx));
      auto xf = (x - n) * plf::log_2(eve::as(xx));
      auto r = plf::ldexp(plf::exp(xf), n);
      r = if_else(out_of_range, plf::if_else(negative, eve::zero, plf::inf(eve::as<T>())), r);
      r = if_else(nan, xx, r);
      return r;
    }
  }
}
