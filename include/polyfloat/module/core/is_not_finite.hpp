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
  struct is_not_finite_t : eve::elementwise_callable<is_not_finite_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_ABI constexpr eve::as_logical_t<plf::as_component_type_t<Z>> operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(is_not_finite_t, is_not_finite_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var is_not_finite
  //!   @brief test the parameter for being infinite or NaN.
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
  //!      template<concepts::polyfloat_like T> constexpr auto is_not_finite(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns true if and only if `z` is infinite or NaN.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/is_not_finite.cpp}
  //======================================================================================================================

  inline constexpr auto is_not_finite = eve::functor<is_not_finite_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O>
  constexpr auto is_not_finite_(POLYFLOAT_DELAY(), O const&, Z const& z) noexcept
  {
    return eve::is_not_finite(hi(z));
  }
}
