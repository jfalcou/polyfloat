/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once
#include <polyfloat/details/add_utility.hpp>

namespace plf::_
{

  template<typename T1, typename T2>
  POLYFLOAT_ABI T1& mul_equal(T1& self, T2 other) noexcept
  requires(dimension_v<T1> == 2u) && (dimension_v<T2> == 1u)
  {
    auto [xhi, xlo] = self;
    auto [p, e] = eve::two_prod(xhi, other);
    auto pp = p;
    auto phm = xlo * other;
    fasttwoadd(p, e + phm, p, e);
    auto test = eve::is_not_finite(p + e);
    self = plf::if_else(test, T1(pp), plf::_::from_pair(p, e));
    EVE_ASSERT(eve::all(plf::is_normalized(self)), "output of += is not normalized");
    return self;
  }

  template<typename T1, typename T2>
  POLYFLOAT_ABI T1& mul_equal(T1& self, T2 other) noexcept
  requires(dimension_v<T1> == 2u) && (dimension_v<T2> == 2u)
  {
    auto [xhi, xlo] = self;
    auto [yhi, ylo] = other;
    auto [p, e] = eve::two_prod(xhi, yhi);
    auto pp = p;
    auto phm = xhi * ylo + xlo * yhi;
    fasttwoadd(p, e + phm, p, e);
    auto test = eve::is_not_finite(p + e);
    self = plf::if_else(test, T1(pp), plf::_::from_pair(p, e));
    EVE_ASSERT(eve::all(plf::is_normalized(self)), "output of += is not normalized");
    return self;
  }

  template<typename T1, typename T2>
  POLYFLOAT_ABI T1& mul_equal(T1& self, T2 other) noexcept
  requires(dimension_v<T1> == 3u) && (dimension_v<T2> == 1u)
  {
    auto [xhi, xmd, xlo] = self;
    auto yhi = other;
    auto [phh, ehh] = eve::two_prod(xhi, yhi);
    auto p = phh;
    auto [phm, emh] = eve::two_prod(xmd, yhi);
    twoadd(ehh, phm, ehh, phm);
    fasttwoadd(phh, ehh, phh, ehh);
    twoadd(ehh, (phm + emh) + (yhi * xlo), ehh, phm);
    fasttwoadd(phh, ehh, phh, ehh);
    fasttwoadd(ehh, phm, ehh, phm);
    fasttwoadd(phh, ehh, phh, ehh);
    auto test = eve::is_not_finite(phh + ehh + phm);
    self = plf::if_else(test, T1(p), plf::_::from_triple(phh, ehh, phm));
    EVE_ASSERT(eve::all(plf::is_normalized(self)), "output of += is not normalized");
    return self;
  }

  template<typename T1, typename T2>
  POLYFLOAT_ABI T1& mul_equal(T1& self, T2 other) noexcept
  requires(dimension_v<T1> == 3u) && (dimension_v<T2> == 2u)
  {
    auto [xhi, xmd, xlo] = self;
    auto [yhi, ymd] = other;
    auto [phh, ehh] = eve::two_prod(xhi, yhi);
    auto p = phh;
    auto [phm, ehm] = eve::two_prod(xhi, ymd);
    auto [pmh, emh] = eve::two_prod(xmd, yhi);
    auto pmm = (xmd * ymd);
    auto plh = (yhi * xlo);
    twoadd(phm, pmh, phm, pmh);
    ehm += emh;
    twoadd(ehh, phm, ehh, phm);
    auto phl = plh + pmm;
    fasttwoadd(phh, ehh, phh, ehh);
    phm += pmh;
    ehm += phl;
    phm += ehm;
    twoadd(ehh, phm, ehh, phm);
    fasttwoadd(phh, ehh, phh, ehh);
    fasttwoadd(ehh, phm, ehh, phm);
    fasttwoadd(phh, ehh, phh, ehh);
    auto test = eve::is_not_finite(phh + ehh + phm);
    self = plf::if_else(test, T1(p), plf::_::from_triple(phh, ehh, phm));
    EVE_ASSERT(eve::all(plf::is_normalized(self)), "output of += is not normalized");
    return self;
  }

  template<typename T1, typename T2>
  POLYFLOAT_ABI T1& mul_equal(T1& self, T2 other) noexcept
  requires(dimension_v<T1> == 3u) && (dimension_v<T2> == 3u)
  {
    auto [xhi, xmd, xlo] = self;
    auto [yhi, ymd, ylo] = other;
    auto [phh, ehh] = eve::two_prod(xhi, yhi);
    auto p = phh;
    auto [phm, ehm] = eve::two_prod(xhi, ymd);
    auto [pmh, emh] = eve::two_prod(xmd, yhi);
    auto phl = (xhi * ylo);
    auto pmm = (xmd * ymd);
    auto plh = (xlo * yhi);
    twoadd(phm, pmh, phm, pmh);
    ehm += emh;
    phl += plh;
    twoadd(ehh, phm, ehh, phm);
    phl += pmm;
    fasttwoadd(phh, ehh, phh, ehh);
    phm += pmh;
    ehm += phl;
    phm += ehm;
    twoadd(ehh, phm, ehh, phm);
    fasttwoadd(phh, ehh, phh, ehh);
    fasttwoadd(ehh, phm, ehh, phm);
    fasttwoadd(phh, ehh, phh, ehh);
    auto test = eve::is_not_finite(phh + ehh + phm);
    self = plf::if_else(test, T1(p), plf::_::from_triple(phh, ehh, phm));
    EVE_ASSERT(eve::all(plf::is_normalized(self)), "output of += is not normalized");
    return self;
  }

}
