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
  template<typename Options> struct eps_t : eve::constant_callable<eps_t, Options>
  {
    template<typename T>
    static POLYFLOAT_FORCEINLINE constexpr auto value(eve::as<T> const&, auto const&)
    {
      using u_t = eve::underlying_type_t<T>;

      if constexpr(plf::dimension_v<T> == 1)
      {
        return eve::eps(eve::as(u_t()));
      }
      if constexpr(plf::dimension_v<T> == 2)
      {
        if constexpr(std::same_as<u_t, eve::float16_t>) return T(0x1p-20);
        else if constexpr(std::same_as<u_t, float>  ) return T(0x1p-48);
        else if constexpr(std::same_as<u_t, double> ) return T(0x1p-104);
      }
      else if constexpr(plf::dimension_v<T> == 3)
      {
        if constexpr(std::same_as<u_t, eve::float16_t>) return T(0x1p-30);
        else if constexpr(std::same_as<u_t, float>  ) return T(0x1p-72);
        else if constexpr(std::same_as<u_t, double> ) return T(0x1p-156);
      }
      else
      {
        return eve::eps(eve::as<u_t>());
      }
    }

    template<concepts::polyfloat_like T>
    POLYFLOAT_FORCEINLINE constexpr T operator()(as<T> const& v) const
    {
      return POLYFLOAT_CALL(v);
    }

    EVE_CALLABLE_OBJECT(eps_t, eps_);
  };
  //======================================================================================================================
  //! @addtogroup constants
  //! @{
  //!   @var eps
  //!   @brief return the epsolute value.
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <kyosu/core.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace kyosu
  //!   {
  //!      template<kyosu::concepts::polyfloat_like T> constexpr auto eps(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the epsolute value of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/eps.cpp}
  //======================================================================================================================

  inline constexpr auto eps = eve::functor<eps_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}
