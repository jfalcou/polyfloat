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

  template<typename Options> struct is_eqz_t : eve::elementwise_callable<is_eqz_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_FORCEINLINE constexpr eve::as_logical_t<plf::as_component_type_t<Z>> operator()(Z z) const noexcept
    {
     return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(is_eqz_t, is_eqz_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var is_eqz
  //!   @brief test the parameter for equality to zero.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto is_eqz(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the value of z ==  0.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/is_eqz.cpp}
  //======================================================================================================================

  inline constexpr auto is_eqz = eve::functor<is_eqz_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto is_eqz_(POLYFLOAT_DELAY(), O const& , Z const& z) noexcept
  {
    return eve::is_eqz(hi(z));
  }
}
