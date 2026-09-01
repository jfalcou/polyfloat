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

  template<typename Options> struct maxlog_t : eve::constant_callable<maxlog_t, Options>
  {
    template<typename T> static POLYFLOAT_FORCEINLINE constexpr T value(eve::as<T> const&, auto const&)
    {
      using u_t = plf::as_component_type_t<T>;
      if constexpr (plf::dimension_v<T> == 1)
      {
        if constexpr (std::same_as<u_t, float>) return float(0x1.62e43p+6);
        else if constexpr (std::same_as<u_t, double>) return double(0x1.62e42fefa39efp+9);
      }
      else if constexpr (plf::dimension_v<T> == 2)
      {
        if constexpr (std::same_as<u_t, float>) return plf::_::from_pair<float>(0x1.62p+6, 0x0.0p1);
        else if constexpr (std::same_as<u_t, double>) return plf::_::from_pair<double>(0x1.62e42fefa39efp+9, 0x0.0p+1);
      }
      else if constexpr (plf::dimension_v<T> == 3)
      {
        if constexpr (std::same_as<u_t, float>) return plf::_::from_triple<float>(0x1.62p+6, 0x0.0p+1, 0x0.0p1);
        else if constexpr (std::same_as<u_t, double>)
          return plf::_::from_triple<double>(0x1.62e42fefa39efp+9, 0x0.0p+1, 0x0.0p1);
      }
    }

    template<concepts::polyfloat_like T> POLYFLOAT_FORCEINLINE constexpr T operator()(as<T> const& v) const
    {
      return POLYFLOAT_CALL(v);
    }

    POLYFLOAT_CALLABLE_OBJECT(maxlog_t, maxlog_);
  };
  //======================================================================================================================
  //! @addtogroup constants
  //! @{
  //!   @var maxlog
  //!   @brief return the exp(1) value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto maxlog(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!
  //!   **Return value**
  //!
  //!     Returns exp(1).
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/maxlog.cpp}
  //======================================================================================================================

  inline constexpr auto maxlog = eve::functor<maxlog_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}
