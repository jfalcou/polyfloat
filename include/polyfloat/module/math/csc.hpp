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
#include <polyfloat/module/math/sin.hpp>

namespace plf
{

  template<typename Options>
  struct csc_t : plf::elementwise_callable<csc_t,
                                           eve::csc_t,
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

    POLYFLOAT_CALLABLE_OBJECT(csc_t, csc_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var csc
  //!   @brief return the cosecant value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto csc(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the cosecant of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/csc.cpp}
  //======================================================================================================================

  inline constexpr auto csc = eve::functor<csc_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename T, eve::callable_options O> constexpr auto csc_(POLYFLOAT_DELAY(), O const& o, T a0) noexcept
  {
    if constexpr (O::contains(eve::radpi))
    {
      T x = plf::abs(a0);
      x = plf::if_else(plf::is_nez(a0) && (plf::is_not_finite(x) || plf::is_flint(x)), plf::nan(eve::as(x)), x);
      auto [fn, xr, dxr] = plf::rem2(x);
      return plf::if_else(plf::is_eqz(x), plf::nan(eve::as(x)),
                          plf::rec[pedantic](sin_finalize(a0, plf::quadrant(fn), xr, dxr)));
    }
    else if constexpr (O::contains(eve::deg))
    {
      if constexpr (O::contains(eve::quarter_circle)) return plf::rec[eve::pedantic](plf::sin[eve::deg][o](a0));
      else
      {
        auto a0_180 = plf::div_180(a0);
        auto test = plf::is_nez(a0_180) && plf::is_flint(a0_180);
        return plf::if_else(test, plf::nan(eve::as(a0)), plf::rec[eve::pedantic](plf::sin[eve::deg][o](a0)));
      }
    }
    else return plf::rec[pedantic](plf::sin[o](a0));
  }
}

namespace plf
{
  constexpr auto cscd = plf::csc[eve::deg];
  constexpr auto cscpi = plf::csc[eve::radpi];
}
