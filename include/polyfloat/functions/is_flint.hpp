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

  template<typename Options> struct is_flint_t : eve::elementwise_callable<is_flint_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_FORCEINLINE constexpr eve::as_logical_t<plf::as_component_type_t<Z>> operator()(Z z) const noexcept
    {
     return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(is_flint_t, is_flint_);
  };

//================================================================================================
//! @addtogroup functions
//! @{
//!   @var is_flint
//!   @brief `elementwise callable` returning a logical true  if and only if the element value is a floating value
//!   representing an integer
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
//!      // Regular overloads
//!      constexpr auto is_flint(floating_value auto x)                 noexcept; // 1
//!      constexpr auto is_flint(integer_value auto x)                  noexcept; // 2
//!
//!      // Lanes masking
//!      constexpr auto is_flint[conditional_expr auto c](value auto x) noexcept; // 3
//!      constexpr auto is_flint[logical_value auto m](value auto x)    noexcept; // 3
//!
//!      // Semantic options
//!      constexpr auto is_flint[pedantic](floating_value auto x)       noexcept; // 4
//!   }
//!   @endcode
//!
//!   **Parameters**
//!
//!     * `x`: [argument](@ref eve::value).
//!     * `c`: [Conditional expression](@ref eve::conditional_expr) masking the operation.
//!     * `m`: [Logical value](@ref eve::logical_value) masking the operation.
//!
//!   **Return value**
//!
//!     1. The call `is_flint(x)` is semantically  equivalent to `is_flint (eve::frac(x))`;
//!        This means that x represents an integral value.
//!     2. Always returns `true`
//!     3. [The operation is performed conditionnaly](@ref conditional).
//!     4. The call `is_flint[pedantic](x)` also check that the input is not greater or equal to the
//!        largest consecutive integer in the element type of `x` (`maxflint(as(x))`).
//!
//!  @groupheader{Example}
//!  @godbolt{doc/is_flint.cpp}
//================================================================================================
  inline constexpr auto is_flint = eve::functor<is_flint_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto is_flint_(POLYFLOAT_DELAY(), O const& , Z const& z) noexcept
  {
    if constexpr(dimension_v<Z> == 1)
      return eve::is_flint(z);
    else if constexpr(dimension_v<Z> == 2)
      return eve::is_flint(lo(z)) && eve::is_flint(hi(z));
    else if  constexpr(dimension_v<Z> == 3)
      return eve::is_flint(lo(z)) && eve::is_flint(md(z)) && ( eve::is_flint(hi(z)));
    }
}
