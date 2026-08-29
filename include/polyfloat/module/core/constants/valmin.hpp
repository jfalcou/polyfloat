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
  template<typename Options> struct valmin_t : eve::constant_callable<valmin_t, Options>
  {
    template<typename T> static POLYFLOAT_FORCEINLINE constexpr T value(eve::as<T> const&, auto const&)
    {
      using u_t = eve::underlying_type_t<T>;
      auto vlm = eve::valmin(eve::as<u_t>());
      if constexpr (dimension_v<T> == 1) return vlm;
      else if constexpr (dimension_v<T> == 2)
      {
        auto nbts = -plf::effective_mantissa_bits(eve::as<u_t>());
        return plf::_::from_pair(vlm, eve::ldexp(vlm, nbts));
      }
      else if constexpr (dimension_v<T> == 3)
      {
        auto nbts = -plf::effective_mantissa_bits(eve::as<u_t>());
        return plf::_::from_triple(vlm, eve::ldexp(vlm, nbts), eve::ldexp(vlm, 2 * nbts));
      }
    }

    template<concepts::polyfloat_like T> POLYFLOAT_FORCEINLINE constexpr T operator()(as<T> const& v) const
    {
      return POLYFLOAT_CALL(v);
    }

    EVE_CALLABLE_OBJECT(valmin_t, valmin_);
  };
  //======================================================================================================================
  //! @addtogroup constants
  //! @{
  //!   @var valmin
  //!   @brief return the minimal representable flint value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto valmin(T z) noexcept;
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
  //!  @godbolt_todo{doc/valmin.cpp}
  //======================================================================================================================

  inline constexpr auto valmin = eve::functor<valmin_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}
