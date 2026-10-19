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
#include <polyfloat/module/math/atan2.hpp>

namespace plf
{

  template<typename Options>
  struct asin_t : plf::elementwise_callable<asin_t, eve::asin_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(asin_t, asin_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var asin
  //!   @brief return the inverse cocose value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto asin(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the inverse cocose of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/asin.cpp}
  //======================================================================================================================

  inline constexpr auto asin = eve::functor<asin_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename T, eve::callable_options O> constexpr auto asin_(POLYFLOAT_DELAY(), O const&, T a0) noexcept
  {
    return plf::atan2(a0, plf::sqrt(oneminus(plf::sqr(a0))));
    //     a0 = plf::if_else(plf::abs(a0) <= plf::one(eve::as(a0)), a0, plf::nan(as(a0)));
    //     T x0(eve::asin(hi(a0)));
    //     std::cout << "a0 " << a0 << std::endl;
    //     //    auto [c, s] = plf::coscos(x0);
    //     auto c = plf::cos(x0);
    //     auto s = plf::sin(x0);
    //     auto x1 = x0 - (s - a0) / c;
    //     c = plf::cos(x1);
    //     s = plf::sin(x1);
    //     x1 -= (s - a0) / c;
    //     if constexpr (dimension_v<T> == 2) return if_else(plf::is_eqz(a0), plf::pio_2(eve::as(a0)), x1);
    //     c = plf::cos(x1);
    //     s = plf::sin(x1);
    //     //    auto [c, s] = plf::sincos(x0);
    //     x1 -= (s - a0) / c;
    //     return x1;
  }
}
