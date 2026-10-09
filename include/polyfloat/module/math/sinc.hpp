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

namespace plf
{

  template<typename Options>
  struct sinc_t : eve::elementwise_callable<sinc_t,
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

    POLYFLOAT_CALLABLE_OBJECT(sinc_t, sinc_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var sinc
  //!   @brief return the sine cardinal value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto sinc(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the sine cardinal of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/sinc.cpp}
  //======================================================================================================================

  inline constexpr auto sinc = eve::functor<sinc_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename T, eve::callable_options O> constexpr auto sinc_(POLYFLOAT_DELAY(), O const& o, T a0) noexcept
  {
    using elt_t = eve::element_type_t<T>;
    if constexpr (dimension_v<T> == 1) return eve::sinc[o](a0);
    else if constexpr (O::contains(eve::deg))
    {
      return plf::sinc[eve::radpi](plf::div_180(a0));
    }
    else if constexpr (O::contains(eve::radpi))
    {
      return sinc[o](pi(eve::as<elt_t>()) * a0);
    }
    else
    {
      if constexpr (O::contains(eve::quarter_circle))
      {
        return sinc_eval(plf::sqr(a0));
      }
      else if constexpr (O::contains(eve::half_circle) || O::contains(eve::full_circle) || O::contains(eve::medium))
      {
        auto [fn, xr, dxr] = pio_2_reduce(plf::abs(a0));
        auto x = plf::abs(a0);
        auto r = plf::_::sin_finalize(a0, fn, xr, dxr) / a0;
        r = plf::if_else(plf::is_infinite(x), eve::zero(as(x)), r);
        return plf::if_else(x < plf::eps(eve::as<elt_t>()), plf::one(eve::as(a0)), r);
      }
      else
      {
        auto x = plf::abs(a0);
        if (eve::all(x <= plf::Rempio2_limit[quarter_circle](as(a0)))) return sinc[quarter_circle](a0);
        else if (eve::all(x <= plf::Rempio2_limit[half_circle](as(a0)))) return sinc[half_circle](a0);
        else if (eve::all(x <= plf::Rempio2_limit[full_circle](as(a0)))) return sinc[full_circle](a0);
        else if (eve::all(x <= plf::Rempio2_limit[medium](as(a0)))) return sinc[medium](a0);
        else
        {
          auto r = sin[big](a0) / a0;
          r = if_else(plf::is_infinite(x), zero(eve::as(x)), r);
          return plf::if_else(x < plf::eps(eve::as<elt_t>()), plf::one(eve::as(a0)), r);
        }
      }
    }
  }
}
