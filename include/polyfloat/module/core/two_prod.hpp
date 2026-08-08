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

  template<typename Options> struct two_prod_t : eve::strict_tuple_callable<two_prod_t, Options, raw_option, pedantic_option>
  {
//     template<typename... Ts> struct result : as_polyfloat_like<Ts...>
//     {
//     };

    template<concepts::polyfloat_like T>
    POLYFLOAT_FORCEINLINE typename kumi::tuple<T, T> constexpr operator()(T t0,  T t1) const noexcept
    {
      return POLYFLOAT_CALL(t0, t1);
    }

    POLYFLOAT_CALLABLE_OBJECT(two_prod_t, two_prod_);
  };
//================================================================================================
//! @addtogroup core_accuracy
//! @{
//!   @var two_prod
//!   @brief Computes the [elementwise](@ref glossary_elementwise) pair consisting of the
//!   product and its resulting rounding error.
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
//!      constexpr auto two_prod( auto x, auto y)            noexcept; // 1
//!      // Semantic options
//!      constexpr auto two_prod[pedantic](auto x, auto y)   noexcept; // 2
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
//!       * `e` is a value such that `a`\f$\oplus\f$`e` is equal to `x`\f$\oplus\f$`y`,
//!          where \f$\oplus\f$ adds its two parameters with infinite precision.
//!
//!     1. Classical algorithm, always valid.
//!     2. Handles overflow.
//!
//!  @groupheader{External references}
//!   *  [On the Computation of Correctly-Rounded Sums](https://www.vinc17.net/research/papers/rr_ccrsums2.pdf)
//!
//!  @groupheader{Example}
//!  @godbolt{doc/core/two_prod.cpp}
//================================================================================================
  inline constexpr auto two_prod = eve::functor<two_prod_t>;
//================================================================================================
//! @}
//================================================================================================

  namespace _
  {
    template<typename T, eve::callable_options O>
    constexpr POLYFLOAT_FORCEINLINE auto two_prod_(POLYFLOAT_DELAY(), O const&, T a, T b)
    {
      auto r0 = a * b;
      auto e0 = if_else(plf::is_not_finite(r0), zero, plf::fma[pedantic](a, b, -r0));
      return eve::zip(r0,e0);
    }
  }
}
