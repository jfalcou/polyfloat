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
  struct minmag_t : eve::strict_tuple_callable<minmag_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z1, concepts::polyfloat_like... Zs>
    POLYFLOAT_FORCEINLINE constexpr as_polyfloat_like_t<Z1, Zs...> operator()(Z1 z1, Zs... zs) const noexcept
    {
      return POLYFLOAT_CALL(z1, zs...);
    }

    POLYFLOAT_CALLABLE_OBJECT(minmag_t, minmag_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var minmag
  //!   @brief return the value having the minimum of the absolute values.
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
  //!      template<polyfloat::concepts::polyfloat_like T1, polyfloat_like Z2> constexpr auto minmag(T1 z1, T2 z2) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z, zs...`: Values to process.
  //!
  //!   **Return value**
  //!
  //!      Returns the value having the minimum of the absolute of the parameters.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/minmag.cpp}
  //======================================================================================================================

  inline constexpr auto minmag = eve::functor<minmag_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================

  template<typename Options> constexpr auto neutral(minmag_t<Options>) noexcept
  {
    return plf::valmin;
  }
}

namespace plf::_
{
  template<typename Z1, typename... Zs, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto minmag_(POLYFLOAT_DELAY(), O const&, Z1 z1, Zs... zs) noexcept
  {
    if constexpr (sizeof...(Zs) == 0) return z1;
    else
    {
      using r_t = as_polyfloat_t<Z1, Zs...>;
      using u_t = eve::element_type_t<r_t>;
      auto cvt = [](auto a) { return plf::convert(a, as<u_t>()); };
      if constexpr (sizeof...(Zs) == 1)
      {
        auto zz1 = cvt(z1);
        auto zzs = cvt(zs...);
        return plf::if_else(plf::is_less(plf::abs(zz1), plf::abs(zzs)), zz1, zzs);
      }
      else
      {
        r_t that(cvt(z1));
        ((that = minmag(that, zs)), ...);
        return that;
      }
    }
  }
}
