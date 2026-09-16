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
#include <polyfloat/module/math/constants/log_10.hpp>

namespace plf
{

  template<typename Options>
  struct pow_abs_t : eve::elementwise_callable<pow_abs_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z1, Z z2) const noexcept
    {
      return POLYFLOAT_CALL(z1, z2);
    }

    POLYFLOAT_CALLABLE_OBJECT(pow_abs_t, pow_abs_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var pow_abs
  //!   @brief return \f$|x|^y\f$.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constpow_absr auto pow_abs(T x, T x) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns \f$|x|^y\f$.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/pow_abs.cpp}
  //======================================================================================================================

  inline constexpr auto pow_abs = eve::functor<pow_abs_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<typename T, typename U, eve::callable_options O>
  constexpr auto pow_abs_(POLYFLOAT_DELAY(), O const& o, T a, U b) noexcept
  {
    using r_t = as_polyfloat_like_t<T, U>;
    using e_t = eve::element_type_t<r_t>;
    using u_t = eve::underlying_type_t<r_t>;
    auto cvt = [](auto a) { return plf::convert(a, eve::as<e_t>()); };
    if constexpr (dimension_v<T> == 1) return eve::pow_abs[o](a, b);
    else
    {
      auto x = cvt(a);
      auto y = cvt(b);
      auto iseqzx = plf::is_eqz(x);
      auto ylt0 = y < plf::zero(as(y));
      auto ax = plf::abs(x);
      auto ax_is1 = plf::is_unit(ax);
      auto const largelimit = (sizeof(u_t) == 4 ? 31 : 63);
      auto [yf, yi] = plf::modf(plf::abs(y));
      auto test = yf > r_t(0.5);
      yf = dec[test](yf);
      auto z = plf::exp[o](yf * plf::log[o](ax));
      yi = inc[test](yi);
      yi = if_else(ax_is1, eve::one, yi);
      auto large = (yi > r_t(largelimit));
      yi = if_else(large, eve::one, yi);

      auto russian = [](auto base, auto rexpo) {
        r_t result(1);
        auto expo(rexpo);
        while (eve::any(is_nez(expo)))
        {
          result *= if_else(is_odd(expo), base, eve::one);
          expo = eve::trunc(expo / 2);
          base = sqr(base);
        }
        return result;
      };
      if constexpr (!O::contains(raw)) yi = if_else(is_not_finite(yi), eve::zero, yi);
      z *= russian(ax, hi(yi));
      z = if_else(large, if_else(ax < one(as(x)), zero, inf(as(x))), z);
      z = if_else(iseqzx && ylt0, zero, z);
      z = if_else(is_infinite(ax), inf(as(x)), z);
      z = if_else(ylt0, plf::rec(z), z);
      z = if_else(ax_is1 || is_eqz(y), one, z);
      z = if_else(iseqzx && is_gtz(y), zero, z);
      z = if_else(is_nan(x) && is_nan(y), allbits, z);
      return z;
    }
  }
}
