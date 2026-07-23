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
#include <polyfloat/functions/if_else.hpp>
#include <polyfloat/functions/inc.hpp>
#include <polyfloat/functions/is_negative.hpp>

namespace plf
{

  template<typename Options> struct ceil_t : eve::elementwise_callable<ceil_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(ceil_t, ceil_);
  };
  //======================================================================================================================
  //! @addtogroup functions
  //! @{
  //!   @var ceil
  //!   @brief return the ceilolute value.
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
  //!      template<kyosu::concepts::polyfloat_like T> constexpr auto ceil(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the ceil value of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/ceil.cpp}
  //======================================================================================================================

  inline constexpr auto ceil = eve::functor<ceil_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto ceil_(POLYFLOAT_DELAY(), O const& , Z const& z) noexcept
  {
    if constexpr(dimension_v<Z> == 1)
      return eve::ceil(z);
    else if constexpr(dimension_v<Z> == 2)
    {
      auto [h, l] = z;
      auto hifl = eve::is_flint(h);
      auto lofrac = l < eve::one(eve::as(l));
      auto loneg = eve::is_negative(l);
      auto r2 = if_else(lofrac, inc[loneg](Z(h)),Z(h, eve::ceil(l)));
      auto r1 = if_else(hifl, r2, Z(eve::ceil(h)));
      return r1;
    }
    else if constexpr(dimension_v<Z> == 3)
    {
      auto [h, m, l] = z;
      auto hifl = eve::is_flint(h);
      auto mdfl = eve::is_flint(m);
      auto lofl = eve::is_flint(l);
      auto mdfrac = l < eve::one(eve::as(l));
      auto lofrac = m < eve::one(eve::as(l));
      auto mdneg = eve::is_negative(m);
      auto loneg = eve::is_negative(l);
      auto r3 = if_else(lofrac, inc[loneg](Z(h, m)),Z(h, m));
      auto r2 = if_else(mdfrac, inc[mdneg](Z(h)), Z(h, eve::ceil(m), eve::zero(eve::as(l))));
      auto r1 = if_else(hifl, if_else(mdfl, r3, r2), Z(ceil(h)));
      return r1;
    }
  }
}
