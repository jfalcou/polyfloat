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

  template<typename Options> struct horner_t : eve::strict_tuple_callable<horner_t, Options, raw_option, pedantic_option>
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

    POLYFLOAT_CALLABLE_OBJECT(horner_t, horner_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var horner
  //!   @brief Implement the horner scheme to evaluate polynomials with coefficients
  //!   in decreasing power order
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
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace eve
  //!   {
  //!      // Regular overloads
  //!      constexpr auto horner(floating_value auto x, value auto ...ci)                      noexcept; // 1
  //!      constexpr auto horner(floating_value auto x, eve::coefficients auto tci)            noexcept; // 2
  //!
  //!      // Lanes masking
  //!      constexpr auto horner[conditional_expr auto c](*any of the above overloads*/)       noexcept; // 3
  //!      constexpr auto horner[logical_value auto m](*any of the above overloads*/)          noexcept; // 3
  //!
  //!      // Semantic options
  //!      constexpr auto horner[pedantic](/*any of the above overloads*/)                     noexcept; // 4
  //!      constexpr auto horner[kahan](/*any of the above overloads*/)                        noexcept; // 5
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
  //!    * `c`: [Conditional expression](@ref eve::conditional_expr) masking the operation.
  //!    * `m`: [Logical value](@ref eve::logical_value) masking the operation.
  //!
  //!   **Return value**
  //!
  //!     If \f$(c_i)_{0\le i\le n-1}\f$ denotes the coefficients of the polynomial by decreasing
  //!     power order,  the Horner scheme evaluates the polynom \f$p\f$ at \f$x\f$ by :
  //!     \f$\qquad\qquad\displaystyle p(x) = (((c_0x+c_1)x+ ... )x + c_{n-1})\f$
  //!
  //!     1. The value of the polynom at  `x` is returned.
  //!     2. Same as the call with the elements of the tuple.
  //!     3. [The operation is performed conditionnaly](@ref conditional).
  //!     4. `fma[pedantic]` instead of `fma` is used in internal computations.
  //!     5. a Kahan like compensated algorithm is used to enhance accuracy.
  //!
  //!    @note If the coefficients are simd values of cardinal N, this means you simultaneously
  //!      compute the values of N polynomials.
  //!        *  If x is scalar, the polynomials are all computed at the same point
  //!        *  If x is simd, the nth polynomial is computed on the nth value of x
  //!
  //!  @groupheader{External references}
  //!   *  [Wikipedia](https://en.wikipedia.org/wiki/Horner's_method)
  //!
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/horner.cpp}
  //======================================================================================================================

  inline constexpr auto horner = eve::functor<horner_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<typename X, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto
  horner_(POLYFLOAT_DELAY(), O const &, X ) noexcept
  {
    return eve::zero(eve::as<X>());
  }

  template<typename X, typename C, typename... Cs, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto
  horner_(POLYFLOAT_DELAY(), O const & o, X xx, C c, Cs... cs) noexcept
  {
    using r_t   =  as_polyfloat_like_t<X, C, Cs...>;
//    using u_t = eve::as_element<r_t>; //r_t::ptype_t;
//      auto cvt = [](auto a){return plf::convert(a, eve::as_element<r_t>{});};
    constexpr auto N =  sizeof...(Cs);
    if constexpr( N == 0 )
      return plf::convert(c, eve::as_element<r_t>{});
//     else if constexpr(O::contains(kahan))
//     {
//       using a_t = std::array<r_t, N>;
//       a_t err;
//       auto i = 0;
//       auto s = cvt(c);
//       auto x = cvt(xx);
//       auto step = [&s, &err, x, &i]( auto a){
//         auto [pi, epi] = eve::two_prod(s, x);
//         auto [si, esi] = eve::two_add(pi, a);
//         s = si;
//         err[i] = epi+esi;
//         ++i;
//         return s;
//       };
//       ((s = step(cvt(cs))), ...);
//       using tup_t =  kumi::result::generate_t<N, decltype([](std::size_t){return r_t(); })>;
//       auto t = std::bit_cast<tup_t, a_t>(err);
//       return s+ eve::horner(x, coefficients(t));
//     }
    else
    {
      r_t x = plf::convert(xx, eve::as_element<r_t>{}); //r_t(xx);
      r_t that(c);
      ((that = fma(that, x, plf::convert(cs, eve::as_element<r_t>{}))), ...);
      return that;
    }
  }

  template<typename X, eve::product_type Tuple, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto
  horner_(POLYFLOAT_DELAY(), O const & o, X x, eve::coefficients<Tuple> const& tup) noexcept
  {
    if constexpr(Tuple::size() == 0)
      return eve::zero(as(x));
    else
    {
      using r_t = as_polyfloat_t<X, eve::coefficients<Tuple>>;
      return kumi::apply( [&](auto... m) { return plf::horner[o](x, convert(m, eve::as_element<r_t>())...); }, tup);
    }
  }


  template<typename X, eve::_::range R, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto
  horner_(POLYFLOAT_DELAY(), O const & o, X xx, R const& r) noexcept
  {
    using r_t = as_polyfloat_like<X, typename R::value_type>;
    using u_t = eve::element_type_t<r_t>;
    auto cvt = [](auto a){return plf::convert(a,  as<u_t>());};
    auto x    = cvt(xx);
    auto cur  = std::begin(r);
    auto last = std::end(r);
    if( last == cur ) return zero(as<r_t>());
    else if( std::distance(cur, last) == 1 ) return cvt(*cur);
    else
    {
      using std::advance;
      auto that = cv_t(*cur);
      auto step = [&](auto th, auto arg) { return fma[o](x, th, arg); };
      for( advance(cur, 1); cur != last; advance(cur, 1) ) that = step(that, cv_t(*cur));
      return that;
    }
  }
}
