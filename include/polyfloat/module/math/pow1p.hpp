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
#include <polyfloat/module/math/pow_abs.hpp>
#include <polyfloat/module/math/log1p.hpp>

namespace plf
{

  template<typename Options>
  struct pow1p_t : plf::elementwise_callable<pow1p_t, eve::pow1p_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z1, concepts::polyfloat_like Z2>
    POLYFLOAT_ABI constexpr as_polyfloat_like_t<Z1, Z2> operator()(Z1 z1, Z2 z2) const noexcept
    {
      return POLYFLOAT_CALL(z1, z2);
    }

    POLYFLOAT_CALLABLE_OBJECT(pow1p_t, pow1p_);
  };
  //======================================================================================================================
  //! @addtogroup math
  //! @{
  //!   @var pow1p
  //!   @brief return \f$(1+x)^y\f$.
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <polyfloat/math.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace polyfloat
  //!   {
  //!      // Regular overload
  //!      constexpr auto pow1p(auto x, auto y)                       noexcept; // 1
  //!
  //!      // Lanes masking
  //!      constexpr auto pow1p[conditional_expr c](auto x, auto y)   noexcept; // 2
  //!      constexpr auto pow1p[logical_value auto m](auto x, auto y) noexcept; // 2
  //!
  //!      // Semantic options
  //!      constexpr auto pow1p[raw]( auto x,  auto y)                noexcept; // 3
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     1. Returns the [elementwise](@ref glossary_elementwise) \f$(1+x)^y\f$, with good accuracy,
  //!        even when `x` is  small.
  //!     2. [The operation is performed conditionally](@ref conditional)
  //!     3. faster but less accurate call.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/math/pow1p.cpp}
  //======================================================================================================================

  inline constexpr auto pow1p = eve::functor<pow1p_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<typename T, typename U, eve::callable_options O>
  constexpr auto pow1p_(POLYFLOAT_DELAY(), O const& o, T a, U b) noexcept
  {
    using r_t = as_polyfloat_like_t<T, U>;
    if constexpr (O::contains(raw))
    {
      return plf::dec(plf::pow[o](a, b));
    }
    else
    {
      using e_t = eve::element_type_t<r_t>;
      auto cvt = [](auto a) { return plf::convert(a, eve::as<e_t>()); };
      auto x = cvt(a);
      auto y = cvt(b);
      auto incx = plf::inc(x);
      return plf::if_else(abs(x) > plf::half(as(x)), plf::pow[o](incx, y), plf::exp[o](y * plf::log1p(x)));
    }
  }
}
