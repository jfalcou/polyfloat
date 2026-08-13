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

  template<typename Options> struct is_lez_t : eve::callable<is_lez_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_FORCEINLINE constexpr auto operator()(Z z) const noexcept ->  eve::as_logical_t<as_component_type_t<Z>>
    {
     return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(is_lez_t, is_lez_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var is_lez
  //!   @brief test the parameter for less or equal to zero.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto is_lez(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the value of z <= 0.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/is_lez.cpp}
  //======================================================================================================================

  inline constexpr auto is_lez = eve::functor<is_lez_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto is_lez_(POLYFLOAT_DELAY(), O const& , Z const& z) noexcept
  {
    return eve::is_lez(hi(z));
  }
}
