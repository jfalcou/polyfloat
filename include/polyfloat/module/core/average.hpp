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
#include <polyfloat/module/core/parts.hpp>
#include <polyfloat/module/core/fma.hpp>

namespace plf
{

  template<typename Options>
  struct average_t : eve::strict_tuple_callable<average_t, Options, raw_option, pedantic_option>
  {
    template<typename... Ts> struct result : as_polyfloat_like<Ts...>
    {
    };

    template<concepts::polyfloat_like Z1, concepts::polyfloat_like... Zs>
    POLYFLOAT_FORCEINLINE constexpr as_polyfloat_like_t<Z1, Zs...> operator()(Z1 z1, Zs... zs) const noexcept
    {
      return POLYFLOAT_CALL(z1, zs...);
    }

    template<eve::non_empty_product_type Tup>
    POLYFLOAT_FORCEINLINE constexpr kumi::apply_traits_t<result, Tup> operator()(Tup tup) const noexcept
    requires(eve::same_lanes_or_scalar_tuple<Tup> && kumi::size_v<Tup> >= 1)
    {
      return POLYFLOAT_CALL(tup);
    }

    POLYFLOAT_CALLABLE_OBJECT(average_t, average_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var average
  //!   @brief return the mean value.
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
  //!      template<polyfloat::concepts::polyfloat_like T1, polyfloat_like Z2> constexpr auto average(T1 z1, T2 z2) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z, zs...`: Values to process.
  //!
  //!   **Return value**
  //!
  //!      Returns the average of the parameters.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/average.cpp}
  //======================================================================================================================

  inline constexpr auto average = eve::functor<average_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename T1, typename... Ts, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto average_(POLYFLOAT_DELAY(), O const& o, T1 a0, Ts... args) noexcept
  {
    using r_t = as_polyfloat_like_t<T1, Ts...>;
    using e_t = eve::element_type_t<r_t>;
    if constexpr (sizeof...(Ts) == 0) return a0;
    else
    {
      constexpr auto N = sizeof...(Ts) + 1;
      /*expr*/ e_t const invn = 1 / (e_t(N));
      if constexpr (O::contains(raw))
      {
        return eve::mul[o](add[o.drop(raw)](a0, args...), invn);
      }
      else
      {
        using u_t = eve::element_type_t<r_t>;
        auto cvt = [](auto a) { return plf::convert(a, as<u_t>()); };
        r_t that(a0 * invn);
        auto next = [invn](auto avg, auto x) { return x * invn + avg; }; //plf::fma(x, invn, avg); }; //fma ?
        ((that = next(that, cvt(args))), ...);
        return that;
      }
    }
  }
}
