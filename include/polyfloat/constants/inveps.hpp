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

  template<typename Options> struct inveps_t : eve::constant_callable<inveps_t, Options>
  {
   template<typename T>
    static POLYFLOAT_FORCEINLINE constexpr auto value(eve::as<T> const&, auto const&)
    {
      using u_t = eve::underlying_type_t<T>;
      if constexpr(std::integral<T>        )
        return T(1);
      else if constexpr(plf::dimension_v<T> == 1)
      {
        if constexpr(std::same_as<T, eve::float16_t>) return T(0x1p10);
        else if constexpr(std::same_as<T, float>  ) return T(0x1p23);
        else if constexpr(std::same_as<T, double> ) return T(0x1p52);
      }
      else if constexpr(plf::dimension_v<T> == 2)
      {
        if constexpr(std::same_as<T, eve::float16_t>) return T(0x1p20);
        else if constexpr(std::same_as<T, float>  ) return T(0x1p46);
        else if constexpr(std::same_as<T, double> ) return T(0x1p104);
      }
      else if constexpr(plf::dimension_v<T> == 3)
      {
        if constexpr(std::same_as<T, eve::float16_t>) return T(0x1p30);
        else if constexpr(std::same_as<T, float>  ) return T(0x1p69);
        else if constexpr(std::same_as<T, double> ) return T(0x1p156);
      }
    }

    template<concepts::polyfloat_like T>
    POLYFLOAT_FORCEINLINE constexpr eve::underlying_type_t<T> operator()(as<T> const& v) const
    {
      return POLYFLOAT_CALL(v);
    }

    POLYFLOAT_CALLABLE_OBJECT(inveps_t, inveps_);
  };
  //======================================================================================================================
  //! @addtogroup constants
  //! @{
  //!   @var inveps
  //!   @brief return the invepsolute value.
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <kyosu/functions.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace kyosu
  //!   {
  //!      template<kyosu::concepts::polyfloat_like T> constexpr auto inveps(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!
  //!   **Return value**
  //!
  //!     Returns the inverse of the machine precision in the given type.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/inveps.cpp}
  //======================================================================================================================

  inline constexpr auto inveps = eve::functor<inveps_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}
