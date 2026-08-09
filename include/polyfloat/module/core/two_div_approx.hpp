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
#include <polyfloat/module/core/if_else.hpp>
#include <polyfloat/module/core/is_not_finite.hpp>

namespace plf
{

  template<typename Options> struct two_div_approx_t : eve::strict_tuple_callable<two_div_approx_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like T>
    POLYFLOAT_FORCEINLINE typename kumi::tuple<T, T> constexpr operator()(T t0,  T t1) const noexcept
    {
      return POLYFLOAT_CALL(t0, t1);
    }

    POLYFLOAT_CALLABLE_OBJECT(two_div_approx_t, two_div_approx_);
  };
//================================================================================================
//! @addtogroup core_accuracy
//! @{
//!   @var two_div_approx
//!   @brief Computes the [elementwise](@ref glossary_elementwise) pair consisting of the
//!   division and its resulting approximate rounding error.
//!
//!   @groupheader{Header file}
//!
//!   @code
//!   #include <eve/module/core.hpp>
//!   @endcode
//!
//!   @groupheader{Callable Signatures}
//!
//!   @code
//!   namespace eve
//!   {
//!      // Regular overload
//!      constexpr auto two_div_approx( auto x, auto y, auto z)            noexcept; // 1
//!
//!      // Semantic options
//!      constexpr auto two_div_approx[pedantic](auto x, auto y, auto z)  noexcept; // 2
//!   }
//!   @endcode
//!
//!   **Parameters**
//!
//!     * `x`, `y`:  polyfloatt arguments](@ref eve::floating_value) of same dimension.
//!
//!   **Return value**
//!
//!     Computes [elementwise](@ref glossary_elementwise) a pair of values `[a,e]` such that:
//!       * `a` is `div(x, y, z)`
//!       * `e` is a value such that `a`\f$\oplus\f$`e` is equal to `x`\f$\odiv\f$`y`,
//!          where \f$\oplus\f$ div_approxs its two parameters with infinite precision.
//!
//!     1. algorithm using div.
//!     2. Handles overflow.
//!
//!  @groupheader{External references}
//!   *  [Exact and Approximated error of the DIV](https://inria.hal.science/inria-00429617/document)
//!
//!  @groupheader{Example}
//!  @godbolt{doc/core/two_div_approx.cpp}
//================================================================================================
  inline constexpr auto two_div_approx = eve::functor<two_div_approx_t>;
//================================================================================================
//! @}
//================================================================================================

  namespace _
  {
    template<typename T, eve::callable_options O>
    constexpr POLYFLOAT_FORCEINLINE auto two_div_approx_(POLYFLOAT_DELAY(), O const&, T x, T y)
    {
      auto r0 = x/y;
      auto e0 = if_else(is_not_finite(r0), zero, plf::fma[pedantic](-r0, y, x)/y );
      return eve::zip(r0,e0);
    }
  }
}
