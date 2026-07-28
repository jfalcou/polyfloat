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
#include <polyfloat/functions/abs.hpp>
#include <polyfloat/functions/if_else.hpp>
#include <polyfloat/functions/is_less.hpp>
#include <polyfloat/functions/parts.hpp>

namespace plf
{

  template<typename Options> struct min_t : eve::strict_tuple_callable<min_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z1,  concepts::polyfloat_like ...Zs>
      POLYFLOAT_FORCEINLINE constexpr as_polyfloat_like_t<Z1, Zs...> operator()(Z1 z1, Zs ...zs) const noexcept
    {
     return POLYFLOAT_CALL(z1, zs...);
    }

    POLYFLOAT_CALLABLE_OBJECT(min_t, min_);
  };
  //======================================================================================================================
  //! @addtogroup functions
  //! @{
  //!   @var min
  //!   @brief return the minimum value.
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <kyosu/functions.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace kyosu
  //!   {
  //!      template<kyosu::concepts::polyfloat_like T1, polyfloat_like Z2> constexpr auto min(T1 z1, T2 z2) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z, zs...`: Values to process.
  //!
  //!   **Return value**
  //!
  //!      Returns the minimum value of the parameters.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/min.cpp}
  //======================================================================================================================

  inline constexpr auto min = eve::functor<min_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z1, typename ... Zs, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto min_(POLYFLOAT_DELAY(), O const& , Z1 z1, Zs ...zs) noexcept
  {
    using r_t = as_polyfloat_t<Z1, Zs...>;
    using u_t = eve::element_type_t<r_t>;
    auto cvt = [](auto a){return plf::convert(a,  as<u_t>());};
    if constexpr(sizeof...(Zs) == 1)
      return if_else(is_less(z1, zs...), cvt(z1), cvt(zs)...);
    else
    {
      r_t that(cvt(z1));
      ((that = min(that, zs)), ...);
      return that;
    }
  }
}
