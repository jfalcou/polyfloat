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

  template<typename Options> struct prev_t : eve::elementwise_callable<prev_t, Options, raw_option, pedantic_option>
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
      EVE_ASSERT(eve::all(n >= 0), "[plf::prev] : second parameter must be positive");
      return POLYFLOAT_CALL(z, n);
    }

    POLYFLOAT_CALLABLE_OBJECT(prev_t, prev_);
  };
  //======================================================================================================================
  //! @addtogroup functions
  //! @{
  //!   @var prev
  //!   @brief return the previous representable value.
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
  //!      constexpr auto prev(value auto x)                            noexcept; // 1
  //!      constexpr auto prev(value auto x, integral_value auto n)     noexcept; // 2
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
  //!     Returns the previous nth representable value.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/prev.cpp}
  //======================================================================================================================

  inline constexpr auto prev = eve::functor<prev_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto prev_(POLYFLOAT_DELAY(), O const& , Z const& z) noexcept
  {
    using c_t = plf::as_component_type_t<Z>;
    if constexpr(dimension_v<Z> == 1)
      return eve::prev(z);
    else if constexpr(dimension_v<Z> == 2)
    {
      auto [h, l] = z;
      return plf::_::from_pair<c_t>(h, eve::prev(l));
    }
    else if constexpr(dimension_v<Z> == 3)
    {
      auto [h, m, l] = z;
      return plf::_::from_triple<c_t>(h, m, eve::prev(l));
    }
  }

  template<typename Z, typename N, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto prev_(POLYFLOAT_DELAY(), O const& , Z const& z,  N n) noexcept
  {
    using c_t = plf::as_component_type_t<Z>;
    if constexpr(dimension_v<Z> == 1)
      return eve::prev(z, n);
    else if constexpr(dimension_v<Z> == 2)
    {
      auto [h, l] = z;
      return  plf::_::from_pair<c_t>(h, eve::prev(l, n));
    }
    else if constexpr(dimension_v<Z> == 3)
    {
      auto [h, m, l] = z;
      return  plf::_::from_triple<c_t>(h, m, eve::prev(l, n));
    }
  }
}
