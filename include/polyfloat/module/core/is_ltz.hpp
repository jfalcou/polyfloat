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

  template<typename Options> struct is_ltz_t : eve::callable<is_ltz_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_FORCEINLINE constexpr auto operator()(Z z) const noexcept -> eve::as_logical_t<as_component_type_t<Z>>
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(is_ltz_t, is_ltz_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var is_ltz
  //!   @brief test the parameter for less than zero.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto is_ltz(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the value of z < 0.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/is_ltz.cpp}
  //======================================================================================================================

  inline constexpr auto is_ltz = eve::functor<is_ltz_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto is_ltz_(POLYFLOAT_DELAY(), O const&, Z const& z) noexcept
  {
    return eve::is_ltz(hi(z));
  }
}
