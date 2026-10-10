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

namespace plf
{

  template<typename Options>
  struct sin_t : plf::elementwise_callable<sin_t,
                                           eve::sin_t,
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

    POLYFLOAT_CALLABLE_OBJECT(sin_t, sin_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var sin
  //!   @brief return the sine value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto sin(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the sine of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/sin.cpp}
  //======================================================================================================================

  inline constexpr auto sin = eve::functor<sin_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename T, eve::callable_options O> constexpr auto sin_(POLYFLOAT_DELAY(), O const&, T a0) noexcept
  {
    if constexpr (O::contains(eve::deg))
    {
      return plf::sin[eve::radpi](plf::div_180(a0));
    }
    else if constexpr (O::contains(eve::radpi))
    {
      if constexpr (O::contains(quarter_circle))
      {
        return eve::sin_kernel[quarter_circle](a0 * pi(eve::as<T>()));
      }
      else
      {
        auto x = plf::abs(a0);
        x = plf::if_else(plf::is_not_finite(x), plf::nan(eve::as(x)), x); // nan or Inf input
        x = plf::if_else(plf::is_greater(x, plf::maxflint(eve::as(x))), eve::zero, x);
        auto [fn, xr, dxr] = plf::rem2(x);
        return sin_finalize(a0, fn, xr, dxr);
      }
    }
    else
    {
      if constexpr (O::contains(eve::quarter_circle))
      {
        return sin_eval(plf::sqr(a0), a0);
      }
      else if constexpr (O::contains(eve::half_circle) || O::contains(eve::full_circle) || O::contains(eve::medium))
      {
        auto [fn, xr, dxr] = pio_2_reduce(plf::abs(a0));
        return plf::_::sin_finalize(a0, fn, xr, dxr);
      }
      else
      {
        auto x = abs(a0);
        if (eve::all(x <= Rempio2_limit[quarter_circle](as(a0)))) return sin[quarter_circle](a0);
        else if (eve::all(x <= Rempio2_limit[half_circle](as(a0)))) return sin[half_circle](a0);
        else if (eve::all(x <= Rempio2_limit[full_circle](as(a0)))) return sin[full_circle](a0);
        else if (eve::all(x <= Rempio2_limit[medium](as(a0)))) return sin[medium](a0);
        else return sin[big](a0);
      }
    }
  }
}
