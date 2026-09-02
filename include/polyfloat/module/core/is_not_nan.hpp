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
  struct is_not_nan_t : eve::elementwise_callable<is_not_nan_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_FORCEINLINE constexpr eve::as_logical_t<plf::as_component_type_t<Z>> operator()(Z z) const noexcept
    {
      return eve::is_not_nan(hi(z));
    }

    POLYFLOAT_CALLABLE_OBJECT(is_not_nan_t, is_not_nan_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var is_not_nan
  //!   @brief returns a logical true if and only if the element
  //!    is not a Nan
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto is_not_nan(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     returns true if and only z is not a Nan.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/is_not_nan.cpp}
  //======================================================================================================================

  inline constexpr auto is_not_nan = eve::functor<is_not_nan_t>;
}
