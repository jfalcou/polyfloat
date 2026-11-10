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
  struct prevint_t : plf::elementwise_callable<prevint_t, eve::prevint_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_ABI constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(prevint_t, prevint_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var prevint
  //!   @brief returns the greatest flint strictly less than the input.
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <polyfloat/polyfloat.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace plf
  //!   {
  //!      constexpr auto prevint(eve::value auto x)                            noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `x`: value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the greatest flint strictly less than `x`.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/prevint.cpp}
  //======================================================================================================================

  inline constexpr auto prevint = eve::functor<prevint_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O>
  constexpr auto prevint_(POLYFLOAT_DELAY(), O const& o, Z const& v) noexcept
  {
    auto ni = plf::floor(plf::prev[o.drop(raw)](v));
    if (!O::contains(raw)) ni = if_else(plf::is_nan(v), v, ni);
    return ni;
  }
}
