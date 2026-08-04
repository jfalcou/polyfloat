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

  template<typename Options> struct next_t : eve::elementwise_callable<next_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    template<concepts::polyfloat_like Z, eve::integral_value N>
    POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z,  N n) const noexcept
    requires(eve::same_lanes_or_scalar<Z, N>)
    {
      EVE_ASSERT(eve::all(n >= 0), "[plf::next] : second parameter must be positive");
      return POLYFLOAT_CALL(z, n);
    }

    POLYFLOAT_CALLABLE_OBJECT(next_t, next_);
  };
  //======================================================================================================================
  //! @addtogroup functions
  //! @{
  //!   @var next
  //!   @brief return the next representable value.
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <polyfloat/functions.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace polyfloat
  //!   {
  //!      constexpr auto next(value auto x)                            noexcept; // 1
  //!      constexpr auto next(value auto x, integral_value auto n)     noexcept; // 2
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!     * `n`: increment
  //!
  //!   **Return value**
  //!
  //!     Returns the next nth representable value.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/next.cpp}
  //======================================================================================================================

  inline constexpr auto next = eve::functor<next_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto next_(POLYFLOAT_DELAY(), O const& , Z const& z) noexcept
  {
    if constexpr(dimension_v<Z> == 1)
      return eve::next(z);
    else if constexpr(dimension_v<Z> == 2)
    {
      auto [h, l] = z;
      return eve::zip(h, eve::next(l));
    }
    else if constexpr(dimension_v<Z> == 3)
    {
      auto [h, m, l] = z;
      return eve::zip(h, m, eve::next(l));
    }
  }

  template<typename Z, typename N, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto next_(POLYFLOAT_DELAY(), O const& , Z const& z,  N n) noexcept
  {
    if constexpr(dimension_v<Z> == 1)
      return eve::next(z, n);
    else if constexpr(dimension_v<Z> == 2)
    {
      auto [h, l] = z;
      return Z(h, eve::next(l, n));
    }
    else if constexpr(dimension_v<Z> == 3)
    {
      auto [h, m, l] = z;
      return Z(h, m, eve::next(l, n));
    }
  }
}
