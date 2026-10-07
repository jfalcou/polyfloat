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
#include <polyfloat/module/math/details/pio_2_splitting.hpp>
#include <polyfloat/module/math/details/cody_waite_reduce.hpp>

namespace plf::_
{
  template<typename T> POLYFLOAT_FORCEINLINE constexpr auto pio_2_reduce(T const& x) noexcept
  {
    using e_t = eve::element_type_t<T>;
    auto const coefs = eve::coefficients(pio_2_splitting(as<e_t>()));
    ;
    auto invpio2 = 2 * plf::inv_pi(eve::as<e_t>());
    return cody_waite_reduce(x, invpio2, coefs);
  }
}
