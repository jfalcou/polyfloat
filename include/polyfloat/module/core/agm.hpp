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
#include <polyfloat/module/core/constants/eps.hpp>
#include <polyfloat/module/core/abs.hpp>
#include <polyfloat/module/core/average.hpp>
#include <polyfloat/module/core/exponent.hpp>
#include <polyfloat/module/core/if_else.hpp>
#include <polyfloat/module/core/is_eqz.hpp>
#include <polyfloat/module/core/is_infinite.hpp>
#include <polyfloat/module/core/is_lez.hpp>
#include <polyfloat/module/core/is_unordered.hpp>
#include <polyfloat/module/core/ldexp.hpp>
#include <polyfloat/module/core/sign.hpp>
#include <polyfloat/module/core/sqrt.hpp>

namespace plf
{

  template<typename Options> struct agm_t : eve::callable<agm_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like T0, concepts::polyfloat_like T1>
    requires(eve::same_lanes_or_scalar<T0, T1>)
    EVE_FORCEINLINE as_polyfloat_like_t<T0, T1> constexpr operator()(T0 t0, T1 t1) const noexcept
    {
      return POLYFLOAT_CALL(t0, t1);
    }

    POLYFLOAT_CALLABLE_OBJECT(agm_t, agm_);
  };
  //======================================================================================================================
  //! @agmtogroup core
  //! @{
  //!   @var agm
  //!   @brief return the arithmetic-geometric mean.
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <polyfloat/module/core.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace polyfloat
  //!   {
  //!      template<polyfloat::concepts::polyfloat_like Z1, polyfloat_like Z2> constexpr auto agm(Z1 z1, Z2 z2) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z1`, `z2`: Values to process.
  //!
  //!    **Return value**
  //!
  //!      The value of the arithmetic-geometric mean is returned. No overflow can occur.
  //!      The two parameters must share the same sign.
  //!
  //!  @groupheader{External references}
  //!   *  [Wolfram MathWorld](https://mathworld.wolfram.com/Arithmetic-GeometricMean.html)
  //!   *  [Wikipedia](https://en.wikipedia.org/wiki/Arithmetic-geometric_mean)
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/core/agm.cpp}
  //======================================================================================================================

  inline constexpr auto agm = eve::functor<agm_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

    template<typename T0, typename T1, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto agm_(POLYFLOAT_DELAY(), O const& , T0 const& t0, T1 const& t1) noexcept
  {
    using r_t   =  as_polyfloat_like_t<T0, T1>;
    if constexpr(dimension_v<r_t>   == 1)
      return eve::agm(t0, t1);
    else
    {
      auto cvt = [](auto a){return plf::convert(a, eve::as_element<r_t>{});};
      auto a = cvt(t0);
      auto b = cvt(t1);
      auto ex = exponent(average(a, b));
      auto r     = nan(as<r_t>());
      auto null = is_eqz(a)||is_eqz(b);
      r = if_else(null, zero, r);
      auto infi = is_infinite(a) || is_infinite(b);
      r = if_else(infi, a+b, r);
      auto unord = is_unordered(a, b);
      auto done = is_lez(sign(a)*sign(b)) || unord || infi;
      a = if_else(done,  zero, a);
      b = if_else(done,  zero, b);
      a =  ldexp(a, -ex);
      b =  ldexp(b, -ex);
      auto c  = average(a, -b);
      while (eve::any(abs(c) > 2*eps(as(c))))
      {
        auto an=average(a, b);
        auto bn=sqrt(a*b);
        c=average(a, -b);
        a=an;
        b=bn;
      }
      return if_else(done, r, ldexp(b, ex));
    }
  }
}
