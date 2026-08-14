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

  template<typename Options> struct is_not_equal_t : eve::callable<is_not_equal_t, Options, raw_option, pedantic_option, numeric_option>
  {
    template<concepts::polyfloat_like Z1,  concepts::polyfloat_like Z2>
      POLYFLOAT_FORCEINLINE constexpr  eve::as_logical_t<as_polyfloat_like_t<Z1, Z2>>
    operator()(Z1 z1, Z2 z2) const noexcept
    {
     return POLYFLOAT_CALL(z1, z2);
    }

    POLYFLOAT_CALLABLE_OBJECT(is_not_equal_t, is_not_equal_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var is_not_equal
  //!   @brief return the is_not_equal value.
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
  //!      template<polyfloat::concepts::polyfloat_like T1, polyfloat_like Z2> constexpr auto is_not_equal(T1 z1, T2 z2)          noexcept; //1
  //!      template<polyfloat::concepts::polyfloat_like T1, polyfloat_like Z2> constexpr auto is_not_equal[numeric](T1 z1, T2 z2) noexcept; //2
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z1`, `z2` : Values to process.
  //!
  //!   **Return value**
  //!
  //!     1. Returns true is  `z1` is not_equal to `z2`.
  //!     2. consider nan values as not_equal
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/is_not_equal.cpp}
  //======================================================================================================================

  inline constexpr auto is_not_equal = eve::functor<is_not_equal_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z1, typename Z2, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto is_not_equal_(POLYFLOAT_DELAY(), O const& , Z1 const& z1, Z2 const& z2) noexcept
  {

    auto neq = z1 != z2;
    if constexpr(O::contains(numeric)) return neq && (is_not_nan(z1) && is_not_nan(z2));
    else                               return neq;
  }
}
