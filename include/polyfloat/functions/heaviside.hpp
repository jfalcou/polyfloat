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
#include <polyfloat/functions/if_else.hpp>
#include <polyfloat/functions/is_gtz.hpp>

namespace plf
{

  template<typename Options> struct heaviside_t : eve::strict_elementwise_callable<heaviside_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    {
     return POLYFLOAT_CALL(z);
    }
    template<concepts::polyfloat_like Z1, concepts::polyfloat_like Z2>
    POLYFLOAT_FORCEINLINE constexpr as_polyfloat_t<Z1, Z2> operator()(Z1 z1, Z2 z2) const noexcept
    {
     return POLYFLOAT_CALL(z1, z2);
    }

    POLYFLOAT_CALLABLE_OBJECT(heaviside_t, heaviside_);
  };
  //======================================================================================================================
  //! @addtogroup functions
  //! @{
  //!   @var heaviside
  //!   @brief return the heavisideolute value.
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <kyosu/functions.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace kyosu
  //!   {
  //!      // Regular overload
  //!      constexpr auto heaviside(value auto x)                                            noexcept; // 1
  //!      constexpr auto heaviside(value auto x, auto s)                                    noexcept; // 2
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!     * `s`: shift.
  //!
  //!    **Return value**
  //!        1. Each [element](@ref glossary_elementwise)  of the result contains:
  //!           * `0`, if `x` is less or equal to zero.
  //!           * `1` otherwise.
  //!        2. Each [element](@ref glossary_elementwise)  of the result contains:
  //!           * `0`, if `x` is less or equal to `s` (default to zero).
  //!           * `1` otherwise.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/heaviside.cpp}
  //======================================================================================================================

  inline constexpr auto heaviside = eve::functor<heaviside_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto heaviside_(POLYFLOAT_DELAY(), O const& , Z const& a) noexcept
  {
    return Z(eve::heaviside(hi(a)));
  }

  template<typename Z1, typename Z2, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto heaviside_(POLYFLOAT_DELAY(), O const&, Z1 const&  a, Z2 const&  s) noexcept
  {
    using t_t = as_polyfloat_t<Z1, Z2>;
    return if_else(a > s, t_t(1), eve::zero);
  }
}
