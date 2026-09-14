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
#include <polyfloat/module/math/log.hpp>

namespace plf
{

  template<typename Options> struct acoth_t : eve::elementwise_callable<acoth_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(acoth_t, acoth_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var acoth
  //!   @brief return the inverse hyperbolic cotangent value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto acoth(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the inverse hyperbolic cotangent of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/acoth.cpp}
  //======================================================================================================================

  inline constexpr auto acoth = eve::functor<acoth_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<typename T, eve::callable_options O> constexpr auto acoth_(POLYFLOAT_DELAY(), O const& o, T a0) noexcept
  {
    if constexpr (dimension_v<T> == 1) return eve::acoth[o](a0);
    else
    {
      auto r = plf::half(eve::as(a0)) * plf::log(plf::inc(a0) / plf::dec(a0));
      r = if_else(plf::is_unit(a0), plf::sign(a0) * plf::inf(eve::as(a0)), r);
      r = if_else(plf::is_infinite(a0), sign(a0) * plf::zero(as(a0)), r);
      return r;
    }
  }
}
