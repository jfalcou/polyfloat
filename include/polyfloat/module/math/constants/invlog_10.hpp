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

  template<typename Options> struct invlog_10_t : eve::constant_callable<invlog_10_t, Options>
  {
    template<typename T>
    static POLYFLOAT_FORCEINLINE constexpr T value(eve::as<T> const&, auto const&)
    {
      using u_t = plf::as_component_type_t<T>;
      if constexpr(plf::dimension_v<T> == 1)
      {
        if constexpr(std::same_as<u_t, float>  ) return float(0x1.26bb1cp+1);
        else if constexpr(std::same_as<u_t, double> ) return double(0x1.26bb1bbb55516p+1);
      }
      else if constexpr(plf::dimension_v<T> == 2)
      {
        if constexpr(std::same_as<u_t, float>  ) return plf::_::from_pair<float>(0x1.bcb7b2p-2,  -0x1.5b235ep-27);
        else if constexpr(std::same_as<u_t, double> ) return plf::_::from_pair<double>(0x1.bcb7b1526e50ep-2,  0x1.95355baaafad3p-57);
      }
      else if constexpr(plf::dimension_v<T> == 3)
      {
        if constexpr(std::same_as<u_t, float>  ) return plf::_::from_triple<float>(0x1.bcb7b2p-2,  -0x1.5b235ep-27,  -0x1.cd5954p-54);
        else if constexpr(std::same_as<u_t, double> ) return plf::_::from_triple<double>(0x1.bcb7b1526e50ep-2,  0x1.95355baaafad3p-57,  0x1.ee191f71a3012p-112);

      }
    }

    template<concepts::polyfloat_like T>
    POLYFLOAT_FORCEINLINE constexpr T operator()(as<T> const& v) const
    {
      return POLYFLOAT_CALL(v);
    }

    POLYFLOAT_CALLABLE_OBJECT(invlog_10_t, invlog_10_);
  };
  //======================================================================================================================
  //! @addtogroup constants
  //! @{
  //!   @var invlog_10
  //!   @brief return the log(2) value.
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
  //!      template<kyosu::concepts::polyfloat_like T> constexpr auto invlog_10(T z) noexcept;
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
  //!  @godbolt{doc/invlog_10.cpp}
  //======================================================================================================================

  inline constexpr auto invlog_10 = eve::functor<invlog_10_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}
