//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once
#include <eve/eve.hpp>
#include <polyfloat/polyfloat.hpp>
#include <polyfloat/module/core/convert.hpp>
#include <polyfloat/module/core/if_else.hpp>
#include <polyfloat/module/core/oneminus.hpp>
#include <polyfloat/module/core/is_normalized.hpp>
#include <polyfloat/types/triple_real.hpp>
#include <polyfloat/types/double_real.hpp>

namespace plf
{

  //====================================================================================================================
  //! @name Compound Assignment Operators
  //! @related polyfloat
  //! @{
  //====================================================================================================================

  POLYFLOAT_ABI void twoadd(auto a, auto b, auto& r0, auto& r1)
  {
    auto [x, y] = eve::two_add(a, b);
    r0 = x;
    r1 = y;
  }
  POLYFLOAT_ABI void fasttwoadd(auto a, auto b, auto& r0, auto& r1)
  {
    auto [x, y] = eve::two_add[eve::raw](a, b);
    r0 = x;
    r1 = y;
  }

  /// Adds the polyfloat value `other` to `self` and returns the new value of `self`.
  template<concepts::polyfloat T1, concepts::polyfloat_like T2>
  constexpr auto& operator+=(T1& self, T2 other) noexcept
  requires(dimension_v<T1> >= dimension_v<T2>)
  {
    if constexpr (eve::integral_value<T2>) return self += eve::convert(other, eve::as(eve::underlying_type_t<T1>()));
    else
    {
      if constexpr (dimension_v<T1> == 2u)
      {
        if constexpr (dimension_v<T2> == 1u)
        {
          auto [xhi, xlo] = self;
          auto [a, b] = eve::two_add(xhi, other);
          auto test = eve::is_not_finite(a + b);
          auto aa = a;
          auto c = xlo;
          fasttwoadd(a, c, a, c);
          fasttwoadd(a, b + c, a, b);
          self = plf::if_else(test, T1(aa), plf::_::from_pair(a, b));
          EVE_ASSERT(eve::all(plf::is_normalized(self)), "output of += is not normalized");
          return self;
        }
        else if constexpr (dimension_v<T2> == 2u)
        {
          auto [xhi, xlo] = self;
          auto [yhi, ylo] = other;
          auto [a, b] = eve::two_add(xhi, yhi);
          auto test = eve::is_not_finite(a + b);
          auto aa = a;
          auto [c, d] = eve::two_add(xlo, ylo);
          fasttwoadd(a, c, a, c);
          fasttwoadd(a, (b + d) + c, a, b);
          self = plf::if_else(test, T1(aa), plf::_::from_pair(a, b));
          EVE_ASSERT(eve::all(plf::is_normalized(self)), "output of += is not normalized");
          return self;
        }
      }
      else if constexpr (dimension_v<T1> == 3u)
      {
        T1 oth{plf::convert(other, eve::as<eve::element_type_t<T1>>())};
        auto [xhi, xmd, xlo] = self;
        if constexpr (dimension_v<T2> == 1u)
        {
          auto yhi = other;
          auto [a, b] = eve::two_add(xhi, yhi);
          auto aa = a;
          auto c = xmd;
          auto e = xlo;
          fasttwoadd(a, c, a, c);
          twoadd(b, c, b, c);
          fasttwoadd(a, b, a, b);
          fasttwoadd(b, c + e, b, c);
          fasttwoadd(a, b, a, b);
          fasttwoadd(b, c, b, c);
          auto test = eve::is_not_finite(a + b + c);
          self = plf::if_else(test, T1(aa), plf::_::from_triple(a, b, c));
          EVE_ASSERT(eve::all(plf::is_normalized(self)), "output of += is not normalized");
          return self;
        }
        else if constexpr (dimension_v<T2> == 2u)
        {
          auto [yhi, ymd] = other;

          auto [a, b] = eve::two_add(xhi, yhi);
          auto aa = a;
          auto [c, d] = eve::two_add(xmd, ymd);
          auto e = xlo;
          fasttwoadd(a, c, a, c);
          twoadd(d, e, d, e);
          fasttwoadd(a, d, a, d);
          twoadd(b, c, b, c);
          twoadd(c + e, d, c, d);
          twoadd(b, c, b, c);
          fasttwoadd(a, b, a, b);
          fasttwoadd(b, c + d, b, c);
          fasttwoadd(a, b, a, b);
          fasttwoadd(b, c, b, c);
          auto test = eve::is_not_finite(a + b + c);
          self = plf::if_else(test, T1(aa), plf::_::from_triple(a, b, c));
          EVE_ASSERT(eve::all(plf::is_normalized(self)), "output of += is not normalized");
          return self;
        }
        else if constexpr (dimension_v<T2> >= 2u)
        {
          auto [yhi, ymd, ylo] = oth;
          auto [a, b] = eve::two_add(xhi, yhi);
          auto aa = a;
          auto [c, d] = eve::two_add(xmd, ymd);
          auto [e, f] = eve::two_add(xlo, ylo);
          fasttwoadd(a, c, a, c);
          twoadd(d, e, d, e);
          fasttwoadd(a, d, a, d);
          twoadd(b + f, c, b, c);
          twoadd(c + e, d, c, d);
          twoadd(b, c, b, c);
          fasttwoadd(a, b, a, b);
          fasttwoadd(b, c + d, b, c);
          fasttwoadd(a, b, a, b);
          fasttwoadd(b, c, b, c);
          auto test = eve::is_not_finite(a + b + c);
          self = plf::if_else(test, T1(aa), plf::_::from_triple(a, b, c));
          EVE_ASSERT(eve::all(plf::is_normalized(self)), "output of += is not normalized");
          return self;
        }
      }
    }
  }

