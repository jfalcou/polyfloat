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
#include <polyfloat/module/core/two_fma_approx.hpp>

namespace plf
{

  template<typename Options> struct dot_t : eve::strict_tuple_callable<dot_t, Options, kahan_option, raw_option, pedantic_option>
  {
    template<typename... Ts> struct result : as_polyfloat_like<Ts...>
    {
    };

    template<concepts::polyfloat_like... Ts>
    requires(eve::same_lanes_or_scalar<Ts...>)
    EVE_FORCEINLINE typename result<Ts...>::type constexpr operator()(Ts... ts) const noexcept
    {
      return POLYFLOAT_CALL(ts...);
    }

    template<eve::non_empty_product_type Tup1, eve::non_empty_product_type Tup2>
    EVE_FORCEINLINE constexpr kumi::apply_traits_t<result, kumi::result::cat_t<Tup1, Tup2>>
    operator()(Tup1 const& t1, Tup2 const& t2) const noexcept
    requires(eve::same_lanes_or_scalar_tuple<Tup1> &&
             eve::same_lanes_or_scalar_tuple<Tup2> &&
             (Tup1::size() == Tup2::size()) &&
             !concepts::polyfloat_like<Tup1> &&
             !concepts::polyfloat_like<Tup2>)
    {
      return POLYFLOAT_CALL(t1, t2);
    }

    template<eve::non_empty_product_type Tup>
    requires(eve::same_lanes_or_scalar_tuple<Tup> && !concepts::polyfloat_like<Tup>)
    EVE_FORCEINLINE constexpr kumi::apply_traits_t<result, Tup> operator()(Tup const& t) const noexcept
    requires(kumi::size_v<Tup> >= 1)
    {
      return POLYFLOAT_CALL(t);
    }

    POLYFLOAT_CALLABLE_OBJECT(dot_t, dot_);
  };
  //======================================================================================================================
  //! @dottogroup core
  //! @{
  //!   @var dot
  //!   @brief return the dot product  of the vector of the first half of parameters by
  //!    the vector of the second half.
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
  //!      constexpr auto dot(auto value... xs, auto value... ys)        noexcept; // 1
  //!      constexpr auto dot(kumi::tuple xs, kumi::tuple ys)            noexcept; // 2
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z1`, `z2`: Values to process.
  //!
  //!   **Return value**
  //!
  //!    1. dot product. \f$\sum_s x_s*y_s\f$.
  //!    2. use the content of the tuples
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/core/dot.cpp}
  //======================================================================================================================

  inline constexpr auto dot = eve::functor<dot_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<eve::callable_options O, concepts::polyfloat_like... Ts>
  POLYFLOAT_FORCEINLINE constexpr auto dot_(POLYFLOAT_DELAY(), O const& o, Ts const&... args) noexcept
  requires(sizeof...(Ts) > 1  && sizeof...(Ts)%2 == 0)
  {
    if constexpr(sizeof...(Ts) == 2)
    {
      return plf::mul[o](args...);
    }
    else
    {
      using r_t =  as_polyfloat_like_t<Ts...>;
      using u_t = eve::element_type_t<r_t>;
      auto cvt = [](auto a){return plf::convert(a,  as<u_t>());};
      auto coeffs = kumi::tuple{cvt(args)...};
      auto[f,s]   = kumi::split(coeffs, kumi::index<sizeof...(Ts)/2>);
      return add[o]( kumi::map([](auto a, auto b) { return a*b; }, f, s));
    }
  }

  template<eve::non_empty_product_type PT1, eve::non_empty_product_type PT2, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto dot_(POLYFLOAT_DELAY(), O const & o, PT1 f, PT2 s) noexcept
  requires (kumi::as_tuple_t<PT1>::size() == kumi::as_tuple_t<PT2>::size() &&
            !concepts::polyfloat_like<PT1> &&
            !concepts::polyfloat_like<PT2>)
  {
    using Tup1 = kumi::as_tuple_t<PT1>;
    using Tup2 = kumi::as_tuple_t<PT2>;
    constexpr auto siz = Tup1::size();
    if constexpr(siz == 1)
    {
      return get<0>(f)*get<0>(s);
    }
    else
    {
      using r1_t = kumi::apply_traits_t<plf::as_polyfloat_like, Tup1>;
      using r2_t = kumi::apply_traits_t<plf::as_polyfloat_like, Tup2>;
      using r_t =  plf::as_polyfloat_like_t<r1_t, r2_t>;
      using u_t = eve::element_type_t<r_t>;
      auto cvt = [](auto a){return plf::convert(a,  as<u_t>());};
      return add[o]( kumi::map([cvt](auto a, auto b) { return cvt(a*b); }, f, s));
    }
  }

}
