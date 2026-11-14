/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

namespace plf::_
{

  POLYFLOAT_ABI void twoadd(auto a, auto b, auto& r0, auto& r1) noexcept
  {
    auto [x, y] = eve::two_add(a, b);
    r0 = x;
    r1 = y;
  }

  POLYFLOAT_ABI void fasttwoadd(auto a, auto b, auto& r0, auto& r1) noexcept
  {
    auto [x, y] = eve::two_add[eve::raw](a, b);
    r0 = x;
    r1 = y;
  }
}
