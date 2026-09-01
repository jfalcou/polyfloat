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
  //====================================================================================================================
  //! @name Streaming Operators
  //! @related polyfloat
  //! @{
  //====================================================================================================================

  /// Stream insertion for Poly-Float based types
  template<typename C, typename Ct, concepts::polyfloat CD> auto& operator<<(std::basic_ostream<C, Ct>& os, CD const& z)
  {
    auto display_positive = [](auto& os, auto e, bool first) -> decltype(auto) {
      if (first) return os << e;
      else if (eve::is_positive(e)) return os << " + " << e;
      else return os << " - " << -e;
    };
    kumi::for_each_index([&](auto i, auto v) { display_positive(os, v, i == 0); }, z);
    return os;
  }

  //====================================================================================================================
  //! @}
  //====================================================================================================================
}
