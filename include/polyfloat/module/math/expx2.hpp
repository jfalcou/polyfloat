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
#include <polyfloat/module/math/expm1.hpp>

namespace plf
{

  template<typename Options> struct expx2_t : eve::elementwise_callable<expx2_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(expx2_t, expx2_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var expx2
  //!   @brief return \f$e^{z^2]\f$.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto expx2(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns \f$e^{z^2]\f$.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/expx2.cpp}
  //======================================================================================================================

  inline constexpr auto expx2 = eve::functor<expx2_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename T, eve::callable_options O> constexpr auto expx2_(POLYFLOAT_DELAY(), O const& o, T a0) noexcept
  {
    if constexpr (dimension_v<T> == 1) return eve::expx2[o](a0);
    else
    {
      if constexpr (O::contains(raw)) return exp[o](eve::sqr(a0));
      else
      {
        if constexpr (eve::platform::supports_invalids && eve::scalar_value<T>)
          if (eve::is_nan(a0)) return a0;
        if constexpr (eve::scalar_value<T> && eve::platform::supports_infinites)
          if (is_infinite(a0)) return inf(as<T>());
        T x = eve::abs(a0);
        using u_t = underlying_type_t<T>;
        u_t const Expx2c1 = ieee_constant<0x1.0000000000000p+7, 0x1.0p+5f>(eve::as<u_t>{});
        u_t const Expx2c2 = ieee_constant<0x1.0000000000000p-7, 0x1.0p-5f>(eve::as<u_t>{});
        /* Represent x as an exact multiple of 1/32 plus a residual.  */
        T m = Expx2c1 * plf::floor(plf::fma(Expx2c2, x, plf::half(as<T>())));
        x -= m;
        /* x**2 = m**2 + 2mf + f**2 */
        T u = plf::sqr(m);
        T u1 = plf::fma(T(2) * m, x, plf::sqr(x));
        /* u is exact, u1 is small.  */
        auto gtmxlg = is_not_less_equal(u + u1, plf::maxlog(eve::as<T>()));
        if constexpr (eve::scalar_value<T>)
        {
          if (gtmxlg) return plf::inf(as<T>());
          return plf::exp[o](u) * plf::exp[o](u1);
        }
        else if constexpr (eve::simd_value<T>)
        {
          T r = plf::if_else(gtmxlg, plf::inf(as<T>()), plf::exp[o](u) * plf::exp[o](u1));
          if constexpr (eve::platform::supports_infinites) r = plf::if_else(plf::is_pinf(x), x, r);
          if constexpr (eve::platform::supports_invalids) r = plf::if_else(plf::is_nan(a0), eve::allbits, r);
          return r;
        }
        return u + u1;
      }
    }
  }
}
