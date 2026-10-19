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
  template<typename Options> struct three_pio_4_t : eve::constant_callable<three_pio_4_t, Options>
  {
    template<typename T> POLYFLOAT_FORCEINLINE static constexpr auto value(eve::as<T> const&, auto const&)
    {
      using u_t = eve::underlying_type_t<T>;

      if constexpr (plf::dimension_v<T> == 1)
      {
        return eve::three_pio_4(eve::as(u_t()));
      }
      if constexpr (plf::dimension_v<T> == 2)
      {
        if constexpr (std::same_as<u_t, float>)
          return plf::_::from_pair<u_t>(0x1.2d97c80000000p+1, -0x1.99bc5c0000000p-28);
        else if constexpr (std::same_as<u_t, double>)
          return plf::_::from_pair<u_t>(0x1.2d97c7f3321d2p+1, 0x1.a79394c9e8a0ap-54);
      }
      else if constexpr (plf::dimension_v<T> == 3)
      {
        if constexpr (std::same_as<u_t, float>)
          return plf::_::from_triple<u_t>(0x1.2d97c80000000p+1, -0x1.99bc5c0000000p-28, 0x1.a793940000000p-54);
        else if constexpr (std::same_as<u_t, double>)
          return plf::_::from_triple<u_t>(0x1.2d97c7f3321d2p+1, 0x1.a79394c9e8a0ap-54, 0x1.456737b06ea1ap-108);
      }
    }

    template<concepts::polyfloat_like T> POLYFLOAT_FORCEINLINE constexpr T operator()(as<T> const& v) const
    {
      return POLYFLOAT_CALL(v);
    }

    POLYFLOAT_CALLABLE_OBJECT(three_pio_4_t, three_pio_4_);
  };
  //======================================================================================================================
  //! @addtogroup constants
  //! @{
  //!   @var three_pio_4
  //!   @brief return the three_pio_4 value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto three_pio_4(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the three_pio_4 value as T.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/three_pio_4.cpp}
  //======================================================================================================================

  inline constexpr auto three_pio_4 = eve::functor<three_pio_4_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}
