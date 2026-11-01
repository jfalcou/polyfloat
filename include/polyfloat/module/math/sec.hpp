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
#include <polyfloat/module/math/cos.hpp>

namespace plf
{

  template<typename Options>
  struct sec_t : plf::elementwise_callable<sec_t,
                                           eve::sec_t,
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
    template<concepts::polyfloat_like Z> POLYFLOAT_ABI constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(sec_t, sec_);
  };
  //======================================================================================================================
  //! @addtogroup math
  //! @{
  //!   @var sec
  //!   @brief return the secant value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto sec(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the secant of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/math/sec.cpp}
  //======================================================================================================================

  inline constexpr auto sec = eve::functor<sec_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename T, eve::callable_options O> constexpr auto sec_(POLYFLOAT_DELAY(), O const& o, T a0) noexcept
  {
    if constexpr (O::contains(eve::radpi))
    {
      if constexpr (O::contains(eve::quarter_circle))
      {
        auto x = abs(a0);
        auto test = plf::is_not_less_equal(x, T(0.25));
        a0 = plf::if_else(test, plf::nan(eve::as(a0)), a0);
        a0 *= plf::pi(eve::as<T>());
        auto x2 = plf::sqr(a0);
        return plf::rec[eve::pedantic](cos_eval(x2));
      }
      else
      {
        auto x = plf::abs(a0);
        auto z = plf::cospi[o](x);
        return plf::if_else(plf::is_nez(z) && plf::is_finite(a0), plf::rec[eve::pedantic](z), plf::nan(as(a0)));
      }
    }
    else if constexpr (O::contains(eve::deg))
    {
      if constexpr (O::contains(eve::quarter_circle)) return plf::rec[pedantic](plf::cos[eve::deg][o](a0));
      else
      {
        auto a0_180 = plf::div_180(a0);
        auto test = plf::is_not_flint(a0_180) && plf::is_flint(a0_180 + plf::mhalf(eve::as(a0_180)));
        return plf::if_else(test, plf::nan(eve::as(a0)), plf::rec[eve::pedantic](plf::cos[eve::deg][o](a0)));
      }
    }
    else return plf::rec[eve::pedantic](plf::cos[o](a0));
  }
}

namespace plf
{
  constexpr auto secd = plf::sec[eve::deg];
  constexpr auto secpi = plf::sec[eve::radpi];
}
