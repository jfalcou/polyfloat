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
#include <polyfloat/module/core/two_split.hpp>

namespace plf
{

  template<typename Options> struct dekker_prod_t : eve::strict_tuple_callable<dekker_prod_t, Options, raw_option, pedantic_option>
  {
//     template<typename... Ts> struct result : as_polyfloat_like<Ts...>
//     {
//     };

    template<concepts::polyfloat_like T>
    POLYFLOAT_FORCEINLINE typename kumi::tuple<T, T> constexpr operator()(T t0,  T t1) const noexcept
    {
      return POLYFLOAT_CALL(t0, t1);
    }

    POLYFLOAT_CALLABLE_OBJECT(dekker_prod_t, dekker_prod_);
  };
//================================================================================================
//! @addtogroup core_accuracy
//! @{
//!   @var dekker_prod
//!   @brief Computes the [elementwise](@ref glossary_elementwise) pair consisting of the
//!   product and its resulting rounding error without using fma.
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
//!      constexpr auto dekker_prod( auto x, auto y)            noexcept; // 1
//!      // Semantic options
//!      constexpr auto dekker_prod[pedantic](auto x, auto y)   noexcept; // 2
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
//!          where \f$\oplus\f$ adds its dekker parameters with infinite precision.
//!
//!     1. Classical algorithm, always valid.
//!     2. Handles overflow.
//!
//!  @groupheader{External references}
//!   *  [On the Computation of Correctly-Rounded Sums](https://www.vinc17.net/research/papers/rr_ccrsums2.pdf)
//!
//!  @groupheader{Example}
//!  @godbolt{doc/core/dekker_prod.cpp}
//================================================================================================
  inline constexpr auto dekker_prod = eve::functor<dekker_prod_t>;
//================================================================================================
//! @}
//================================================================================================

  namespace _
  {
    template<typename T, eve::callable_options O>
    constexpr POLYFLOAT_FORCEINLINE
    auto dekker_prod_(POLYFLOAT_DELAY(), O const&, T a, T b) noexcept
    {
      auto[ah, al] = two_split(a);
      auto[bh, bl] = two_split(b);
      auto abh = a*b;
      auto ahbh= ah*bh;
      auto ahbl= ah*bl;
      auto albh= al*bh;
      auto albl= al*bl;
      auto t1 = ahbh-abh;
      auto t2 = t1 + ahbl;
      auto t3 = t2 + albh;
      auto abl= t3 +albl;
      return eve::zip(abh, abl);
    }
  }
}
