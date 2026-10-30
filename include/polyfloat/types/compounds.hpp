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
#include <polyfloat/types/triple_real.hpp>
#include <polyfloat/types/double_real.hpp>
#include <iostream>

namespace plf
{
  namespace _
  {
    template<typename T> auto clean0s(T hi, T lo) noexcept
    {
      return eve::if_else(eve::is_not_finite(hi), plf::double_real_t<T>(hi), plf::double_real_t<T>(hi, lo));
    }

    template<typename T> auto clean0s(auto f, auto hs, auto ho, T h, T l) noexcept
    {
      auto output_is_finite = eve::is_finite(h);
      if (eve::all(output_is_finite)) return from_pair(h, l); //plf::double_real_t<T>(h, l);
      else
      {
        auto input_is_finite = eve::is_finite(hs) && eve::is_finite(ho);
        if (eve::all(input_is_finite)) return from_pair(h, l); //plf::double_real_t<T>(h, l);
        else
          return eve::if_else(output_is_finite, from_pair(h, l),
                              from_pair(hs, ho)); //plf::double_real_t<T>, plf::double_real_t<T>(f(hs, ho)));
      }
    }

    template<typename T> auto clean1s(auto f, auto hs, auto ho, T h, T m, T l) noexcept
    {
      auto output_is_finite = eve::is_finite(h);
      if (eve::all(output_is_finite)) return plf::triple_real_t<T>(h, m, l);
      else
      {
        auto input_is_finite = eve::is_finite(hs) && eve::is_finite(ho);
        if (eve::all(input_is_finite)) return from_triple(h, m, l); //return plf::triple_real_t<T>(h, m, l);
        else
          return eve::if_else(
            output_is_finite, from_triple(h, m, l),
            from_triple(hs, ho,
                        eve::zero(eve::as(ho)))); //plf::triple_real_t<T>(h, m, l), plf::triple_real_t<T>(f(hs, ho)));
      }
    }

    template<typename T> auto clean1s(T hi, T md, T lo) noexcept
    {
      return eve::if_else(eve::is_not_finite(hi), plf::triple_real_t<T>(hi),
                          from_triple(hi, md, lo)); //plf::triple_real_t<T>(hi, md, lo));
    }

    auto four_add1(auto a, auto b, auto c, auto d) noexcept
    {
      auto [t0, t1] = eve::two_add(a, b);
      auto [t01, t2] = eve::two_add(t0, c);
      auto [aa, t3] = eve::two_add(t01, d);
      auto t02 = t1 + t2;
      auto bb = t02 + t3;
      return eve::zip(aa, bb);
    }
  }

  //====================================================================================================================
  //! @name Compound Assignment Operators
  //! @related polyfloat
  //! @{
  //====================================================================================================================

  /// Adds the polyflat value `other` to `self` and returns the new value of `self`.
  template<concepts::polyfloat T1, concepts::polyfloat_like T2>
  constexpr auto& operator+=(T1& self, T2 other) noexcept
  requires(dimension_v<T1> >= dimension_v<T2>)
  {
    T1 oth{plf::convert(other, eve::as<eve::element_type_t<T1>>())};
    if constexpr (dimension_v<T1> == 2u)
    {
      auto [xhi, xlo] = self;
      auto [yhi, ylo] = oth;
      auto [a, b] = eve::two_add(xhi, yhi);
      auto [c, d] = eve::two_add(xlo, ylo);
      auto [aa, cc] = eve::two_add[eve::raw](a, c);
      b += d;
      b += cc;
      auto [e, f] = eve::two_add(aa, b);
      auto test = eve::is_not_finite(e + f);
      return self = plf::if_else(test, T1(a), plf::_::from_pair(e, f));

      //       auto [xhi, xlo] = self;
      //       auto [yhi, ylo] = oth;
      //       auto [hi, lo] = eve::two_add(xhi, yhi);
      //       auto [thi, tlo] = eve::two_add(xlo, ylo);
      //       auto [hi1, lo1] = eve::two_add[eve::raw](hi, lo + thi);
      //       auto [hi2, lo2] = eve::two_add[eve::raw](hi1, tlo + lo1);
      //       return self = _::clean0s(eve::add, xhi, yhi, hi2, lo2);
    }
    else if constexpr (dimension_v<T1> == 3u)
    {
      auto [xhi, xmd, xlo] = self;
      auto [yhi, ymd, ylo] = oth;
      auto [a1, b1] = eve::two_add(xhi, yhi);
      auto [c1, d1] = eve::two_add(xmd, ymd);
      auto [e1, f1] = eve::two_add(xlo, ylo);
      auto [a2, c2] = eve::two_add[raw](a1, c1);
      b1 += f1;
      auto [d2, e2] = eve::two_add(d1, e1);
      auto [a3, d3] = eve::two_add[raw](a2, d2);
      auto [b2, c3] = eve::two_add(b1, c2);
      c3 += e2;
      auto [c4, d4] = eve::two_add(c3, d3);
      auto [b3, c5] = eve::two_add(b2, c4);
      auto [a4, b4] = eve::two_add[raw](a3, b3);
      c4 += d4;
      auto [b5, c6] = eve::two_add[raw](b4, c5);
      auto [a5, b6] = eve::two_add[raw](a4, b5);
      auto [b7, c7] = eve::two_add[raw](b6, c6);
      auto test = eve::is_not_finite(a5 + b7 + c7);
      return self = plf::if_else(test, T1(a1), plf::_::from_triple(a5, b7, c7));

      //             auto [ahi, amd, alo] = self;
      //             auto [bhi, bmd, blo] = oth;
      //             auto [zhi, t1] = eve::two_add(ahi, bhi);
      //             auto [t2, t3] = eve::two_add(amd, bmd);
      //             auto [t7, t4] = eve::two_add(t1, t2);
      //             auto t6 = alo + blo;
      //             auto t5 = t3 + t4;
      //             auto t8 = t5 + t6;
      //             auto [zmd, zlo] = eve::two_add(t7, t8);
      //             return self = _::clean1s(eve::add, ahi, bhi, zhi, zmd, zlo);
    }
  }

