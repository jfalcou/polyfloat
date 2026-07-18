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

namespace plf
{
  namespace _
  {

    EVE_FORCEINLINE auto clean0s(auto hi,  auto md, auto lo) noexcept
    {
      auto iszhi = eve::is_eqz(hi);
      auto iszmd = eve::is_eqz(md);
      eve::swap_if(iszhi&& iszmd, hi, lo);
      eve::swap_if(iszhi&&!iszmd, md, hi);
      eve::swap_if(iszhi&&!iszmd, md, lo);
      return eve::zip(hi, md, lo);
    }

    EVE_FORCEINLINE auto four_quick_add(auto a,auto b, auto c, auto d) noexcept
    {
      //unchecked requirement `|a| > |b| > |c| > |d|`
      auto [t0, t1] = eve::two_add[eve::raw](a ,  b);
      auto [t01, t2] = eve::two_add[eve::raw](t0,  c);
      auto [hi, t3] = eve::two_add[eve::raw](t01,  d);
      auto lo      =( t1 + t2) +t3;

      return eve::zip(hi, lo);
    }
  }

  //====================================================================================================================
  //! @name Compound Assignment Operators
  //! @related polyfloat
  //! @{
  //====================================================================================================================

  /// Adds the floating value `other` to `self` and returns the new value of `self`.
  template <concepts::polyfloat T1, eve::floating_value T2>
  requires(dimension_v<T2> == 1)
  constexpr auto& operator+=(T1 & self, T2 oth) noexcept
  {
    if constexpr(dimension_v<T1> == 2u)
    {
      auto [xhi, xlo] = self;
      auto [hi, lo] = eve::two_add(xhi, oth);
      auto [hi1, lo1] = eve::two_add[eve::raw](hi, lo + xlo);
      return self = eve::two_add[eve::raw](hi1, lo1);
    }
    else if constexpr(dimension_v<T1> == 3u)
    {
      auto [ahi, amd, alo] = self;
      auto [zhi, t1] = eve::two_add(ahi, oth);
      auto [t7, t4] = eve::two_add(t1, amd);
      auto [zmd, zlo] = eve::two_add(t7, t4 + alo);
      auto [zhi1, zmd1, zlo1] = _::clean0s(zhi,zmd,zlo );
      return self = _::clean0s(zhi,zmd,zlo );
    }
  }

  /// Adds the polyflat value `other` to `self` and returns the new value of `self`.
  template <concepts::polyfloat T1, concepts::polyfloat T2>
  constexpr auto& operator+=(T1 & self, T2  other) noexcept
  requires( dimension_v<T1> >= dimension_v<T2>  )
  {
    T1 oth(other);
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

  /// Substracts the floating value `other` to `self` and returns the new value of `self`.
  template <concepts::polyfloat T1, eve::floating_value T2>
  constexpr auto& operator-=(T1 & self, T2  other) noexcept
  requires(dimension_v<T2> == 1)
  {
    using u_t = eve::underlying_type_t<plf::as_component_type_t<T1>>;
    auto oth = eve::convert(other, eve::as<u_t>());
    if constexpr(dimension_v<T1> == 2u)
    {
      auto [xhi, xlo] = self;
      auto [hi, lo] = eve::two_add(xhi, oth);
      auto [hi1, lo1] = eve::two_add[eve::raw](hi, lo + xlo);
      return self = eve::two_add[eve::raw](hi1, lo1);
    }
    else if constexpr(dimension_v<T1> == 3u)
    {
      auto [ahi, amd, alo] = self;
      auto [zhi, t1] = eve::two_sub(ahi, oth);
      auto [t7, t4] = eve::two_sub(t1, amd);
      auto [zmd, zlo] = eve::two_add(t7, t4 + alo);
      auto [zhi1, zmd1, zlo1] = _::clean0s(zhi,zmd,zlo );
      return self = _::clean0s(zhi,zmd,zlo );
    }
  }


  /// Substracts the polyfloat value `other` to `self` and returns the new value of `self`.
  template <concepts::polyfloat T1, concepts::polyfloat T2>
  constexpr auto& operator-=(T1 & self, T2 other) noexcept
  requires( dimension_v<T1> >= dimension_v<T2>  )
  {
    T1 oth(other);
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
      auto [zhi, t1] = eve::two_sub(ahi, bhi);
      auto [t2, t3] = eve::two_sub(amd, bmd);
      auto [t7, t4] = eve::two_add(t1, t2);
      auto t6 = alo - blo;
      auto t5 = t3 + t4;
      auto t8 = t5 + t6;
      auto [zmd, zlo] = eve::two_add(t7, t8);
      return self  = _::clean0s(zhi,zmd,zlo );
    }
  }

