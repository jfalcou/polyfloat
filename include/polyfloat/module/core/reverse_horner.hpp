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
#include <eve/concept/range.hpp>
#include <polyfloat/module/core/convert.hpp>

namespace plf
{

  template<typename Options> struct reverse_horner_t : eve::strict_tuple_callable<reverse_horner_t, Options, kahan_option, raw_option, pedantic_option>
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

    template<concepts::polyfloat_like X, eve::non_empty_product_type Tup>
    requires(eve::same_lanes_or_scalar_tuple<Tup> && !concepts::polyfloat_like<Tup>)
      EVE_FORCEINLINE constexpr as_polyfloat_like_t<X, eve::coefficients<Tup>> operator()(X const & x, Tup const& t) const noexcept
    requires(kumi::size_v<Tup> >= 1)
    {
      return POLYFLOAT_CALL(x, t);
    }

    POLYFLOAT_CALLABLE_OBJECT(reverse_horner_t, reverse_horner_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var reverse_horner
  //!   @brief Implement the reverse_horner scheme to evaluate polynomials with coefficients
  //!   in decreasing power order
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
  //!      // Regular overloads
  //!      constexpr auto reverse_horner( auto x, value auto ...ci)                      noexcept; // 1
  //!      constexpr auto reverse_horner( auto x, eve::coefficients auto tci)            noexcept; // 2
  //!
  //!      // Semantic options
  //!      constexpr auto reverse_horner[kahan](/*any of the above overloads*/)          noexcept; // 3
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!    * `x`: [evaluation point floating value](@ref eve::floating_value) arguments.
  //!    * `ci...`: [floating values](@ref eve::floating_value) polynom coefficients in decreasing power order,
  //!        Note that the values of the `ci` are not necessarily floating but the non floating ones
  //!        are to be scalar
  //!    * `tci`: eve::coefficients is a specialization of [tuple](@ref eve::product_type) of floating values,
  //!             used to avoid possible ambiguities
  //!
  //!   **Return value**
  //!
  //!     If \f$(c_i)_{0\le i\le n-1}\f$ denotes the coefficients of the polynomial by decreasing
  //!     power order,  the Reverse_Horner scheme evaluates the polynom \f$p\f$ at \f$x\f$ by :
  //!     \f$\qquad\qquad\displaystyle p(x) = (((c_0x+c_1)x+ ... )x + c_{n-1})\f$
  //!
  //!     1. The value of the polynom at  `x` is returned.
  //!     2. Same as the call with the elements of the tuple.
  //!     3. a Kahan like compensated algorithm is used to enhance accuracy.
  //!
  //!    @note If the coefficients are simd values of cardinal N, this means you simultaneously
  //!      compute the values of N polynomials.
  //!        *  If x is scalar, the polynomials are all computed at the same point
  //!        *  If x is simd, the nth polynomial is computed on the nth value of x
  //!
  //!  @groupheader{External references}
  //!   *  [Wikipedia](https://en.wikipedia.org/wiki/Reverse_Horner's_method)
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/reverse_horner.cpp}
  //======================================================================================================================

  inline constexpr auto reverse_horner = eve::functor<reverse_horner_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<typename X, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto
  reverse_horner_(POLYFLOAT_DELAY(), O const &, X ) noexcept
  {
    return eve::zero(eve::as<X>());
  }

  template<typename X, typename C, typename... Cs, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto
  reverse_horner_(POLYFLOAT_DELAY(), O const & o, X xx, C c0, Cs... cs) noexcept
  {
    using r_t   =  as_polyfloat_like_t<X, C, Cs...>;
    if constexpr(dimension_v<r_t> == 1)
      return eve::reverse_horner[o](xx, c0, cs...);
    else
    {
      auto cvt = [](auto a){return plf::convert(a, eve::as_element<r_t>{});};
      constexpr auto N =  sizeof...(Cs);
      if constexpr( N == 0 )
        return plf::convert(c0, eve::as_element<r_t>{});
      else
      {
        auto x = r_t(xx);
        using t_t = kumi::result::fill_t<sizeof...(cs)+1, r_t>;
        t_t c {r_t{c0}, r_t{cs}...};
        return reverse_horner[o](x, coefficients<t_t>(c));
      }
    }
  }

  template<typename X, eve::product_type Tuple, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto
  reverse_horner_(POLYFLOAT_DELAY(), O const & o, X x, eve::coefficients<Tuple> const& tup) noexcept
  {
    return horner[o](x, eve::coefficients(kumi::reverse(tup)));
  }

  template<typename X, eve::_::range R, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto
  reverse_horner_(POLYFLOAT_DELAY(), O const & o, X xx, R const& r) noexcept
  {
    using r_t = as_polyfloat_like<X, typename R::value_type>;
    using u_t = eve::element_type_t<r_t>;
    auto cvt = [](auto a){return plf::convert(a,  as<u_t>());};
    auto x    = cvt(xx);
    auto cur  = std::rbegin(r);
    auto first = std::rend(r);
    if( first == cur ) return zero(as<r_t>());
    else if( std::distance(cur, first) == 1 ) return cvt(*cur);
    else
    {
      auto dfma = fma[o];
      auto that = cvt(zero(as<r_t>()));
      auto step = [&](auto th, auto arg) { return dfma(x, th, arg); };
      for(; cur != first; ++cur ) that = step(that, cvt(*cur));
      return that;
    }
  }
}
