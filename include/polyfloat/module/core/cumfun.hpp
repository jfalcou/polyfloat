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

namespace plf
{

  template<typename Options> struct cumfun_t : eve::strict_tuple_callable<cumfun_t, Options, raw_option, pedantic_option>
  {
    template<typename T>
    using return_type = T;

    template<typename... Ts>
    using result = kumi::result::fill_t<sizeof...(Ts), return_type<plf::as_polyfloat_like_t<Ts...>>>;

    template<eve::product_type Tup>
    using tuple_result = kumi::result::fill_t< Tup::size(), return_type<kumi::apply_traits_t<as_polyfloat_like, Tup>>>;

    template<typename F, concepts::polyfloat_like ... Zs>
    POLYFLOAT_FORCEINLINE result<Zs...> constexpr operator()(F f, Zs const& ...zs) const noexcept
    {
      return POLYFLOAT_CALL(f, zs...);
    }

    template<typename F, eve::non_empty_product_type PT>
    POLYFLOAT_FORCEINLINE constexpr tuple_result<PT>
    operator()(  F f, PT t) const noexcept
    {
      return POLYFLOAT_CALL(f, t);
    }

    POLYFLOAT_CALLABLE_OBJECT(cumfun_t, cumfun_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var cumfun
  //!   @brief convert a pack of values into
  //!     a tuple of the cumulative application of a two parameter eve fonction defining
  //!     an abelian monoid.
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <polyfloat/module/core.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!      // Regular overloads
  //!      constexpr auto cumfun(typename f, eve::value auto ... xs)     noexcept; // 1
  //!      constexpr auto cumfun(typename f, non_empty_product_type tup) noexcept; // 2
  //!
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `f`: invocable of two arguments.
  //!     * `xs...`: [values](@ref eve::value) arguments.
  //!     * `tup`: kumi tuple of values.
  //!
  //!    **Return value**
  //!
  //!     1. return a kumi tuple of the values of the cumulated values of all `xs` converted to
  //!         the element type of the common value of the `xs` using f.
  //!     2. same as 1., using the tuple elements.
  //!
  //!  @note currently cumfun can be applied with `f` being one of these POLYFLOAT functors :
  //!   `add`, `mul`, `min`, `max` that define abelian monoids and each possess
  //!   `a well defined neutral element.
  //!
  //!  @groupheader{Example}
  //!  @godbolt{doc/core/cumfun.cpp}
  //================================================================================================
  inline constexpr auto cumfun = eve::functor<cumfun_t>;
  //================================================================================================
  //! @}
  //================================================================================================
}

namespace plf::_
{
  template <typename F, eve::product_type PT, eve::callable_options O>
  EVE_FORCEINLINE constexpr auto cumfun_(POLYFLOAT_DELAY(), O const & o, F f, PT tup) noexcept
  {
    if constexpr(PT::size() == 0)
      return kumi::make_tuple();
    else
    {
      using e_t =  kumi::apply_traits_t<plf::as_polyfloat, PT>;
      auto n = neutral(f)(eve::as<e_t>());
      auto cvt = [](auto a){return plf::convert(a, eve::as_element<e_t>{});};
      return kumi::inclusive_scan_left(f[o], kumi::map(cvt, tup), n);
    }
  }

  template<typename F, typename ...Ts, eve::callable_options O>
  EVE_FORCEINLINE constexpr auto
  cumfun_(POLYFLOAT_DELAY(), O const & o, F f, Ts... ts) noexcept
  {
    return plf::cumfun[o](f, kumi::make_tuple(ts...));
  }
}
