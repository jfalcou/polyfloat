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

  template<typename Options>
  struct exp2_t : plf::elementwise_callable<exp2_t, eve::exp2_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_ABI constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(exp2_t, exp2_);
  };
  //======================================================================================================================
  //! @defgroup plf_exp2 plf::exp2
  //! @ingroup math
  //! @brief return \f$2^x\f$.
  //! @{
  //!   @var exp2
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <polyfloat/polyfloat.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace plf
  //!   {
  //!      template<concepts::polyfloat_like T> constexpr auto exp2(T x) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns \f$2^z\f$. If x is greater than plf::maxlog2 the result is inf.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/math/exp2.cpp}
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
    using u_t = eve::underlying_type_t<T>;
    auto negative = plf::is_ltz(xx);
    auto nan = plf::is_nan(xx);
    auto out_of_range = plf::is_greater(plf::abs(xx), plf::maxlog2(eve::as<u_t>()));
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