  /// Substracts the polyfloat value `other` to `self` and returns the new value of `self`.
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
      return self = plf::if_else(test, T1(p00), plf::_::from_pair(p, e));

      //       auto [hi, lo] = eve::two_prod(xhi, yhi);
      //       auto t1 = xhi * ylo;
      //       auto t2 = xlo * yhi;
      //       auto t = lo + (t1 + t2);
      //       auto [hi2, lo2] = eve::two_add[eve::raw](hi, t);
      //       self = _::clean0s(eve::mul, xhi, yhi, hi2, lo2);
      //       return self = if_else(eve::is_nan(xhi * yhi), T1(eve::nan(eve::as(xhi))), self);
    }
    else if constexpr (dimension_v<T1> == 3u)
    {
      auto [xh, xm, xl] = self;
      auto [yh, ym, yl] = oth;
      //       std::cout << "self "<< self << std::endl;
      //       std::cout << "oth  " << oth << std::endl;
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
      //       std::cout << "test " << test << std::endl;
      //       std::cout << "p00 " << p00 << " e00 " << e00 << " p01 " << p01 << std::endl;
      return self = plf::if_else(test, T1(p), plf::_::from_triple(p00, e00, p01));

      //       auto [p1_00, e1_00] = eve::two_prod(xh, yh);
      //       auto [p1_01, e1_01] = eve::two_prod(xh, ym);
      //       auto [p1_10, e1_10] = eve::two_prod(xm, yh);
      //       auto p1_02 = eve::mul(xh, yl);
      //       auto p1_11 = eve::mul(xm, ym);
      //       auto p1_20 = eve::mul(xl, yh);

      //       auto [p2_01, p2_10] = eve::two_add(p1_01, p1_10);
      //       e1_01 += e1_10;
      //       p1_02 += p1_20;

      //       auto [e2_00, p3_01] = eve::two_add(e1_00, p2_01);
      //       p1_02 += p1_11;

      //       auto [p2_00, e3_00] = eve::two_add[eve::raw](p1_00, e2_00);
      //       p2_01 += p2_10;
      //       e1_01 += p1_02;
      //       p2_01 += e1_01;

      //       auto  [e4_00, p4_01] = eve::two_add(e3_00, p3_01);
      //       auto  [p3_00, e5_00] = eve::two_add[eve::raw](p2_00, e4_00);
      //       auto  [e6_00, p5_01] = eve::two_add[eve::raw](e5_00, p4_01);
      //       auto  [p4_00, e7_00] = eve::two_add[eve::raw](p3_00, e6_00);
      //       auto test = eve::is_not_finite(p4_00+e7_00+p5_01);
      //       return self = plf::if_else(test, T1(p1_00), plf::_::from_triple(p4_00, e4_00, p3_01));

      auto [ahi, amd, alo] = self;
      auto [bhi, bmd, blo] = oth;
      auto [hi, t1] = eve::two_prod(ahi, bhi);
      auto [t2, t3] = eve::two_prod(ahi, bmd);
      auto [t4, t5] = eve::two_prod(amd, bhi);
      auto [t6, t7] = eve::two_prod(amd, bmd);

      auto t8 = ahi * blo;
      auto t9 = alo * bhi;
      auto t10 = amd * blo;
      auto t11 = alo * bmd;
      auto t12 = t8 + t9;
      auto t13 = t10 + t11;

      auto [t14, t15] = eve::two_add[eve::raw](t1, t6);

      auto t16 = t7 + t15;
      auto t17 = t12 + t13;
      auto t18 = t16 + t17;

      auto [t19, t20] = eve::two_add[eve::raw](t14, t18);
      auto [t21, t22] = _::four_add1(t2, t3, t4, t5);
      auto [md, lo] = _::four_add1(t21, t22, t19, t20);
      self = _::clean1s(eve::mul, ahi, bhi, hi, md, lo);
      return self = if_else(eve::is_nan(ahi * bhi), T1(eve::nan(eve::as(ahi))), self);
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
      // ok aussi
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
    return self *= _::rec(oth);
  }
}

#include <polyfloat/types/ops2.hpp>
