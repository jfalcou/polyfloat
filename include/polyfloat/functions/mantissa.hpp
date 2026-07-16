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

  template<typename Options> struct mantissa_t : eve::callable<mantissa_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_FORCEINLINE Z operator()(Z z) const noexcept
    {
     return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(mantissa_t, mantissa_);
  };
//================================================================================================
//! @addtogroup functions
//! @{
//!   @var mantissa
//!   @brief  `elementwise_callable` object computing the IEEE mantissa of the floating value.
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
//!      constexpr auto mantissa(floating_value auto x)                          noexcept; // 1
//!
//!      // Lanes masking
//!      constexpr auto mantissa[conditional_expr auto c](floating_value auto x) noexcept; // 2
//!      constexpr auto mantissa[logical_value auto m](floating_value auto x)    noexcept; // 2
//!
//!      // Semantic options
//!      constexpr auto mantissa[raw](floating_value auto x)                     noexcept; // 3
//!   }
//!   @endcode
//!
//!   **Parameters**
//!
//!     * `x`: [real argument](@ref eve::value).
//!     * `c`: [Conditional expression](@ref eve::conditional_expr) masking the operation.
//!     * `m`: [Logical value](@ref eve::logical_value) masking the operation.
//!
//!    **Return value**
//!
//!      1. The value of the IEEE mantissa is returned. In particular:
//!        *  `nan` returns nan
//!        *  \f$\pm\infty\f$ returns \f$\pm\1\f$.
//!        *  zero returns zero
//!      2. [The operation is performed conditionnaly](@ref conditional).
//!      3. The results for zero and nan are unspecified.
//!
//!
//! @note The `exponent` \f$e\f$ and `mantissa` \f$m\f$ of a floating point entry \f$x\f$
//!       are related by \f$x =  m\times 2^e\f$, with  \f$|m| \in \{0, nan\} \cup [1, 2[\f$.
//!
//!  @groupheader{Example}
//!  @godbolt{doc/core/mantissa.cpp}
//================================================================================================
  inline constexpr auto mantissa = eve::functor<mantissa_t>;
//================================================================================================
//! @}
//================================================================================================

  namespace _
  {
    template<typename Z, eve::callable_options O>
    POLYFLOAT_FORCEINLINE constexpr auto mantissa_(POLYFLOAT_DELAY(), O const& o, Z const& z) noexcept
    {
      if constexpr(dimension_v<Z> == 1)
        return eve::mantissa(z);
      else
      {
        auto n =  exponent(z);
        auto h = eve::ldexp[o](hi(z), -n);
        if constexpr(dimension_v<Z> == 2)
        {
          auto l = eve::ldexp[o](lo(z), -n);
          return Z(h, l);
        }
        else if constexpr(dimension_v<Z> == 3)
        {
          auto m = eve::ldexp[o](md(z), -n);
          auto l = eve::ldexp[o](lo(z), -n);
          return Z(h, m, l);
        }
      }
    }
  }
}
