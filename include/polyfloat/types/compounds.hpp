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
namespace plf
{
  namespace _
  {
    template<typename T> EVE_FORCEINLINE auto clean0s(T hi, T lo) noexcept
    {
      return eve::if_else(eve::is_not_finite(hi), plf::double_real_t<T>(hi), plf::double_real_t<T>(hi, lo));
    }

    template<typename T> EVE_FORCEINLINE auto clean0s(auto f, auto hs, auto ho, T h, T l) noexcept
    {
      auto output_is_finite = eve::is_finite(h);
      if (eve::all(output_is_finite)) return plf::double_real_t<T>(h, l);
      else
      {
        auto input_is_finite = eve::is_finite(hs) && eve::is_finite(ho);
        if (eve::all(input_is_finite)) return plf::double_real_t<T>(h, l);
        else return eve::if_else(output_is_finite, plf::double_real_t<T>(h, l), plf::double_real_t<T>(f(hs, ho)));
      }
    }

    template<typename T> EVE_FORCEINLINE auto clean1s(auto f, auto hs, auto ho, T h, T m, T l) noexcept
    {
      auto output_is_finite = eve::is_finite(h);
      if (eve::all(output_is_finite)) return plf::triple_real_t<T>(h, m, l);
      else
      {
        auto input_is_finite = eve::is_finite(hs) && eve::is_finite(ho);
        if (eve::all(input_is_finite)) return plf::triple_real_t<T>(h, m, l);
        else return eve::if_else(output_is_finite, plf::triple_real_t<T>(h, m, l), plf::triple_real_t<T>(f(hs, ho)));
      }
    }

    template<typename T> EVE_FORCEINLINE auto clean1s(T hi, T md, T lo) noexcept
    {
      return eve::if_else(eve::is_not_finite(hi), plf::triple_real_t<T>(hi), plf::triple_real_t<T>(hi, md, lo));
    }

    EVE_FORCEINLINE auto four_add1(auto a, auto b, auto c, auto d) noexcept
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
      auto [hi, lo] = eve::two_add(xhi, yhi);
      auto [thi, tlo] = eve::two_add(xlo, ylo);
      auto [hi1, lo1] = eve::two_add[eve::raw](hi, lo + thi);
      auto [hi2, lo2] = eve::two_add[eve::raw](hi1, tlo + lo1);
      return self = _::clean0s(eve::add, xhi, yhi, hi2, lo2);
    }
    else if constexpr (dimension_v<T1> == 3u)
    {
      auto [ahi, amd, alo] = self;
      auto [bhi, bmd, blo] = oth;
      auto [zhi, t1] = eve::two_add(ahi, bhi);
      auto [t2, t3] = eve::two_add(amd, bmd);
      auto [t7, t4] = eve::two_add(t1, t2);
      auto t6 = alo + blo;
      auto t5 = t3 + t4;
      auto t8 = t5 + t6;
      auto [zmd, zlo] = eve::two_add(t7, t8);
      return self = _::clean1s(eve::add, ahi, bhi, zhi, zmd, zlo);
    }
  }

  /// Substracts the polyfloat value `other` to `self` and returns the new value of `self`.
  template<concepts::polyfloat T1, concepts::polyfloat_like T2>
  constexpr auto& operator-=(T1& self, T2 other) noexcept
  requires(dimension_v<T1> >= dimension_v<T2>)
  {
    T1 oth{plf::convert(other, eve::as<eve::element_type_t<T1>>())};
    if constexpr (dimension_v<T1> == 2u)
    {
      auto [xhi, xlo] = self;
      auto [yhi, ylo] = oth;
      auto [hi, lo] = eve::two_sub(xhi, yhi);
      auto [thi, tlo] = eve::two_sub(xlo, ylo);
      auto c = lo + thi;
      auto [hi1, lo1] = eve::two_add[eve::raw](hi, c);
      c = tlo + lo1;
      auto [hi2, lo2] = eve::two_add[eve::raw](hi1, c);
      return self = _::clean0s(eve::sub, xhi, yhi, hi2, lo2);
    }
    else if constexpr (dimension_v<T1> == 3u)
    {
      auto [ahi, amd, alo] = self;
      auto [bhi, bmd, blo] = oth;
      auto [zhi, t1] = eve::two_sub(ahi, bhi);
      auto [t2, t3] = eve::two_sub(amd, bmd);
      auto [t7, t4] = eve::two_add(t1, t2);
      auto t6 = alo - blo;
      auto t5 = t3 + t4;
      auto t8 = t5 + t6;
      auto [zmd, zlo] = eve::two_add(t7, t8);
      return self = _::clean1s(eve::sub, ahi, bhi, zhi, zmd, zlo);
    }
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
      auto [hi, lo] = eve::two_prod(xhi, yhi);
      auto t1 = xhi * ylo;
      auto t2 = xlo * yhi;
      auto t = lo + (t1 + t2);
      auto [hi2, lo2] = eve::two_add[eve::raw](hi, t);
      return self = _::clean0s(eve::mul, xhi, yhi, hi2, lo2);
    }
    else if constexpr (dimension_v<T1> == 3u)
    {
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
      return self = _::clean1s(eve::mul, ahi, bhi, hi, md, lo);
    }
  }
}

#include <polyfloat/types/ops1.hpp> //define +, -, *, / * is used by plf::rec and /=

namespace plf
{

  namespace _
  {
    template<concepts::polyfloat_like T> POLYFLOAT_FORCEINLINE auto rec(T a) noexcept
    {
      if constexpr (dimension_v<T> == 1 && std::is_floating_point_v<T>) return eve::rec[pedantic](a);
      else if constexpr (dimension_v<T> == 2)
      {
        auto [a0, b0] = a;
        auto x0 = eve::rec[pedantic](a0);
        auto x1 = x0 + x0 * (T(1) - a * x0);
        return x1;
      }
      else if constexpr (dimension_v<T> == 3)
      {
        auto [a0, b0, c0] = a;
        auto x0 = eve::rec[pedantic](a0);
        auto x1 = x0 + x0 * (T(1) - a * x0);
        auto x2 = x1 + x1 * (T(1) - a * x1);
        auto x3 = x2 + x2 * (T(1) - a * x2);
        return x3;
      }
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
