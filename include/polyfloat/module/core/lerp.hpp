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
#include <polyfloat/module/core/abs.hpp>

namespace plf
{

  template<typename Options> struct lerp_t : eve::strict_tuple_callable<lerp_t, Options, raw_option, pedantic_option>
  {
    template<typename... Ts> struct result : as_polyfloat_like<Ts...>
    {
    };

    template<concepts::polyfloat_like Z0, concepts::polyfloat_like Z1, concepts::polyfloat_like Z2>
    EVE_FORCEINLINE typename result<Z0, Z1, Z2>::type constexpr operator()(Z0 z0, Z1 z1, Z2 z2) const noexcept
    {
      return POLYFLOAT_CALL(z0, z1, z2);
    }

    POLYFLOAT_CALLABLE_OBJECT(lerp_t, lerp_);
  };
  //======================================================================================================================
  //! @lerptogroup core
  //! @{
  //!   @var lerp
  //!   @brief return the fused multiply add of the parameters.
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
  //!      template<polyfloat::concepts::polyfloat_like Z1, polyfloat_like Z2, polyfloat_like Z3> constexpr auto lerp(Z1 z1, Z2 z2, Z3 z3) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z1`, `z2`, `z3`: Values to process.
  //!
  //!   **Return value**
  //!
  //!     The value of the interpolation (or extrapolation)  between `z1` and `z2` is returned.
  //!     The call is semantically equivalent to `z1+z3*(z2-z1)`
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/lerp.cpp}
  //======================================================================================================================

  inline constexpr auto lerp = eve::functor<lerp_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z1, typename Z2, typename Z3, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto lerp_(
    POLYFLOAT_DELAY(), O const&, Z1 const& x, Z2 const& y, Z3 const& z) noexcept
  {
    using r_t = as_polyfloat_t<Z1, Z2, Z3>;
    auto cvt = [](auto a) { return plf::convert(a, eve::as<eve::element_type_t<r_t>>()); };
    auto a = cvt(x);
    auto b = cvt(y);
    auto t = cvt(z);
    return fma[pedantic](t, b, fnma[pedantic](t, a, a));
  }
}
