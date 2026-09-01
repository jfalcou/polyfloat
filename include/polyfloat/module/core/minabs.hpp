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
  struct minabs_t : eve::strict_tuple_callable<minabs_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z1, concepts::polyfloat_like... Zs>
    POLYFLOAT_FORCEINLINE constexpr as_polyfloat_like_t<Z1, Zs...> operator()(Z1 z1, Zs... zs) const noexcept
    {
      return POLYFLOAT_CALL(z1, zs...);
    }

    POLYFLOAT_CALLABLE_OBJECT(minabs_t, minabs_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var minabs
  //!   @brief return the minimum of the absolute values.
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
  //!      template<polyfloat::concepts::polyfloat_like T1, polyfloat_like Z2> constexpr auto minabs(T1 z1, T2 z2) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z, zs...`: Values to process.
  //!
  //!   **Return value**
  //!
  //!      Returns the minimum value of the absolute of the parameters.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/minabs.cpp}
  //======================================================================================================================

  inline constexpr auto minabs = eve::functor<minabs_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================

  template<typename Options> constexpr auto neutral(minabs_t<Options>) noexcept
  {
    return plf::valmin;
  }
}

namespace plf::_
{
  template<typename Z1, typename... Zs, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto minabs_(POLYFLOAT_DELAY(), O const&, Z1 z1, Zs... zs) noexcept
  {
    if constexpr (sizeof...(Zs) == 0) return z1;
    else
    {
      using r_t = as_polyfloat_t<Z1, Zs...>;
      using u_t = eve::element_type_t<r_t>;
      auto cvt = [](auto a) { return plf::convert(a, as<u_t>()); };
      if constexpr (sizeof...(Zs) == 1)
      {
        auto az1 = plf::abs(cvt(z1));
        auto azs = plf::abs(cvt(zs...));
        return plf::if_else(plf::is_less(az1, azs), az1, azs);
      }
      else
      {
        r_t that(cvt(z1));
        ((that = minabs(that, zs)), ...);
        return that;
      }
    }
  }
}
