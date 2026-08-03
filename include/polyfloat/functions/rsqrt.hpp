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
#include <polyfloat/functions/ldexp.hpp>
#include <polyfloat/functions/frexp.hpp>
#include <polyfloat/functions/mul.hpp>
#include <polyfloat/functions/sqr.hpp>
#include <iostream>

namespace plf
{

  template<typename Options> struct rsqrt_t : eve::callable<rsqrt_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    {
     return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(rsqrt_t, rsqrt_);
  };
  //======================================================================================================================
  //! @addtogroup functions
  //! @{
  //!   @var rsqrt
  //!   @brief return the inverse square root value.
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <kyosu/functions.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace kyosu
  //!   {
  //!      template<kyosu::concepts::polyfloat_like T> constexpr auto rsqrt(T z) noexcept;
  //!      template<kyosu::concepts::polyfloat_like T> constexpr auto rsqrt[raw](T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the inverse square root of z. With raw option the computation can overflow.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/rsqrt.cpp}
  //======================================================================================================================

  inline constexpr auto rsqrt = eve::functor<rsqrt_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<typename Z, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto rsqrt_(POLYFLOAT_DELAY(), O const& , Z const& z) noexcept
  {
    auto div2 = [](auto x){return ldexp(x, -1); };
    if constexpr(!O::contains(eve::raw) && dimension_v<Z> > 1) //avoid overflow;
    {
      auto [zz, n] = frexp(z);
      auto oddn = eve::is_odd(n);
      zz = if_else(oddn, plf::ldexp(zz, 1), zz);
      n =  plf::dec[oddn](n)  ;
      auto r = ldexp(rsqrt[eve::raw](zz),  -n/2);
      return r;
    }
    else
    if constexpr(dimension_v<Z> == 1)
      return eve::rsqrt(z);
    else if constexpr(dimension_v<Z> == 2)
    {
      auto [a0, b0] = z;
      auto x0 = eve::rsqrt(a0);
      Z x1 = x0+div2(x0*(Z(1)-z*eve::sqr(x0)));
      Z x2 = x1+div2(x1*(Z(1)-z*plf::sqr(x1)));
      return x2;
    }
    else if constexpr(dimension_v<Z> == 3)
    {
      auto [a0, b0, c0] = z;
      auto x0 = eve::rsqrt(a0);
      auto x1 = x0+div2(x0*(Z(1)-z*eve::sqr(x0)));
      auto x2 = x1+div2(x1*(Z(1)-z*plf::sqr(x1)));
      auto x3 = x2+div2(x2*(Z(1)-z*plf::sqr(x2)));
      return x3;

    }
  }
}
