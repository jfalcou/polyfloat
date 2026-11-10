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
    template<concepts::polyfloat_like T>
    POLYFLOAT_ABI typename eve::zipped<T, T> constexpr operator()(T t0, T t1) const noexcept
    {
      return POLYFLOAT_CALL(t0, t1);
    }

    POLYFLOAT_CALLABLE_OBJECT(two_add_t, two_add_);
  };
  //================================================================================================
  //! @addtogroup core_accuracy
  //! @{
  //!   @var two_add
  //!   @brief Computes the [elementwise](@ref glossary_elementwise) pair of the rounded sum of two values and its rounding error.
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
  //!      // Regular overload
  //!      constexpr auto two_add( auto x, auto y)            noexcept; // 1
  //!      constexpr auto two_add[raw](auto x,  auto y)       noexcept; // 2
  //!
  //!      // Semantic options
  //!      constexpr auto two_add[pedantic](eve::floating_value auto x, eve::floating_value auto y)  noexcept; // 3
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `x`, `y`: two values of the same type, `float` or `double`, or their registers.
  //!
  //!   **Return value**
  //!
  //!     A pair \f$(a, e)\f$ where \f$a = \mathrm{RN}(x + y)\f$. In rounding to nearest and without overflow,
  //!     \f$a + e = x + y\f$ exactly.
  //!
  //!     1. The 2Sum algorithm, valid for any order of the operands.
  //!     2. With `raw`, the Fast2Sum algorithm, valid only if the exponent of `x` is at least the one of `y`,
  //!        which holds when \f$|x| \ge |y|\f$.
  //!     3. With `pedantic`, the 2Sum algorithm, and the error is zero when the sum or the error is not finite.
  //!
  //!  @groupheader{External references}
  //!   *  [P. Kornerup, V. Lef&egrave;vre, N. Louvet, J.-M. Muller, On the Computation of Correctly-Rounded Sums](https://www.vinc17.net/research/papers/rr_ccrsums2.pdf)
  //!   *  [J.-M. Muller et al., Handbook of Floating-Point Arithmetic, 2nd edition](https://doi.org/10.1007/978-3-319-76526-6)
  //!
  //!  @groupheader{Example}
  //!  @godbolt{doc/core/two_add.cpp}
  //================================================================================================
  inline constexpr auto two_add = eve::functor<two_add_t>;
  //================================================================================================
  //! @}
  //================================================================================================

  namespace _
  {
    template<typename T, eve::callable_options O> constexpr auto two_add_(POLYFLOAT_DELAY(), O const&, T a, T b)
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
