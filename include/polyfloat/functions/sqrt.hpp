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

namespace plf
{

  template<typename Options> struct sqrt_t : eve::callable<sqrt_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    {
     return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(sqrt_t, sqrt_);
  };
  //======================================================================================================================
  //! @addtogroup functions
  //! @{
  //!   @var sqrt
  //!   @brief return the square value.
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
  //!      template<kyosu::concepts::polyfloat_like T> constexpr auto sqrt(T z) noexcept;
  //!      template<kyosu::concepts::polyfloat_like T> constexpr auto sqrt[raw](T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the square root of z. With raw option the computation can overflow.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/sqrt.cpp}
  //======================================================================================================================

  inline constexpr auto sqrt = eve::functor<sqrt_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<typename Z, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto sqrt_(POLYFLOAT_DELAY(), O const& , Z const& z) noexcept
  {
    if constexpr(!O::contains(eve::raw) && dimension_v<Z> > 1) //avoid overflow;
    {
      auto [zz, n] = frexp(z);
      auto oddn = eve::is_odd(n);
      zz = plf::mul[oddn](zz, 2);
      n =  plf::dec[oddn](n)  ;
      return ldexp(sqrt[eve::raw](zz),  n/2);
    }
    else if constexpr(dimension_v<Z> == 1)
      return eve::sqrt(z);
    else if constexpr(dimension_v<Z> == 2)
    {
      auto [a0, b0] = z;
      auto x0 = eve::rsqrt(a0);
      auto x1 = x0+x0*(Z(1)-sqr(z)*x0)/2;
      return x1*z;
    }
    else if constexpr(dimension_v<Z> == 3)
    {
      auto [a0, b0, c0] = z;
      auto x0 = eve::rsqrt(a0);
      auto x1 = x0+x0*(Z(1)-z*eve::sqr(x0))/2;
      auto x2 = x1+x1*(Z(1)-z*sqr(x1))/2;
      auto x3 = x2+x2*(Z(1)-z*sqr(x2))/2;
      return x3*z;

    }
  }
}
