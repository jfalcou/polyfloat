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

namespace plf
{

  template<typename Options> struct negate_t : eve::strict_tuple_callable<negate_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z1,  concepts::polyfloat_like Z2>
      POLYFLOAT_FORCEINLINE constexpr as_polyfloat_like_t<Z1, Z2> operator()(Z1 z1, Z2 z2) const noexcept
    {
     return POLYFLOAT_CALL(z1, z2);
    }

    POLYFLOAT_CALLABLE_OBJECT(negate_t, negate_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var negate
  //!   @brief return the first parametermultiplied with the  sign of the second.
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
  //!      template<kyosu::concepts::polyfloat_like T1, polyfloat_like Z2> constexpr auto negate(T1 z1, T2 z2) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     *  `z1`, `z2`: Values to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the z1 multiplied by the sign of z2
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/negate.cpp}
  //======================================================================================================================

  inline constexpr auto negate = eve::functor<negate_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z1, typename Z2, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto negate_(POLYFLOAT_DELAY(), O const& , Z1 const& z1, Z2 const& z2) noexcept
  {
    return abs(z1)*eve::sign(hi(z2));
  }
}
