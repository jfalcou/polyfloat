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
#include <polyfloat/module/core/max.hpp>

namespace plf
{

  template<typename Options>
  struct variance_t : eve::strict_tuple_callable<variance_t, Options, raw_option, pedantic_option>
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

    POLYFLOAT_CALLABLE_OBJECT(variance_t, variance_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var variance
  //!   @brief return the absolute value of the maximum of the parameters.
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
  //!      template<polyfloat::concepts::polyfloat_like Z1, polyfloat_like Z2> constexpr auto variance(Z1 z1, Z2 z2) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z1`, `z2`: Values to process.
  //!
  //!   **Return value**
  //!
  //!      Returns the absolute value of the maximum of the arguments.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/variance.cpp}
  //======================================================================================================================

  inline constexpr auto variance = eve::functor<variance_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<eve::callable_options O, concepts::polyfloat_like T0, concepts::polyfloat_like... Ts>
  POLYFLOAT_FORCEINLINE constexpr auto variance_(POLYFLOAT_DELAY(),
                                                 O const& o,
                                                 T0 const& a0,
                                                 Ts const&... args) noexcept
  {
    auto avg = plf::average[o](a0, args...);
    auto var = plf::average[o](plf::sqr(a0 - avg), plf::sqr(args - avg)...);
    if constexpr (O::contains(raw)) return var;
    else return var - plf::sqr(plf::average[o](a0 - avg, (args - avg)...));
  }

}
