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
  template<typename Options> struct inv_2pi_t : eve::constant_callable<inv_2pi_t, Options>
  {
    template<typename T> static POLYFLOAT_FORCEINLINE constexpr auto value(eve::as<T> const&, auto const&)
    {
      using u_t = eve::underlying_type_t<T>;

      if constexpr (plf::dimension_v<T> == 1)
      {
        return eve::inv_2pi(eve::as(u_t()));
      }
      if constexpr (plf::dimension_v<T> == 2)
      {
        if constexpr (std::same_as<u_t, float>)
          return plf::_::from_pair<u_t>(0x1.45f3060000000p-3, 0x1.b939100000000p-28);
        else if constexpr (std::same_as<u_t, double>)
          return plf::_::from_pair<u_t>(0x1.45f306dc9c883p-3, -0x1.6b01ec5417056p-57);
      }
      else if constexpr (plf::dimension_v<T> == 3)
      {
        if constexpr (std::same_as<u_t, float>)
          return plf::_::from_triple<u_t>(0x1.45f3060000000p-3, 0x1.b939100000000p-28, 0x1.529fc20000000p-54);
        else if constexpr (std::same_as<u_t, double>)
          return plf::_::from_triple<u_t>(0x1.45f306dc9c883p-3, -0x1.6b01ec5417056p-57, -0x1.6447e493ad4cep-111);
      }
    }

    template<concepts::polyfloat_like T> POLYFLOAT_FORCEINLINE constexpr T operator()(as<T> const& v) const
    {
      return POLYFLOAT_CALL(v);
    }

    EVE_CALLABLE_OBJECT(inv_2pi_t, inv_2pi_);
  };
  //======================================================================================================================
  //! @addtogroup constants
  //! @{
  //!   @var inv_2pi
  //!   @brief return the inv_2pi value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto inv_2pi(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the inv_2pi value as T.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/inv_2pi.cpp}
  //======================================================================================================================

  inline constexpr auto inv_2pi = eve::functor<inv_2pi_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}
