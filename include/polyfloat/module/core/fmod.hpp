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
#include <polyfloat/module/core/is_unordered.hpp>
#include <polyfloat/module/core/is_infinite.hpp>
#include <polyfloat/module/core/is_eqz.hpp>

namespace plf
{

  template<typename Options> struct fmod_t : eve::strict_tuple_callable<fmod_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z1,  concepts::polyfloat_like Z2>
      POLYFLOAT_FORCEINLINE constexpr as_polyfloat_like_t<Z1, Z2> operator()(Z1 z1, Z2 z2) const noexcept
    {
     return POLYFLOAT_CALL(z1, z2);
    }

    POLYFLOAT_CALLABLE_OBJECT(fmod_t, fmod_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var fmod
  //!   @brief return the remainder of the values.
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <kyosu/module/core.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!
  //!   @code
  //!   namespace plf
  //!   {
  //!      // Regular overload
  //!      constexpr auto fmod(floating_value auto x, floating_value auto y)                          noexcept; // 1
  //!
  //!      // Lanes masking
  //!      constexpr auto fmod[conditional_expr auto c](floating_value auto x, floating_value auto y) noexcept; // 2
  //!      constexpr auto fmod[logical_value auto m](floating_value auto x, floating_value auto y)    noexcept; // 2
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `x`, `y`: [real](@ref plf::floating_value) argumentx.
  //!     * `c`: [Conditional expression](@ref plf::conditional_expr) masking the operation.
  //!     * `m`: [Logical value](@ref plf::logical_value) masking the operation.
  //!
  //!   **Return value**
  //!
  //!     1. Returns the remainder after division division of `x` by `y` and mimick
  //!        the behaviour of std::fmod. In particular:
  //!          * If `x` is \f$\pm0\f$, \f$\pm0\f$ is returned.
  //!          * If `x` is \f$\pm\inf\f$ or `NaN`, `NaN` is returned.
  //!          * If `y` is \f$\pm0\f$, `NaN` is returned.
  //!          * If `y` is \f$\pm\inf\f$ and `x` is finite, `x`is returned.
  //!     2. [The operation is performed conditionnaly](@ref conditional).
  //!
  //!  @groupheader{External references}
  //!   *  [C++ standard reference](https://en.cppreference.com/w/cpp/numeric/math/fmod)
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/fmod.cpp}
  //======================================================================================================================

  inline constexpr auto fmod = eve::functor<fmod_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z1, typename Z2, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto fmod_(POLYFLOAT_DELAY(), O const& , Z1 const& aa, Z2 const& bb) noexcept
  {
     using plf_t = as_polyfloat_t<Z1, Z2>;
     if constexpr(dimension_v<plf_t> == 1)
      return eve::fmod(aa, bb);
    else
    {
      using u_t = eve::element_type_t<plf_t>;
      auto cvt = [](auto a){ return plf::convert(a, as<u_t>());};
      auto a = cvt(aa);
      auto b = cvt(bb);
      return if_else(is_unordered(a, b) || is_infinite(a) || is_eqz(b),
                     eve::allbits,
                     plf::if_else(is_eqz(a)||is_infinite(b), a, fnma(b, div[toward_zero](a, b), a)));

    }
  }
}
