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
  template<typename Options> struct oneosqrteps_t : eve::constant_callable<oneosqrteps_t, Options>
  {
    template<typename T> static POLYFLOAT_FORCEINLINE constexpr auto value(eve::as<T> const&, auto const&)
    {
      using u_t = eve::underlying_type_t<T>;

      if constexpr (plf::dimension_v<T> == 1)
      {
        return eve::oneosqrteps(eve::as(u_t()));
      }
      if constexpr (plf::dimension_v<T> == 2)
      {
        if constexpr (std::same_as<u_t, eve::float16_t>) return T(0x1p+10);
        else if constexpr (std::same_as<u_t, float>) return T(0x1p+23);
        else if constexpr (std::same_as<u_t, double>) return T(0x1p+52);
      }
      else if constexpr (plf::dimension_v<T> == 3)
      {
        if constexpr (std::same_as<u_t, eve::float16_t>) return T(0x1p+15);
        else if constexpr (std::same_as<u_t, float>)
          return plf::_::from_triple<u_t>(0x1.6a09e6p+34, 0x1.9fcef4p+8, -0x1.b7ba68p-17);
        else if constexpr (std::same_as<u_t, double>) return T(0x1p+78);
      }
      else
      {
        return eve::oneosqrteps(eve::as<u_t>());
      }
    }

    template<concepts::polyfloat_like T> POLYFLOAT_FORCEINLINE constexpr T operator()(as<T> const& v) const
    {
      return POLYFLOAT_CALL(v);
    }

    EVE_CALLABLE_OBJECT(oneosqrteps_t, oneosqrteps_);
  };
  //======================================================================================================================
  //! @addtogroup constants
  //! @{
  //!   @var oneosqrteps
  //!   @brief return the inverse of sqrteps value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto oneosqrteps(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the inverse of sqrteps value.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/oneosqrteps.cpp}
  //======================================================================================================================

  inline constexpr auto oneosqrteps = eve::functor<oneosqrteps_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}
