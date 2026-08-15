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
#include <polyfloat/module/core/abs.hpp>

namespace plf
{

  template<typename Options> struct add_t : eve::strict_tuple_callable<add_t, Options, raw_option, pedantic_option>
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
  //!      template<polyfloat::concepts::polyfloat_like Z1, polyfloat_like Z2> constexpr auto add(Z1 z1, Z2 z2) noexcept;
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
  //!  @godbolt{doc/core/add.cpp}
  //======================================================================================================================

  inline constexpr auto add = eve::functor<add_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================

  template <typename Options>
  constexpr auto neutral(add_t<Options>) noexcept { return plf::zero; }

  // Required for optimisation detections
  using callable_add_ = eve::tag_t<add>;

}

namespace plf::_
{
  template<typename T0, eve::callable_options O>
  EVE_FORCEINLINE constexpr auto add_(POLYFLOAT_DELAY(), O const&, T0 t0) noexcept
  {
    return t0;
  }
    template<typename T1, typename T2, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto add_(POLYFLOAT_DELAY(), O const& , T1 const& t1, T2 const& t2) noexcept
  {
    return t1+t2;
  }

  template<eve::callable_options O, concepts::polyfloat_like T0, concepts::polyfloat_like T1, concepts::polyfloat_like... Ts>
  POLYFLOAT_FORCEINLINE constexpr auto add_(POLYFLOAT_DELAY(), O const& o,
                                            T0 const& t0, T1 const& t1, Ts const&... ts) noexcept
  {
    using t_t = as_polyfloat_t<T0, T1, Ts...>;
    if constexpr (concepts::real<t_t>)
      return eve::add[o](t0, t1, ts...);
    else
    {
      using u_t = eve::element_type_t<t_t>;
      auto cvt = [](auto a){return plf::convert(a,  as<u_t>());};
      auto p0   = add[o](cvt(t0),cvt(t1));
      ((p0 = add[o](p0,cvt(ts))),...);
      return p0;
    }
  }

}
