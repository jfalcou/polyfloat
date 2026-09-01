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
  template<typename Options> struct logeps_t : eve::constant_callable<logeps_t, Options>
  {
    template<typename T> static POLYFLOAT_FORCEINLINE constexpr auto value(eve::as<T> const&, auto const&)
    {
      using u_t = eve::underlying_type_t<T>;

      if constexpr (plf::dimension_v<T> == 1)
      {
        return eve::logeps(eve::as(u_t()));
      }
      if constexpr (plf::dimension_v<T> == 2)
      {
        if constexpr (std::same_as<u_t, float>) return plf::_::from_pair<u_t>(-0x1.fe2804p+4, -0x1.d0f668p-21);
        else if constexpr (std::same_as<u_t, double>)
          return plf::_::from_pair<u_t>(-0x1.205966f2b4f12p+6, -0x1.6dca0480f5c1ap-48);
      }
      else if constexpr (plf::dimension_v<T> == 3)
      {
        if constexpr (std::same_as<u_t, float>)
          return plf::_::from_triple<u_t>(-0x1.7e9e04p+5, 0x1.468e62p-21, 0x1.0d2ca6p-46);
        else if constexpr (std::same_as<u_t, double>)
          return plf::_::from_triple<u_t>(-0x1.b0861a6c0f69cp+6, 0x1.db50f93e8f5d9p-48, 0x1.fc6b4d1af0c52p-102);
      }
      else
      {
        return eve::logeps(eve::as<u_t>());
      }
    }

    template<concepts::polyfloat_like T> POLYFLOAT_FORCEINLINE constexpr T operator()(as<T> const& v) const
    {
      return POLYFLOAT_CALL(v);
    }

    EVE_CALLABLE_OBJECT(logeps_t, logeps_);
  };
  //======================================================================================================================
  //! @addtogroup constants
  //! @{
  //!   @var logeps
  //!   @brief return the logeps value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto logeps(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the logeps value of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/logeps.cpp}
  //======================================================================================================================

  inline constexpr auto logeps = eve::functor<logeps_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}
