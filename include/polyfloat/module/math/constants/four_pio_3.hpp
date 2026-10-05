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
  template<typename Options> struct four_pio_3_t : eve::constant_callable<four_pio_3_t, Options>
  {
    template<typename T> static POLYFLOAT_FORCEINLINE constexpr auto value(eve::as<T> const&, auto const&)
    {
      using u_t = eve::underlying_type_t<T>;

      if constexpr (plf::dimension_v<T> == 1)
      {
        return eve::four_pio_3(eve::as(u_t()));
      }
      if constexpr (plf::dimension_v<T> == 2)
      {
        if constexpr (std::same_as<u_t, float>)
          return plf::_::from_pair<u_t>(0x1.0c15240000000p+2, -0x1.f4a3260000000p-24);
        else if constexpr (std::same_as<u_t, double>)
          return plf::_::from_pair<u_t>(0x1.0c152382d7366p+2, -0x1.ee6913347c2a6p-52);
      }
      else if constexpr (plf::dimension_v<T> == 3)
      {
        if constexpr (std::same_as<u_t, float>)
          return plf::_::from_triple<u_t>(0x1.0c15240000000p+2, -0x1.f4a3260000000p-24, -0x1.3dcd220000000p-49);
        else if constexpr (std::same_as<u_t, double>)
          return plf::_::from_triple<u_t>(0x1.0c152382d7366p+2, -0x1.ee6913347c2a6p-52, -0x1.4bba47a9e5fd2p-108);
      }
    }

    template<concepts::polyfloat_like T> POLYFLOAT_FORCEINLINE constexpr T operator()(as<T> const& v) const
    {
      return POLYFLOAT_CALL(v);
    }

    EVE_CALLABLE_OBJECT(four_pio_3_t, four_pio_3_);
  };
  //======================================================================================================================
  //! @addtogroup constants
  //! @{
  //!   @var four_pio_3
  //!   @brief return the four_pio_3 value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto four_pio_3(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the four_pio_3 value as T.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/four_pio_3.cpp}
  //======================================================================================================================

  inline constexpr auto four_pio_3 = eve::functor<four_pio_3_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}
