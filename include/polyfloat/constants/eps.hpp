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
      if constexpr(std::integral<T>        )
        return T(1);
      else if constexpr(plf::dimension_v<T> == 1)
        return  eve::eps(eve::as<u_t>());  //(sizeof(u_t) == 4 ? 2.384185791015625e-07f:  2.220446049250313e-16);
      else if constexpr(plf::dimension_v<T> == 2)
      {
        if constexpr(std::same_as<T, eve::float16_t>) return T(0x1p-20);
        else if constexpr(std::same_as<T, float>  ) return T(0x1p-46);
        else if constexpr(std::same_as<T, double> ) return T(0x1p-104);
      }
      //return (sizeof(u_t) == 4 ? 2.842170943040401e-14f :  3.388131789017201e-21);
      else if constexpr(plf::dimension_v<T> == 3)
      {
        if constexpr(std::same_as<T, eve::float16_t>) return T(0x1p-30);
        else if constexpr(std::same_as<T, float>  ) return T(0x1p-69);
        else if constexpr(std::same_as<T, double> ) return T(0x1p-156);
      }
      //  return (sizeof(u_t) == 4 ? 2.465190328815662e-32f :  2.736911063134408e-48); ;
    }

    template<concepts::polyfloat_like T>
    POLYFLOAT_FORCEINLINE constexpr eve::underlying_type_t<T> operator()(as<T> const& v) const
    {
      return POLYFLOAT_CALL(v);
    }

    POLYFLOAT_CALLABLE_OBJECT(eps_t, eps_);
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
  //!   #include <kyosu/functions.hpp>
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
