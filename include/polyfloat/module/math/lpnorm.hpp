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
#include <polyfloat/module/math/pow_abs.hpp>

namespace plf
{

  template<typename Options>
  struct lpnorm_t : eve::strict_tuple_callable<lpnorm_t, Options, raw_option, pedantic_option>
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

    POLYFLOAT_CALLABLE_OBJECT(lpnorm_t, lpnorm_);
  };
  //======================================================================================================================
  //! @lpnormtogroup core
  //! @{
  //!   @var lpnorm
  //!   @brief object computing the lpnorm operation \f$ \left(\sum_{i = 0}^n  |x_i|^p\right)^{\frac1p} \f$.
  //!
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
  //!      template<polyfloat::concepts::polyfloat_like Z, polyfloat_like ... Zs> constexpr auto lpnorm(Z z, Zs... zs) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z, zs...`: Values to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the sum of the arguments.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/lpnorm.cpp}
  //======================================================================================================================

  inline constexpr auto lpnorm = eve::functor<lpnorm_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================

  template<typename Options> constexpr auto neutral(lpnorm_t<Options>) noexcept
  {
    return plf::zero;
  }

  // Required for optimisation detections
  using callable_lpnorm_ = eve::tag_t<lpnorm>;

}

namespace plf::_
{
  template<typename T0, eve::callable_options O>
  EVE_FORCEINLINE constexpr auto lpnorm_(POLYFLOAT_DELAY(), O const&, T0 t0) noexcept
  {
    return plf::abs(t0);
  }

  template<typename P, typename... Ts, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto lpnorm_(POLYFLOAT_DELAY(), O const& o, P const& p, Ts... ts) noexcept
  {
    using r_t = as_polyfloat_like_t<P, Ts...>;
    using e_t = eve::element_type_t<r_t>;
    auto cvt = [](auto a) { return plf::convert(a, eve::as<e_t>()); };
    r_t rp = cvt(p);
    auto e = -plf::maxmag(-plf::if_else(-plf::is_nan(ts), zero, -plf::exponent(ts))...);
    auto f = [&](auto a) { return plf::pow_abs(-plf::ldexp[eve::pedantic](cvt(a), e), rp); };
    r_t that = plf::add[o](f(ts)...);
    return plf::ldexp[eve::pedantic](plf::pow_abs(that, plf::rec[eve::pedantic](rp)), -e);
  }
}
