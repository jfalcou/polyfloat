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

  template<typename Options> struct is_eqpz_t : eve::elementwise_callable<is_eqpz_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_FORCEINLINE constexpr eve::as_logical_t<plf::as_component_type_t<Z>> operator()(Z z) const noexcept
    {
     return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(is_eqpz_t, is_eqpz_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var is_eqpz
  //!   @brief test the parameter for equality to positive zero.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto is_eqpz(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the value of `z ==  0 && is_positive(z)`.
  //!
  //!  @note as zero is represented by N \f$\pm0\f$ fields only the sign of the hi field is taken into account
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/is_eqpz.cpp}
  //======================================================================================================================

  inline constexpr auto is_eqpz = eve::functor<is_eqpz_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto is_eqpz_(POLYFLOAT_DELAY(), O const& , Z const& z) noexcept
  {
    return eve::is_eqpz(hi(z));
  }
}
