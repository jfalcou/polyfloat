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
#include <polyfloat/module/core/trunc.hpp>
#include <polyfloat/module/core/nearest.hpp>
#include <polyfloat/module/core/ceil.hpp>
#include <polyfloat/module/core/floor.hpp>

namespace plf
{

  template<typename Options> struct div_t : eve::strict_tuple_callable<div_t, Options, raw_option, pedantic_option,
                                                                       to_nearest_option, toward_zero_option,
                                                                       downward_option, upward_option>
  {
    template<concepts::polyfloat_like Z1,  concepts::polyfloat_like Z2>
      POLYFLOAT_FORCEINLINE constexpr as_polyfloat_like_t<Z1, Z2> operator()(Z1 z1, Z2 z2) const noexcept
    {
     return POLYFLOAT_CALL(z1, z2);
    }

    POLYFLOAT_CALLABLE_OBJECT(div_t, div_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var div
  //!   @brief return the ratio of the values.
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
  //!   {
  //!      template<polyfloat::concepts::polyfloat_like T1, polyfloat_like Z2> constexpr auto div(T1 z1, T2 z2) noexcept; //1
  //!
  //!      // Semantic exclusive options
  //!      constexpr auto div[upward](/*any of the above overloads*/)                   noexcept; // 2
  //!      constexpr auto div[downward](/*any of the above overloads*/)                 noexcept; // 2
  //!      constexpr auto div[toward_zero](/*any of the above overloads*/)              noexcept; // 2
  //!      constexpr auto div[to_nearest](/*any of the above overloads*/)               noexcept; // 2
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z1`, `z2`: Values to process.
  //!
  //!   **Return value**
  //!
  //!    1. Returns the ratio of the arguments.
  //!    2. Pproduces:
  //!       * `eve::trunc(div(x, z))`, if `d` is `toward_zero`.
  //!       * `eve::floor(div(x, z))`, if `d` is `downward`.
  //!       * `eve::ceil(div(x,  z))`, if `d` is `upward`.
  //!       * `eve::nearest(div(x, z))`, if `d` is `to_nearest`.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/div.cpp}
  //======================================================================================================================

  inline constexpr auto div = eve::functor<div_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename T0, typename T1, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto div_(POLYFLOAT_DELAY(), O const& , T0 const& a, T1 const& b) noexcept
  {
    using t_t = as_polyfloat_t<T0, T1>;
    using u_t = eve::element_type_t<t_t>;
    auto cvt = [](auto a){return plf::convert(a,  as<u_t>());};
    auto d = cvt(a)/cvt(b);
    if constexpr(O::contains(to_nearest))
      return nearest(d);
    else if  constexpr(O::contains(toward_zero))
      return trunc(d);
    else if  constexpr(O::contains(downward))
      return floor(d);
    else if  constexpr(O::contains(upward))
      return ceil(d);
    else
      return d;

  }
}
