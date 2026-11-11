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
  struct two_div_approx_t : eve::strict_tuple_callable<two_div_approx_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like T>
    POLYFLOAT_ABI typename eve::zipped<T, T> constexpr operator()(T t0, T t1) const noexcept
    {
      return POLYFLOAT_CALL(t0, t1);
    }

    POLYFLOAT_CALLABLE_OBJECT(two_div_approx_t, two_div_approx_);
  };
  //================================================================================================
  //! @addtogroup core_accuracy
  //! @{
  //!   @var two_div_approx
  //!   @brief Computes the [elementwise](@ref glossary_elementwise) pair of the rounded quotient of two values and an approximation of its rounding error.
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
  //!      constexpr auto two_div_approx(auto x, auto y)            noexcept; // 1
  //!
  //!      // Semantic options
  //!      constexpr auto two_div_approx[pedantic](auto x, auto y)  noexcept; // 2
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `x`, `y`: two values of the same type, `float` or `double`, or their registers.
  //!
  //!   **Return value**
  //!
  //!     A pair \f$(a, e)\f$ where \f$a = \mathrm{RN}(x / y)\f$ and \f$e = \mathrm{RN}(r / y)\f$, with the remainder
  //!     \f$r = \mathrm{fma}(-a, y, x)\f$. In rounding to nearest, with \f$y \ne 0\f$ and without underflow,
  //!     \f$r = x - a y\f$ exactly, and \f$a + e\f$ approximates \f$x / y\f$. The error is zero when the quotient is
  //!     not finite.
  //!
  //!  @groupheader{External references}
  //!   *  [J.-M. Muller et al., Handbook of Floating-Point Arithmetic, 2nd edition](https://doi.org/10.1007/978-3-319-76526-6)
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
    template<typename T, eve::callable_options O> constexpr auto two_div_approx_(POLYFLOAT_DELAY(), O const&, T x, T y)
    {
      auto r0 = x / y;
      auto e0 = if_else(is_not_finite(r0), zero, plf::fma[pedantic](-r0, y, x) / y);
      return eve::zip(r0, e0);
    }
  }
}
