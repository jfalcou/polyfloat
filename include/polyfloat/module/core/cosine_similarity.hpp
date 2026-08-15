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

  template<typename Options> struct cosine_similarity_t : eve::strict_tuple_callable<cosine_similarity_t, Options, kahan_option, raw_option, pedantic_option>
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

    template<eve::non_empty_product_type Tup>
    requires(eve::same_lanes_or_scalar_tuple<Tup> && !concepts::polyfloat_like<Tup>)
    EVE_FORCEINLINE constexpr kumi::apply_traits_t<result, Tup> operator()(Tup const& t) const noexcept
    requires(kumi::size_v<Tup> >= 1)
    {
      return POLYFLOAT_CALL(t);
    }

    POLYFLOAT_CALLABLE_OBJECT(cosine_similarity_t, cosine_similarity_);
  };
  //======================================================================================================================
  //! @cosine_similaritytogroup core
  //! @{
  //!   @var cosine_similarity
  //!   @brief return the cosine_similarity product  of the vector of the first half of parameters by
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
  //!      constexpr auto cosine_similarity(auto ... xs, auto value... ys)        noexcept; // 1
  //!      constexpr auto cosine_similarity(kumi::tuple xs, kumi::tuple ys)       noexcept; // 2
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `xs`, `ys`: Values to process.
  //!
  //!   **Return value**
  //!
  //!    1. cosine_similarity product. \f$\frac{\sum_s (x_s*y_s)}{\sqrt{\sum_s (x_s^2)*\sum_s (y_s^2)}}\f$.
  //!       It is the cosine of the angle between the two vectors. One or minus one means thaat the vectors are proportionnal,
  //!       zero that they are orthogonal.
  //!    2. use the content of the tuples
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/core/cosine_similarity.cpp}
  //======================================================================================================================

  inline constexpr auto cosine_similarity = eve::functor<cosine_similarity_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<eve::callable_options O, concepts::polyfloat_like... Ts>
  POLYFLOAT_FORCEINLINE constexpr auto cosine_similarity_(POLYFLOAT_DELAY(), O const& o, Ts const&... args) noexcept
  requires(sizeof...(Ts) > 1  && sizeof...(Ts)%2 == 0)
  {
    using r_t =  as_polyfloat_like_t<Ts...>;
    using u_t = eve::element_type_t<r_t>;
    auto cvt = [](auto a){return plf::convert(a,  as<u_t>());};
    auto coeffs = eve::zip(cvt(args)...);
    auto[f,s]   = kumi::split(coeffs, kumi::index<sizeof...(Ts)/2>);
    return cosine_similarity(f, s);
  }

  template<eve::non_empty_product_type PT1,
           eve::non_empty_product_type PT2, callable_options O>
    POLYFLOAT_FORCEINLINE constexpr auto cosine_similarity_(POLYFLOAT_DELAY(), O const & o, PT1 f, PT2 s) noexcept
    requires (kumi::as_tuple_t<PT1>::size() == kumi::as_tuple_t<PT2>::size())
    {
      using Tup1 = kumi::as_tuple_t<PT1>;
      using Tup2 = kumi::as_tuple_t<PT2>;
      constexpr auto siz = Tup1::size();
      if constexpr(siz == 1)
      {
        return eve::sign(get<0>(f)*get<0>(s));
      }
      else
      {
        using r1_t = kumi::apply_traits_t<plf::as_polyfloat_like, Tup1>;
        using r2_t = kumi::apply_traits_t<plf::as_polyfloat_like, Tup2>;
        using r_t =  plf::as_polyfloat_like_t<r1_t, r2_t>;

        auto sa2 = eve::sum_of_squares[o](f);
        auto sb2 = eve::sum_of_squares[o](s);
        auto sab = eve::dot[o](f, s);
        auto r = sab*eve::rsqrt(sa2*sb2);
        return plf::if_else(plf::is_eqz(sab), zero, plf::if_else(is_eqz(sa2)||is_eqz(sb2), sa2*sb2, r));
      }
    }
  }
}
