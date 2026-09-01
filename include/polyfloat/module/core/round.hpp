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

  template<typename Options>
  struct round_t : eve::callable<round_t,
                                 Options,
                                 raw_option,
                                 pedantic_option,
                                 to_nearest_option,
                                 toward_zero_option,
                                 downward_option,
                                 upward_option>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_FORCEINLINE constexpr as_polyfloat_like_t<Z> operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(round_t, round_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var round
  //!   @brief rounds a value, to nearest unless an option says otherwise.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto round(T z) noexcept; //1
  //!
  //!      // Semantic exclusive options
  //!      constexpr auto round[upward](/*any of the above overloads*/)                   noexcept; // 2
  //!      constexpr auto round[downward](/*any of the above overloads*/)                 noexcept; // 2
  //!      constexpr auto round[toward_zero](/*any of the above overloads*/)              noexcept; // 2
  //!      constexpr auto round[to_nearest](/*any of the above overloads*/)               noexcept; // 2
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Values to process.
  //!
  //!   **Return value**
  //!
  //!    1. Returns the `plf::nearest(z)`.
  //!    2. P roduces:
  //!       * `plf::trunc(z)`, if `d` is `toward_zero`.
  //!       * `plf::floor(z)`, if `d` is `downward`.
  //!       * `plf::ceil(z)`, if `d` is `upward`.
  //!       * `plf::nearest(z)`, if `d` is `to_nearest`.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/round.cpp}
  //======================================================================================================================

  inline constexpr auto round = eve::functor<round_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename T, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto round_(POLYFLOAT_DELAY(), O const&, T a) noexcept
  {
    if constexpr (O::contains(toward_zero)) return trunc(a);
    else if constexpr (O::contains(downward)) return floor(a);
    else if constexpr (O::contains(upward)) return ceil(a);
    else return nearest(a);
  }
}
