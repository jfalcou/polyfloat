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
  template<typename Options> struct sqrt_2_t : eve::constant_callable<sqrt_2_t, Options>
  {
    template<typename T> static POLYFLOAT_FORCEINLINE constexpr auto value(eve::as<T> const&, auto const&)
    {
      using u_t = eve::underlying_type_t<T>;

      if constexpr (plf::dimension_v<T> == 1)
      {
        if constexpr (sizeof(u_t) == 8) return u_t(0x1.6a09e667f3bcdp+0);
        else return u_t(0x1.6a09e6p+0);
      }
      else if constexpr (plf::dimension_v<T> == 2)
      {
        if constexpr (sizeof(u_t) == 8) return plf::_::from_pair<u_t>(0x1.6a09e667f3bcdp+0, -0x1.bdd3413b26456p-54);
        else return plf::_::from_pair<u_t>(0x1.6a09e6p+0, 0x1.9fcef4p-26);
      }
      else if constexpr (plf::dimension_v<T> == 3)
      {
        if constexpr (sizeof(u_t) == 8)
          return plf::_::from_triple<u_t>(0x1.6a09e667f3bcdp+0, -0x1.bdd3413b26456p-54, 0x1.57d3e3adec175p-108);
        else return plf::_::from_triple<u_t>(0x1.6a09e6p+0, 0x1.9fcef4p-26, -0x1.b7ba68p-51);
      }
    }

    template<concepts::polyfloat_like T> POLYFLOAT_FORCEINLINE constexpr T operator()(as<T> const& v) const
    {
      return POLYFLOAT_CALL(v);
    }

    EVE_CALLABLE_OBJECT(sqrt_2_t, sqrt_2_);
  };
  //======================================================================================================================
  //! @addtogroup constants
  //! @{
  //!   @var sqrt_2
  //!   @brief return the sqrt of 2.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto sqrt_2(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the sqrt of 2.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/sqrt_2.cpp}
  //======================================================================================================================

  inline constexpr auto sqrt_2 = eve::functor<sqrt_2_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}
