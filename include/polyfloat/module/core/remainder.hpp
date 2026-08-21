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
#include <polyfloat/module/core/trunc.hpp>
#include <polyfloat/module/core/nearest.hpp>
#include <polyfloat/module/core/ceil.hpp>
#include <polyfloat/module/core/floor.hpp>

namespace plf
{

  template<typename Options> struct remainder_t : eve::strict_tuple_callable<remainder_t, Options, raw_option, pedantic_option,
                                                                       to_nearest_option, toward_zero_option,
                                                                       downward_option, upward_option>
  {
    template<concepts::polyfloat_like Z1,  concepts::polyfloat_like Z2>
      POLYFLOAT_FORCEINLINE constexpr as_polyfloat_like_t<Z1, Z2> operator()(Z1 z1, Z2 z2) const noexcept
    {
     return POLYFLOAT_CALL(z1, z2);
    }

    POLYFLOAT_CALLABLE_OBJECT(remainder_t, remainder_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var remainder
  //!   @brief return the remainder after division of the values.
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
  //!      template<polyfloat::concepts::polyfloat_like T1, polyfloat_like T2> constexpr auto remainder(T1 x, T2 y) noexcept; //1
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z1`, `z2`: Values to process.
  //!
  //!   **Return value**
  //!
  //!      Return the remainder after division of `x` by `y` and is equivalent to  `x-div[to_nearest](x, y)*y`.
  //!
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/remainder.cpp}
  //======================================================================================================================

  inline constexpr auto remainder = eve::functor<remainder_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename T0, typename T1, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto remainder_(POLYFLOAT_DELAY(), O const& o, T0 const& a, T1 const& b) noexcept
  {
    return rem[to_nearest](a, b);
  }
}