  /// Multiply the floating value `other` to `self` and returns the new value of `self`.
  template <concepts::polyfloat T1, eve::floating_value T2>
  constexpr auto& operator*=(T1 & self, T2 other) noexcept
  {
    using u_t = eve::underlying_type_t<plf::as_component_type_t<T1>>;
    auto oth = eve::convert(other, eve::as<u_t>());
    if constexpr(dimension_v<T1> == 2u)
    {
      auto [xhi, xlo] = self;
      auto [hi, lo] = eve::two_prod(xhi, oth);
      auto t = lo + (xlo * oth);
      return self = eve::two_add[eve::raw](hi, t);
    }
    else if constexpr(dimension_v<T1> == 3u)
    {
      using T =  decltype(oth);
      auto [ahi, amd, alo] = self;
      auto [hi,t1] = eve::two_prod(ahi, oth);
      auto [t4,t5] = eve::two_prod(amd, oth);
      auto [t19, t20] = eve::two_add[eve::raw](t1, alo * oth);
      auto [t21, t22] = eve::two_add[eve::raw](t4, t5);
      auto [md, lo]   =  _::four_quick_add(t21, t22, t19, t20);
      return self = T1(hi, md, lo);
    }
  }

  /// Multiply the polyfloat value `other` to `self` and returns the new value of `self`.
  template <concepts::polyfloat T1, concepts::polyfloat T2>
  constexpr auto& operator*=(T1 & self, T2 other) noexcept
  requires( dimension_v<T1> >= dimension_v<T2>  )
  {
    T1 oth(other);
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
      auto [t21, t22] = _::four_quick_add(t2, t3, t4, t5);
      auto [md, lo]   = _::four_quick_add(t21, t22, t19, t20);
      return self = T1(hi, md, lo);
    }
  }
}

#include <polyfloat/types/ops1.hpp> //define +, -, *, / * is uded by rec and /=

namespace plf
{

  namespace _
  {
    template <concepts::polyfloat_like T> POLYFLOAT_FORCEINLINE auto rec(T a) noexcept
    {
      if constexpr(dimension_v<T> == 1)
        return eve::rec[pedantic](a);
      else if constexpr(dimension_v<T> == 2)
      {
        auto [a0, b0] = a;
        auto x0 = eve::rec[pedantic](a0);
        auto x1 = x0+x0*(T(1)-a*x0);
        return x1;
//         auto [yhi, ylo] = a;
//         auto hi = eve::rec[pedantic](yhi);
//         auto [uh, ul] = eve::two_prod(hi, yhi);
//         auto lo = ((hi - uh) - ul)/yhi;
//         return T(eve::two_add[eve::raw](hi, lo));
      }
      else if constexpr(dimension_v<T> == 3)
      {
        auto [a0, b0, c0] = a;
        auto x0 = eve::rec[pedantic](a0);
        auto x1 = x0+x0*(T(1)-a*x0);
        auto x2 = x1+x1*(T(1)-a*x1);
//        return x2;
         auto x3 = x2+x2*(T(1)-a*x2);
         return x3;
      }
    }
  }

  /// Divide  `self` by the  value `other` and returns the new value of `self`.
  template <concepts::polyfloat T1, concepts::polyfloat T2>
  constexpr auto& operator/=(T1 & self, T2 other) noexcept
  {
//     if constexpr(dimension_v<T1>  ==  2)
//     {
//       auto [xhi, xlo] = self;
//       auto [yhi, ylo] = other;
//       auto hi = xhi / yhi;
// //     if !isfinite(hi)
// //         return zero_error_result(hi)
// //     end
//       auto [uh, ul] = eve::two_prod(hi, yhi);
//       auto lo = eve::fnma(hi, ylo, (((xhi - uh) - ul) + xlo))/yhi;
//       return self = eve::two_add[eve::raw](hi, lo);
//     }
//     else
      return self *= _::rec(other);
   }

  /// Divide the polyfloat  `self` by   the floating value `other` and returns the new value of `self`.
  template <concepts::polyfloat T1, eve::floating_value T2>
  constexpr auto& operator/=(T1 & self, T2 other) noexcept
  {
    return self *= eve::rec(other);
  }

}

#include <polyfloat/types/ops2.hpp>
#include <polyfloat/types/ops3.hpp>
