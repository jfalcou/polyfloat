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
  struct sincos_t : plf::elementwise_callable<sincos_t,
                                              eve::sincos_t,
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
    template<concepts::polyfloat_like Z>
    POLYFLOAT_FORCEINLINE constexpr eve::zipped<Z, Z> operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(sincos_t, sincos_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var sincos
  //!   @brief return the sine and cosine values.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto sincos(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the sine and cosine of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/sincos.cpp}
  //======================================================================================================================

  inline constexpr auto sincos = eve::functor<sincos_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename T, eve::callable_options O> constexpr auto sincos_(POLYFLOAT_DELAY(), O const&, T a0) noexcept
  {
    if constexpr (O::contains(eve::deg))
    {
      if constexpr (O::contains(quarter_circle))
      {
        return plf::sincos[eve::radpi][quarter_circle](plf::div_180(a0));
      }
      else
      {
        auto x = eve::abs(a0);
        if (eve::all(x <= T(45))) return plf::sincos[eve::deg][eve::quarter_circle](x);
        auto [fn, xr, dxr] = rem180(x);
        return sincos_finalize(a0, fn, xr, dxr);
      }
    }
    else if constexpr (O::contains(eve::radpi))
    {
      if constexpr (O::contains(quarter_circle))
      {
        return eve::sincos_kernel[quarter_circle](a0 * pi(eve::as<T>()));
      }
      else
      {
        auto x = eve::abs(a0);
        auto nn = kumi::tuple(plf::nan(eve::as(x)));
        auto zz = kumi::tuple(plf::zero(eve::as(x)));
        x = plf::if_else(plf::is_not_finite(x), nn, x); // nan or Inf input
        x = plf::if_else(plf::is_greater(x, plf::maxflint(eve::as(x))), zz, x);
        auto [fn, xr, dxr] = rem2(x);
        return sincos_finalize(fn, xr, dxr);
      }
    }
    else
    {
      if constexpr (O::contains(eve::quarter_circle))
      {
        auto a02 = plf::sqr(a0);
        return kumi::tuple{sin_eval(a02, a0), cos_eval(a02)};
      }
      else if constexpr (O::contains(eve::half_circle) || O::contains(eve::full_circle) || O::contains(eve::medium))
      {
        auto [fn, xr, dxr] = pio_2_reduce(plf::abs(a0));
        return plf::_::sincos_finalize(a0, fn, xr, dxr);
      }
      else
      {
        auto x = abs(a0);
        if (eve::all(x <= Rempio2_limit[quarter_circle](as(a0)))) return sincos[quarter_circle](a0);
        else if (eve::all(x <= Rempio2_limit[half_circle](as(a0)))) return sincos[half_circle](a0);
        else if (eve::all(x <= Rempio2_limit[full_circle](as(a0)))) return sincos[full_circle](a0);
        else if (eve::all(x <= Rempio2_limit[medium](as(a0)))) return sincos[medium](a0);
        else return sincos[big](a0);
      }
    }
  }
}
