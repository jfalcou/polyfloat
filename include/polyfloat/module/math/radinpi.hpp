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
  struct radinpi_t : eve::elementwise_callable<radinpi_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(radinpi_t, radinpi_);
  };

  //================================================================================================
  //! @addtogroup math
  //! @{
  //! @var radinpi
  //!
  //! @brief `elementwise_callable` object multiplying the input by \f$1/\pi\f$.
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
  //!      constexpr auto radinpi( auto x)                          noexcept; // 1
  //!
  //!      // Lanes masking
  //!      constexpr auto radinpi[conditional_expr auto c]( auto x) noexcept; // 2
  //!      constexpr auto radinpi[logical_value auto m]( auto x)    noexcept; // 2
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
  //!    1. Returns the radian input converted in \f$\pi\f$ multiples.
  //!    2. [The operation is performed conditionally](@ref conditional).
  //!
  //!  @groupheader{Example}
  //!  @godbolt{doc/math/radinpi.cpp}
  //================================================================================================
  inline constexpr auto radinpi = eve::functor<radinpi_t>;
  //================================================================================================
  //!  @}
  //================================================================================================
}

namespace plf::_
{

  template<typename T, eve::callable_options O>
  EVE_FORCEINLINE constexpr T radinpi_(POLYFLOAT_DELAY(), O const&, T const& a) noexcept
  {
    if constexpr (dimension_v<T> == 1) return eve::radinpi(a);
    else
    {
      auto [r2ph, r2pl] = plf::two_split(plf::inv_pi(eve::as<T>()));
      return plf::fma(a, r2ph, a * r2pl);
    }
  }
}
