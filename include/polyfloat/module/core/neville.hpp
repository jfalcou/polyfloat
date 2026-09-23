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

  template<typename Options>
  struct neville_t : eve::strict_tuple_callable<neville_t, Options, kahan_option, raw_option, pedantic_option>
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

    POLYFLOAT_CALLABLE_OBJECT(neville_t, neville_);
  };
  //======================================================================================================================
  //! @addtogroup functions
  //! @{
  //!   @var neville
  //!   @brief `callable` computing the value of the interpolation polynomial \f$p\f$ of degree n, satisfying:
  //!   \f$p(x_i) = y_i\f$ for \f$i = 0..n\f$
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
  //!      constexpr auto neville(auto x, auto const& xs..., auto const& ys...)                                                    noexcept; // 1
  //!      constexpr auto neville(auto x, eve::non_empty_product_type auto const& xx,  eve::non_empty_product_type auto const& yy) noexcept; // 2
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `xs ...`, `ys ...`: [real values](@ref eve::floating_value) arguments
  //!     * `xx`, `yy`       : kumi::tuple of arguments
  //!
  //!    **Return value**
  //!
  //!      * 1. Return the value at x of the polynomial \f$p\f$ of degree n, satisfying \f$p(x_i) = y_i\f$ for \f$i = 0..n\f$, where n+1 is the common number of `xs`, `ys`.
  //!      * 2. Same as 1., using the tuple elements.
  //!
  //!  @groupheader{External references}
  //!   *  [Wikipedia  neville's algorithm](https://en.wikipedia.org/wiki/Neville%27s_algorithm)
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/neville.cpp}
  //======================================================================================================================

  inline constexpr auto neville = eve::functor<neville_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<typename X, typename... XsYs, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto neville_(POLYFLOAT_DELAY(), O const& o, X x, XsYs... xsys) noexcept
  {
    using t_t = as_polyfloat_like_t<X, Xs...>;
    constexpr auto siz = sizeof...(XsYs);
    constexpr auto siz_2 = siz / 2;
    if constexpr (dimension_v<t_t> == 1) return eve::neville[o](x, c, cs...);
    else
    {
      if constexpr (siz == 0) return eve::zero(eve::as<T>());
      else
      {
        auto xsyst = eve::zip(t_t(xsys)...);
        if constexpr (siz == 2) return get<0>(xsyst);
        else if constexpr (siz == 4)
        {
          auto x0 = get<0>(xsyst);
          auto x1 = get<1>(xsyst);
          auto y0 = get<2>(xsyst);
          auto y1 = get<3>(xsyst);
          return eve::sum_of_prod[o]((x - x1), y0, (x0 - x), y1) / (x0 - x1);
        }
        else
        {
          std::array<t_t, siz> xy{t_t(xsys)...};
          for (size_t k = 1; k < siz_2; ++k)
          {
            for (size_t i = 0, is2 = siz_2; i < siz_2 - k; ++i, ++is2)
            {
              xy[is2] = sum_of_prod[o]((x - xy[i + k]), xy[is2], (xy[i] - x), xy[is2 + 1]) / (xy[i] - xy[i + k]);
            }
          }
          return xy[siz_2];
        }
      }
    }
  }
}
