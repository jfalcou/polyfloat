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

  template<typename Options> struct exponent_t : eve::callable<exponent_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_FORCEINLINE  eve::as_integer_t<as_component_type_t<Z>, signed> operator()(Z z) const noexcept
    {
     return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(exponent_t, exponent_);
  };

//================================================================================================
//! @addtogroup core_internal
//! @{
//!   @var exponent
//!   @brief `elementwise_callable` object computing the integral IEEE exponent of the floating value.
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
//!      constexpr auto exponent(floating_value auto x)       noexcept; // 1
//!
//!      // Semantic options
//!      constexpr auto exponent[raw](floating_value auto x)  noexcept; // 2
//!   }
//!   @endcode
//!
//!   **Parameters**
//!
//!     * `x` :  [argument](@ref eve::floating_value).
//!
//!    **Return value**
//!
//!      1. The value of the IEEE exponent is returned. In particular:
//!        *  `inf`,  `minf` and `nan` return `maxexponent` plus 1
//!        *  zero returns zero
//!      2 identical except that results for zero, nan and infinite  inputs are unspecified
//!
//! @note  The exponent \f$e\f$ and mantissa \f$m\f$ of a floating point entry \f$x\f$ are related by
//!       \f$x =  m\times 2^e\f$, with  \f$|m| \in \{0\} \cup [1, 2[\f$.
//!
//!  @groupheader{Example}
//!  @godbolt{doc/exponent.cpp}
//================================================================================================
  inline constexpr auto exponent = eve::functor<exponent_t>;
//================================================================================================
//! @}
//================================================================================================

  namespace _
  {
    template<typename Z, eve::callable_options O>
    POLYFLOAT_FORCEINLINE constexpr auto exponent_(POLYFLOAT_DELAY(), O const& o, Z const& z) noexcept
    {
      return eve::exponent(hi(z));
    }
  }
}
