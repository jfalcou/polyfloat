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
#include <polyfloat/module/core/is_flint.hpp>

namespace plf
{

  template<typename Options> struct is_odd_t : eve::elementwise_callable<is_odd_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_FORCEINLINE constexpr eve::as_logical_t<plf::as_component_type_t<Z>> operator()(Z z) const noexcept
    {
     return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(is_odd_t, is_odd_);
  };

//================================================================================================
//! @addtogroup core
//! @{
//!   @var is_odd
//!   @brief `elementwise callable`returns a logical true  if and only if the element value is a floating value
//!   representing an odd integer
//!
//!   @groupheader{Header file}
//!
//!   @code
//!   #include <eve/module/module/core.hpp>
//!   @endcode
//!
//!   @groupheader{Callable Signatures}
//!
//!   @code
//!   namespace plf
//!   {
//!      // Regular overloads
//!      constexpr auto is_odd(floating_value auto x)                 noexcept;
//!   }
//!   @endcode
//!
//!   **Parameters**
//!
//!     * `x`: [argument](@ref eve::value).
//!
//!   **Return value**
//!
//!     1. returns true if and only if x represent an odd number
//!
//!  @groupheader{Example}
//!  @godbolt{doc/core/is_odd.cpp}
//================================================================================================
  inline constexpr auto is_odd = eve::functor<is_odd_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto is_odd_(POLYFLOAT_DELAY(), O const& , Z const& a) noexcept
  {
    auto da = dec(a);
    return (a != da) && is_even(da);
  }
}
