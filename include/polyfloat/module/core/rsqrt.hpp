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
#include <polyfloat/module/core/ldexp.hpp>
#include <polyfloat/module/core/frexp.hpp>
#include <polyfloat/module/core/mul.hpp>
#include <polyfloat/module/core/sqr.hpp>
#include <polyfloat/module/core/dec.hpp>
#include <polyfloat/module/core/if_else.hpp>
#include <polyfloat/module/core/mantissa.hpp>

namespace plf
{

  template<typename Options> struct rsqrt_t : plf::callable<rsqrt_t, eve::rsqrt_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_ABI constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(rsqrt_t, rsqrt_);
  };
  //======================================================================================================================
  //! @defgroup plf_rsqrt plf::rsqrt
  //! @ingroup core
  //! @brief return the inverse square root value.
  //! @{
  //!   @var rsqrt
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
  //!      template<concepts::polyfloat_like T> constexpr auto rsqrt(T z) noexcept;
  //!      template<concepts::polyfloat_like T> constexpr auto rsqrt[raw](T z) noexcept;
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
  //!  @godbolt{doc/core/rsqrt.cpp}
  //======================================================================================================================

  inline constexpr auto rsqrt = eve::functor<rsqrt_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<typename Z, eve::callable_options O> constexpr auto rsqrt_(POLYFLOAT_DELAY(), O const&, Z const& z) noexcept
  {
    using u_t = eve::element_type_t<Z>;
    constexpr u_t h(0.5);
    constexpr u_t one(1.0);
    constexpr u_t th(1.5);
    if constexpr (!O::contains(eve::raw)) //avoid overflow;
    {
      auto [zz, n] = frexp[pedantic](z);
      auto oddn = eve::is_odd(n);
      zz = plf::if_else(oddn, 2 * zz, zz);
      n = plf::dec[oddn](n);
      return ldexp(rsqrt[eve::raw](zz), -n / 2);
    }
    else if constexpr (dimension_v<Z> == 2)
    {
      auto x0 = eve::rsqrt(plf::hi(z));
      Z x1 = x0 * (th - z * (h * eve::sqr(x0)));
      return x1 * (th - h * plf::sqr(x1) * z);
    }
    else if constexpr (dimension_v<Z> == 3)
    {
      auto x0 = eve::rsqrt(plf::hi(z));
      Z x1 = x0 * (th - z * (h * eve::sqr(x0)));
      x1 = x1 * (th - h * plf::sqr(x1) * z);
      return x1 * (th - h * plf::sqr(x1) * z);
    }
  }
}
