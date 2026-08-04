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
#include <polyfloat/functions/convert.hpp>
#include <iostream>
#include <iomanip>

namespace plf
{
  namespace _
  {

    EVE_FORCEINLINE auto clean0s(auto hi,  auto md, auto lo) noexcept
    {
//      std::cout << std::setprecision(16) << "avant " << hi << " " << md << " " << lo << std::endl;
//       auto iszhi = eve::is_eqz(hi);
//       auto iszmd = eve::is_eqz(md);
//       eve::swap_if(iszhi&& iszmd, hi, lo);
//       eve::swap_if(iszhi&&!iszmd, md, hi);
//       eve::swap_if(iszhi&&!iszmd, md, lo);
//       std::cout << "apres " << hi << " " << md << " " << lo << std::endl;
//       return eve::zip(hi, md, lo);
//      std::cout <<  "apres " << as_polyfloat_n_t<3, decltype(hi)>(hi, md, lo) << std::endl; ;
      return as_polyfloat_n_t<3, decltype(hi)>(hi, md, lo);
    }

//     EVE_FORCEINLINE auto four_quick_add(auto a,auto b, auto c, auto d) noexcept
//     {
//       //unchecked requirement  `|a| ≥ |b| ≥ |c| ≥ |d|`
//       auto [t0, t1]  = eve::two_add[eve::raw](a ,  b);
//       auto [t01, t2] = eve::two_add[eve::raw](t0,  c);
//       auto [hi, t3]  = eve::two_add[eve::raw](t01,  d);
//       t0 = t1+t2;
//       auto lo = t0+t3;
//       return eve::zip(hi, lo);
//     }

    EVE_FORCEINLINE auto four_add1(auto a,auto b, auto c, auto d) noexcept
    {
      auto [t0, t1] = eve::two_add(a , b);
      auto [t01, t2] = eve::two_add(t0, c);
      auto [aa,  t3] = eve::two_add(t01, d);
      auto t02 = t1 + t2;
      auto bb = t02 + t3;
      return eve::zip(aa, bb);
    }

//   EVE_FORCEINLINE auto four_add2(auto a,auto b, auto c, auto d) noexcept
//     {
//       auto [t0, t1] = eve::two_add(a,  b);
//       auto [t2, t3] = eve::two_add(c,  d);
//       auto [hi, t4] = eve::two_add(t0, t2);
//       auto [t5, lo] = eve::two_add(t1, t3);
//       auto [hm, ml] = eve::two_add(t4, t5);
//       auto [ml1, lo1] = eve::two_add[raw](ml, lo);
//       auto [hm1, ml2] = eve::two_add[raw](hm, ml1);
//       auto [hi1, hm2] = eve::two_add[raw](hi,hm1);
//       return   eve::zip(hi1, hm2, ml2, lo1);
//     }
  }

  //====================================================================================================================
  //! @name Compound Assignment Operators
  //! @related polyfloat
  //! @{
  //====================================================================================================================

