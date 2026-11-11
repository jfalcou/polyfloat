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
  struct is_ngtz_t : eve::elementwise_callable<is_ngtz_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_ABI constexpr eve::as_logical_t<plf::as_component_type_t<Z>> operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(is_ngtz_t, is_ngtz_);
  };
  //======================================================================================================================
  //! @defgroup plf_is_ngtz plf::is_ngtz
  //! @ingroup core
  //! @brief test the parameter for not greater than zero.
  //! @{
  //!   @var is_ngtz
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
  //!      template<concepts::polyfloat_like T> constexpr auto is_ngtz(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the value of `!(z > 0)`.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/is_ngtz.cpp}
  //======================================================================================================================

  inline constexpr auto is_ngtz = eve::functor<is_ngtz_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O>
  constexpr auto is_ngtz_(POLYFLOAT_DELAY(), O const&, Z const& z) noexcept
  {
    return eve::is_ngtz(hi(z));
  }
}
