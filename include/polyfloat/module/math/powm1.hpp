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
#include <polyfloat/module/math/pow_abs.hpp>
#include <polyfloat/module/math/log_abs.hpp>

namespace plf
{

  template<typename Options>
  struct powm1_t : plf::elementwise_callable<powm1_t, eve::powm1_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z1, concepts::polyfloat_like Z2>
    POLYFLOAT_ABI constexpr as_polyfloat_like_t<Z1, Z2> operator()(Z1 z1, Z2 z2) const noexcept
    {
      return POLYFLOAT_CALL(z1, z2);
    }

    POLYFLOAT_CALLABLE_OBJECT(powm1_t, powm1_);
  };
  //======================================================================================================================
  //! @addtogroup math
  //! @{
  //!   @var powm1
  //!   @brief return \f$x^y-1\f$.
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <polyfloat/math.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace polyfloat
  //!   {
  //!      // Regular overload
  //!      constexpr auto powm1(auto x, auto y)                       noexcept; // 1
  //!
  //!      // Lanes masking
  //!      constexpr auto powm1[conditional_expr c](auto x, auto y)   noexcept; // 2
  //!      constexpr auto powm1[logical_value auto m](auto x, auto y) noexcept; // 2
  //!
  //!      // Semantic options
  //!      constexpr auto powm1[raw]( auto x,  auto y)                noexcept; // 3
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!    1. Returns the [elementwise](@ref glossary_elementwise) power minus one, with good accuracy,
  //!       even when `y` is very small, or when `x` is close to 1.
  //!    2. [The operation is performed conditionally](@ref conditional)
  //!    3. faster but less accurate call.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/math/powm1.cpp}
  //======================================================================================================================

  inline constexpr auto powm1 = eve::functor<powm1_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<typename T, typename U, eve::callable_options O>
  constexpr auto powm1_(POLYFLOAT_DELAY(), O const& o, T a, U b) noexcept
  {
    using r_t = as_polyfloat_like_t<T, U>;
    if constexpr (O::contains(raw))
    {
      return plf::dec(plf::pow[o](a, b));
    }
    else
    {
      using e_t = eve::element_type_t<r_t>;
      auto cvt = [](auto a) { return plf::convert(a, eve::as<e_t>()); };
      auto x = cvt(a);
      auto y = cvt(b);
      auto r = plf::dec(plf::pow(x, y));
      auto test = (plf::abs(y * plf::dec(x)) < r_t(0.5) || (plf::abs(y) < r_t(0.2)));
      if (eve::any(test))
      {
        // We don't have any good/quick approximation for log(x) * y
        // so just try it and see:
        auto l = y * plf::log_abs(x);
        auto tmp0 = plf::expm1(l);
        auto tmp1 = plf::minus[plf::is_ltz(x) && plf::is_odd(x)](tmp0);
        return plf::if_else(l < T(0.5), tmp1, r);
      }
      else return r;
    }
  }
}
