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
  struct prevint_t : eve::elementwise_callable<prevint_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(prevint_t, prevint_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var prevint
  //!   @brief returns the least flint greater than the input.
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
  //!      constexpr auto prevint(value auto x)                            noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the least flint greater than the input.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/prevint.cpp}
  //======================================================================================================================

  inline constexpr auto prevint = eve::functor<prevint_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto prevint_(POLYFLOAT_DELAY(), O const& o, Z const& v) noexcept
  {
    if constexpr (dimension_v<Z> == 1) return eve::prevint(v);
    else
    {
      auto ni = plf::floor(plf::prev[o.drop(raw)](v));
      if (!O::contains(raw)) ni = if_else(plf::is_nan(v), v, ni);
      return ni;
    }
  }
}
