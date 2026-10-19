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
#include <polyfloat/module/math/tan.hpp>

namespace plf
{

  template<typename Options>
  struct atan_t : plf::elementwise_callable<atan_t,
                                            eve::atan_t,
                                            Options,
                                            raw_option,
                                            pedantic_option,
                                            eve::rad_option,
                                            eve::radpi_option,
                                            eve::deg_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(atan_t, atan_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var atan
  //!   @brief return the arctangent value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto atan(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the arctangent of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/atan.cpp}
  //======================================================================================================================

  inline constexpr auto atan = eve::functor<atan_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  // take the absolute value atan(-x) =  -atan(x) -> ax > 0
  // restrain ax to < 1 atan(ax) =  pi/2-atan(1/ax) -> 0 <= axx <= 1
  // restrain axx to [0, sqrt(2)-1] atan(axx) = pi/4 - atan((1-axxx)/(1+axx)) and axxx < sqrt(2)-1
  // use 1 or 2 newton steps to reach precision
  //Perhaps 2 imprvt to see latter
  // 1 treat small values differently
  // 2 the three steps can be progressive T,  double_real_t<T> and triple_real_t<T>
  template<typename T, eve::callable_options O> constexpr auto atan_(POLYFLOAT_DELAY(), O const& o, T a0) noexcept
  {
    if constexpr (O::contains(eve::rad)) return atan[o.drop(rad)](a0);
    else if constexpr (O::contains(eve::deg)) return radindeg(atan[o.drop(eve::deg)](a0));
    else if constexpr (O::contains(eve::radpi)) return radinpi(atan[o.drop(eve::radpi)](a0));
    else
    {
      auto a0pos = plf::is_positive(a0);
      auto ax = plf::abs(a0);
      auto invax = ax > plf::one(eve::as(a0));
      auto axx = plf::rec[eve::pedantic][invax](ax);
      auto thresh = axx > plf::dec(plf::sqrt(T(2)));                        //plf::sqrt_2m1(eve::as(x));
      auto axxx = plf::if_else(thresh, plf::oneminus(axx) / inc(axx), axx); // all lanes are less than sqrt(2)-1)
      T r(eve::atan(plf::hi(axxx)));
      auto t = plf::tan[quarter_circle](r);
      r -= (t - axxx) * plf::rec(plf::inc(plf::sqr(t)));
      if constexpr (dimension_v<T> == 2)
      {
        r = if_else(thresh && invax, pio_4(eve::as(a0)) + r, r);
        r = if_else(thresh && !invax, pio_4(eve::as(a0)) - r, r);
        r = if_else(!thresh && invax, pio_2(eve::as(a0)) - r, r);
        r = if_else(a0pos, r, -r);
        return r;
      }
      else if constexpr (dimension_v<T> == 3)
      {
        t = plf::tan[quarter_circle](r);
        r -= (t - axxx) * plf::rec(plf::inc(plf::sqr(t)));
        r = if_else(thresh && invax, pio_4(eve::as(a0)) + r, r);
        r = if_else(thresh && !invax, pio_4(eve::as(a0)) - r, r);
        r = if_else(!thresh && invax, pio_2(eve::as(a0)) - r, r);
        r = if_else(a0pos, r, -r);
        return r;
      }
    }
  }
  constexpr auto atand = plf::atan[eve::deg];
  constexpr auto atanpi = plf::atan[eve::radpi];

}
