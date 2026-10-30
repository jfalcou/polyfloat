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
#include <polyfloat/module/core/minus.hpp>
#include <polyfloat/module/core/is_negative.hpp>
#include <polyfloat/types/triple_real.hpp>
#include <polyfloat/types/double_real.hpp>

namespace plf
{

  template<typename Options> struct sqr_t : plf::callable<sqr_t, eve::sqr_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_ABI constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(sqr_t, sqr_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var sqr
  //!   @brief return the square value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto sqr(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the square of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/sqr.cpp}
  //======================================================================================================================

  inline constexpr auto sqr = eve::functor<sqr_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<typename Z, eve::callable_options O> constexpr auto sqr_(POLYFLOAT_DELAY(), O const&, Z const& z) noexcept
  {
    if constexpr (dimension_v<Z> == 2)
    {
      auto [xh, xl] = z;
      auto [p00, e00] = eve::two_prod(xh, xh);
      auto p0 = p00;
      e00 = eve::fma(xh, xl + xl, e00);
      auto [p, e] = eve::two_add[raw](p00, e00);
      auto test = eve::is_not_finite(p + e);
      return plf::if_else(test, Z(p0), plf::_::from_pair(p, e));

      //      auto [zhi, zlo] = z;
      //       auto [p1, p2] = eve::two_prod(zhi, zhi);
      //       p2 += 2 * zhi * zlo;
      //       p2 += eve::sqr(zlo);
      //       auto [l, h] = eve::two_add[eve::raw](p1, p2);
      //       return Z(l, h);
    }
    else if constexpr (dimension_v<Z> == 3)
    {
      auto [xh, xm, xl] = z;
      auto [p00, e00] = eve::two_prod(xh, xh);
      auto p = p00;
      auto [p01, e01] = eve::two_prod(xh, xm + xm);
      auto [a1, b1] = eve::two_add(e00, p01);
      e00 = a1;
      p01 = b1;
      auto [a2, b2] = eve::two_add[eve::raw](p00, e00);
      p00 = a2;
      e00 = b2;
      p01 += e01 + eve::fma(xh, 2 * xl, eve::sqr(xm));
      auto [a3, b3] = eve::two_add(e00, p01);
      e00 = a3;
      p01 = b3;
      auto [a4, b4] = eve::two_add[eve::raw](p00, e00);
      p00 = a4;
      e00 = b4;
      auto [a5, b5] = eve::two_add[eve::raw](e00, p01);
      e00 = a5;
      p01 = b5;
      auto [a6, b6] = eve::two_add[eve::raw](p00, e00);
      p00 = a6;
      e00 = b6;
      auto test = eve::is_not_finite(p00 + e00 + p01);
      return plf::if_else(test, Z(p), plf::_::from_triple(p00, e00, p01));

      //       auto [ahi, amd, alo] = z;
      //       auto [hi, t1] = eve::two_prod(ahi, ahi);
      //       auto [t2, t3] = eve::two_prod(ahi, amd);
      //       auto [t6, t7] = eve::two_prod(amd, amd);
      //       auto t8 = ahi * alo;
      //       auto t10 = amd * alo;
      //       auto [t14, t15] = eve::two_add[eve::raw](t1, t6);
      //       auto t16 = t7 + t15;
      //       auto t17 = 2 * (t8 + t10);
      //       auto t18 = t16 + t17;
      //       auto [t19, t20] = eve::two_add[eve::raw](t14, t18);
      //       auto [t21, t22] = eve::two_add(2 * t2, 2 * t3);
      //       auto [md, lo] = _::four_add1(t21, t22, t19, t20);
      //       return Z(hi, md, lo);
    }
  }
}
