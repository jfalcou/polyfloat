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
#include <polyfloat/module/core/cumfun.hpp>
#include <polyfloat/module/core/sub.hpp>


namespace plf
{

  template<typename Options> struct diff_t : eve::callable<diff_t, Options, raw_option, pedantic_option>
  {
    template<std::size_t N, typename... Ts>
    struct result;

    template < size_t N,  size_t SZ> static constexpr size_t sz = SZ > N ? SZ-N : 0;

    template<std::size_t N, concepts::polyfloat_like... Ts>
    struct result<N,Ts...> : kumi::result::fill<sz<N, sizeof...(Ts)>, plf::as_polyfloat_like_t<Ts...>> {};

    template<std::size_t N, eve::same_lanes_or_scalar_tuple Tup>
    struct result<N, Tup> : kumi::result::fill<sz<N, kumi::size_v<Tup>>, kumi::apply_traits_t<as_polyfloat_like, Tup>> {};

    template<eve::same_lanes_or_scalar_tuple Tup>
    POLYFLOAT_FORCEINLINE typename result<1, Tup>::type constexpr
    operator()(Tup const& t) const noexcept
    { return POLYFLOAT_CALL(t); }

    template<std::size_t N, eve::same_lanes_or_scalar_tuple Tup>
    POLYFLOAT_FORCEINLINE typename result<N, Tup>::type constexpr
    operator()(kumi::index_t<N>, Tup const& t) const noexcept
    { return POLYFLOAT_CALL(kumi::index_t<N>{}, t); }

    template<concepts::polyfloat_like... Ts>
    requires(eve::same_lanes_or_scalar<Ts...>)
    POLYFLOAT_FORCEINLINE typename result<1, Ts...>::type constexpr
    operator()(Ts const& ...ts) const noexcept
    { return POLYFLOAT_CALL(kumi::make_tuple(ts...)); }

    template<size_t N, concepts::polyfloat_like... Ts>
    requires(eve::same_lanes_or_scalar<Ts...>)
    POLYFLOAT_FORCEINLINE typename result<N, Ts...>::type constexpr
    operator()(kumi::index_t<N>, Ts const&...ts) const
    { return POLYFLOAT_CALL(kumi::index_t<N>{}, kumi::make_tuple(ts...)); }

    POLYFLOAT_CALLABLE_OBJECT(diff_t, diff_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var diff
  //!   @brief convert a pack of values into
  //!     a tuple of the cumulative sum of its values
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
  //!   namespace plf
  //!   {
  //!      constexpr auto diff(auto const& xs...)                                                            noexcept; // 1
  //!      constexpr auto diff(eve::non_empty_product_type auto const& x)                                    noexcept; // 1
  //!      typename<auto N> constexpr auto diff(kumi::index_t<N>,  auto const& xs...)                        noexcept; // 2
  //!      typename<auto N> constexpr auto diff(kumi::index_t<N>,eve::non_empty_product_type auto const& x)  noexcept; // 2
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `xs ...` : polyfloat arguments
  //!     * `x`      : kumi::tuple of arguments
  //!
  //!    **Return value**
  //!
  //!      * 1. Return a tuple containing the elementwise adjacent differences of the parameters or of the elements of the tuple.
  //!      * 2. Return a tuple containing the elementwise Nth adjacent differences of the parameters or of the elements of the tuple.
  //!
  //!  @groupheader{External references}
  //!   *  [Wikipedia divided differences](https://en.cppreference.com/w/cpp/types/integral_constant.html)
  //!
  //!  @groupheader{Example}
  //!  @godbolt{doc/core/diff.cpp}
  //================================================================================================
  inline constexpr auto diff = eve::functor<diff_t>;
  //================================================================================================
  //! @}
  //================================================================================================
}

namespace plf::_
{
 template<eve::non_empty_product_type CHKS> auto internal_dif(CHKS chks)
  {
    constexpr auto SZ = CHKS::size();
    if constexpr(SZ > 3)
    {
      auto t0 = get<0>(chks);
      auto t1 = get<1>(chks);
      auto v0 = plf::sub(t0, eve::slide_left(t0, t1, eve::index<1>));
      return kumi::cat(eve::unfold(v0), internal_dif(kumi::pop_front(chks)));
    }
    else  if constexpr(SZ == 3)
    {
      auto t0 = get<0>(chks);
      auto t1 = get<1>(chks);
      auto t2 = get<2>(chks);
      auto v0 = plf::sub(t0, eve::slide_left(t0, t1, eve::index<1>));
      auto v1 = plf::sub(t1, eve::slide_left(t1, t2, eve::index<1>));
      auto v2 = plf::sub(t2, eve::slide_left(t2    , eve::index<1>));
      return eve::unfold(v0, v1, v2);
    }
    else if constexpr(SZ == 2)
    {
      auto t0 = get<0>(chks);
      auto t1 = get<1>(chks);
      auto v0 = plf::sub(t0, eve::slide_left(t0, t1, eve::index<1>));
      auto v1 = plf::sub(t1, eve::slide_left(t1    , eve::index<1>));
      return eve::unfold(v0, v1);
    }
    else //if constexpr(SZ == 1)
    {
      auto t0 = get<0>(chks);
      return eve::unfold(eve::sub(t0, eve::slide_left(t0, eve::index<1>)));
    }
  }


  template<eve::non_empty_product_type PT , eve::callable_options O>
  POLYFLOAT_NOINLINE constexpr auto
  diff_(POLYFLOAT_DELAY(), O const &, PT const& x) noexcept
  {
    using r_t = kumi::apply_traits_t<as_polyfloat_like, PT>;
    using u_t = eve::element_type_t<r_t>;
    auto cvt = [](auto a){return plf::convert(a,  as<u_t>());};
    auto xx =  kumi::map([cvt](auto m){ return cvt(m); }, x);
    return kumi::map(eve::sub, kumi::pop_back(xx), kumi::pop_front(xx));
  }


  template<std::size_t N, eve::non_empty_product_type PT , eve::callable_options O>
  POLYFLOAT_NOINLINE constexpr auto
  diff_(POLYFLOAT_DELAY(), O const &, kumi::index_t<N>, PT const & x) noexcept
  {
    using r_t = kumi::apply_traits_t<plf::as_polyfloat_like, PT>;
    using u_t = eve::element_type_t<r_t>;
    auto cvt = [](auto a){return plf::convert(a,  as<u_t>());};
    auto xx =  kumi::map([cvt](auto m){ return cvt(m); }, x);
    if constexpr(N >= kumi::size_v<PT>)
      return kumi::tuple{};
    else if constexpr(N == 0)
      return xx;
    else
    {
      if constexpr(N == 1)             return diff(xx);
      else                             return diff(kumi::index_t<N-1>{}, diff(xx));
    }
  }


  template<plf::concepts::polyfloat_like ...Ts , eve::callable_options O>
  POLYFLOAT_NOINLINE constexpr auto
  diff_(POLYFLOAT_DELAY(), O const &, Ts const& ...xs) noexcept
  {
    return diff(kumi::make_tuple(xs...));
  }


  template<std::size_t N, plf::concepts::polyfloat_like ...Ts , eve::callable_options O>
  POLYFLOAT_NOINLINE constexpr auto
  diff_(POLYFLOAT_DELAY(), O const &, kumi::index_t<N> in, Ts const& ...xs) noexcept
  {
    return diff(in, kumi::make_tuple(xs...));
  }
}
