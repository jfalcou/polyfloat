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
#include <polyfloat/module/core/is_nan.hpp>
#include <polyfloat/module/core/maxmag.hpp>

namespace plf
{

  template<typename Options> struct hypot_t : eve::strict_tuple_callable<hypot_t, Options, raw_option, pedantic_option>
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

    template<eve::non_empty_product_type Tup>
    requires(eve::same_lanes_or_scalar_tuple<Tup> && !concepts::polyfloat_like<Tup>)
    EVE_FORCEINLINE constexpr kumi::apply_traits_t<result, Tup> operator()(Tup const& t) const noexcept
    requires(kumi::size_v<Tup> >= 1)
    {
      return POLYFLOAT_CALL(t);
    }

    POLYFLOAT_CALLABLE_OBJECT(hypot_t, hypot_);
  };
  //======================================================================================================================
  //! @hypottogroup core
  //! @{
  //!   @var hypot
  //!   @brief return the sum of the parameters.
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
  //!      template<polyfloat::concepts::polyfloat_like Z1, polyfloat_like Z2> constexpr auto hypot(Z1 z1, Z2 z2) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z1`, `z2`: Values to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the sum of the arguments.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/hypot.cpp}
  //======================================================================================================================

  inline constexpr auto hypot = eve::functor<hypot_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================

  template <typename Options>
  constexpr auto neutral(hypot_t<Options>) noexcept { return plf::zero; }

  // Required for optimisation detections
  using callable_hypot_ = eve::tag_t<hypot>;

}

namespace plf::_
{
  template<typename T0, eve::callable_options O>
  EVE_FORCEINLINE constexpr auto hypot_(POLYFLOAT_DELAY(), O const&, T0 t0) noexcept
  {
    return plf::abs(t0);
  }

  template<eve::callable_options O, concepts::polyfloat_like T0, concepts::polyfloat_like T1, concepts::polyfloat_like... Ts>
  POLYFLOAT_FORCEINLINE constexpr auto hypot_(POLYFLOAT_DELAY(), O const& o,
                                            T0 const& r0, T1 const& r1, Ts const&... rs) noexcept
  {
    if constexpr(O::contains(raw))
    {
      return plf::sqrt(plf::sum_of_squares(r0, r1, rs...));
    }
    else
    {
      using r_t = as_polyfloat_t<T0, T1, Ts...>;
      if constexpr (dimension_v<r_t> == 1)
        return eve::hypot[o](r0, r1, rs...);
      else
      {
        auto cvt = [](auto a){return plf::convert(a, eve::as_element<r_t>{});};
        auto expo = [&](auto x){return if_else(plf::is_nan(x), eve::zero, plf::exponent(cvt(x))); };
        auto e  = -eve::maxmag(expo(r0), expo(r1), expo(rs)...);
        if constexpr(O::contains(pedantic))
        {
          auto nan_found = plf::false_(eve::as<r_t>());
          auto f = [&](auto a){
            nan_found = plf::is_nan(a);
            return if_else(nan_found, zero, plf::sqr(ldexp[o](cvt(a), e)));
          };
          r_t that = plf::add[o](f(r0), f(r1), f(rs)...);
          auto r = plf::ldexp[pedantic](plf::sqrt(that), -e);
          return if_else(nan_found && !is_infinite(r), plf::nan, r);
        }
        else
        {
          auto f = [&](auto a){ return cvt(plf::sqr(ldexp[o](cvt(a), e))); };
          r_t that = plf::add[o](f(r0), f(r1), f(rs)...);
          return plf::ldexp[pedantic](plf::sqrt(that), -e);
        }
      }
    }
  }

}
