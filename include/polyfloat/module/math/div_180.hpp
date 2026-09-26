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

  template<typename Options>
  struct div_180_t : eve::elementwise_callable<div_180_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(div_180_t, div_180_);
  };
  //======================================================================================================================
  //! @addtogroup math
  //! @{
  //! @var div_180
  //!
  //! @brief `elementwise_callable` object computing the product of the input by \f$1/180\f$.
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   #include <eve/module/math.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace eve
  //!   {
  //!      // Regular overload
  //!      constexpr auto div_180(auto x)                                   noexcept; // 1
  //!
  //!      // Lanes masking
  //!      constexpr auto div_180[conditional_expr auto c](auto x)          noexcept; // 2
  //!      constexpr auto div_180[logical_floating_value auto m](auto x)    noexcept; // 2
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!    * `x`: [floating_value](@ref eve::value).
  //!    * `c`: [Conditional expression](@ref eve::conditional_expr) masking the operation.
  //!    * `m`: [Logical value](@ref eve::logical_value) masking the operation.
  //!
  //!   **Return value**
  //!
  //!     1. Returns the [elementwise](@ref glossary_elementwise) the  input divided by 180.
  //!     2. [The operation is performed conditionally](@ref conditional).
  //!
  //!  @groupheader{Example}
  //!  @godbolt{doc/math/div_180.cpp}
  //================================================================================================
  inline constexpr auto div_180 = eve::functor<div_180_t>;
  //================================================================================================
  //!  @}
  //================================================================================================
}

namespace plf::_
{

  template<typename T, eve::callable_options O> constexpr auto div_180_(POLYFLOAT_DELAY(), O const&, T a) noexcept
  {
    if constexpr (dimension_v<T> == 1) return eve::div_180(a);
    else
    {
      auto [dh, dl] = plf::two_split(plf::oneo_180(eve::as<T>()));
      return plf::fma(a, dh, a * dl);
    }
  }
}
