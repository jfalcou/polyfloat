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

  template<typename Options> struct mul_pi_t : eve::elementwise_callable<mul_pi_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_ABI constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(mul_pi_t, mul_pi_);
  };
  //======================================================================================================================
  //! @addtogroup math
  //! @{
  //! @var mul_pi
  //!
  //! @brief `elementwise_callable` object computing accurately the product of the input by \f$\pi\f$.
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
  //!      constexpr auto mul_pi(auto x)                                   noexcept; // 1
  //!
  //!      // Lanes masking
  //!      constexpr auto mul_pi[conditional_expr auto c](auto x)          noexcept; // 2
  //!      constexpr auto mul_pi[logical_floating_value auto m](auto x)    noexcept; // 2
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
  //!  @godbolt{doc/math/mul_pi.cpp}
  //================================================================================================
  inline constexpr auto mul_pi = eve::functor<mul_pi_t>;
  //================================================================================================
  //!  @}
  //================================================================================================
}

namespace plf::_
{

  template<typename T, eve::callable_options O> constexpr auto mul_pi_(POLYFLOAT_DELAY(), O const&, T a) noexcept
  {
    auto [dh, dl] = plf::two_split(plf::pi(eve::as<T>()));
    return plf::fma[plf::is_nez(a)](a, dh, a * dl);
  }
}
