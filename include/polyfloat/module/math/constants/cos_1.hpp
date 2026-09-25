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

namespace plf
{
  template<typename Options> struct cos_1_t : eve::constant_callable<cos_1_t, Options>
  {
    template<typename T> static POLYFLOAT_FORCEINLINE constexpr auto value(eve::as<T> const&, auto const&)
    {
      using u_t = eve::underlying_type_t<T>;

      if constexpr (plf::dimension_v<T> == 1)
      {
        return eve::cos_1(eve::as(u_t()));
      }
      if constexpr (plf::dimension_v<T> == 2)
      {
        if constexpr (std::same_as<u_t, float>)
          return plf::_::from_pair<u_t>(0x1.14a2800000000p-1, 0x1.f6a0d20000000p-26);
        else if constexpr (std::same_as<u_t, double>)
          return plf::_::from_pair<u_t>(0x1.14a280fb5068cp-1, -0x1.b71edcc9344bcp-55);
      }
      else if constexpr (plf::dimension_v<T> == 3)
      {
        if constexpr (std::same_as<u_t, float>)
          return plf::_::from_triple<u_t>(0x1.14a2800000000p-1, 0x1.f6a0d20000000p-26, -0x1.1b71ee0000000p-51);
        else if constexpr (std::same_as<u_t, double>)
          return plf::_::from_triple<u_t>(0x1.14a280fb5068cp-1, -0x1.b71edcc9344bcp-55, -0x1.c85acbb918aedp-109);
      }
    }

    template<concepts::polyfloat_like T> POLYFLOAT_FORCEINLINE constexpr T operator()(as<T> const& v) const
    {
      return POLYFLOAT_CALL(v);
    }

    EVE_CALLABLE_OBJECT(cos_1_t, cos_1_);
  };
  //======================================================================================================================
  //! @addtogroup constants
  //! @{
  //!   @var cos_1
  //!   @brief return the cos_1 value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto cos_1(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the cos_1 value as T.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/cos_1.cpp}
  //======================================================================================================================

  inline constexpr auto cos_1 = eve::functor<cos_1_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}
