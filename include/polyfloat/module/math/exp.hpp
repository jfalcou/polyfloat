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

  template<typename Options> struct exp_t : eve::elementwise_callable<exp_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(exp_t, exp_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var exp
  //!   @brief return the exponential value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto exp(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the exponential of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/exp.cpp}
  //======================================================================================================================

  inline constexpr auto exp = eve::functor<exp_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<typename T, eve::callable_options O> constexpr auto exp_(POLYFLOAT_DELAY(), O const&, T xx) noexcept
  {
    if constexpr (dimension_v<T> == 1) return eve::exp(xx);
    else
    {
      using u_t = eve::underlying_type_t<T>;
      auto negative = plf::is_ltz(xx);
      auto nan = plf::is_nan(xx);
      auto out_of_range = plf::is_greater(plf::abs(xx), plf::maxlog(eve::as<u_t>()));
      xx = plf::if_else(out_of_range, inf, xx);
      auto x = plf::if_else(out_of_range || nan, zero, xx);

      constexpr int shift = dimension_v<T> == 2 ? -6 : -16;
      constexpr u_t p = 1ul << (-shift);
      auto e = plf::euler(eve::as<eve::element_type_t<T>>());
      auto n = plf::hi(nearest(x));
      auto xf = x - n;
      xf = plf::ldexp(xf, shift);
      // PadeApproximant[Exp[x], {x, 0, {10,10}}]
      auto nn =
        (xf * (xf * (xf * (xf * (xf * (xf * (xf * (xf * (xf * (xf + 110) + 5940) + 205920) + 5045040) + 90810720) +
                                 1210809600) +
                           11762150400) +
                     79394515200) +
               335221286400) +
         670442572800);
      auto dd =
        (xf * (xf * (xf * (xf * (xf * (xf * (xf * (xf * (xf * (xf - 110) + 5940) - 205920) + 5045040) - 90810720) +
                                 1210809600) -
                           11762150400) +
                     79394515200) -
               335221286400) +
         670442572800);
      auto nod = if_else(nn == dd, eve::one, nn / dd);
      auto r = pown(e, n) * pown(nod, p);
      r = if_else(out_of_range, if_else(negative, eve::zero, plf::inf(eve::as<T>())), r);
      r = if_else(nan, xx, r);

      return r;
    }
  }
}
