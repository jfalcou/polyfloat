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
#include <polyfloat/module/core/trunc.hpp>
#include <polyfloat/module/core/nearest.hpp>
#include <polyfloat/module/core/ceil.hpp>
#include <polyfloat/module/core/floor.hpp>

namespace plf
{

  template<typename Options> struct rem_t : eve::strict_tuple_callable<rem_t, Options, raw_option, pedantic_option,
                                                                       to_nearest_option, toward_zero_option,
                                                                       downward_option, upward_option>
  {
    template<concepts::polyfloat_like Z1,  concepts::polyfloat_like Z2>
      POLYFLOAT_FORCEINLINE constexpr as_polyfloat_like_t<Z1, Z2> operator()(Z1 z1, Z2 z2) const noexcept
    {
     return POLYFLOAT_CALL(z1, z2);
    }

    POLYFLOAT_CALLABLE_OBJECT(rem_t, rem_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var rem
  //!   @brief return the remender after division of the values.
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
  //!      template<polyfloat::concepts::polyfloat_like T1, polyfloat_like T2> constexpr auto rem(T1 x, T2 y) noexcept; //1
  //!
  //!      // Semantic exclusive options
  //!      constexpr auto rem[upward](/*any of the above overloads*/)                   noexcept; // 2
  //!      constexpr auto rem[downward](/*any of the above overloads*/)                 noexcept; // 2
  //!      constexpr auto rem[toward_zero](/*any of the above overloads*/)              noexcept; // 2
  //!      constexpr auto rem[to_nearest](/*any of the above overloads*/)               noexcept; // 2
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z1`, `z2`: Values to process.
  //!
  //!   **Return value**
  //!
  //!      1. Return the remainder after division of `x` by `y` and is
  //!         equivalent to  `x-div[toward_zero](x, y)*y`.
  //!      2. The call is equivalent to  `x-div[o](x, y)*y` where `o` is the chosen option.
  //!
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/rem.cpp}
  //======================================================================================================================

  inline constexpr auto rem = eve::functor<rem_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename T0, typename T1, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto rem_(POLYFLOAT_DELAY(), O const& o, T0 const& a, T1 const& b) noexcept
  {
    if constexpr(O::contains(to_nearest))
    {
      return if_else(plf::is_eqz(b) || plf::is_unordered(a, b),
                     plf::if_else(plf::is_eqz(a) || plf::is_infinite(b), a, nan(as(a))),
                     plf::fnma(b, eve::div[to_nearest](a, b), a)); // as remainder
    }
    else if constexpr(O::contains(upward) || O::contains(downward))
    {
      return  plf::fnma(b, eve::div[o](a, b), a);
    }
    else
    {
      return plf::if_else(plf::is_unordered(a, b) || plf::is_infinite(a) || plf::is_eqz(b),
                     plf::nan(as(a)),
                     if_else(is_eqz(a), a, plf::fnma(b, div[toward_zero](a, b), a)));
    }
  }
}
