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

  template<typename Options> struct log_10_t : eve::constant_callable<log_10_t, Options>
  {
    template<typename T> static POLYFLOAT_FORCEINLINE constexpr T value(eve::as<T> const&, auto const&)
    {
      using u_t = plf::as_component_type_t<T>;
      if constexpr (plf::dimension_v<T> == 1)
      {
        if constexpr (std::same_as<u_t, float>) return float(0x1.26bb1cp+1);
        else if constexpr (std::same_as<u_t, double>) return double(0x1.26bb1bbb55516p+1);
      }
      else if constexpr (plf::dimension_v<T> == 2)
      {
        if constexpr (std::same_as<u_t, float>) return plf::_::from_pair<float>(0x1.26bb1cp+1, -0x1.12aabap-25);
        else if constexpr (std::same_as<u_t, double>)
          return plf::_::from_pair<double>(0x1.26bb1bbb55516p+1, -0x1.f48ad494ea3e9p-53);
      }
      else if constexpr (plf::dimension_v<T> == 3)
      {
        if constexpr (std::same_as<u_t, float>)
          return plf::_::from_triple<float>(0x1.26bb1cp+1, -0x1.12aabap-25, -0x1.3e915ap-50);
        else if constexpr (std::same_as<u_t, double>)
          return plf::_::from_triple<double>(0x1.26bb1bbb55516p+1, -0x1.f48ad494ea3e9p-53, -0x1.9ebae3ae0260cp-107);
      }
    }

    template<concepts::polyfloat_like T> POLYFLOAT_FORCEINLINE constexpr T operator()(as<T> const& v) const
    {
      return POLYFLOAT_CALL(v);
    }

    POLYFLOAT_CALLABLE_OBJECT(log_10_t, log_10_);
  };
  //======================================================================================================================
  //! @addtogroup constants
  //! @{
  //!   @var log_10
  //!   @brief return the log(10) value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto log_10(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!
  //!   **Return value**
  //!
  //!     Returns log(2).
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/log_10.cpp}
  //======================================================================================================================

  inline constexpr auto log_10 = eve::functor<log_10_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}
