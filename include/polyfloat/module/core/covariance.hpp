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
#include <polyfloat/module/core/dot.hpp>
#include <polyfloat/module/core/average.hpp>

namespace plf
{
 template<typename Options> struct covariance_t : eve::strict_tuple_callable<covariance_t, Options, raw_option, pedantic_option>
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
    requires(eve::same_lanes_or_scalar_tuple<Tup1> && eve::same_lanes_or_scalar_tuple<Tup2>)
    EVE_FORCEINLINE constexpr kumi::apply_traits_t<result, kumi::result::cat_t<Tup1, Tup2>>
    operator()(Tup1 const& t1, Tup2 const& t2) const noexcept
    {
      return POLYFLOAT_CALL(t1, t2);
    }

    POLYFLOAT_CALLABLE_OBJECT(covariance_t, covariance_);
  };
  //======================================================================================================================
  //! @covariancetogroup core
  //! @{
  //!   @var covariance
  //!   @brief `elementwise_callable` object computing the elementwise  covariance product
  //!     of the vector of the first half parameters by the vector of the last half.
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <eve/module/core.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace eve
  //!   {
  //!      // Regular overloads
  //!      constexpr auto covariance(auto xsys...)                                                              noexcept; // 1
  //!      constexpr auto covariance(eve::non_empty_product_type xs, eve::non_empty_product_type ys)            noexcept; // 2
  //!
  //!      // Semantic options
  //!      constexpr auto covariance[unbiased](/*any of the above overloads*/)                                  noexcept; // 3
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `xsys`      :  `xs` followed by same number of `ys`
  //!     * `xs`, `ys`  :  tuples of floating value arguments.
  //!
  //!    **Return value**
  //!
  //!    1. covariance product. \f$\frac1N\sum_s (x_s-\bar{x_s})*(y_s-\bar{y_s})\f$.
  //!       where N is the number of `x_s` (minus 1 if `unbiased` option is used).
  //!    2. Uses the tuples elements
  //!    3. see 1.
  //!
  //!  @see [`welford_covariance`](@ref welford_variance) for incremental or parallel covariance and averages computations.
  //!
  //!  @groupheader{Example}
  //!  @godbolt{doc/core/covariance.cpp}
  //======================================================================================================================

  inline constexpr auto covariance = eve::functor<covariance_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<eve::callable_options O, concepts::polyfloat_like... Ts>
  POLYFLOAT_FORCEINLINE constexpr auto covariance_(POLYFLOAT_DELAY(), O const& o, Ts const&... args) noexcept
  requires(sizeof...(Ts) > 1  && sizeof...(Ts)%2 == 0)
  {
    using r_t =  as_polyfloat_like_t<Ts...>;
    using u_t = eve::element_type_t<r_t>;
    auto cvt = [](auto a){return plf::convert(a,  as<u_t>());};
    auto coeffs = eve::zip(cvt(args)...);
    auto[f,s]   = kumi::split(coeffs, kumi::index<sizeof...(Ts)/2>);
    return covariance[o](f, s);
  }

  template<eve::non_empty_product_type PT1, eve::non_empty_product_type PT2, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto covariance_(POLYFLOAT_DELAY(), O const & o, PT1 f, PT2 s) noexcept
  requires (kumi::as_tuple_t<PT1>::size() == kumi::as_tuple_t<PT2>::size())
  {
    using Tup1 = kumi::as_tuple_t<PT1>;
    using Tup2 = kumi::as_tuple_t<PT2>;
    constexpr auto siz = Tup1::size();
    constexpr auto fac = O::contains(unbiased) ? siz-1 : siz;
    using r1_t = kumi::apply_traits_t<eve::common_value, Tup1>;
    using r2_t = kumi::apply_traits_t<eve::common_value, Tup2>;
    using r_t =  eve::common_value_t<r1_t, r2_t>;

    if constexpr(siz == 1)
      return eve::zero(eve::as<r_t>());
    else
    {
      auto avgf = plf::average[o](f);
      auto avgs = plf::average[o](s);
      if constexpr(O::contains(raw))
        auto cov = kumi::sum( kumi::map([avgf, avgs](auto a, auto b) { return (a-avgf)*(b-avgs); }, f, s))/fac;
      else
      {
        auto fc =  kumi::map([avgf](auto a) { return (a-avgf); }, f);
        auto sc =  kumi::map([avgs](auto a) { return (a-avgs); }, s);
        return eve::dot[o](fc, sc)/fac;
      }
    }
  }
}
