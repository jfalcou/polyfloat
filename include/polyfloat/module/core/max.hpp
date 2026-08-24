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

  template<typename Options> struct max_t : eve::callable<max_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z1,  concepts::polyfloat_like ...Zs>
      POLYFLOAT_FORCEINLINE constexpr as_polyfloat_like_t<Z1, Zs...> operator()(Z1 z1, Zs ...zs) const noexcept
    {
     return POLYFLOAT_CALL(z1, zs...);
    }

    POLYFLOAT_CALLABLE_OBJECT(max_t, max_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var max
  //!   @brief return the maximum value.
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
  //!      template<polyfloat::concepts::polyfloat_like T1, polyfloat_like Z2> constexpr auto max(T1 z1, T2 z2) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z, zs...`: Values to process.
  //!
  //!   **Return value**
  //!
  //!      Returns the maximum value of the parameters.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/max.cpp}
  //======================================================================================================================

  inline constexpr auto max = eve::functor<max_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================

  template <typename Options>
  constexpr auto neutral(max_t<Options>) noexcept { return plf::valmin; }
}

namespace plf::_
{
  template<typename Z1, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto max_(POLYFLOAT_DELAY(), O const& , Z1 z1) noexcept
  {
    return z1;
  }

  template<typename Z0, typename Z1, typename ... Zs, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto max_(POLYFLOAT_DELAY(), O const& , Z0 z0, Z1 z1, Zs ...zs) noexcept
  {
    using r_t = as_polyfloat_t<Z0, Z1, Zs...>;
    using u_t = eve::element_type_t<r_t>;
    auto cvt = [](auto a){return plf::convert(a,  as<u_t>());};
    if constexpr(sizeof...(Zs) == 0)
    {
      return plf::if_else(plf::is_less(cvt(z0), cvt(z1)), cvt(z1), cvt(z0));
    }
    else
    {
      r_t that = max(cvt(z0), cvt(z1));
      ((that = max(that, zs)), ...);
      return that;
    }
  }
}
