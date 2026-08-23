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
#include <polyfloat/module/core/minus.hpp>
#include <polyfloat/module/core/is_negative.hpp>

namespace plf
{

  template<typename Options> struct rat_t : eve::callable<rat_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_FORCEINLINE constexpr kumi::tuple<Z, Z>
    operator()(Z z) const noexcept
    {
     return POLYFLOAT_CALL(z);
    }

    template<concepts::polyfloat_like Z0, concepts::polyfloat_like Z1>
    POLYFLOAT_FORCEINLINE constexpr  kumi::tuple<as_polyfloat_like_t<Z0, Z1>, as_polyfloat_like_t<Z0, Z1>>
    operator()(Z0 z0, Z1 tol) const noexcept
    {
     return POLYFLOAT_CALL(z0, tol);
    }

    POLYFLOAT_CALLABLE_OBJECT(rat_t, rat_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var rat
  //!   @brief return the ratolute value.
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
  //!      constexpr auto rat(floating_value auto x)                           noexcept;
  //!      constexpr auto rat(floating_value auto x, floating_value auto tol)  noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!
  //!     * `x` :  [argument](@ref eve::value).
  //!     * `tol`: [floating value](@ref eve::value). By  default `tol`
  //!        is equal to `10*eps(as(x))*eve::abs(x)`.
  //!
  //!   **Return value**
  //!
  //!     Returns the ratolute value of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/rat.cpp}
  //======================================================================================================================

  inline constexpr auto rat = eve::functor<rat_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto rat_(POLYFLOAT_DELAY(), O const& , Z const& x) noexcept
  {
//    std::cout << 10*hi(plf::eps(eve::as(x))*plf::abs(x)) << std::endl;
    return rat(x,10*hi(plf::eps(eve::as(x))*plf::abs(x)));
  }

  template<typename Z0, typename Z1, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto rat_(POLYFLOAT_DELAY(), O const& , Z0 const& xx, Z1 const& tol) noexcept
  {
    using r_t = as_polyfloat_like_t<Z0, Z1>;
    auto cvt =  [](auto a){return plf::convert(a, eve::as<eve::element_type_t<r_t>>());};
    r_t x = cvt(xx);
    if constexpr(dimension_v<r_t> == 1)
      return eve::rat(x, tol);
    else
    {
      auto is_inf = is_infinite(x);
      auto y      = plf::if_else(is_inf, eve::zero, x);
      auto n      = plf::nearest(y);
      auto d      = plf::one(as(y));
      auto frac   = y - n;
      auto lastn  = plf::one(as(y));
      auto lastd  = plf::zero(as(y));

      while( true )
      {
        auto notdone = plf::is_nez(y) && (plf::abs(y - n / d) >= tol);
        if( eve::none(notdone) ) break;
        auto flip   = plf::rec[notdone][pedantic](frac);
        auto step   = plf::if_else(notdone, plf::nearest(flip), zero);
        frac        = flip - step;
        auto savedn = n;
        auto savedd = d;
        n           = plf::fma[notdone](n, step, lastn);
        d           = plf::fma[notdone](d, step, lastd);
        lastn       = savedn;
        lastd       = savedd;
      }
      n *= plf::sign(d);
      d = plf::abs(d);
      n = plf::if_else(is_inf, plf::sign(x), n);
      d = plf::if_else(is_inf, eve::zero, d);
      return eve::zip(n, d);
    }
  }
}
