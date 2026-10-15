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
#include <polyfloat/module/math/details/sincos_coefs.hpp>
#include <polyfloat/module/math/details/trig_finalize.hpp>
#include <polyfloat/module/math/details/rempio2_limits.hpp>
#include <polyfloat/module/math/details/pio2_reduce.hpp>
#include <polyfloat/module/math/details/rem2.hpp>
#include <polyfloat/module/math/details/rem180.hpp>
#include <polyfloat/module/math/div_180.hpp>
#include <polyfloat/module/math/tan.hpp>

namespace plf
{

  template<typename Options>
  struct cot_t : plf::elementwise_callable<cot_t,
                                           eve::cot_t,
                                           Options,
                                           raw_option,
                                           pedantic_option,
                                           eve::quarter_circle_option,
                                           eve::half_circle_option,
                                           eve::full_circle_option,
                                           eve::medium_option,
                                           eve::big_option,
                                           eve::radpi_option,
                                           eve::deg_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(cot_t, cot_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var cot
  //!   @brief return the cotangent value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto cot(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the cotangent of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/cot.cpp}
  //======================================================================================================================

  inline constexpr auto cot = eve::functor<cot_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename T, eve::callable_options O> constexpr auto cot_(POLYFLOAT_DELAY(), O const& o, T a0) noexcept
  {
    auto x = abs(a0);
    if constexpr (O::contains(eve::deg))
    {
      return plf::tan[eve::radpi](plf::div_180(a0));
    }
    else if constexpr (O::contains(eve::radpi))
    {
      if constexpr (O::contains(eve::quarter_circle))
      {
        x = plf::if_else(plf::is_not_less_equal(x, T(0.25)), plf::nan(eve::as(x)), x);
        auto r = plf::rec[eve::pedantic](tancot_eval(plf::mul_pi(x)));
        return plf::if_else(plf::is_negative(a0), -r, r);
      }
      else
      {
        if (eve::all(x <= T(0.25))) return plf::cot[eve::radpi][eve::quarter_circle](a0);
        x = plf::if_else(plf::is_not_finite(a0) || plf::is_flint(x), plf::nan(eve::as(a0)), x);
        auto [fn, xr, dxr] = plf::rem2(x);
        return cot_finalize(a0, plf::quadrant(fn), xr, dxr);
      }
    }
    else
    {
      if constexpr (O::contains(eve::quarter_circle))
      {
        auto aa0nlepio4 = is_not_less_equal(x, pio_4(eve::as<T>()));
        auto r = tancot_eval(x);
        r = plf::if_else(plf::is_negative(a0), -r, r);
        return plf::if_else(aa0nlepio4, plf::nan(eve::as(a0)), plf::rec[eve::pedantic](r));
      }
      else
      {
        if (eve::all(x <= Rempio2_limit[eve::quarter_circle](eve::as(a0))))
        {
          return plf::cot[eve::quarter_circle](a0);
          ;
        }
        else if constexpr (O::contains(eve::half_circle) || O::contains(eve::full_circle) || O::contains(eve::medium))
        {
          auto [fn, xr, dxr] = pio_2_reduce(x);
          return cot_finalize(a0, fn, xr, dxr);
        }
        else
          return plf::cot[eve::medium](
            plf::if_else(plf::is_not_less_equal(x, plf::Rempio2_limit[eve::medium](as(a0))), nan(eve::as(a0)), a0));
        //       else
        //         return cot[big](a0); TO DO REPLACE previous line
      }
    }
  }
}

namespace plf
{
  constexpr auto cotd = plf::cot[eve::deg];
  constexpr auto cotpi = plf::cot[eve::radpi];
}
