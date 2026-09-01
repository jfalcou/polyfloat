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
  struct nextint_t : eve::elementwise_callable<nextint_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(nextint_t, nextint_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var nextint
  //!   @brief returns the greatest flint less than the input.
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
  //!      constexpr auto nextint(value auto x)                            noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the greatest flint less than the input.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/nextint.cpp}
  //======================================================================================================================

  inline constexpr auto nextint = eve::functor<nextint_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto nextint_(POLYFLOAT_DELAY(), O const& o, Z const& v) noexcept
  {
    if constexpr (dimension_v<Z> == 1) return eve::nextint(v);
    else
    {
      auto ni = plf::ceil(plf::next[o.drop(raw)](v));
      if (!O::contains(raw)) ni = if_else(plf::is_nan(v), v, ni);
      return ni;
    }
  }
}
