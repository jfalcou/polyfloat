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
#include <polyfloat/module/core/two_add.hpp>
#include <polyfloat/module/core/dekker_prod.hpp>

namespace plf
{

  template<typename Options>
  struct two_fma_approx_t : eve::strict_tuple_callable<two_fma_approx_t, Options, raw_option, pedantic_option>
  {
    template<typename... Ts> struct result : as_polyfloat_like<Ts...>
    {
    };

    template<concepts::polyfloat_like T0, concepts::polyfloat_like T1, concepts::polyfloat_like T2>
    POLYFLOAT_FORCEINLINE typename kumi::tuple<result<T0, T1, T2>, result<T0, T1, T2>> constexpr operator()(
      T0 t0, T1 t1, T2 t2) const noexcept
    {
      return POLYFLOAT_CALL(t0, t1, t2);
    }

    POLYFLOAT_CALLABLE_OBJECT(two_fma_approx_t, two_fma_approx_);
  };
  //================================================================================================
  //! @addtogroup core_accuracy
  //! @{
  //!   @var two_fma_approx
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
  //!      constexpr auto two_fma_approx( auto x, auto y, auto z)            noexcept; // 1
  //!
  //!      // Semantic options
  //!      constexpr auto two_fma_approx[pedantic](auto x, auto y, auto z)  noexcept; // 2
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
  //!       * `a` is `fma(x, y, z)`
  //!       * `e` is a value such that `a`\f$\oplus\f$`e` is equal to `x`\f$\odiv\f$`y`,
  //!          where \f$\oplus\f$ fma_approxs its two parameters with infinite precision.
  //!
  //!     The algorithm depends on the overload:
  //!
  //!     1. algorithm using fma.
  //!     2. Handles overflow.
  //!
  //!  @groupheader{External references}
  //!   *  [Exact and Approximated error of the FMA](https://inria.hal.science/inria-00429617/document)
  //!
  //!  @groupheader{Example}
  //!  @godbolt{doc/core/core/core/two_fma_approx.cpp}
  //================================================================================================
  inline constexpr auto two_fma_approx = eve::functor<two_fma_approx_t>;
  //================================================================================================
  //! @}
  //================================================================================================

  namespace _
  {
    template<typename T0, typename T1, typename T2, eve::callable_options O>
    constexpr POLYFLOAT_FORCEINLINE auto two_fma_approx_(POLYFLOAT_DELAY(), O const&, T0 aa, T1 bb, T2 cc)
    {
      using r_t = as_polyfloat_like_t<T0, T1, T2>;
      using u_t = eve::element_type_t<r_t>;
      auto cvt = [](auto a) { return plf::convert(a, as<u_t>()); };
      auto a = cvt(aa);
      auto b = cvt(bb);
      auto c = cvt(cc);
      auto d = fma(a, b, c);
      auto [v1, v2] = dekker_prod(a, b);
      auto [w1, w2] = two_add(c, v1);
      auto t = w1 - d;
      return eve::zip(d, t + (v2 + w2));
    }
  }
}
