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
  template<typename Options> struct sqrteps_t : eve::constant_callable<sqrteps_t, Options>
  {
    template<typename T> static POLYFLOAT_FORCEINLINE constexpr auto value(eve::as<T> const&, auto const&)
    {
      using u_t = eve::underlying_type_t<T>;

      if constexpr (plf::dimension_v<T> == 1)
      {
        return eve::sqrteps(eve::as(u_t()));
      }
      if constexpr (plf::dimension_v<T> == 2)
      {
        if constexpr (std::same_as<u_t, eve::float16_t>) return T(0x1p-10);
        else if constexpr (std::same_as<u_t, float>) return T(0x1p-23);
        else if constexpr (std::same_as<u_t, double>) return T(0x1p-52);
      }
      else if constexpr (plf::dimension_v<T> == 3)
      {
        if constexpr (std::same_as<u_t, eve::float16_t>) return T(0x1p-15);
        else if constexpr (std::same_as<u_t, float>)
          return plf::_::from_triple<u_t>(0x1.6a09e6p-35, 0x1.9fcef4p-61, -0x1.b7ba68p-86);
        else if constexpr (std::same_as<u_t, double>) return T(0x1p-78);
      }
      else
      {
        return eve::sqrteps(eve::as<u_t>());
      }
    }

    template<concepts::polyfloat_like T> POLYFLOAT_FORCEINLINE constexpr T operator()(as<T> const& v) const
    {
      return POLYFLOAT_CALL(v);
    }

    EVE_CALLABLE_OBJECT(sqrteps_t, sqrteps_);
  };
  //======================================================================================================================
  //! @addtogroup constants
  //! @{
  //!   @var sqrteps
  //!   @brief return the sqrtepsolute value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto sqrteps(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the sqrtepsolute value of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/sqrteps.cpp}
  //======================================================================================================================

  inline constexpr auto sqrteps = eve::functor<sqrteps_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}
