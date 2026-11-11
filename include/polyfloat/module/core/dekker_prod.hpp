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

  template<typename Options>
  struct dekker_prod_t : eve::strict_tuple_callable<dekker_prod_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like T0, concepts::polyfloat_like T1>
    POLYFLOAT_ABI typename eve::zipped<plf::as_polyfloat_like_t<T0, T1>, plf::as_polyfloat_like_t<T0, T1>> constexpr
    operator()(T0 t0, T1 t1) const noexcept
    {
      return POLYFLOAT_CALL(t0, t1);
    }

    POLYFLOAT_CALLABLE_OBJECT(dekker_prod_t, dekker_prod_);
  };
  //================================================================================================
  //! @addtogroup core_accuracy
  //! @{
  //!   @var dekker_prod
  //!   @brief Computes the pair of the rounded product of two values and its rounding error, without an fma.
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
  //!      constexpr auto dekker_prod( auto x, auto y)            noexcept; // 1
  //!      // Semantic options
  //!      constexpr auto dekker_prod[pedantic](auto x, auto y)   noexcept; // 2
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `x`, `y`: two values of `float` or `double`, or their registers, converted to their common type.
  //!
  //!   **Return value**
  //!
  //!     A pair \f$(a, e)\f$ where \f$a = \mathrm{RN}(x y)\f$, and \f$e\f$ is computed from the splittings of `x`
  //!     and `y` by plf::two_split. In rounding to nearest, \f$a + e = x y\f$ exactly when neither the
  //!     product nor the splittings overflow, which excludes `x` and `y` close to the largest finite value,
  //!     and \f$e_x + e_y \ge e_{\min} + p - 1\f$. The error is zero when the product is not finite. The option
  //!     `pedantic` does not change the result.
  //!
  //!  @groupheader{External references}
  //!   *  [T. J. Dekker, A floating-point technique for extending the available precision](https://doi.org/10.1007/BF01397083)
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
    template<typename T0, typename T1, eve::callable_options O>
    constexpr auto dekker_prod_(POLYFLOAT_DELAY(), O const&, T0 aa, T1 bb) noexcept
    {
      using r_t = plf::as_polyfloat_like_t<T0, T1>;
      auto cvt = [](auto a) { return plf::convert(a, eve::as_element<r_t>{}); };
      auto a = cvt(aa);
      auto b = cvt(bb);
      auto [ah, al] = two_split(a);
      auto [bh, bl] = two_split(b);
      auto abh = a * b;
      auto abl = ah * bh - abh;
      abl += ah * bl;
      abl += al * bh;
      abl += al * bl;
      if constexpr (eve::platform::supports_invalids) abl = plf::if_else(plf::is_not_finite(abh), eve::zero, abl);
      return eve::zip(abh, abl);
    }
  }
}
