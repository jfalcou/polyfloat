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

namespace plf
{

  template<typename Options> struct ldexp_t : eve::callable<ldexp_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z1,  eve::integral_value N>
      POLYFLOAT_FORCEINLINE constexpr Z1 operator()(Z1 z1, N n) const noexcept
    {
      using r_t = eve::element_type_t<decltype(hi(Z1()))>;
      return POLYFLOAT_CALL(z1, plf::convert(n, eve::as<r_t>()));
    }

    template<concepts::polyfloat_like Z,  eve::floating_value N>
      POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z, N n) const noexcept
    {
      using r_t = eve::element_type_t<as_component_type_t<Z>>;
      return POLYFLOAT_CALL(z, plf::convert(n, eve::as<r_t>()));
    }

    POLYFLOAT_CALLABLE_OBJECT(ldexp_t, ldexp_);
  };

//======================================================================================================================
//! @addtogroup functions
//! @{
//!   @var ldexp
//!   @brief `strict_elementwise callable` computing \f$\textstyle x 2^n\f$.
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
//!      constexpr auto ldexp(floating_value auto x, integral_value N)                           noexcept; // 1
//!
//!      // Lanes masking
//!      constexpr auto ldexp[conditional_expr auto c](floating_value auto x), integral_value N) noexcept; // 2
//!      constexpr auto ldexp[logical_value auto m](floating_value auto x, integral_value N)     noexcept; // 2
//!
//!      // Semantic options
//!      constexpr auto ldexp[pedantic](floating_value auto x, integral_value N)                   noexcept; // 3
//!   }
//!   @endcode
//!
//!   **Parameters**
//!
//!     * `x`: [value](@ref eve::value).
//!     * `c`: [Conditional expression](@ref eve::conditional_expr) masking the operation.
//!     * `n`: [integral value argument](@ref eve::integral_value).
//!     * `m`: [Logical value](@ref eve::logical_value) masking the operation.
//!
//!    **Return value**
//!
//!     1. The value of \f$\textstyle x 2^n\f$ is returned.
//!     2. [The operation is performed conditionnaly](@ref conditional).
//!     3. Takes extra care to handling limit values.
//!         * If `x` is \f$\pm0\f$, it is returned, unmodified.
//!         * If `x` is \f$\pm\infty\f$, it is returned, unmodified.
//!         * If `n` is 0, then `x` is returned, unmodified.
//!         * If `x` is NaN, NaN is returned.
//!
//!  @groupheader{External references}
//!   *  [C++ standard reference](https://en.cppreference.com/w/cpp/numeric/math/ldexp)
//!
//!  @groupheader{Example}
//!  @godbolt{doc/ldexp.cpp}
//================================================================================================
  inline constexpr auto ldexp = eve::functor<ldexp_t>;
//================================================================================================
//! @}
//================================================================================================
}

namespace plf::_
{
  template<typename Z, typename N, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto ldexp_(POLYFLOAT_DELAY(), O const& , Z const& z, N const & n) noexcept
  {
    if constexpr(dimension_v<Z> ==  1)
      return eve::ldexp(z, n);
    else if constexpr(dimension_v<Z> ==  2)
    {
      auto [zh, zl] = z;
      auto h = eve::ldexp(zh, n);
      auto l = eve::ldexp(zl, n);
      return Z(h, l);
    }
    else    if constexpr(dimension_v<Z> ==  3)
    {
      auto [zh, zm, zl] = z;
      auto h = eve::ldexp(zh, n);
      auto m = eve::ldexp(zm, n);
      auto l = eve::ldexp(zl, n);
      Z z(h);
      md(z) = m; lo(z) = l;
      return z;
//      return Z(h, m, l);
    }
  }

};
