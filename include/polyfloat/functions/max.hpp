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
#include <polyfloat/functions/parts.hpp>

namespace plf
{

  template<typename Options> struct max_t : eve::elementwise_callable<max_t, Options>
  {
    template<concepts::polyfloat_like Z1,  concepts::polyfloat_like Z2>
      POLYFLOAT_FORCEINLINE constexpr as_polyfloat_like_t<Z1, Z2> operator()(Z1 z1, Z2 z2) const noexcept
    {
     return POLYFLOAT_CALL(z1, z2);
    }

    POLYFLOAT_CALLABLE_OBJECT(max_t, max_);
  };
  //======================================================================================================================
  //! @addtogroup functions
  //! @{
  //!   @var max
  //!   @brief return the maximum value.
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
  //!      template<kyosu::concepts::polyfloat_like T1, polyfloat_like Z2> constexpr auto max(T1 z1, T2 z2) noexcept;
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
  //!  @godbolt{doc/max.cpp}
  //======================================================================================================================

  inline constexpr auto max = eve::functor<max_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z1, typename ... Zs, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto max_(POLYFLOAT_DELAY(), O const& , Z1 z1, Zs ...zs) noexcept
  {
    using r_t = eve::common_value_t<Z1, Zs...>;
    if constexpr(sizeof...(Zs) == 1)
      return if_else(is_less(z1, zs...), r_t(zs)..., r_t(z1));
    else
    {
      r_t that(z1);
      ((that = max(that, r_t(zs))), ...);
      return that;
    }
  }
}
