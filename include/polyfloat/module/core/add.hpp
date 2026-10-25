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
#include <polyfloat/module/core/is_not_finite.hpp>
#include <polyfloat/module/core/if_else.hpp>

namespace plf
{

  template<typename Options> struct add_t : eve::strict_tuple_callable<add_t, Options, raw_option, pedantic_option, eve::mod_option>
  {
    template<typename... Ts> struct result : as_polyfloat_like<Ts...>
    {
    };

    template<concepts::polyfloat_like... Ts>
    requires(eve::same_lanes_or_scalar<Ts...>)
    POLYFLOAT_ABI typename result<Ts...>::type constexpr operator()(Ts... ts) const noexcept
    {
      return POLYFLOAT_CALL(ts...);
    }

    template<eve::non_empty_product_type Tup>
    requires(eve::same_lanes_or_scalar_tuple<Tup> && !concepts::polyfloat_like<Tup>)
    POLYFLOAT_ABI constexpr kumi::apply_traits_t<result, Tup> operator()(Tup const& t) const noexcept
    requires(kumi::size_v<Tup> >= 1)
    {
      return POLYFLOAT_CALL(t);
    }

    POLYFLOAT_CALLABLE_OBJECT(add_t, add_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var add
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
  //!      template<polyfloat::concepts::polyfloat_like Z1, polyfloat_like ... Zs> constexpr auto add(Z1 z1, Zs... zs) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z1`, `zs...`: Values to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the sum of the arguments.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/add.cpp}
  //======================================================================================================================

  inline constexpr auto add = eve::functor<add_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================

  template<typename Options> constexpr auto neutral(add_t<Options>) noexcept
  {
    return plf::zero;
  }

  // Required for optimisation detections
  using callable_add_ = eve::tag_t<add>;

}

namespace plf::_
{
  template<typename T0, eve::callable_options O> constexpr auto add_(POLYFLOAT_DELAY(), O const&, T0 t0) noexcept
  {
    return t0;
  }

  template<typename T1, typename T2, eve::callable_options O>
  constexpr auto add_(POLYFLOAT_DELAY(), O const& o , T1 const& a, T2 const& b) noexcept
  {
    auto s = a+b;
    if constexpr(O::contains(eve::mod))
    {
      using r_t = plf::as_polyfloat_like_t<T1, T2>;
      using u_t = eve::element_type_t<r_t>;
      auto p = o[eve::mod].value(eve::as<u_t>{});
      return plf::if_else(s >= p, s-p, p);
    }
    else
      return s;
  }

  template<eve::callable_options O,
           concepts::polyfloat_like T0,
           concepts::polyfloat_like T1,
           concepts::polyfloat_like... Ts>
  constexpr auto add_(POLYFLOAT_DELAY(), O const& o, T0 const& t0, T1 const& t1, Ts const&... ts) noexcept
  {
    using t_t = as_polyfloat_t<T0, T1, Ts...>;
    using u_t = eve::element_type_t<t_t>;
    auto cvt = [](auto a) { return plf::convert(a, as<u_t>()); };
    auto p0 = add[o](cvt(t0), cvt(t1));
    ((p0 = add[o](p0, cvt(ts))), ...);
    return p0;
  }
}

