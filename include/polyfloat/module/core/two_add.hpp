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

  template<typename Options>
  struct two_add_t : eve::strict_tuple_callable<two_add_t, Options, raw_option, pedantic_option>
  {
    //     template<typename... Ts> struct result : as_polyfloat_like<Ts...>
    //     {
    //     };

    template<concepts::polyfloat_like T>
    POLYFLOAT_FORCEINLINE typename kumi::tuple<T, T> constexpr operator()(T t0, T t1) const noexcept
    {
      return POLYFLOAT_CALL(t0, t1);
    }

    POLYFLOAT_CALLABLE_OBJECT(two_add_t, two_add_);
  };
  //================================================================================================
  //! @addtogroup core_accuracy
  //! @{
  //!   @var two_add
  //!   @brief Computes the [elementwise](@ref glossary_elementwise) pair consisting of the
  //!   sum and its resulting rounding error.
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
  //!      constexpr auto two_add( auto x, auto y)            noexcept; // 1
  //!      constexpr auto two_add[raw](auto x,  auto y)       noexcept; // 2
  //!
  //!      // Semantic options
  //!      constexpr auto two_add[pedantic](floating_value auto x, floating_value auto y)  noexcept; // 3
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
  //!     The algorithm depends on the overload:
  //!
  //!     1. Classical algorithm, always valid.
  //!     2. 'Fast' algorithm, valid only if |x| < |y|.
  //!     3. Handles overflow.
  //!
  //!  @groupheader{External references}
  //!   *  [On the Computation of Correctly-Rounded Sums](https://www.vinc17.net/research/papers/rr_ccrsums2.pdf)
  //!
  //!  @groupheader{Example}
  //!  @godbolt{doc/core/core/two_add.cpp}
  //================================================================================================
  inline constexpr auto two_add = eve::functor<two_add_t>;
  //================================================================================================
  //! @}
  //================================================================================================

  namespace _
  {
    template<typename T, eve::callable_options O>
    constexpr POLYFLOAT_FORCEINLINE auto two_add_(POLYFLOAT_DELAY(), O const&, T a, T b)
    {
      auto r0 = a + b;
      T err;
      if constexpr (O::contains(raw)) // 2fp, this does not work if |a| < |b| (or if radix is not 2, not our case)
      {
        err = b - (r0 - a);
      }
      else //6fp always ok
      {
        auto z = r0 - a;
        err = a - (r0 - z) + (b - z);
      }
      if constexpr (eve::platform::supports_infinites && O::contains(pedantic))
        err = if_else(is_not_finite(err) || is_not_finite(r0), eve::zero, err);
      return eve::zip(r0, err);
    }
  }
}
