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

  template<typename Options> struct frexp_t : eve::callable<frexp_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_FORCEINLINE auto operator()(Z z) const noexcept ->  kumi::tuple<Z, as_component_type_t<Z>> //decltype(plf::hi(Z()))>
    {
     return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(frexp_t, frexp_);
  };
//================================================================================================
//! @addtogroup core_internal
//! @{
//!   @var frexp
//!   @brief `elementwise_callable` computing the ieee  pair of mantissa and exponent of a polyfloat value,
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
//!      constexpr auto frexp(floating_value auto x)                          noexcept; // 1
//!
//!      // Lanes masking
//!      constexpr auto frexp[conditional_expr auto c](floating_value auto x) noexcept; // 2
//!      constexpr auto frexp[logical_value auto m](floating_value auto x)    noexcept; // 2
//!
//!      // Semantic options
//!      constexpr auto frexp[pedantic](floating_value x)                     noexcept; // 3
//!   }
//!   @endcode
//!
//!   **Parameters**
//!
//!     * `x`: [value](@ref eve::value).
//!     * `c`: [Conditional expression](@ref eve::conditional_expr) masking the operation.
//!     * `m`: [Logical value](@ref eve::logical_value) masking the operation.
//!
//!   **Return value**
//!
//!     1. returns a kumi::tuple `{m,e}`  of values ` of the same type as `x`, which are related by
//!       \f$x =  m\times 2^e\f$, with  \f$|m| \in [0.5, 1.5[\f$.
//!       However, the cases \f$x = \pm\infty\f$ or is a Nan or a denormal are undefined.
//!     2. [The operation is performed conditionnaly](@ref conditional).
//!     3. this option takes also properly care of the cases where
//!        \f$x = \pm0, \pm\infty\f$ or is a Nan, where \f$m=x\f$ and \f$e=0\f$ and of the
//!        denormal cases.
//!
//!  @groupheader{External references}
//!    *  [C++ standard reference](https://en.cppreference.com/w/cpp/numeric/math/frexp)
//!
//!  @groupheader{Example}
//!  @godbolt{doc/core/frexp.cpp}
//================================================================================================
  inline constexpr auto frexp = eve::functor<frexp_t>;
//================================================================================================
//! @}
//================================================================================================

  namespace _
  {
    template<typename Z, eve::callable_options O>
    POLYFLOAT_FORCEINLINE constexpr auto frexp_(POLYFLOAT_DELAY(), O const& o, Z const& z) noexcept
    {
      if constexpr(dimension_v<Z> == 1)
        return eve::frexp(z);
      else
      {
        auto [h, n] = eve::frexp[o](hi(z));
        if constexpr(dimension_v<Z> == 2)
        {
          auto l = eve::ldexp[o](lo(z), -n);
          return kumi::tuple{Z(h, l), n};
        }
        else if constexpr(dimension_v<Z> == 3)
        {
          auto l = eve::ldexp[o](lo(z), -n);
          auto m = eve::ldexp[o](md(z), -n);
          return kumi::tuple{Z(h, m, l), n};
        }
      }
    }
  }
}
