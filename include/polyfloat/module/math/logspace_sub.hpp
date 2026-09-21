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
  struct logspace_sub_t : eve::strict_tuple_callable<logspace_sub_t, Options, raw_option, pedantic_option>
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

    POLYFLOAT_CALLABLE_OBJECT(logspace_sub_t, logspace_sub_);
  };
  //======================================================================================================================
  //! @addtogroup math
  //! @{
  //!   @var logspace_sub
  //!   @brief object computing the logspace_sub operation: \f$\log\left(e^{\log x_0}-\sum_{i = 1}^n e^{\log x_i}\right)\f$.
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
  //!      template<polyfloat::concepts::polyfloat_like Z, polyfloat_like ... Zs> constexpr auto logspace_sub(Z z, Zs... zs) noexcept;
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
  //!  @godbolt{doc/math/logspace_sub.cpp}
  //======================================================================================================================

  inline constexpr auto logspace_sub = eve::functor<logspace_sub_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename T0, eve::callable_options O>
  EVE_FORCEINLINE constexpr auto logspace_sub_(POLYFLOAT_DELAY(), O const&, T0 t0) noexcept
  {
    return plf::abs(t0);
  }

  template<typename T0, typename T1, typename... Ts, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto logspace_sub_(
    POLYFLOAT_DELAY(), O const& o, T0 const& t0, T1 const& t1, Ts... ts) noexcept
  {
    using r_t = as_polyfloat_like_t<T0, T1, Ts...>;
    using e_t = eve::element_type_t<r_t>;
    auto cvt = [](auto a) { return plf::convert(a, eve::as<e_t>()); };
    if constexpr (sizeof...(Ts) == 0)
    {
      auto r0 = cvt(t0);
      auto r1 = cvt(t1);
      auto x = r1 - r0;
      auto test = x > -log_2(as(x));
      if (eve::all(test)) return r0 + plf::log(-plf::expm1(x));
      else if (eve::any(test)) return r0 + if_else(test, log[o](-expm1(x)), plf::log[o](plf::oneminus(exp(x))));
      else return r0 + plf::log(plf::oneminus(plf::exp(x)));
    }
    else
    {
      r_t that(logspace_sub[o](t0, t1));
      auto lsub = [o](auto that_, auto next) -> r_t {
        that_ = logspace_sub[o](that_, next);
        return that_;
      };
      ((that = lsub(that, ts)), ...);
      return that;
    }
  }
}
