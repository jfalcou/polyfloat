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
#include <polyfloat/details/force_if_any.hpp>

namespace plf
{

  template<typename Options>
  struct sum_of_squares_t : eve::callable<sum_of_squares_t, Options, kahan_option, raw_option, pedantic_option>
  {
    template<typename... Ts> struct result : as_polyfloat_like<Ts...>
    {
    };

    template<concepts::polyfloat_like T0, concepts::polyfloat_like... Ts>
    EVE_FORCEINLINE plf::as_polyfloat_like_t<T0, Ts...> constexpr operator()(T0 t0, Ts... ts) const noexcept
    requires(eve::same_lanes_or_scalar<T0, Ts...>)
    {
      return POLYFLOAT_CALL(t0, ts...);
    }

    template<eve::non_empty_product_type Tup>
    EVE_FORCEINLINE constexpr kumi::apply_traits_t<result, Tup> operator()(Tup const& t) const noexcept
    requires(eve::same_lanes_or_scalar_tuple<Tup> && !concepts::polyfloat_like<Tup> && kumi::size_v<Tup> >= 1)
    {
      return POLYFLOAT_CALL(t);
    }

    POLYFLOAT_CALLABLE_OBJECT(sum_of_squares_t, sum_of_squares_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var sum_of_squares
  //!   @brief return the sum of squares of the vector components.
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <polyfloat/module/core.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace polyfloat
  //!   {
  //!      // Regular overloads
  //!      constexpr auto sum_of_squares(auto ... xss)        noexcept; // 1
  //!      constexpr auto sum_of_squares(kumi::tuple xs)      noexcept; // 2
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `xs`: Values to process.
  //!
  //!   **Return value**
  //!
  //!    1. sum of squares. \f$\\sum_s x_s^2\f$.
  //!    2. use the content of the tuple
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/sum_of_squares.cpp}
  //======================================================================================================================

  inline constexpr auto sum_of_squares = eve::functor<sum_of_squares_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<eve::callable_options O, concepts::polyfloat_like T0, concepts::polyfloat_like... Ts>
  POLYFLOAT_FORCEINLINE constexpr plf::as_polyfloat_like_t<T0, Ts...> sum_of_squares_(POLYFLOAT_DELAY(),
                                                                                      O const& o,
                                                                                      T0 const& a0,
                                                                                      Ts const&... args) noexcept
  {
    using r_t = plf::as_polyfloat_like_t<T0, Ts...>;
    if constexpr (dimension_v<r_t> == 1) return eve::sum_of_squares(args...);
    else if constexpr (sizeof...(Ts) == 0) return plf::sqr[o](a0);
    else if constexpr (O::contains(kahan))
    {
      auto pair_sqr_add = [](auto pair0, auto r1) {
        auto [r0, e0] = pair0;
        auto [s, e1] = plf::two_fma_approx(r1, r1, r0);
        return zip(s, e0 + e1);
      };
      auto p0 = two_prod(a0, a0);
      ((p0 = pair_sqr_add(p0, args)), ...);
      auto [r, e] = p0;
      auto res = r + e;
      res = plf::_::force_if_any(o, res, eve::is_infinite, inf(as(res)), a0, args...);
      return if_else(is_nan(res), inf(as(res)), res);
    }
    else
    {
      auto cvt = [](auto a) { return plf::convert(a, eve::as_element<r_t>{}); };
      r_t r = plf::add(sqr(cvt(a0)), sqr(cvt(args))...);
      return plf::_::force_if_any(o, r, eve::is_infinite, inf(as(r)), cvt(a0), cvt(args)...);
    }
  }

  template<eve::product_type PT, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto sum_of_squares_(POLYFLOAT_DELAY(), O const& o, PT tup) noexcept
  requires(eve::same_lanes_or_scalar_tuple<PT> && !concepts::polyfloat_like<PT> && kumi::size_v<PT> >= 1)
  {
    return kumi::apply([o](auto... m) { return sum_of_squares[o](m...); }, tup);
  }
}
