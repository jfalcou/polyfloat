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
#include <polyfloat/module/core/next.hpp>
#include <polyfloat/module/core/prev.hpp>

namespace plf
{

  template<typename Options>
  struct nextafter_t : eve::elementwise_callable<nextafter_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_FORCEINLINE constexpr Z operator()(Z x, Z y) const noexcept
    {
      return POLYFLOAT_CALL(x, y);
    }

    POLYFLOAT_CALLABLE_OBJECT(nextafter_t, nextafter_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var nextafter
  //!   @brief return the nextafter representable value.
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <polyfloat/module/core.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace polyfloat
  //!   {
  //!      constexpr auto nextafter( auto x, auto y)                         noexcept; // 1
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `x`, `y`: polyfloats to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the next representable value value of x in y direction .
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/nextafter.cpp}
  //======================================================================================================================

  inline constexpr auto nextafter = eve::functor<nextafter_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto nextafter_(POLYFLOAT_DELAY(), O const& o, Z const& a, Z const& b) noexcept
  {
    if constexpr (O::contains(pedantic))
    {
      return plf::if_else(a < b, plf::next[o](a), plf::if_else(a > b, plf::prev[o](a), a));
    }
    else
    {
      return plf::next[a < b](plf::prev[a > b](a));
    }
  }
}
