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
#include <polyfloat/module/core/sub.hpp>

namespace plf
{

  template<typename Options> struct dist_t : eve::strict_tuple_callable<dist_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z1,  concepts::polyfloat_like Z2>
      POLYFLOAT_FORCEINLINE constexpr as_polyfloat_like_t<Z1, Z2> operator()(Z1 z1, Z2 z2) const noexcept
    {
     return POLYFLOAT_CALL(z1, z2);
    }

    POLYFLOAT_CALLABLE_OBJECT(dist_t, dist_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var dist
  //!   @brief return the distance value.
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
  //!      template<polyfloat::concepts::polyfloat_like T1, polyfloat_like Z2> constexpr auto dist(T1 z1, T2 z2) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     *  `z1`, `z2`: Values to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the distance between the two parameters
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/dist.cpp}
  //======================================================================================================================

  inline constexpr auto dist = eve::functor<dist_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z1, typename Z2, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto dist_(POLYFLOAT_DELAY(), O const& , Z1 const& z1, Z2 const& z2) noexcept
  {
    return plf::abs(z1-z2);
  }
}