  /// Subtracts the polyfloat value `other` from `self` and returns the new value of `self`.
  template<concepts::polyfloat T1, concepts::polyfloat_like T2>
  constexpr auto& operator-=(T1& self, T2 other) noexcept
  requires(dimension_v<T1> >= dimension_v<T2>)
  {
    return self += -other;
  }

  /// Multiply the polyfloat value `other` to `self` and returns the new value of `self`.
  template<concepts::polyfloat T1, concepts::polyfloat_like T2>
  constexpr auto& operator*=(T1& self, T2 other) noexcept
  requires(dimension_v<T1> >= dimension_v<T2>)
  {
    T1 oth{plf::convert(other, eve::as<eve::element_type_t<T1>>())};
    if constexpr (dimension_v<T1> == 2u)
    {
      auto [xhi, xlo] = self;
      auto [yhi, ylo] = oth;
      auto [p00, e00] = eve::two_prod(xhi, yhi);
      auto p01 = xhi * ylo;
      auto p10 = xlo * yhi;
      p01 += p10;
      e00 += p01;
      auto [p, e] = eve::two_add[raw](p00, e00);
      auto test = eve::is_not_finite(p + e);
      self = plf::if_else(test, T1(p00), plf::_::from_pair(p, e));
      EVE_ASSERT(eve::all(plf::is_normalized(self)), "output of += is not normalized");
      return self;
    }
    else if constexpr (dimension_v<T1> == 3u)
    {
      auto [xh, xm, xl] = self;
      auto [yh, ym, yl] = oth;
      auto [p00, e00] = eve::two_prod(xh, yh);
      auto p = p00;
      auto [p01, e01] = eve::two_prod(xh, ym);
      auto [p10, e10] = eve::two_prod(xm, yh);
      auto p02 = eve::mul(xh, yl);
      auto p11 = eve::mul(xm, ym);
      auto p20 = eve::mul(xl, yh);
      auto [a1, b1] = eve::two_add(p01, p10);
      p01 = a1;
      p10 = b1;
      e01 += e10;
      p02 += p20;
      auto [a2, b2] = eve::two_add(e00, p01);
      e00 = a2;
      p01 = b2;
      p02 += p11;
      auto [a3, b3] = eve::two_add[eve::raw](p00, e00);
      p00 = a3;
      e00 = b3;
      p01 += p10;
      e01 += p02;
      p01 += e01;
      auto [a4, b4] = eve::two_add(e00, p01);
      e00 = a4;
      p01 = b4;
      auto [a5, b5] = eve::two_add[eve::raw](p00, e00);
      p00 = a5;
      e00 = b5;
      auto [a6, b6] = eve::two_add[eve::raw](e00, p01);
      e00 = a6;
      p01 = b6;
      auto [a7, b7] = eve::two_add[eve::raw](p00, e00);
      p00 = a7;
      e00 = b7;
      auto test = eve::is_not_finite(p00 + e00 + p01);
      self = plf::if_else(test, T1(p), plf::_::from_triple(p00, e00, p01));
      EVE_ASSERT(eve::all(plf::is_normalized(self)), "output of *= is not normalized");
      return self;
    }
  }
}

