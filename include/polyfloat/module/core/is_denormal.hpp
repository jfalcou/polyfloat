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

  template<typename Options> struct is_denormal_t : eve::elementwise_callable<is_denormal_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_FORCEINLINE constexpr eve::as_logical_t<plf::as_component_type_t<Z>> operator()(Z z) const noexcept
    {
     return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(is_denormal_t, is_denormal_);
  };

//================================================================================================
//! @addtogroup core
//! @{
//!   @var is_denormal
//!   @brief `elementwise callable` returning a logical true  if and only if the element value is a denormal floating value
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
//!      constexpr auto is_denormal(floating_value auto x)                 noexcept;
//!   }
//!   @endcode
//!
//!   **Parameters**
//!
//!     * `x`: [argument](@ref eve::value).
//!
//!   **Return value**
//!
//!     returns true if and only if x is a denormal number
//!
//!  @groupheader{Example}
//!  @godbolt{doc/core/is_denormal.cpp}
//================================================================================================
  inline constexpr auto is_denormal = eve::functor<is_denormal_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto is_denormal_(POLYFLOAT_DELAY(), O const& , Z const& z) noexcept
  {
    return eve::is_denormal(hi(z));
  }
}
