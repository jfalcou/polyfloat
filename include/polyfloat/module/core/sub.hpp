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

  template<typename Options> struct sub_t : eve::strict_tuple_callable<sub_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z1, concepts::polyfloat_like Z2>
    POLYFLOAT_FORCEINLINE constexpr as_polyfloat_like_t<Z1, Z2> operator()(Z1 z1, Z2 z2) const noexcept
    {
      return POLYFLOAT_CALL(z1, z2);
    }

    POLYFLOAT_CALLABLE_OBJECT(sub_t, sub_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var sub
  //!   @brief return the difference of the values.
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
  //!      template<polyfloat::concepts::polyfloat_like T1, polyfloat_like Z2> constexpr auto sub(T1 z1, T2 z2) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the difference of the arguments.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/sub.cpp}
  //======================================================================================================================

  inline constexpr auto sub = eve::functor<sub_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z1, typename Z2, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto sub_(POLYFLOAT_DELAY(), O const&, Z1 const& z1, Z2 const& z2) noexcept
  {
    return z1 - z2;
  }
}
