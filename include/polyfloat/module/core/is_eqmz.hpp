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

  template<typename Options> struct is_eqmz_t : eve::elementwise_callable<is_eqmz_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_FORCEINLINE constexpr eve::as_logical_t<plf::as_component_type_t<Z>> operator()(Z z) const noexcept
    {
     return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(is_eqmz_t, is_eqmz_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var is_eqmz
  //!   @brief test the parameter for equality to negative zero.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto is_eqmz(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the value of `z ==  0 && is_negative(z)`.
  //!
  //!  @note as zero is represented by N \f$\pm0\f$ fields only the sign of the hi field is taken into account
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/is_eqmz.cpp}
  //======================================================================================================================

  inline constexpr auto is_eqmz = eve::functor<is_eqmz_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto is_eqmz_(POLYFLOAT_DELAY(), O const& , Z const& z) noexcept
  {
    return eve::is_eqmz(hi(z));
  }
}
