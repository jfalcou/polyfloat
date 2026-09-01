//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

#include <eve/eve.hpp>
#include <polyfloat/details/callable.hpp>
#include <polyfloat/types/concepts.hpp>
#include <polyfloat/types/traits.hpp>
#include <polyfloat/module/core/constants/valmax.hpp>
#include <polyfloat/module/core/sqrt.hpp>

namespace plf
{
  template<typename Options> struct sqrtvalmax_t : eve::constant_callable<sqrtvalmax_t, Options>
  {
    template<typename T> static POLYFLOAT_FORCEINLINE constexpr T value(eve::as<T> const&, auto const&)
    {
      using u_t = eve::underlying_type_t<T>;
      if constexpr (dimension_v<T> == 1) return eve::sqrtvalmax(eve::as<u_t>());
      else if constexpr (dimension_v<T> == 2)
      {
        if constexpr (sizeof(u_t) == 8) return plf::_::from_pair<u_t>(0x1p+512, -0x1p+405);
        else return plf::_::from_pair<u_t>(0x1p+64, -0x1p+15);
      }
      else if constexpr (dimension_v<T> == 3)
      {
        if constexpr (sizeof(u_t) == 8) return plf::_::from_triple<u_t>(0x1p+512, -0x1p+352, -0x1p+191);
        else return plf::_::from_triple<u_t>(0x1p+64, -0x1p-9, -0x1p-83);
      }
    }

    template<concepts::polyfloat_like T> POLYFLOAT_FORCEINLINE constexpr T operator()(as<T> const& v) const
    {
      return POLYFLOAT_CALL(v);
    }

    EVE_CALLABLE_OBJECT(sqrtvalmax_t, sqrtvalmax_);
  };
  //======================================================================================================================
  //! @addtogroup constants
  //! @{
  //!   @var sqrtvalmax
  //!   @brief return the sqrt of the maximal representable value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto sqrtvalmax(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z` :   [Type wrapper](@ref eve::as) instance embedding the type of the constant.
  //!
  //!    **Return value**
  //!
  //!     Returns the sqrt of the maximal representable value.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/sqrtvalmax.cpp}
  //======================================================================================================================

  inline constexpr auto sqrtvalmax = eve::functor<sqrtvalmax_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}
