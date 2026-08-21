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
#include <polyfloat/module/core/round.hpp>

namespace plf
{

  template<typename Options> struct roundscale_t : eve::callable<roundscale_t, Options,
                                                                upward_option, downward_option,
                                                                to_nearest_option, toward_zero_option>
  {
    template<concepts::polyfloat_like T0, eve::integral_value T1>
    POLYFLOAT_FORCEINLINE constexpr T0 operator()(T0 t0, T1 n) const noexcept
    {
      return POLYFLOAT_CALL(t0, n);
    }

    template<concepts::polyfloat_like T0, auto N>
    POLYFLOAT_FORCEINLINE constexpr T0 operator()(T0 t0, eve::index_t<N> const & n) const noexcept
    {
      return POLYFLOAT_CALL(t0, n);
    }

    POLYFLOAT_CALLABLE_OBJECT(roundscale_t, roundscale_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var roundscale
  //!   @brief return the roundscaletionnal part of the value.
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <polyfloat/core.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace polyfloat
  //!      // Regular overload
  //!      constexpr auto roundscale(floating_value auto x, index_t<scale>)       noexcept; // 1
  //!      constexpr auto roundscale(floating_value auto x, integral_value scale) noexcept; // 1
  //!
  //!      // Semantic option
  //!      constexpr auto roundscale[downward](/*any of the above overloads*/)    noexcept; // 2
  //!      constexpr auto roundscale[upward](/*any of the above overloads*/)      noexcept; // 2
  //!      constexpr auto roundscale[to_nearest](/*any of the above overloads*/)  noexcept; // 2
  //!      constexpr auto roundscale[toward_zero](/*any of the above overloads*/) noexcept; // 2
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!      * `x`:      [real floating value](@ref eve::floating_value).
  //!      * `scale` : int or std::integral_constant of int type limited to the range [0, 15].
  //!
  //!   **Return value**
  //!
  //!      1. Returns the [elementwise](@ref glossary_elementwise) reduced part of the scaled input.
  //!         The number of roundtion bits retained is specified by scale. By default the internal
  //!         rounding after scaling is done to nearest integer.
  //!         The call `roundscale(x, scale)` is equivalent to  `eve::ldexp(eve::nearest(eve::ldexp(x,scale), -scale))`
  //!      2. with `o` denoting one of these options the call is equivalent to  `eve::ldexp(eve::round[o](eve::ldexp(x,scale), -scale))`
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/roundscale.cpp}
  //======================================================================================================================

  inline constexpr auto roundscale = eve::functor<roundscale_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<auto S, typename T, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr T roundscale_(POLYFLOAT_DELAY(),
                                               O const& o,
                                               T const& a0,
                                               eve::index_t<S> const &) noexcept
  {
    return roundscale[o](a0, S);
  }

  template<typename T, typename S, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr T roundscale_(POLYFLOAT_DELAY(),
                                               O const & o,
                                               T const & a0,
                                               S const & scale) noexcept
  {
    auto nbmb = 
    return  plf::ldexp[eve::pedantic](plf::round[o](plf::ldexp[eve::pedantic](a0, scale)), -scale);
  }
}