  /// Adds the polyflat value `other` to `self` and returns the new value of `self`.
  template <concepts::polyfloat T1, concepts::polyfloat_like T2>
  constexpr auto& operator+=(T1 & self, T2  other) noexcept
  requires( dimension_v<T1> >= dimension_v<T2>  )
  {
    T1 oth{plf::convert(other, eve::as<eve::element_type_t<T1>>())};
    if constexpr(dimension_v<T1> == 2u)
    {
      auto [xhi, xlo] = self;
      auto [yhi, ylo] = oth;
      auto [hi, lo] = eve::two_add(xhi, yhi);
      auto [thi, tlo] = eve::two_add(xlo, ylo);
      auto [hi1, lo1] = eve::two_add[eve::raw](hi, lo + thi);
      return self = eve::two_add[eve::raw](hi1, tlo + lo1);
    }
    else if constexpr(dimension_v<T1> == 3u)
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
      return self = _::clean0s(zhi,zmd,zlo );
    }
  }

  /// Substracts the polyfloat value `other` to `self` and returns the new value of `self`.
  template <concepts::polyfloat T1, concepts::polyfloat_like T2>
  constexpr auto& operator-=(T1 & self, T2 other) noexcept
  requires( dimension_v<T1> >= dimension_v<T2>  )
  {
    T1 oth{plf::convert(other, eve::as<eve::element_type_t<T1>>())};
    if constexpr(dimension_v<T1> == 2u)
    {
      auto [xhi, xlo] = self;
      auto [yhi, ylo] = oth;
      auto [hi, lo] = eve::two_sub(xhi, yhi);
      auto [thi, tlo] = eve::two_sub(xlo, ylo);
      auto c = lo + thi;
      auto [hi1, lo1] = eve::two_add[eve::raw](hi, c);
      c = tlo + lo1;
      return self = eve::two_add[eve::raw](hi1, c);
    }
    else if constexpr(dimension_v<T1> == 3u)
    {
      auto [ahi, amd, alo] = self;
      auto [bhi, bmd, blo] = oth;
//       std::cout << "self  " << self << std::endl;
//       std::cout << "oth   " << oth  << std::endl;
      auto [zhi, t1] = eve::two_sub(ahi, bhi);
      auto [t2, t3] = eve::two_sub(amd, bmd);
      auto [t7, t4] = eve::two_add(t1, t2);
      auto t6 = alo - blo;
      auto t5 = t3 + t4;
      auto t8 = t5 + t6;
      auto [zmd, zlo] = eve::two_add(t7, t8);
//      return self  = T1(zhi,zmd,zlo);
      return self  = _::clean0s(zhi,zmd,zlo );
    }
  }

  /// Multiply the polyfloat value `other` to `self` and returns the new value of `self`.
  template <concepts::polyfloat T1, concepts::polyfloat_like T2>
  constexpr auto& operator*=(T1 & self, T2 other) noexcept
  requires( dimension_v<T1> >= dimension_v<T2>  )
  {
    T1 oth{plf::convert(other, eve::as<eve::element_type_t<T1>>())};
    if constexpr(dimension_v<T1> == 2u)
    {
      auto [xhi, xlo] = self;
      auto [yhi, ylo] = oth;
      auto [hi, lo] = eve::two_prod(xhi, yhi);
      auto t1 = xhi * ylo;
      auto t2 = xlo * yhi;
      auto t = lo + (t1 + t2);
      return self = eve::two_add[eve::raw](hi, t);
    }
    else if constexpr(dimension_v<T1> == 3u)
    {
      auto [ahi, amd, alo] = self;
      auto [bhi, bmd, blo] = oth;
      auto [hi,t1] = eve::two_prod(ahi, bhi);
      auto [t2,t3] = eve::two_prod(ahi, bmd);
      auto [t4,t5] = eve::two_prod(amd, bhi);
      auto [t6,t7] = eve::two_prod(amd, bmd);

      auto t8  = ahi * blo;
      auto t9  = alo * bhi;
      auto t10 = amd * blo;
      auto t11 = alo * bmd;
      auto t12 = t8  + t9;
      auto t13 = t10 + t11;

      auto [t14, t15] = eve::two_add[eve::raw](t1, t6);

      auto t16 = t7  + t15;
      auto t17 = t12 + t13;
      auto t18 = t16 + t17;

      auto [t19, t20] = eve::two_add[eve::raw](t14, t18);
      auto [t21, t22] = _::four_add1(t2, t3, t4, t5);
      auto [md, lo]   = _::four_add1(t21, t22, t19, t20);
      return self = _::clean0s(hi, md, lo);
    }
  }
}

#include <polyfloat/types/ops1.hpp> //define +, -, *, / * is used by plf::rec and /=

namespace plf
{

  namespace _
  {
    template <concepts::polyfloat_like T> POLYFLOAT_FORCEINLINE auto rec(T a) noexcept
    {
      if constexpr(dimension_v<T> == 1 && std::is_floating_point_v<T>)
        return eve::rec[pedantic](a);
      else if constexpr(dimension_v<T> == 2)
      {
        auto [a0, b0] = a;
        auto x0 = eve::rec[pedantic](a0);
        auto x1 = x0+x0*(T(1)-a*x0);
        auto x2 = x1+x1*(T(1)-a*x1);
        return x2;
      }
      else if constexpr(dimension_v<T> == 3)
      {
        auto [a0, b0, c0] = a;
//        auto x0 = plf::_::rec<as_polyfloat_n_t<2, T>>(as_polyfloat_n_t<2, T>(a0, b0));
        auto x0 = eve::rec[pedantic](a0);
        auto x1 = x0+x0*(T(1)-a*x0);
        auto x2 = x1+x1*(T(1)-a*x1);
        auto x3 = x2+x2*(T(1)-a*x2);
        return x3;
      }
    }
  }

  /// Divide  `self` by the  value `other` and returns the new value of `self`.
  template <concepts::polyfloat T1, concepts::polyfloat_like T2>
  constexpr auto& operator/=(T1 & self, T2 other) noexcept
  {
   T1 oth{plf::convert(other, eve::as<eve::element_type_t<T1>>())};
    return self *= _::rec(oth);
  }
}

#include <polyfloat/types/ops2.hpp>
#include <polyfloat/types/ops3.hpp>
