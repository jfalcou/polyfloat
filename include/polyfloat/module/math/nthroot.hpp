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
#include <polyfloat/module/math/pow.hpp>
#include <polyfloat/module/core/pown.hpp>
#include <type_traits>

namespace plf
{

  template<typename Options> struct nthroot_t : eve::callable<nthroot_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z1, eve::integral_value N>
    POLYFLOAT_FORCEINLINE constexpr eve::as_wide_as_t<N, Z1> operator()(Z1 z1, N n) const noexcept
    {
      return POLYFLOAT_CALL(z1, n);
    }

    template<concepts::polyfloat_like Z, concepts::polyfloat_like N>
    POLYFLOAT_FORCEINLINE constexpr as_polyfloat_like_t<Z, N> operator()(Z z, N n) const noexcept
    {
      return POLYFLOAT_CALL(z, n);
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
  //!  @godbolt_todo{doc/core/nthroot.cpp}
  //======================================================================================================================

  inline constexpr auto nthroot = eve::functor<nthroot_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<typename Z1, eve::integral_value N, eve::callable_options O>
  constexpr auto nthroot_(POLYFLOAT_DELAY(), O const& o, Z1 xx, N n) noexcept
  {
    using r_t = eve::as_wide_as_t<N, Z1>;
    using e_t = eve::element_type_t<r_t>;
    return nthroot[o](plf::convert(xx, eve::as<e_t>()), plf::convert(n, eve::as<e_t>()));
  }

  template<typename T, typename N, eve::callable_options O>
  constexpr auto nthroot_(POLYFLOAT_DELAY(), O const& o, T x, N n) noexcept
  requires(!eve::integral_value<N>)
  {
    if constexpr (dimension_v<T> == 1) return eve::nthroot[o](x, n);
    else
    {
      using r_t = plf::as_polyfloat_like_t<T, N>;
      using e_t = eve::element_type_t<r_t>;
      auto xx = plf::convert(x, eve::as<e_t>());
      auto nn = plf::convert(n, eve::as<e_t>());
      auto ltz = plf::is_ltz(xx);
      r_t r{};
      hi(r) = eve::pow[o](plf::abs(plf::hi(xx)), eve::rec[pedantic](hi(nn)));
      r = (plf::dec(nn) * r + xx * plf::pown(r, -dec(nn))) / nn;
      if constexpr (dimension_v<T> == 3)
      {
        r = (plf::dec(nn) * r + xx * plf::pown(r, -dec(nn))) / nn;
      }
      auto res = plf::if_else(plf::is_eqz(xx), xx, r);
      if constexpr (!O::contains(raw)) res = plf::if_else(plf::is_not_finite(xx), xx, res);
      return plf::if_else(ltz && plf::is_even(nn), plf::nan(eve::as(res)), res);
    }
  }
}
