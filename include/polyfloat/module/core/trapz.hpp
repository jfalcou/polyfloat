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

  template<typename Options> struct trapz_t : eve::callable<trapz_t, Options
                                                            , raw_option, pedantic_option>
  {
    template<eve::product_type Tup, typename X>
    using XTup = typename kumi::result::push_back< Tup, X >::type;

   // one sequence of polyfloat
    template<concepts::polyfloat_like ...Ts>
    POLYFLOAT_FORCEINLINE constexpr plf::as_polyfloat_like_t<Ts...>
    operator()(Ts ... ts) const noexcept
    {
      return POLYFLOAT_CALL(ts...);
    }

    // one tuple of polyfloat
    template<eve::non_empty_product_type PT>
    POLYFLOAT_FORCEINLINE constexpr kumi::apply_traits_t<as_polyfloat_like, PT>
    operator()(PT t) const noexcept
    requires(!concepts::polyfloat_like<PT>)
    {
      return POLYFLOAT_CALL(t);
    }

    // one polyfloat and one tuple of polyfloat
    template<concepts::polyfloat_like X, eve::non_empty_product_type Y>
    POLYFLOAT_FORCEINLINE constexpr kumi::apply_traits_t<as_polyfloat_like, XTup<Y, X>>
    operator()(X dx, Y y) const noexcept
    requires(!concepts::polyfloat_like<Y>)
    {
      return POLYFLOAT_CALL(dx, y);
    }

    // two polyfloat tuples
    template<eve::non_empty_product_type X, eve::non_empty_product_type Y>
    POLYFLOAT_FORCEINLINE constexpr kumi::apply_traits_t<as_polyfloat_like, kumi::result::cat_t<X, Y>>
    operator()(X x, Y y) const noexcept
    requires(!concepts::polyfloat_like<X> && !concepts::polyfloat_like<Y>)
    {
      return POLYFLOAT_CALL(x, y);
    }

    // an invocable f and a sequence  of polyfloat
    template<typename F, concepts::polyfloat_like ...Ts>
    POLYFLOAT_FORCEINLINE constexpr auto
    operator()(F f, Ts ... ts) const noexcept -> decltype(f(as_polyfloat_like_t<Ts...>()))
    requires((sizeof...(Ts) >= 1) && std::invocable<F, as_polyfloat_like_t<Ts...>>)
    {
      return POLYFLOAT_CALL(f, ts...);
    }

    // an invocable f and a tuple of polyfloat
    template<typename F, eve::non_empty_product_type X>
    POLYFLOAT_FORCEINLINE constexpr auto
    operator()(F f, X x) const noexcept -> decltype(f(kumi::apply_traits_t<as_polyfloat_like, X>()))
      requires (std::invocable<F, typename kumi::apply_traits<as_polyfloat, X>::type> && !concepts::polyfloat_like<X>)
    {
      return POLYFLOAT_CALL(f, x);
    }


    POLYFLOAT_CALLABLE_OBJECT(trapz_t, trapz_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var trapz
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
//!  @note Where [trapz}(@ref eve::trapz) returns only the overall integral, `trapz` returns a tuple
//!        of the current partialintegral values.
//!
//!  @groupheader{External references}
//!   *  [Wikipedia trapezoidal rule](https://en.wikipedia.org/wiki/Trapezoidal_rule)
//!
  //!  @groupheader{Example}
  //!  @godbolt{doc/core/trapz.cpp}
  //================================================================================================
  inline constexpr auto trapz = eve::functor<trapz_t>;
  //================================================================================================
  //! @}
  //================================================================================================
}

namespace plf::_
{

  // one tuple of polyfloat
  template <eve::product_type PT, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto trapz_(POLYFLOAT_DELAY(), O const & o,
                                              PT tup) noexcept
  requires(!concepts::polyfloat_like<PT>)
  {
    if constexpr(PT::size() == 2)
      return plf::average(tup);
    else
      return plf::add[o](tup)-plf::average[o](kumi::front(tup), kumi::back(tup));
  }

  // one sequence  of polyfloat
  template<concepts::polyfloat_like ...Ts, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto
  trapz_(POLYFLOAT_DELAY(), O const & o,
         Ts... ts) noexcept
  requires(sizeof...(Ts) > 1 )
  {
    using r_t = as_polyfloat_like_t<Ts...>;
    auto cvt = [](auto a){return plf::convert(a, eve::as_element<r_t>{});};
    return plf::trapz[o](kumi::tuple{ts...}); //cvt(ts)...});
  }

  // one polyfloat and one tuple of polyfloat
  template <concepts::polyfloat_like DX, eve::product_type PT, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto trapz_(POLYFLOAT_DELAY(), O const & o,
                                              DX dx, PT tup) noexcept
  requires(!plf::concepts::polyfloat_like<PT>)
  {
    return dx*trapz[o](tup);
  }

  // two polyfloat tuples
  template <eve::product_type PTX, eve::product_type PTY, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto trapz_(POLYFLOAT_DELAY(), O const & o,
                                              PTX x, PTY y) noexcept
  requires( PTX::size() == PTY::size()&& !plf::concepts::polyfloat_like<PTX> &&  !plf::concepts::polyfloat_like<PTX>)
  {
    if constexpr(PTX::size() == 1)
      return plf::zero(eve::as(kumi::get<0>(x)+kumi::get<0>(y)));
    else
    {
      auto adjdiff =  kumi::map(plf::sub[o], kumi::pop_front(x), kumi::pop_back(x));
      auto adjsum  =  kumi::map(plf::add[o], kumi::pop_front(y), kumi::pop_back(y));
      return plf::dot[o](adjsum, adjdiff)/2;
    }
  }

  // an invocable f and a sequence  of polyfloat
  template< typename F, concepts::polyfloat_like ...Ts, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto trapz_(POLYFLOAT_DELAY(), O const & o,
                                              F f, Ts... xs) noexcept
  requires((sizeof...(Ts) >= 1) && std::is_invocable<F, as_polyfloat_like_t<Ts...>>::value)
  {
    using r_t =  as_polyfloat_like_t<Ts...>;
    auto cvt = [](auto a){return plf::convert(a, eve::as_element<r_t>{});};
    auto x = kumi::tuple{cvt(xs)...};
    auto fx = kumi::map(f, x);
    return plf::trapz(x, fx);
  }


  // an invocable f and a tuple  of polyfloat
  template< typename F, eve::product_type PTX, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto trapz_(POLYFLOAT_DELAY(), O const & o,
                                              F f, PTX x) noexcept

  requires((PTX::size() >= 1)
           && !concepts::polyfloat_like<F>
           &&  !concepts::polyfloat_like<PTX>
           &&  !kumi::is_product_type_v<F>
          )
  {
    if constexpr(PTX::size() == 1)
      return plf::zero(eve::as(f(get<0>(x))));
    else
      return kumi::apply([o, f](auto ...m){return trapz[o](f, m...); }, x);
  }

}