#include <polyfloat/types/ops1.hpp> //define +, -, *, / * is used by plf::rec and /=

namespace plf
{

  namespace _
  {
    template<concepts::polyfloat_like T> auto rec(T a) noexcept
    {
      if constexpr (dimension_v<T> == 1 && std::is_floating_point_v<T>) return eve::rec[pedantic](a);
      else
      {
        a = eve::if_else(eve::is_denormal(hi(a)), T(hi(a) * eve::zero(as(hi(a)))), a);
        auto correct = [&a](auto x) {
          auto a0 = plf::hi(a);
          x = plf::if_else(eve::is_infinite(a0), T(eve::copysign(eve::zero(eve::as(a0)), a0)), x);
          return plf::if_else(eve::is_eqz(a0), T(eve::copysign(eve::inf(eve::as(a0)), a0)), x);
        };
        if constexpr (dimension_v<T> == 2)
        {
          auto a0 = plf::hi(a);
          auto x0 = eve::rec[pedantic](a0);
          auto x1 = x0 + x0 * plf::oneminus(a * x0);
          return correct(x1);
        }
        else if constexpr (dimension_v<T> == 3)
        {
          auto a0 = plf::_::from_pair(plf::hi(a), plf::md(a));
          auto x0 = plf::_::rec(a0);
          auto x1 = x0 + x0 * plf::oneminus(a * x0);
          return correct(x1);
        }
      }
      // ok aussi mais est-ce plus rapide ?
      //         auto a0 = plf::hi(a);
      //         auto correct =  [&a0](auto x){
      //           x = plf::if_else(eve::is_infinite(a0), T(eve::copysign(eve::zero(eve::as(a0)), a0)), x);
      //           return plf::if_else(eve::is_eqz(a0), T(eve::copysign(eve::inf(eve::as(a0)), a0)), x);
      //         };
      //         auto x0 = eve::rec[pedantic](a0);
      //         auto x1 = x0 + x0* plf::oneminus(a*x0);
      //         if constexpr (dimension_v<T> == 2) return correct(x1);
      //         x1 = x1 + x1* plf::oneminus(a*x1);
      //         x1 = x1 + x1* plf::oneminus(a*x1);
      //         return correct(x1);
      //       }

      // original
      //      else if constexpr (dimension_v<T> == 2)
      //       {
      //         auto [a0, b0] = a;
      //         auto x0 = eve::rec[pedantic](a0);
      //         auto x1 = x0 + x0 * (T(1) - a * x0);
      //         x1 = plf::if_else(eve::is_infinite(hi(a)), T(eve::copysign(eve::zero(eve::as(hi(a))), plf::hi(a))), x1);
      //         return if_else(eve::is_eqz(hi(a)), T(eve::copysign(eve::inf(eve::as(hi(a))), plf::hi(a))), x1);
      //       }
      //       else if constexpr (dimension_v<T> == 3)
      //       {
      //         auto [a0, b0, c0] = a;
      //         auto x0 = eve::rec[pedantic](a0);
      //         auto x1 = x0 + x0 * (T(1) - a * x0);
      //         auto x2 = x1 + x1 * (T(1) - a * x1);
      //         auto x3 = x2 + x2 * (T(1) - a * x2);
      //         x3 = plf::if_else(eve::is_infinite(hi(a)), T(eve::copysign(eve::zero(eve::as(hi(a))), plf::hi(a))), x3);
      //         return if_else(eve::is_eqz(hi(a)), T(eve::copysign(eve::inf(eve::as(hi(a))), plf::hi(a))), x3);
      //       }
    }
  }

  /// Divide  `self` by the  value `other` and returns the new value of `self`.
  template<concepts::polyfloat T1, concepts::polyfloat_like T2> constexpr auto& operator/=(T1& self, T2 other) noexcept
  {
    T1 oth{plf::convert(other, eve::as<eve::element_type_t<T1>>())};
    auto deno = eve::is_denormal(hi(oth));
    if (eve::none(deno)) return self *= _::rec(oth);
    else
    {
      auto a = self * _::rec(oth);
      auto b = T1(hi(self) / hi(oth));
      auto test = deno && eve::is_infinite(hi(a));
      return self = plf::if_else(test, b, a);
    }
    EVE_ASSERT(eve::all(plf::is_normalized(self)), "output of /= is not normalized");
    return self;
  }
}

#include <polyfloat/types/ops2.hpp>
