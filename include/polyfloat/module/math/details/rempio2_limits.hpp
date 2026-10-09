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
#include <type_traits>
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
    template<concepts::polyfloat_like T> constexpr POLYFLOAT_FORCEINLINE T operator()(as<T> v) const
    {
      return POLYFLOAT_CALL(v);
    }

    POLYFLOAT_CALLABLE_OBJECT(Rempio2_limit_t, Rempio2_limit_);
  };

  inline constexpr auto Rempio2_limit = eve::functor<Rempio2_limit_t>;
}

namespace plf::_
{
  template<typename T, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr T Rempio2_limit_(POLYFLOAT_DELAY(), O const&, eve::as<T> const& at) noexcept
  {
    if constexpr (dimension_v<T> == 1) return eve::Rempio2_limit(at);
    else if constexpr (concepts::polyfloat_like<T>)
    {
      if constexpr (O::contains(eve::quarter_circle)) return plf::prev(pio_4(eve::as<T>()));
      else if constexpr (O::contains(eve::half_circle)) return plf::prev(pio_2(eve::as<T>()));
      else if constexpr (O::contains(eve::full_circle)) return plf::prev(pi(eve::as<T>()));
      else if constexpr (O::contains(eve::medium)) return T(0x1.9220e60p+50);
      //        return ieee_constant<0x1.6bcc41e900000p+47, 0x1.9220e60p+50f>(eve::as<u_t>{}); // 1.76858e+15,  2.0e14
      else return plf::valmax(eve::as<T>());
    }
    else return plf::valmax(eve::as<T>());
  }
}
