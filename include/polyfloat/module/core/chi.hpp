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
#include <eve/module/core/regular/if_else.hpp>

namespace plf
{

  template<typename Options> struct chi_t : eve::strict_tuple_callable<chi_t, Options, raw_option, pedantic_option>
  {
    template<typename... Ts> struct result : as_polyfloat_like<Ts...>
    {
    };

    template<concepts::polyfloat_like Z0, concepts::polyfloat_like Z1, concepts::polyfloat_like Z2>
    EVE_FORCEINLINE typename result<Z0, Z1, Z2>::type constexpr operator()(Z0 z0, Z1 z1, Z2 z2) const noexcept
    {
      return POLYFLOAT_CALL(z0, z1, z2);
    }

    template<concepts::polyfloat_like T, typename B>
    constexpr POLYFLOAT_FORCEINLINE T operator()(T a, B const& belongs) const noexcept
    {
      return POLYFLOAT_CALL(a, belongs);
    }

    POLYFLOAT_CALLABLE_OBJECT(chi_t, chi_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var chi
  //!   @brief  indicatrix of the interval \f$[lo, hi[\f$ or
  //!  of the set for which the invocable returns true.
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
  //!      constexpr auto chi(value auto x, value auto lo,  value auto hi)             noexcept; // 1
  //!      constexpr auto chi(value auto x, auto belongs)                              noexcept; // 2
  //!
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `x`: value to chi.
  //!     * `lo`, `hi`: [the boundary values](@ref eve::value) of the interval.
  //!     * `belongs`: predicate function
  //!     * `c`: [Conditional expression](@ref eve::conditional_expr) masking the operation.
  //!     * `m`: [Logical value](@ref eve::logical_value) masking the operation.
  //!
  //!    **Return value**
  //!        1. Each [element](@ref glossary_elementwise)  of the result contains:
  //!           * `0`, if `x` is less than `lo`. or if `hi` is strictly less than `x`.
  //!           * `1` otherwise.
  //!        2  1 in the type of x if belongs(x) evaluate to true else 0.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/chi.cpp}
  //======================================================================================================================

  inline constexpr auto chi = eve::functor<chi_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename T0, typename T1, typename T2, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto chi_(POLYFLOAT_DELAY(), O const& c, T0 a, T1 l, T2 h) noexcept
  {
    using r_t = as_polyfloat_like_t<T0, T1, T2>;
    using u_t = eve::element_type_t<r_t>;
    auto cvt = [](auto a) { return plf::convert(a, as<u_t>()); };
    auto z = if_else(cvt(a) < cvt(h) && cvt(a) >= cvt(l), r_t(1), eve::zero);
    if constexpr (O::contains(eve::condition_key)) return mask_op(c[eve::condition_key], eve::_::return_2nd, a, z);
    else return z;
  }

  template<typename T, typename B, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto chi_(POLYFLOAT_DELAY(), O const& c, T x, B const& b) noexcept
  {
    auto z = if_else(b(x), T(1), eve::zero);
    if constexpr (O::contains(eve::condition_key)) return mask_op(c[eve::condition_key], eve::_::return_2nd, x, z);
    else return z;
  }

}
