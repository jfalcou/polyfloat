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
#include <iostream>
#include <iomanip>
namespace plf
{
  template<typename Options> struct valmax_t : eve::constant_callable<valmax_t, Options>
  {
    template<typename T> static POLYFLOAT_FORCEINLINE constexpr T value(eve::as<T> const&, auto const&)
    {
      using u_t = eve::underlying_type_t<T>;
      using i_t = eve::as_integer_t<u_t>;
      auto vlm = eve::valmax(eve::as<u_t>());
      std::cout << " dimension_v<T> " << dimension_v<T> << std::endl;
      if constexpr (dimension_v<T> == 1) return vlm;
      else if constexpr (dimension_v<T> == 2)
      {
        auto mnbts = -plf::effective_mantissa_bits(eve::as<u_t>());
        return plf::_::from_pair(vlm, eve::ldexp(vlm, mnbts));
      }
      else if constexpr (dimension_v<T> == 3)
      {
        auto mnbts = -plf::effective_mantissa_bits(eve::as<u_t>());
        return plf::_::from_triple(vlm, eve::ldexp(vlm, mnbts), eve::ldexp(vlm, 2 * mnbts));
      }
    }

    template<concepts::polyfloat_like T> POLYFLOAT_FORCEINLINE constexpr T operator()(as<T> const& v) const
    {
      return POLYFLOAT_CALL(v);
    }

    EVE_CALLABLE_OBJECT(valmax_t, valmax_);
  };
  //======================================================================================================================
  //! @addtogroup constants
  //! @{
  //!   @var valmax
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto valmax(T z) noexcept;
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
  //!  @godbolt{doc/core/valmax.cpp}
  //======================================================================================================================

  inline constexpr auto valmax = eve::functor<valmax_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}
