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

  template<typename Options> struct log_2_t : eve::constant_callable<log_2_t, Options>
  {
    template<typename T>
    static POLYFLOAT_FORCEINLINE constexpr T value(eve::as<T> const&, auto const&)
    {
      using u_t = plf::as_component_type_t<T>;
      if constexpr(plf::dimension_v<T> == 1)
      {
        if constexpr(std::same_as<u_t, float>  ) return float(0x1.62e43p-1);
        else if constexpr(std::same_as<u_t, double> ) return double(0x1.62e42fefa39efp-1);
      }
      else if constexpr(plf::dimension_v<T> == 2)
      {
        if constexpr(std::same_as<u_t, float>  ) return plf::_::from_pair<float>(0x1.62e43p-1,  -0x1.05c61p-29);
        else if constexpr(std::same_as<u_t, double> ) return plf::_::from_pair<double>(0x1.62e42fefa39efp-1,  0x1.abc9e3b39803fp-56);

      }
      else if constexpr(plf::dimension_v<T> == 3)
      {
        if constexpr(std::same_as<u_t, float>  ) return plf::_::from_triple<float>(0x1.62e43p-1,  -0x1.05c61p-29,  -0x1.950d88p-54);
        else if constexpr(std::same_as<u_t, double> ) return plf::_::from_triple<double>(0x1.62e42fefa39efp-1,  0x1.abc9e3b39803fp-56,  0x1.7b57a079a1934p-111);
      }
    }

    template<concepts::polyfloat_like T>
    POLYFLOAT_FORCEINLINE constexpr T operator()(as<T> const& v) const
    {
      return POLYFLOAT_CALL(v);
    }

    POLYFLOAT_CALLABLE_OBJECT(log_2_t, log_2_);
  };
  //======================================================================================================================
  //! @addtogroup constants
  //! @{
  //!   @var log_2
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
  //!      template<kyosu::concepts::polyfloat_like T> constexpr auto log_2(T z) noexcept;
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
  //!  @godbolt{doc/log_2.cpp}
  //======================================================================================================================

  inline constexpr auto log_2 = eve::functor<log_2_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}
