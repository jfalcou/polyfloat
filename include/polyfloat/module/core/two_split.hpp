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
#include <polyfloat/module/core/constants/nbmantissabits.hpp>
#include <polyfloat/module/core/ldexp.hpp>
namespace plf
{

  template<typename Options> struct two_split_t : eve::callable<two_split_t, Options>
  {
    template<auto N, concepts::polyfloat_like T>
    POLYFLOAT_ABI eve::zipped<T, T> constexpr operator()(T t, std::integral_constant<int, N> s) const noexcept
    {
      return POLYFLOAT_CALL(t, s);
    }

    template<concepts::polyfloat_like T> POLYFLOAT_ABI eve::zipped<T, T> constexpr operator()(T t) const noexcept
    {
      return POLYFLOAT_CALL(t);
    }

    POLYFLOAT_CALLABLE_OBJECT(two_split_t, two_split_);
  };
  //================================================================================================
  //! @addtogroup core_accuracy
  //! @{
  //!   @var two_split
  //!   @brief Computes the pair of the high and low parts of a value, by splitting its significand.
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
  //!      template<int N> constexpr auto two_split(auto x, std::integral_constant<int, N> s)  noexcept; // 1
  //!      constexpr auto two_split( auto x)                                               noexcept; // 2
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `x`: a value of type `float` or `double`, or a register of them.
  //!     * `s`: the split point, a number of bits.
  //!
  //!   **Return value**
  //!
  //!     1. A pair \f$(x_h, x_l)\f$ where \f$x_h = g + (x - g)\f$, with \f$g = 2^s x\f$, both operations rounded
  //!        in the base type, and \f$x_l = x - x_h\f$.
  //!     2. The same with \f$s = \lfloor (m + 1)/2 \rfloor\f$, \f$m\f$ being the number of stored mantissa bits,
  //!        26 for `double` and 12 for `float`.
  //!
  //!  @groupheader{External references}
  //!   *  [T. J. Dekker, A floating-point technique for extending the available precision](https://doi.org/10.1007/BF01397083)
  //!   *  [J.-M. Muller et al., Handbook of Floating-Point Arithmetic, 2nd edition](https://doi.org/10.1007/978-3-319-76526-6)
  //!
  //!  @groupheader{Example}
  //!  @godbolt{doc/core/two_split.cpp}
  //================================================================================================
  inline constexpr auto two_split = eve::functor<two_split_t>;
  //================================================================================================
  //! @}
  //================================================================================================

  namespace _
  {
    template<auto N, typename T, eve::callable_options O>
    constexpr auto two_split_(POLYFLOAT_DELAY(), O const&, T x, std::integral_constant<int, N>)
    {
      auto K = plf::ldexp(T(1), N);
      auto g = K * x;
      auto d = x - g;
      auto xh = g + d;
      return eve::zip(xh, x - xh);
    }

    template<typename T, eve::callable_options O> constexpr auto two_split_(POLYFLOAT_DELAY(), O const&, T x)
    {
      using u_t = eve::underlying_type_t<T>;
      auto N = (plf::nbmantissabits(eve::as<u_t>()) + 1) / 2;
      auto K = plf::ldexp(T(1), N);
      auto g = K * x;
      auto d = x - g;
      auto xh = g + d;
      return eve::zip(xh, x - xh);
    }
  }
}
