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

    template<concepts::polyfloat_like T> POLYFLOAT_ABI eve::zipped<T, T> operator()(T t0, T t1, T t2) const noexcept
    {
      return POLYFLOAT_CALL(t0, t1, t2);
    }

    POLYFLOAT_CALLABLE_OBJECT(two_fma_approx_t, two_fma_approx_);
  };
  //================================================================================================
  //! @addtogroup core_accuracy
  //! @{
  //!   @var two_fma_approx
  //!   @brief Computes the [elementwise](@ref glossary_elementwise) pair of the rounded fma of three values and an approximation of its rounding error.
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
  //!      constexpr auto two_fma_approx( auto x, auto y, auto z)            noexcept; // 1
  //!
  //!      // Semantic options
  //!      constexpr auto two_fma_approx[pedantic](auto x, auto y, auto z)  noexcept; // 2
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `x`, `y`, `z`: three values of the same type, `float` or `double`, or their registers.
  //!
  //!   **Return value**
  //!
  //!     A pair \f$(a, e)\f$ where \f$a = \mathrm{RN}(x y + z)\f$, and \f$a + e\f$ approximates \f$x y + z\f$, the
  //!     exact error of an fma needing two values in general. The algorithm is ErrFmaApprox of Boldo and Muller,
  //!     in rounding to nearest, without overflow or underflow.
  //!
  //!  @groupheader{External references}
  //!   *  [S. Boldo, J.-M. Muller, Exact and Approximated error of the FMA](https://inria.hal.science/inria-00429617/document)
  //!
  //!  @groupheader{Example}
  //!  @godbolt{doc/core/two_fma_approx.cpp}
  //================================================================================================
  inline constexpr auto two_fma_approx = eve::functor<two_fma_approx_t>;
  //================================================================================================
  //! @}
  //================================================================================================

  namespace _
  {
    template<typename T, eve::callable_options O>
    constexpr auto two_fma_approx_(POLYFLOAT_DELAY(), O const&, T a, T b, T c)
    {
      auto d = fma(a, b, c);
      auto [v1, v2] = dekker_prod(a, b);
      auto [w1, w2] = two_add(c, v1);
      auto t = w1 - d;
      return eve::zip(d, t + (v2 + w2));
    }
  }
}
