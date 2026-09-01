/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once
#include <polyfloat/module/core/three_fma.hpp>

namespace plf::_
{
  template<typename Z1, typename Z2, typename Z3>
  POLYFLOAT_FORCEINLINE constexpr auto inner_fma(Z1 const& x, Z2 const& y, Z3 const& z) noexcept
  {
    using r_t = as_polyfloat_t<Z1, Z2, Z3>;
    if constexpr (dimension_v<r_t> == 1) return eve::fma[pedantic](x, y, z);
    else if constexpr ((dimension_v<Z1> > 2) || (dimension_v<Z2> > 2) || (dimension_v<Z3> > 2))
    {
      using r_t = as_polyfloat_t<Z1, Z2, Z3>;
      auto cvt = [](auto a) { return plf::convert(a, eve::as<eve::element_type_t<r_t>>()); };
      auto [r, e0, e1] = three_fma(cvt(x), cvt(y), cvt(z));
      return r;
    }
    else if constexpr ((dimension_v<Z1> == 2) && (dimension_v<Z2> == 2) && (dimension_v<Z3> == 2))
    {
      //      auto fmap = eve::fma[pedantic];
      auto [xhi, xlo] = x;
      auto [yhi, ylo] = y;
      auto [zhi, zlo] = z;
      auto [chi, c1] = eve::two_prod(xhi, yhi);
      auto t0 = xlo * ylo;
      auto t1 = plf::fma(xhi, ylo, t0);
      auto c2 = plf::fma(xlo, yhi, t1);
      auto c3 = c1 + c2;
      auto [dhi, dlo] = eve::two_add[eve::raw](chi, c3);

      auto [shi, slo] = eve::two_add(zhi, dhi);
      auto [thi, tlo] = eve::two_add(zlo, dlo);
      auto c = slo + thi;
      auto [vhi, vlo] = eve::two_add[eve::raw](shi, c);
      auto w = tlo + vlo;
      auto [hi, lo] = eve::two_add[eve::raw](vhi, w);
      return r_t(hi, lo);
    }
    else if constexpr ((dimension_v<Z1> == 1) && (dimension_v<Z2> == 1))
    {
      auto [zhi, zlo] = z;
      auto [chi, c1] = eve::two_prod(x, y);
      auto [shi, slo] = eve::two_add(zhi, chi);
      auto [thi, tlo] = eve::two_add(zlo, c1);
      auto c = slo + thi;
      auto [vhi, vlo] = eve::two_add[eve::raw](shi, c);
      auto w = tlo + vlo;
      auto [hi, lo] = eve::two_add[eve::raw](vhi, w);
      return r_t(hi, lo);
    }
    //     else
    //     {
    //       using r_t = as_polyfloat_t<Z1, Z2, Z3>;
    //       auto cvt =  [](auto a){return plf::convert(a, eve::as<eve::element_type_t<r_t>>());};
    //       return fma(cvt(x), cvt(y), cvt(z));
    //     }
  }
}
