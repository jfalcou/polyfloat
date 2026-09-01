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
#include <polyfloat/module/core/rsqrt.hpp>

namespace plf
{

  template<typename Options> struct sqrt_t : eve::callable<sqrt_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(sqrt_t, sqrt_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var sqrt
  //!   @brief return the square root value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto sqrt(T z) noexcept;
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto sqrt[raw](T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the square root of z. With raw option the computation can overflow.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/sqrt.cpp}
  //======================================================================================================================

  inline constexpr auto sqrt = eve::functor<sqrt_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<typename Z, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto sqrt_(POLYFLOAT_DELAY(), O const& o, Z const& z) noexcept
  {
    return plf::rsqrt[o](z) * z;
  }
}
