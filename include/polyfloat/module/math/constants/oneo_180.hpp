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
  template<typename Options> struct oneo_180_t : eve::constant_callable<oneo_180_t, Options>
  {
    template<typename T> static POLYFLOAT_FORCEINLINE constexpr auto value(eve::as<T> const&, auto const&)
    {
      using u_t = eve::underlying_type_t<T>;

      if constexpr (plf::dimension_v<T> == 1)
      {
        return 1 / u_t(180);
      }
      if constexpr (plf::dimension_v<T> == 2)
      {
        if constexpr (std::same_as<u_t, float>)
          return plf::_::from_pair<u_t>(0x1.6c16c20000000p-8, -0x1.27d27e0000000p-33);
        else if constexpr (std::same_as<u_t, double>)
          return plf::_::from_pair<u_t>(0x1.6c16c16c16c17p-8, -0x1.f49f49f49f49fp-63);
      }
      else if constexpr (plf::dimension_v<T> == 3)
      {
        if constexpr (std::same_as<u_t, float>)
          return plf::_::from_triple<u_t>(0x1.6c16c20000000p-8, -0x1.27d27e0000000p-33, 0x1.b05b060000000p-58);
        else if constexpr (std::same_as<u_t, double>)
          return plf::_::from_triple<u_t>(0x1.6c16c16c16c17p-8, -0x1.f49f49f49f49fp-63, -0x1.27d27d27d27d2p-117);
      }
    }

    template<concepts::polyfloat_like T> POLYFLOAT_FORCEINLINE constexpr T operator()(as<T> const& v) const
    {
      return POLYFLOAT_CALL(v);
    }

    EVE_CALLABLE_OBJECT(oneo_180_t, oneo_180_);
  };
  //======================================================================================================================
  //! @addtogroup constants
  //! @{
  //!   @var oneo_180
  //!   @brief return the oneo_180 value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto oneo_180(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the oneo_180 value as T.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/oneo_180.cpp}
  //======================================================================================================================

  inline constexpr auto oneo_180 = eve::functor<oneo_180_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}
