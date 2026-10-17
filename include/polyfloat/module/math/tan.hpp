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
#include <polyfloat/module/math/details/trig_finalize.hpp>
#include <polyfloat/module/math/details/rempio2_limits.hpp>
#include <polyfloat/module/math/details/pio2_reduce.hpp>
#include <polyfloat/module/math/details/rem2.hpp>
#include <polyfloat/module/math/details/rem180.hpp>
#include <polyfloat/module/math/mul_pi.hpp>
#include <polyfloat/module/math/div_180.hpp>
#include <iostream>

namespace plf
{

  template<typename Options>
  struct tan_t : plf::elementwise_callable<tan_t,
                                           eve::tan_t,
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

    POLYFLOAT_CALLABLE_OBJECT(tan_t, tan_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var tan
  //!   @brief return the tanine value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto tan(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the tanine of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/tan.cpp}
  //======================================================================================================================

  inline constexpr auto tan = eve::functor<tan_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename T, eve::callable_options O> constexpr auto tan_(POLYFLOAT_DELAY(), O const& o, T a0) noexcept
  {
    if constexpr (O::contains(eve::deg))
    {
      return plf::tan[eve::radpi](plf::div_180(a0));
    }
    else if constexpr (O::contains(eve::radpi))
    {
      if constexpr (O::contains(eve::quarter_circle))
      {
        return plf::tan[eve::quarter_circle](plf::mul_pi(a0));
      }
      else
      {
        auto x = plf::abs(a0);
        x = plf::if_else(plf::is_not_finite(x), plf::nan(eve::as(x)), x); // nan or Inf input
        x = plf::if_else(plf::is_greater(x, plf::maxflint(eve::as(x))), eve::zero,
                         x); //over maxflint all inputs are even integers
        auto [fn, xr, dxr] = plf::rem2(x);
        return tan_finalize(a0, fn, xr, dxr);
      }
    }
    else
    {
      auto x = plf::abs(a0);
      if constexpr (O::contains(eve::quarter_circle))
      {
        auto r = tancot_eval(x);
        return plf::if_else(plf::is_negative(a0), -r, r);
      }
      else if constexpr (O::contains(eve::half_circle) || O::contains(eve::full_circle) || O::contains(eve::medium))
      {
        auto [fn, xr, dxr] = pio_2_reduce(x);
        return plf::_::tan_finalize(a0, fn, xr, dxr);
      }
      else
      {
        if (eve::all(x <= Rempio2_limit[eve::quarter_circle](eve::as(a0))))
        {
          return plf::tan[eve::quarter_circle](a0);
        }
        else if (eve::all(x <= Rempio2_limit[quarter_circle](as(a0)))) return tan[quarter_circle](a0);
        else if (eve::all(x <= Rempio2_limit[medium](as(a0)))) return tan[medium](a0);
        else
          return plf::tan[eve::medium](
            plf::if_else(is_not_less_equal(x, Rempio2_limit[medium](as(a0))), nan(eve::as(a0)), tan[medium](a0)));
        //else return tan[big](a0); TO DO REPLACE previous line
      }
    }
  }
}

namespace plf
{
  constexpr auto tand = plf::tan[eve::deg];
  constexpr auto tanpi = plf::tan[eve::radpi];
}
