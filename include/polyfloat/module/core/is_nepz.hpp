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

  template<typename Options> struct is_nepz_t : eve::elementwise_callable<is_nepz_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_FORCEINLINE constexpr eve::as_logical_t<plf::as_component_type_t<Z>> operator()(Z z) const noexcept
    {
     return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(is_nepz_t, is_nepz_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var is_nepz
  //!   @brief test the parameter for not equality to positive zero.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto is_nepz(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the value of `z !=  0  || is_negative(z)`.
  //!
  //!  @note as zero is represented by N \f$\pm0\f$ fields only the sign of the hi field is taken into account
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/is_nepz.cpp}
  //======================================================================================================================

  inline constexpr auto is_nepz = eve::functor<is_nepz_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto is_nepz_(POLYFLOAT_DELAY(), O const& , Z const& z) noexcept
  {
    return eve::is_nepz(hi(z));
  }
}
