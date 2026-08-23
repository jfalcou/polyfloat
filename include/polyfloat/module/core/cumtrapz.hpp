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
#include <polyfloat/module/core/cumsum.hpp>
#include <polyfloat/module/core/diff.hpp>

namespace toto
{
  template<typename T> struct typename_impl
  {
    static auto value() noexcept
    {
#if defined(_MSC_VER )
      std::string_view data(__FUNCSIG__);
      auto i = data.find('<') + 1,
        j = data.find(">::value");
      auto name = data.substr(i, j - i);
#else
      std::string_view data(__PRETTY_FUNCTION__);
      auto i = data.find('=') + 2,
        j = data.find_last_of(']');
      auto name = data.substr(i, j - i);
#endif
      return std::string(name.data(), name.size());
    }
  };

  template<typename T> inline auto const typename_ = typename_impl<T>::value();
  template<typename T> constexpr auto name(T const&){ return typename_<T>; }
}

namespace plf
{

  template<typename Options> struct cumtrapz_t : eve::callable<cumtrapz_t, Options, raw_option, pedantic_option>
  {
    template<typename T>
    using return_type = T;

    template<typename... Ts>
    using result = kumi::result::fill_t<sizeof...(Ts), return_type<plf::as_polyfloat_like_t<Ts...>>>;

    template<eve::product_type Tup>
    using tuple_result = kumi::result::fill_t< Tup::size(), return_type<kumi::apply_traits_t<as_polyfloat_like, Tup>>>;

    template<eve::product_type Tup, typename X>
    using XTup = typename kumi::result::push_back< Tup, X >::type;

    template<concepts::polyfloat_like X, eve::product_type Tup>
    using xtuple_result = kumi::result::fill_t< Tup::size(), return_type<kumi::apply_traits_t<as_polyfloat_like, XTup< Tup, X >>>>;

//     template<eve::product_type Tup1, eve::product_type Tup2>
//      using XYTup = typename kumi::result::cat< Tup1, Tup2 >::type;

//     template<typename Tup1, eve::product_type Tup2>
//     using xytuple_result = kumi::result::fill_t< Tup1::size(), return_type<kumi::apply_traits_t<as_polyfloat_like, XYTup< Tup1, Tup2 >>>>;

    template<concepts::polyfloat_like ...Ts>
    POLYFLOAT_FORCEINLINE constexpr result<Ts...>
    operator()(Ts ... ts) const noexcept
    {
      return POLYFLOAT_CALL(ts...);
    }

    template<eve::non_empty_product_type PT>
    POLYFLOAT_FORCEINLINE constexpr tuple_result<PT>
    operator()(PT t) const noexcept
    requires(!concepts::polyfloat_like<PT>)
    {
      return POLYFLOAT_CALL(t);
    }

    template<concepts::polyfloat_like X, eve::non_empty_product_type Y>
    POLYFLOAT_FORCEINLINE constexpr xtuple_result<X, Y>
    operator()(X dx, Y y) const noexcept
    requires(!concepts::polyfloat_like<Y>)
    {
      return POLYFLOAT_CALL(dx, y);
    }

    template<eve::non_empty_product_type X, eve::non_empty_product_type Y>
    POLYFLOAT_FORCEINLINE constexpr tuple_result<X>
    operator()(X x, Y y) const noexcept
    requires(!concepts::polyfloat_like<X> && !concepts::polyfloat_like<Y>)
    {
      return POLYFLOAT_CALL(x, y);
    }

    template<typename F, eve::non_empty_product_type X>
    POLYFLOAT_FORCEINLINE constexpr tuple_result<X>
     operator()(F f, X x) const noexcept
    requires (std::invocable<F, typename kumi::apply_traits<as_polyfloat, X>::type>)
    {
      return POLYFLOAT_CALL(f, x);
    }

    template<typename F, concepts::polyfloat_like ...Ts>
    POLYFLOAT_FORCEINLINE constexpr result<Ts...>
    operator()(F f, Ts ... ts) const noexcept
    requires((sizeof...(Ts) >= 1) && std::invocable<F, as_polyfloat_like_t<Ts...>>)
    //    requires((sizeof...(Ts) >= 1) && std::is_invocable<F, as_polyfloat_like_t<Ts...>>::value)
    {
      return POLYFLOAT_CALL(f, ts...);
    }

    POLYFLOAT_CALLABLE_OBJECT(cumtrapz_t, cumtrapz_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var cumtrapz
  //!   @brief convert a pack of values into
  //!     a tuple of the cumulative sum of its values
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <polyfloat/module/core.hpp>
  //!   @endcode
  //!
//!
//!   @code
//!   namespace plf
//!   {
//!      // Regular overloads
//!      constexpr auto trapz(eve::non_empty_product_type auto const& x,
//!                           eve::non_empty_product_type auto const& y)                   noexcept; // 1
//!      constexpr auto trapz(floating_value auto ... ys)                                  noexcept; // 2
//!      constexpr auto trapz(eve::non_empty_product_type auto const& y)                   noexcept; // 2
//!      constexpr auto trapz(floating_value h,
//!                           eve::non_empty_product_type auto const& y)                   noexcept; // 2
//!      constexpr auto trapz(eve::invocable f, floating_value auto ... xs)                noexcept; // 3
//!      constexpr auto trapz(eve::invocable f, eve::non_empty_product_type auto const& x) noexcept; // 3
//!   }
//!   @endcode
//!
//!   **Parameters**
//!
//!     * `xs ...` : polyfloat ordered arguments in increasing values order.
//!     * `x`,     : tuple of polyfloat ordered arguments in increasing values order.
//!     * `y`      : tuple of polyfloat arguments
//!     * `h`      : polyfloat value scaling the abscissas
//!     * `f`      : invocable requiring f :polyfloat_like_t<Xs...>() -> cpolyfloat_like_t<Xs...>.
//!
//!    **Return value**
//!
//!     1. return a kumi tuple of the values of the cumulated trapz of all `xs` converted to
//!         the element type of the common value of the `xs`. the xs have to be sorted in ascending order.
//!     2. same as 1., using the tuple elements.
//!     3. use  `f` to compute the `y` from the `xs ...` or `x`.
//!
//!  @note Where [trapz}(@ref eve::trapz) returns only the overall integral, `cumtrapz` returns a tuple
//!        of the current partialintegral values.
//!
//!  @groupheader{External references}
//!   *  [Wikipedia trapezoidal rule](https://en.wikipedia.org/wiki/Trapezoidal_rule)
//!
  //!  @groupheader{Example}
  //!  @godbolt{doc/core/cumtrapz.cpp}
  //================================================================================================
  inline constexpr auto cumtrapz = eve::functor<cumtrapz_t>;
  //================================================================================================
  //! @}
  //================================================================================================
}

namespace plf::_
{

  template <eve::product_type PT, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto cumtrapz_(POLYFLOAT_DELAY(), O const & o, PT tup) noexcept
  requires(!concepts::polyfloat_like<PT>)
  {
    std::cout << "PT tup" << std::endl;
      if constexpr(PT::size() == 0)
        return kumi::make_tuple();
      else
      {

         using r_t = kumi::apply_traits_t<plf::as_polyfloat_like, PT>;
         auto w = kumi::windows<2>(tup);
         auto r = kumi::map(plf::average, w);
//           std::cout << "r " << r << std::endl;
//           std::cout << "toto::typename_<decltype(r)> " << toto::typename_<decltype(r)> << std::endl;
//           std::cout << "toto::typename_<PT>          " << toto::typename_<PT> << std::endl;
          auto z1 = plf::cumsum(r);
//          auto z = plf::cumsum(tup);
//           std::cout << "z " << z << std::endl;
//           std::cout << "z1 " << z1 << std::endl;

          auto xx =  kumi::push_front(z1, r_t(0));
//         std::cout << "xx "<< xx << std::endl;
         //return typename cumtrapz_t<O>::template tuple_result < PT>();
         return xx;
         //         return kumi::push_front(z, r_t(0));
      }

  }

  template <concepts::polyfloat_like DX, eve::product_type PT, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto cumtrapz_(POLYFLOAT_DELAY(), O const & o, DX dx, PT tup) noexcept
  requires(!plf::concepts::polyfloat_like<PT>)
  {
    if constexpr(PT::size() == 0)
      return kumi::make_tuple();
    else
    {
      std::cout << "dxtup " << std::endl;
      using e_t =  kumi::apply_traits_t<plf::as_polyfloat, PT>;
      using r_t =  as_polyfloat_like_t<e_t, DX>;
      auto cvt = [](auto a){return plf::convert(a, eve::as_element<r_t>{});};
      auto dxtup = kumi::map([dx, cvt](auto m){return cvt(dx*m); }, tup);
      return plf::cumtrapz[o](dxtup);
//      return typename cumtrapz_t<O>::template xtuple_result <DX, PT>();

      //         using r_t = kumi::apply_traits_t<plf::as_polyfloat_like, PT>;
//          auto w = kumi::windows<2>(tup);
//          auto r = kumi::map(plf::average, w);
//          std::cout << "r " << r << std::endl;
//           auto z = plf::cumsum(r);
//           std::cout << "z " << z << std::endl;

//          auto xx = plf::cumsum(r);
//          std::cout << "xx "<< xx << std::endl;
//          return typename cumtrapz_t<O>::template tuple_result < PT>();

//            return kumi::push_front(plf::cumsum(r), r_t(0));
    }
  }

  template <eve::product_type PTX, eve::product_type PTY, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto cumtrapz_(POLYFLOAT_DELAY(), O const & o, PTX x, PTY tup) noexcept
  requires( PTX::size() == PTY::size()&& !plf::concepts::polyfloat_like<PTX> &&  !plf::concepts::polyfloat_like<PTX>)
  {
    if constexpr(PTX::size() == 0)
      return kumi::make_tuple();
    else
    {
      using r1_t = kumi::apply_traits_t<as_polyfloat_like, PTX>;
      using r2_t = kumi::apply_traits_t<as_polyfloat_like, PTY>;
      using r_t = as_polyfloat_like_t<r1_t, r2_t>;
      auto w = kumi::windows<2>(tup);
      auto dx = plf::diff(x);
      auto avg = kumi::map(plf::average, w);
      auto rdx = kumi::map([](auto a, auto b) { return -a*b; }, avg, dx);
      return kumi::push_front(plf::cumsum(rdx), r_t(0));
    }
  }

  template< typename F, concepts::polyfloat_like ...Ts, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto cumtrapz_(POLYFLOAT_DELAY(), O const & o, F f, Ts... xs) noexcept
  requires((sizeof...(Ts) >= 1) && std::is_invocable<F, as_polyfloat_like_t<Ts...>>::value)
  {
    auto x = kumi::tuple{xs...};
    auto fx = kumi::map(f, x);
    return plf::cumtrapz(x, fx);
  }


  template< typename F, eve::product_type PTX, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto cumtrapz_(POLYFLOAT_DELAY(), O const & o, F f, PTX x) noexcept

  {
    return kumi::apply([o, f](auto ...m){return cumtrapz[o](f, m...); }, x);
  }

  template<concepts::polyfloat_like ...Ts, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto
  cumtrapz_(POLYFLOAT_DELAY(), O const & o, Ts... ts) noexcept
  requires(sizeof...(Ts) > 1 )
  {
//     std::cout << " Ts... ts" << std::endl;
//       auto cvt = [](auto a){return plf::convert(a, eve::as_element<r_t>{});};
//      if constexpr(sizeof...(Ts) ==  2)
//        return kumi::tuple{cvt(0), plf::average(cvt(ts)...)};
//     else
    using r_t = as_polyfloat_like_t<Ts...>;
    auto cvt = [](auto a){return plf::convert(a, eve::as_element<r_t>{});};
    return plf::cumtrapz[o](kumi::tuple{cvt(ts)...});


  }
}
