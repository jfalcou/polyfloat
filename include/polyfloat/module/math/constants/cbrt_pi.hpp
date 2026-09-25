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
  template<typename Options> struct cbrt_pi_t : eve::constant_callable<cbrt_pi_t, Options>
  {
    template<typename T> static POLYFLOAT_FORCEINLINE constexpr auto value(eve::as<T> const&, auto const&)
    {
      using u_t = eve::underlying_type_t<T>;

      if constexpr (plf::dimension_v<T> == 1)
      {
        return eve::cbrt_pi(eve::as(u_t()));
      }
      if constexpr (plf::dimension_v<T> == 2)
      {
        if constexpr (std::same_as<u_t, float>)
          return plf::_::from_pair<u_t>(0x1.76ef7e0000000p+0, 0x1.cc412e0000000p-26);
        else if constexpr (std::same_as<u_t, double>)
          return plf::_::from_pair<u_t>(0x1.76ef7e73104b8p+0, -0x1.d41ba28e4f999p-54);
      }
      else if constexpr (plf::dimension_v<T> == 3)
      {
        if constexpr (std::same_as<u_t, float>)
          return plf::_::from_triple<u_t>(0x1.76ef7e0000000p+0, 0x1.cc412e0000000p-26, -0x1.d41ba20000000p-54);
        else if constexpr (std::same_as<u_t, double>)
          return plf::_::from_triple<u_t>(0x1.76ef7e73104b8p+0, -0x1.d41ba28e4f999p-54, -0x1.ccbbc9a2c839dp-110);
      }
    }

    template<concepts::polyfloat_like T> POLYFLOAT_FORCEINLINE constexpr T operator()(as<T> const& v) const
    {
      return POLYFLOAT_CALL(v);
    }

    EVE_CALLABLE_OBJECT(cbrt_pi_t, cbrt_pi_);
  };
  //======================================================================================================================
  //! @addtogroup constants
  //! @{
  //!   @var cbrt_pi
  //!   @brief return the cbrt_pi value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto cbrt_pi(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the cbrt_pi value as T.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/cbrt_pi.cpp}
  //======================================================================================================================

  inline constexpr auto cbrt_pi = eve::functor<cbrt_pi_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}
