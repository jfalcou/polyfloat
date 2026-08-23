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
#include <eve/module/core/regular/if_else.hpp>

namespace plf
{

  template<typename Options> struct clamp_t : eve::strict_tuple_callable<clamp_t, Options, raw_option, pedantic_option>
  {
    template<typename... Ts> struct result : as_polyfloat_like<Ts...>
    {
    };

    template<concepts::polyfloat_like Z0, concepts::polyfloat_like Z1, concepts::polyfloat_like Z2>
    EVE_FORCEINLINE typename result<Z0, Z1, Z2>::type constexpr operator()(Z0 z0, Z1 z1, Z2 z2) const noexcept
    {
      return POLYFLOAT_CALL(z0, z1, z2);
    }

     POLYFLOAT_CALLABLE_OBJECT(clamp_t, clamp_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var clamp
  //!   @brief clamp the value between two bounds.
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <polyfloat/core.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace polyfloat
  //!   {
  //!      constexpr auto clamp(value auto x, value auto lo,  value auto hi)  noexcept; // 1
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `x`: value to clamp.
  //!     * `lo`, `hi`: [the boundary values](@ref eve::value) of the interval.
  //!
  //!    **Return value**
  //!        1. Each [element](@ref glossary_elementwise)  of the result contains:
  //!           *  `lo`, if `x` is less than `lo`.
  //!           *  `hi`, if `hi` is less than `x`.
  //!           *  otherwise `x`.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/clamp.cpp}
  //======================================================================================================================

  inline constexpr auto clamp = eve::functor<clamp_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename T0, typename T1,  typename T2, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto clamp_(POLYFLOAT_DELAY(), O const & c, T0 a, T1 l, T2 h) noexcept
  {
    return plf::min(plf::max(a, l), h);
  }
}
