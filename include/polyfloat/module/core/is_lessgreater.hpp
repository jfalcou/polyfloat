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
#include <polyfloat/module/core/is_not_equal.hpp>
#include <polyfloat/module/core/is_ordered.hpp>

namespace plf
{

  template<typename Options> struct is_lessgreater_t : eve::strict_tuple_callable<is_lessgreater_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z1,  concepts::polyfloat_like Z2>
      POLYFLOAT_FORCEINLINE constexpr  eve::as_logical_t<as_polyfloat_like_t<Z1, Z2>>
    operator()(Z1 z1, Z2 z2) const noexcept
    {
     return POLYFLOAT_CALL(z1, z2);
    }

    POLYFLOAT_CALLABLE_OBJECT(is_lessgreater_t, is_lessgreater_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var is_lessgreater
  //!   @brief  return a logical true  if and only if the elements pair are not equal or unordered.
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
  //!      template<kyosu::concepts::polyfloat_like T1, polyfloat_like Z2> constexpr auto is_lessgreater(T1 z1, T2 z2) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns true if z1 > z2 || z1 <  z2.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/is_lessgreater.cpp}
  //======================================================================================================================

  inline constexpr auto is_lessgreater = eve::functor<is_lessgreater_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z1, typename Z2, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto is_lessgreater_(POLYFLOAT_DELAY(), O const& o, Z1 const& a, Z2 const& b) noexcept
  {
    return  is_not_equal[o](a, b) && is_ordered(a, b);
  }
}
