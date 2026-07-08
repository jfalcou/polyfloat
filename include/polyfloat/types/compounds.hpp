//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once
#include <eve/module/core.hpp>
#include <string>

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
//     eve::swap[
//         hi, md, lo
//     elseif iszero(md)
//         lo, md, hi
//     else
//         md, lo, hi
//     end
    }

  }

  //====================================================================================================================
  //! @name Compound Assignment Operators
  //! @related polyfloat
  //! @{
  //====================================================================================================================

  /// Adds the polyflat value `other` to `self` and returns the new value of `self`.
  template <concepts::polyfloat T1, concepts::polyfloat T2>
  constexpr auto& operator+=(T1 & self, T2 & other) noexcept
  requires( T1::static_dimension >= T2::static_dimension  )
  {
    T1 oth(other);
    if constexpr(T1::static_dimension == 2u)
    {
      auto [xhi, xlo] = self;
      auto [yhi, ylo] = oth;
      auto [hi, lo] = eve::two_add(xhi, yhi);
      auto [thi, tlo] = eve::two_add(xlo, ylo);
      auto c = lo + thi;
      auto [hi1, lo1] = eve::two_add[eve::raw](hi, c);
      c = tlo + lo1;
      auto [hi2, lo2] = eve::two_add[eve::raw](hi1, c);
      self = eve::zip(hi2, lo2);
      return self;
    }
    else if constexpr(T1::static_dimension == 3u)
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
      auto [zhi1, zmd1, zlo1] = _::clean0s(zhi,zmd,zlo );
      self = eve::zip(zhi, zmd1, zlo1);
      return self;
    }
  }

  /// Substracts the polyfloat value `other` to `self` and returns the new value of `self`.
  template <concepts::polyfloat T1, concepts::polyfloat T2>
  constexpr auto& operator-=(T1 & self, T2 & other) noexcept
  requires( T1::static_dimension >= T2::static_dimension  )
  {
    T1 oth(other);
    if constexpr(T1::static_dimension == 2u)
    {
      auto [xhi, xlo] = self;
      auto [yhi, ylo] = oth;
      auto [hi, lo] = eve::two_sub(xhi, yhi);
      auto [thi, tlo] = eve::two_sub(xlo, ylo);
      auto c = lo + thi;
      auto [hi1, lo1] = eve::two_add[eve::raw](hi, c);
      c = tlo + lo1;
      auto [hi2, lo2] = eve::two_add[eve::raw](hi1, c);
      self = eve::zip(hi2, lo2);
      return self;
    }
    else if constexpr(T1::static_dimension == 3u)
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
      auto [zhi1, zmd1, zlo1] = _::clean0s(zhi,zmd,zlo );
      self = eve::zip(zhi, zmd1, zlo1);
      return self;
    }

  }
}
