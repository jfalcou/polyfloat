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
#include <polyfloat/module/core/is_not_finite.hpp>
#include <polyfloat/module/core/if_else.hpp>

namespace plf
{

  template<typename Options> struct dekker_prod_t : eve::strict_tuple_callable<dekker_prod_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like T0, concepts::polyfloat_like T1>
    POLYFLOAT_FORCEINLINE typename kumi::tuple<plf::as_polyfloat_like_t<T0, T1>,
                                               plf::as_polyfloat_like_t<T0, T1>>
    constexpr operator()(T0 t0, T1 t1) const noexcept
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
//!     * `x`, `y`:  polyfloat arguments](@ref eve::floating_value) of same dimension.
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
//!  @godbolt{doc/core/core/dekker_prod.cpp}
//================================================================================================
  inline constexpr auto dekker_prod = eve::functor<dekker_prod_t>;
//================================================================================================
//! @}
//================================================================================================

  namespace _
  {
    template<typename T0,  typename T1, eve::callable_options O>
    constexpr POLYFLOAT_FORCEINLINE
    auto dekker_prod_(POLYFLOAT_DELAY(), O const&, T0 aa, T1 bb) noexcept
    {
      using r_t = plf::as_polyfloat_like_t<T0, T1>;
      auto cvt = [](auto a){return plf::convert(a, eve::as_element<r_t>{});};
      auto a = cvt(aa);
      auto b = cvt(bb);
      auto[ah, al] = two_split(a);
      auto[bh, bl] = two_split(b);
      auto abh = a*b;
      auto abl = ah*bh-abh;
      abl += ah*bl;
      abl += al*bh;
      abl += al*bl;
      if constexpr( eve::platform::supports_invalids ) abl = plf::if_else(plf::is_not_finite(abh), eve::zero, abl);
      return eve::zip(abh, abl);
    }
  }
}
