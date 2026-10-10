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
#include <iostream>

namespace plf
{

  template<typename Options>
  struct cos_t : plf::elementwise_callable<cos_t,
                                           eve::cos_t,
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

    POLYFLOAT_CALLABLE_OBJECT(cos_t, cos_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var cos
  //!   @brief return the cosine value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto cos(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the cosine of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/cos.cpp}
  //======================================================================================================================

  inline constexpr auto cos = eve::functor<cos_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename T, eve::callable_options O> constexpr auto cos_(POLYFLOAT_DELAY(), O const&, T a0) noexcept
  {
    //    using e_t =  eve::element_type_t<T>;
    if constexpr (O::contains(eve::deg))
    {
      return plf::cos[eve::radpi](plf::div_180(a0));
    }
    else if constexpr (O::contains(eve::radpi))
    {
      if constexpr (O::contains(eve::quarter_circle))
      {
        return plf::cos[eve::quarter_circle](a0 * plf::pi(eve::as<T>()));
      }
      else
      {
        auto x = plf::abs(a0);
        x = plf::if_else(plf::is_not_finite(x), plf::nan(eve::as(x)), x); // nan or Inf input
        x = plf::if_else(plf::is_greater(x, plf::maxflint(eve::as(x))), eve::zero, x);
        auto [fn, xr, dxr] = plf::_::rem2(x);
        return cos_finalize(fn, xr, dxr);
      }
    }
    else
    {
      if constexpr (O::contains(eve::quarter_circle))
      {
        return cos_eval(a0);
      }
      else if constexpr (O::contains(eve::half_circle) || O::contains(eve::full_circle) || O::contains(eve::medium))
      {
        auto x = plf::abs(a0);
        auto [fn, xr, dxr] = pio_2_reduce(x);
        return cos_finalize(fn, xr, dxr);
      }
      else
      {
        auto x = abs(a0);
        if (eve::all(x <= Rempio2_limit[quarter_circle](as(a0)))) return cos[quarter_circle](a0);
        else if (eve::all(x <= Rempio2_limit[half_circle](as(a0)))) return cos[half_circle](a0);
        else if (eve::all(x <= Rempio2_limit[full_circle](as(a0)))) return cos[full_circle](a0);
        else if (eve::all(x <= Rempio2_limit[medium](as(a0)))) return cos[medium](a0);
        else return cos[big](a0);
      }
    }
  }
}
