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
#include <iostream>

namespace plf
{

  template<typename Options> struct euler_t : eve::constant_callable<euler_t, Options>
  {
    template<typename T>
    static POLYFLOAT_FORCEINLINE constexpr T value(eve::as<T> const&, auto const&)
    {
      using u_t = plf::as_component_type_t<T>;
      if constexpr(plf::dimension_v<T> == 1)
      {
        std::cout << "---1" << std::endl;
        if constexpr(std::same_as<u_t, float>  ) return float(0x1.5bf0a8p+1);
        else if constexpr(std::same_as<u_t, double> ) return double(0x1.5bf0a8b145769p+1);
      }
      else if constexpr(plf::dimension_v<T> == 2)
      {
        std::cout << "---2" << std::endl;
        if constexpr(std::same_as<u_t, float>  ) return plf::_::from_pair<float>(0x1.5bf0a8p+1, 0x1.628aeep-24);
        else if constexpr(std::same_as<u_t, double> ) return plf::_::from_pair<double>(0x1.5bf0a8b145769p+1, 0x1.4d57ee2b1013ap-53);
      }
      else if constexpr(plf::dimension_v<T> == 3)
      {
        std::cout << "---3" << std::endl;
        if constexpr(std::same_as<u_t, float>  ) return plf::_::from_triple<float>(0x1.5bf0a8p+1, 0x1.628aeep-24, - 0x1.ab2a82p-49);
        else if constexpr(std::same_as<u_t, double> ) return plf::_::from_triple<double>(0x1.5bf0a8b145769p+1, 0x1.4d57ee2b1013ap-53, -0x1.618713a31d3e2p-109);
      }
    }

    template<concepts::polyfloat_like T>
    POLYFLOAT_FORCEINLINE constexpr T operator()(as<T> const& v) const
    {
      return POLYFLOAT_CALL(v);
    }

    POLYFLOAT_CALLABLE_OBJECT(euler_t, euler_);
  };
  //======================================================================================================================
  //! @addtogroup constants
  //! @{
  //!   @var euler
  //!   @brief return the exp(1) value.
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
  //!      template<kyosu::concepts::polyfloat_like T> constexpr auto euler(T z) noexcept;
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
  //!  @godbolt{doc/euler.cpp}
  //======================================================================================================================

  inline constexpr auto euler = eve::functor<euler_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}
