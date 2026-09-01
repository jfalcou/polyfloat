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
#include <polyfloat/module/core/rec.hpp>

namespace plf
{

  template<typename Options> struct pown_t : eve::callable<pown_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z0, concepts::polyfloat_like Z1>
    POLYFLOAT_FORCEINLINE constexpr plf::as_polyfloat_like_t<Z0, Z1> operator()(Z0 z, Z1 n) const noexcept
    requires(!eve::integral_value<Z1>)
    {
      return POLYFLOAT_CALL(z, n);
    }

    template<concepts::polyfloat_like Z, eve::integral_value N>
    POLYFLOAT_FORCEINLINE constexpr eve::as_wide_as_t<N, Z> operator()(Z z, N n) const noexcept
    {
      return POLYFLOAT_CALL(z, n);
    }

    POLYFLOAT_CALLABLE_OBJECT(pown_t, pown_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var pown
  //!   @brief return the square value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto pown(T z, auto n) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!     * `n`: flint exponent (if it is not flint it is truncated before use).
  //!
  //!   **Return value**
  //!
  //!     Returns  \f$z^\tilda{n}\f$. where \f$\tilda{n}\f$ is the truncature of \f$n\f$n.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/pown.cpp}
  //======================================================================================================================

  inline constexpr auto pown = eve::functor<pown_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<typename Z, eve::integral_value N, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto pown_(POLYFLOAT_DELAY(), O const&, Z const& z, N const& n) noexcept
  {
    using r_t = eve::as_wide_as<N, Z>;
    auto cvt = [](auto a) { return plf::convert(a, eve::as(eve::underlying_type_t<r_t>())); };
    return pown(cvt(z), cvt(n));
  }

  template<typename Z, typename N, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto pown_(POLYFLOAT_DELAY(), O const&, Z const& z, N const& n) noexcept
  {
    if constexpr (dimension_v<Z> == 1) return eve::pow(z, n);
    else
    {
      auto isneg = plf::is_ltz(n);
      auto expo = trunc(abs(n));
      Z base(z);
      Z result(1);
      while (eve::any(plf::is_nez(expo)))
      {
        result = mul(result, plf::if_else(is_odd(expo), base, one));
        expo = plf::floor(expo / 2);
        base = plf::sqr(base);
      }
      return if_else(isneg, plf::rec(result), result);
    }
  }
}
