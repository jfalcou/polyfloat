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
#include <polyfloat/module/core/if_else.hpp>
#include <polyfloat/module/core/is_less.hpp>
#include <polyfloat/module/core/parts.hpp>

namespace plf
{

  template<typename Options>
  struct minmax_t : eve::strict_tuple_callable<minmax_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z1, concepts::polyfloat_like... Zs>
    POLYFLOAT_FORCEINLINE constexpr kumi::tuple<as_polyfloat_like_t<Z1, Zs...>, as_polyfloat_like_t<Z1, Zs...>>
    operator()(Z1 z1, Zs... zs) const noexcept
    {
      return POLYFLOAT_CALL(z1, zs...);
    }

    POLYFLOAT_CALLABLE_OBJECT(minmax_t, minmax_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var minmax
  //!   @brief return the minimum and maximum values.
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
  //!      template<polyfloat::concepts::polyfloat_like Ts...> constexpr auto minmax(Ts...zs) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `zs...`: Values to process.
  //!
  //!   **Return value**
  //!
  //!      Returns the kumi pair of the minimum and maximum value of the parameters.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/minmax.cpp}
  //======================================================================================================================

  inline constexpr auto minmax = eve::functor<minmax_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================

}

namespace plf::_
{
  template<typename Z1, typename... Zs, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto minmax_(POLYFLOAT_DELAY(), O const&, Z1 const& z1, Zs... zs) noexcept
  {
    if constexpr (sizeof...(Zs) == 0) return eve::zip(z1, z1);
    else
    {
      using r_t = as_polyfloat_t<Zs...>;
      using u_t = eve::element_type_t<r_t>;
      auto cvt = [](auto a) { return plf::convert(a, as<u_t>()); };
      if constexpr (sizeof...(Zs) == 1)
      {
        auto zz1 = cvt(z1);
        auto zzs = cvt(zs...);
        auto check = zz1 < zzs;
        return eve::zip(plf::if_else(check, zz1, zzs), if_else(check, zzs, zz1));
      }
      else
      {
        return eve::zip(plf::min(z1, zs...), plf::max(z1, zs...));
      }
    }
  }
}
