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
namespace plf
{

  template<typename Options> struct two_split_t : eve::callable<two_split_t, Options>
  {
//     template<auto N, concepts::polyfloat_like T>
//     POLYFLOAT_FORCEINLINE typename kumi::tuple<T, T> constexpr operator()(T t, std::integral_constant<int, N> s) const noexcept
//     {
//       return POLYFLOAT_CALL(t, s);
//     }

    template<concepts::polyfloat_like T>
    POLYFLOAT_FORCEINLINE typename kumi::tuple<T, T> constexpr operator()(T t) const noexcept
    {
      return POLYFLOAT_CALL(t);
    }

    POLYFLOAT_CALLABLE_OBJECT(two_split_t, two_split_);
  };
//================================================================================================
//! @splittogroup core_accuracy
//! @{
//!   @var two_split
//!   @brief Computes the Veltkamp's splitting algorithm
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
//!      template <auto N> constexpr auto two_split(auto x, std::integral_constant<N> s)  noexcept; // 1
//!      constexpr auto two_split( auto x)                                               noexcept; // 2
//!   }
//!   @endcode
//!
//!   **Parameters**
//!
//!     * `x`:  polyfloat argument](@ref eve::floating_value) of same dimension.
//!
//!
//!   **Return value**
//!
//!     1.  Returns a pair \f$(x_h, x_l)\f$ such that the significand of \f$x_h\f$ fits in p − s bits,
//!      the significand of \f$x_l\f$  fits in s−1 bits, and \f$x_h \oplus x_l = x\f$.
//!      p is the number of mantissa bits of x,  With 2 ≤ s ≤ p − 2
//!     2. s is taken as \f$\lceil p/2 \rceil\f$
//!
//!
//!  @groupheader{External references}
//!   *  [On the Computation of Correctly-Rounded Sums](https://www.vinc17.net/research/papers/rr_ccrsums2.pdf)
//!
//!  @groupheader{Example}
//!  @godbolt{doc/core/core/two_split.cpp}
//================================================================================================
  inline constexpr auto two_split = eve::functor<two_split_t>;
//================================================================================================
//! @}
//================================================================================================

  namespace _
  {
    template<auto N, typename T, eve::callable_options O>
    constexpr POLYFLOAT_FORCEINLINE auto two_split_(POLYFLOAT_DELAY(), O const&, T x, std::integral_constant<int, N> )
    {
      auto K = ldexp(T(1), N);
      auto g = K*x;
      auto d =  x-g;
      auto xh = g+d;
      return eve::zip(xh, x-xh);
    }

    template<typename T, eve::callable_options O>
    constexpr POLYFLOAT_FORCEINLINE auto two_split_(POLYFLOAT_DELAY(), O const&, T x)
    {
      using u_t = eve::underlying_type_t<T>;
      auto N = (plf::nbmantissabits(eve::as<u_t>())+1)/2;
      auto K = ldexp(T(1), N);
      auto g = K*x;
      auto d =  x-g;
      auto xh = g+d;
      return eve::zip(xh, x-xh);
    }
  }
}
