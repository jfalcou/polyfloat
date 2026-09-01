//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

#include <eve/eve.hpp>
#include <polyfloat/details/callable.hpp>
#include <polyfloat/types/concepts.hpp>
#include <polyfloat/types/traits.hpp>

namespace plf
{
  template<typename Options>
  struct effective_mantissa_bits_t : eve::constant_callable<effective_mantissa_bits_t, Options>
  {
    template<typename T>
    static POLYFLOAT_FORCEINLINE constexpr eve::as_integer_t<T> value(eve::as<T> const&, auto const&)
    {
      using u_t = eve::underlying_type_t<T>;
      using i_t = eve::as_integer_t<u_t>;
      return (eve::nbmantissabits(eve::as<u_t>()) + 1) * dimension_v<T>;
    }

    template<concepts::polyfloat_like T> POLYFLOAT_FORCEINLINE constexpr T operator()(as<T> const& v) const
    {
      return POLYFLOAT_CALL(v);
    }

    EVE_CALLABLE_OBJECT(effective_mantissa_bits_t, effective_mantissa_bits_);
  };
  //======================================================================================================================
  //! @addtogroup constants
  //! @{
  //!   @var effective_mantissa_bits
  //!   @brief return the maximal representable flint value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto effective_mantissa_bits(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z` :   [Type wrapper](@ref eve::as) instance embedding the type of the constant.
  //!
  //!    **Return value**
  //!
  //!     Returns the effective number of bits of the mantissa value.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/effective_mantissa_bits.cpp}
  //======================================================================================================================

  inline constexpr auto effective_mantissa_bits = eve::functor<effective_mantissa_bits_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}
