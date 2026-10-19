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
  struct atan2_t : plf::elementwise_callable<atan2_t, eve::atan2_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z0, concepts::polyfloat_like Z1>
    POLYFLOAT_FORCEINLINE constexpr plf::as_polyfloat_like_t<Z0, Z1> operator()(Z0 z0, Z1 z1) const noexcept
    {
      return POLYFLOAT_CALL(z0, z1);
    }

    POLYFLOAT_CALLABLE_OBJECT(atan2_t, atan2_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var atan2
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto atan2(T z) noexcept;           //1
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto atan2[pedantic](T z) noexcept; //2
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `x, y`: Value to process.
  //!
  //!   **Return value**
  //!
  //!    1. The arc tangent of \f$\frac{y}x\f$  in the radian range \f$[-\pi , +\pi]\f$ (1.a) , is returned.
  //!       (converted in degrees (1.b) or in   \f$[\pi\f$ multiples (1.c))
  //!       For 1.a The **IEEE** limiting values are almost all satisfied :
  //!
  //!         *  If `x` and `y` are both zero or infinites, Nan is returned (this is not standard conforming)
  //!         *  If `y` is \f$\pm0\f$ and `x` is strictly negative or \f$-0\f$, \f$\pm\pi\f$ is returned
  //!         *  If `y` is \f$\pm0\f$ and `x` is strictly positive or \f$+0\f$, \f$\pm0\f$ is returned
  //!         *  If `y` is \f$\pm\infty\f$ and `x` is finite, \f$\pm\frac\pi2\f$ is returned
  //!         *  If `x` is \f$\pm0\f$ and `y` is strictly negative, \f$-\frac\pi2\f$ is returned
  //!         *  If `x` is \f$\pm0\f$ and `y` is strictly positive, \f$+\frac\pi2\f$  is returned
  //!         *  If `x` is \f$-\infty\f$ and `y` is finite and positive, \f$+\pi\f$ is returned
  //!         *  If `x` is \f$-\infty\f$ and `y` is finite and negative, \f$-\pi\f$ is returned
  //!         *  If `x` is \f$+\infty\f$ and `y` is finite and positive, \f$+0\f$ is returned
  //!         *  If `x` is \f$+\infty\f$ and `y` is finite and negative, \f$-0\f$ is returned
  //!         *  If either `x` is Nan or `y` is Nan, Nan is returned
  //!
  //!    The call will return a NaN if `x` and `y` are both either null or infinite: this result is
  //!    not **IEEE** conformant, but allows to simplify (and speed up) the implementation.
  //!    In all other cases, the result is standard conformant.  And the converted equivalent are returned with the other units.
  //!    2. Same as 1, except that all **IEEE** limiting values are satisfied :
  //!      *  If `y` is \f$\pm\infty\f$ and `x` is \f$-\infty\f$, \f$\pm\frac{3\pi}4\f$ is returned
  //!      *  If `y` is \f$\pm\infty\f$ and `x` is \f$+\infty\f$, \f$\pm\frac{\pi}4\f$ is returned
  //!      *  If `x` is \f$\pm0\f$ and `y` is \f$\pm-0\f$, \f$-\frac\pi2\f$ is returned
  //!      *  If `x` is \f$\pm0\f$ and `y` is \f$\pm+0\f$, \f$+\frac\pi2\f$  is returned
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/atan2.cpp}
  //======================================================================================================================

  inline constexpr auto atan2 = eve::functor<atan2_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename T, typename U, eve::callable_options O>
  constexpr auto atan2_(POLYFLOAT_DELAY(), O const&, T a0, U a1) noexcept
  {
    using r_t = plf::as_polyfloat_like_t<T, U>;
    using elt_t = eve::element_type_t<r_t>;
    auto cvt = [](auto a) { return plf::convert(a, eve::as<elt_t>()); };
    r_t a00 = cvt(a0);
    r_t a10 = cvt(a1);
    if constexpr (O::contains(pedantic))
    {
      if constexpr (eve::scalar_value<r_t> && eve::platform::supports_nans)
      {
        if (plf::is_unordered(a00, a10)) return plf::nan(eve::as(a00));
      }
      if constexpr (eve::platform::supports_infinites)
      {
        auto test1 = plf::is_infinite(a00) && plf::is_infinite(a10);
        a00 = plf::if_else(test1, plf::copysign(one(eve::as(a00)), a00), a00);
        a10 = plf::if_else(test1, plf::copysign(one(eve::as(a00)), a10), a10);
      }
      auto q = plf::abs(a00 / a10);
      r_t z = plf::atan(q);
      r_t sgn = signnz(a00);
      z = plf::if_else(plf::is_positive(a10), z, plf::pi(eve::as(a0)) - z) * sgn;
      z =
        plf::if_else(plf::is_eqz(a00), plf::if_else(plf::is_negative(a10), plf::pi(eve::as(a00)) * sgn, plf::zero), z);
      if constexpr (eve::platform::supports_nans) return plf::if_else(is_unordered(a00, a10), plf::allbits, z);
      else return z;
    }
    else
    {
      auto q = plf::abs(a00 / a10);
      auto z = plf::atan(q);
      return if_else(is_positive(a10), z, (pi(eve::as(a00)) - z)) * signnz(a00);
    }
  }

  //   constexpr auto atan2d = plf::atan2[eve::deg];
  //   constexpr auto atan2pi= plf::atan2[eve::radpi];

}
