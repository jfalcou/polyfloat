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

  template<typename Options> struct two_sub_t : eve::strict_tuple_callable<two_sub_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like T>
    POLYFLOAT_FORCEINLINE typename kumi::tuple<T, T> constexpr operator()(T t0,  T t1) const noexcept
    {
      return POLYFLOAT_CALL(t0, t1);
    }

    POLYFLOAT_CALLABLE_OBJECT(two_sub_t, two_sub_);
  };
//================================================================================================
//! @subtogroup core_accuracy
//! @{
//!   @var two_sub
//!   @brief Computes the [elementwise](@ref glossary_elementwise) pair consisting of the
//!   difference and its resulting rounding error.
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
//!      constexpr auto two_sub( auto x, auto y)            noexcept; // 1
//!      constexpr auto two_sub[raw](auto x,  auto y)       noexcept; // 2
//!
//!      // Semantic options
//!      constexpr auto two_sub[pedantic](floating_value auto x, floating_value auto y)  noexcept; // 3
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
//!       * `a` is `x+y`
//!       * `e` is a value such that `a`\f$\oplus\f$`e` is equal to `x`\f$\ominus\f$`y`,
//!          where \f$\oplus\f$ subs its two parameters with infinite precision.
//!
//!     1. Classical algorithm, always valid.
//!     2. 'Fast' algorithm, valid only if |x| < |y|.
//!     3. Handles overflow.
//!
//!  @groupheader{External references}
//!   *  [On the Computation of Correctly-Rounded Sums](https://www.vinc17.net/research/papers/rr_ccrsums2.pdf)
//!
//!  @groupheader{Example}
//!  @godbolt{doc/core/two_sub.cpp}
//================================================================================================
  inline constexpr auto two_sub = eve::functor<two_sub_t>;
//================================================================================================
//! @}
//================================================================================================

  namespace _
  {
    template<typename T, eve::callable_options O>
    constexpr POLYFLOAT_FORCEINLINE auto two_sub_(POLYFLOAT_DELAY(), O const&, T a, T b)
    {
      auto r0 = a - b;
      T err;
      if constexpr(O::contains(raw)) // 2fp, this does not work if |a| < |b| (or if radix is not 2, not our case)
      {
        err =   (a-r0) -b;
      }
      else //6fp always ok
      {
        auto z  = r0 - a;
        err = a - (r0 - z) + (b + z);
      }
      if constexpr( eve::platform::supports_infinites && O::contains(pedantic))
        err = if_else(is_not_finite(err) || is_not_finite(r0), eve::zero, err);
      return eve::zip(r0, err);
    }
  }
}
