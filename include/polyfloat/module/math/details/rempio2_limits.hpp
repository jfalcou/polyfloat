//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once
#include <eve/module/math/decorator/math.hpp>

namespace plf
{
  template<typename Options>
  struct Rempio2_limit_t : eve::elementwise_callable<Rempio2_limit_t,
                                                     Options,
                                                     eve::quarter_circle_option,
                                                     eve::half_circle_option,
                                                     eve::full_circle_option,
                                                     eve::medium_option,
                                                     eve::big_option>
  {
    template<concepts::polyfloat_like T> constexpr EVE_FORCEINLINE T operator()(as<T> v) const
    {
      return EVE_DISPATCH_CALL(v);
    }

    EVE_CALLABLE_OBJECT(Rempio2_limit_t, Rempio2_limit_);
  };

  inline constexpr auto Rempio2_limit = eve::functor<Rempio2_limit_t>;

  namespace _
  {
    template<typename T, eve::callable_options O>
    EVE_FORCEINLINE constexpr T Rempio2_limit_(POLYFLOAT_DELAY(), O const&, eve::as<T> const& at) noexcept
    {
      if constexpr (dimension_v<T> == 1) return eve::Rempio2_limit(at);
      else if constexpr (concepts::polyfloat_like<T>)
      {
        if constexpr (O::contains(eve::quarter_circle)) return plf::prev(pio_4(eve::as<T>()));
        else if constexpr (O::contains(eve::half_circle)) return plf::prev(pio_2(eve::as<T>()));
        else if constexpr (O::contains(eve::full_circle)) return plf::prev(pi(eve::as<float>()));
        else if constexpr (O::contains(eve::medium))
          return ieee_constant<0x1.6bcc41e900000p+47, 0x1.9220e60p+50f>(eve::as<T>{}); // 1.76858e+15,  2.0e14
        else return plf::valmax(eve::as<T>());
      }
      else return plf::valmax(eve::as<T>());
    }
  }
}
