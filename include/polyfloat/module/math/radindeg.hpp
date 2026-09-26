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
  struct radindeg_t : eve::elementwise_callable<radindeg_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(radindeg_t, radindeg_);
  };
  //======================================================================================================================
  //! @addtogroup math
  //! @{
  //!   @var radindeg
  //! @brief `elementwise_callable` object multiplying the input by \f$180/\pi\f$.
  //!
  //!   @groupheader{Header file}
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
  //!      constexpr auto radindeg(auto x)                          noexcept; // 1
  //!
  //!      // Lanes masking
  //!      constexpr auto radindeg[conditional_expr auto c](auto x) noexcept; // 2
  //!      constexpr auto radindeg[logical_value auto m](auto x)    noexcept; // 2
  //!   }
  //!   @endcode
  //!
  //! **Parameters**
  //!
  //!    * `x`: [floating value](@ref eve::floating_value).
  //!    * `c`: [Conditional expression](@ref eve::conditional_expr) masking the operation.
  //!    * `m`: [Logical value](@ref eve::logical_value) masking the operation.
  //!
  //! **Return value**
  //!
  //!    1. Returns the radian input converted in degree.
  //!    2. [The operation is performed conditionally](@ref conditional).
  //!
  //!  @groupheader{Example}
  //!  @godbolt{doc/math/radindeg.cpp}
  //================================================================================================
  inline constexpr auto radindeg = eve::functor<radindeg_t>;
  //================================================================================================
  //!  @}
  //================================================================================================
}

namespace plf::_
{

  template<typename T, eve::callable_options O> constexpr auto radindeg_(POLYFLOAT_DELAY(), O const&, T a) noexcept
  {
    if constexpr (dimension_v<T> == 1) return eve::radindeg(a);
    else
    {
      auto [r2dh, r2dl] = plf::two_split(plf::rad2deg(eve::as<T>()));
      return plf::fma(a, r2dh, a * r2dl);
    }
  }
}
