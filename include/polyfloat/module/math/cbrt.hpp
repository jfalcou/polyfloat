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
#include <polyfloat/module/math/nthroot.hpp>

namespace plf
{

  template<typename Options> struct cbrt_t : eve::elementwise_callable<cbrt_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(cbrt_t, cbrt_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var cbrt
  //!   @brief return the cubic root.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto cbrt(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the cubic root of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/cbrt.cpp}
  //======================================================================================================================

  inline constexpr auto cbrt = eve::functor<cbrt_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<typename T, eve::callable_options O> constexpr auto cbrt_(POLYFLOAT_DELAY(), O const&, T xx) noexcept
  {
    if constexpr (dimension_v<T> == 1) return eve::cbrt(xx);
    else
    {
      return plf::nthroot(xx, 3);
    }
  }
}
