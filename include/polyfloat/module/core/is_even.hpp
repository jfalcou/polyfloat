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
#include <polyfloat/module/core/ldexp.hpp>

namespace plf
{

  template<typename Options> struct is_even_t : eve::elementwise_callable<is_even_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_FORCEINLINE constexpr eve::as_logical_t<plf::as_component_type_t<Z>> operator()(Z z) const noexcept
    {
     return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(is_even_t, is_even_);
  };

//================================================================================================
//! @addtogroup core
//! @{
//!   @var is_even
//!   @brief returns a logical true  if and only if the element value is a floating value
//!   representing an even integer
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
//!      constexpr auto is_even(floating_value auto x)                 noexcept;
//!   }
//!   @endcode
//!
//!   **Parameters**
//!
//!     * `x`: [argument](@ref eve::value).
//!
//!   **Return value**
//!
//!     1. returns true if and only if x represent an even number
//!
//!  @groupheader{Example}
//!  @godbolt{doc/core/is_even.cpp}
//================================================================================================
  inline constexpr auto is_even = eve::functor<is_even_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto is_even_(POLYFLOAT_DELAY(), O const& , Z const& z) noexcept
  {
    auto t = is_flint(z);
    if constexpr(dimension_v<Z> == 1)
    {
      return eve::is_even(z);
    }
    else
    {

      auto t = is_flint(z);
      return t && is_flint(ldexp(z, -1));
    }
  }
}
