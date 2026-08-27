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
#include <iostream>
#include <iomanip>

namespace plf
{

  template<typename Options> struct nthroot_t : eve::callable<nthroot_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z1,  eve::integral_value N>
      POLYFLOAT_FORCEINLINE constexpr Z1 operator()(Z1 z1, N n) const noexcept
    {
      using r_t = eve::element_type_t<decltype(hi(Z1()))>;
      return POLYFLOAT_CALL(z1, eve::convert(n, eve::as<r_t>()));
    }

    template<concepts::polyfloat_like Z,  eve::floating_value N>
      POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z, N n) const noexcept
    {
      using r_t = eve::element_type_t<as_component_type_t<Z>>;
      return POLYFLOAT_CALL(z, plf::convert(n, eve::as<r_t>()));
    }

    POLYFLOAT_CALLABLE_OBJECT(nthroot_t, nthroot_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var nthroot
  //!   @brief return  the nth root: \f$x^{1/n}\f$.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto nthroot(T x, auto n) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!     * `n`: flint or integral value. If n does not represent an integral value it is truncated before use.
  //!
  //!   **Return value**
  //!
  //!     Returns  \f$x^{1/n}\f$.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/nthroot.cpp}
  //======================================================================================================================

  inline constexpr auto nthroot = eve::functor<nthroot_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<typename T, typename N, eve::callable_options O>
  constexpr auto nthroot_(POLYFLOAT_DELAY(), O const& , T xx, N nn) noexcept
  {
    if constexpr(dimension_v<T> == 1)
      return eve::nthroot(xx, nn);
    else
    {
      auto ltz = plf::is_ltz(xx);
      T r = eve::nthroot(plf::hi(xx), nn);
      r = plf::minus[ltz](r);
      auto w = pown(r, nn);
      auto u = dec(nn)*w + inc(nn)*xx;
      auto v = inc(nn)*w + dec(nn)*xx;     
      auto res = if_else(is_eqz(xx), xx, r*(u/v));
      res =  if_else(plf::is_not_finite(xx), xx, res);
      return if_else(ltz && plf::is_even(nn), eve::nan, res); 
    }
  }
}
