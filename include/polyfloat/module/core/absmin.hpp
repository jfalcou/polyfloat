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
#include <polyfloat/module/core/min.hpp>

namespace plf
{

  template<typename Options> struct absmin_t : eve::strict_tuple_callable<absmin_t, Options, raw_option, pedantic_option>
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

    POLYFLOAT_CALLABLE_OBJECT(absmin_t, absmin_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var absmin
  //!   @brief return the absolute value of the minimum of the parameters.
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <kyosu/module/core.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace kyosu
  //!   {
  //!      template<kyosu::concepts::polyfloat_like Z1, polyfloat_like Z2> constexpr auto absmin(Z1 z1, Z2 z2) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z1`, `z2`: Values to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the absolute value of the minimum of the arguments.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/absmin.cpp}
  //======================================================================================================================

  inline constexpr auto absmin = eve::functor<absmin_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<eve::callable_options O, concepts::polyfloat_like T0, concepts::polyfloat_like... Ts>
  POLYFLOAT_FORCEINLINE constexpr auto absmin_(POLYFLOAT_DELAY(), O const& o,
                                               T0 const& t0, Ts const&... ts) noexcept
  {
    return plf::abs[o.drop(pedantic,numeric)](plf::min(t0, ts...));
  }

}
