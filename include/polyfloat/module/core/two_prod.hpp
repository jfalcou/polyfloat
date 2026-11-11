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
#include <polyfloat/details/inner_fma.hpp>

namespace plf
{

  template<typename Options>
  struct two_prod_t : eve::strict_tuple_callable<two_prod_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like T>
    POLYFLOAT_ABI typename eve::zipped<T, T> constexpr operator()(T t0, T t1) const noexcept
    {
      return POLYFLOAT_CALL(t0, t1);
    }

    POLYFLOAT_CALLABLE_OBJECT(two_prod_t, two_prod_);
  };
  //================================================================================================
  //! @defgroup plf_two_prod plf::two_prod
  //! @ingroup core_accuracy
  //! @brief Computes the [elementwise](@ref glossary_elementwise) pair of the rounded product of two values and its rounding error, with an fma.
  //! @{
  //!   @var two_prod
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
  //!      constexpr auto two_prod( auto x, auto y)            noexcept; // 1
  //!      // Semantic options
  //!      constexpr auto two_prod[pedantic](auto x, auto y)   noexcept; // 2
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `x`, `y`: two values of the same type, `float` or `double`, or their registers.
  //!
  //!   **Return value**
  //!
  //!     A pair \f$(a, e)\f$ where \f$a = \mathrm{RN}(x y)\f$ and \f$e = \mathrm{fma}(x, y, -a)\f$. In rounding to
  //!     nearest, \f$a + e = x y\f$ exactly when the product does not overflow and
  //!     \f$e_x + e_y \ge e_{\min} + p - 1\f$, \f$e_x\f$ and \f$e_y\f$ being the exponents of `x` and `y` and \f$p\f$
  //!     the precision. The error is zero when the product is not finite. The option `pedantic` does not
  //!     change the result.
  //!
  //!  @groupheader{External references}
  //!   *  [J.-M. Muller et al., Handbook of Floating-Point Arithmetic, 2nd edition](https://doi.org/10.1007/978-3-319-76526-6)
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
    template<typename T, eve::callable_options O> constexpr auto two_prod_(POLYFLOAT_DELAY(), O const&, T a, T b)
    {
      auto r0 = a * b;
      if constexpr (dimension_v<T> == 1)
      {
        auto e0 = if_else(plf::is_not_finite(r0), zero, eve::fma[pedantic](a, b, -r0));
        return eve::zip(r0, e0);
      }
      else
      {
        auto e0 = if_else(plf::is_not_finite(r0), zero(eve::as(a)), plf::_::inner_fma(a, b, -r0));
        return eve::zip(r0, e0);
      }
    }
  }
}
