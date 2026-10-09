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
#include <polyfloat/module/core/fma.hpp>
#include <polyfloat/module/core/nearest.hpp>
#include <polyfloat/module/core/quadrant.hpp>
#include <eve/traits/helpers.hpp>

namespace plf::_
{

  template<typename X, typename C, typename Cn, typename C0, typename... Cs>
  POLYFLOAT_FORCEINLINE constexpr auto cody_waite_reduce(X x, C invc, Cn lastc, C0 c0, Cs... cs) noexcept
  {
    using r_t = as_polyfloat_like_t<X, C, Cn, C0, Cs...>;
    auto xn = -plf::nearest(x * invc);
    r_t that = plf::fma(c0, xn, x);
    ((that = plf::fma(cs, xn, that)), ...);
    auto da = xn * lastc;
    auto a = that + da;
    da = (that - a) + da;
    auto n = plf::quadrant(-xn);
    return eve::zip(n, a, da);
  }

  template<typename X, typename C, eve::product_type Tuple>
  POLYFLOAT_FORCEINLINE constexpr auto cody_waite_reduce(X x, C invc, eve::coefficients<Tuple> const& tup) noexcept
  {
    constexpr auto lst = kumi::size_v<Tuple> - 1;
    auto butlast = kumi::extract(tup, kumi::index<0>, kumi::index<lst>);
    auto last = kumi::get<lst>(tup);
    return kumi::apply([&](auto... m) { return plf::_::cody_waite_reduce(x, invc, last, m...); }, butlast);
  }
}
