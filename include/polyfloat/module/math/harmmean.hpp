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
  struct harmmean_t : eve::strict_tuple_callable<harmmean_t, Options, raw_option, pedantic_option>
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

    POLYFLOAT_CALLABLE_OBJECT(harmmean_t, harmmean_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var harmmean
  //!   @brief  Callable object computing the harmonic mean of the inputs.\f$ \fracn{\sum \frac1/xs} \f$.
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
  //!      template<polyfloat::concepts::polyfloat_like T1, polyfloat_like Z2> constexpr auto harmmean(T1 z1, T2 z2) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z, zs...`: Values to process.
  //!
  //!   **Return value**
  //!
  //!      Returns the harmmean of the parameters.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/harmmean.cpp}
  //======================================================================================================================

  inline constexpr auto harmmean = eve::functor<harmmean_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename T1, typename... Ts, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto harmmean_(POLYFLOAT_DELAY(), O const& o, T1 a0, Ts... args) noexcept
  {
    if constexpr (sizeof...(Ts) == 0) return a0;
    else
    {
      using r_t = as_polyfloat_like_t<T1, Ts...>;
      using e_t = eve::element_type_t<r_t>;
      auto cvt = [](auto a) { return plf::convert(a, as<e_t>()); };
      return plf::rec[eve::pedantic](
        plf::average[o](plf::rec[eve::pedantic](cvt(a0)), plf::rec[pedantic](cvt(args))...));
    }
  }
}
