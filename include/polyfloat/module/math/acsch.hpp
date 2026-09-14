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
#include <polyfloat/module/math/asinh.hpp>

namespace plf
{

  template<typename Options> struct acsch_t : eve::elementwise_callable<acsch_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(acsch_t, acsch_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var acsch
  //!   @brief return the inverse hyperbolic cosecant value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto acsch(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the inverse hyperbolic cosecant of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/acsch.cpp}
  //======================================================================================================================

  inline constexpr auto acsch = eve::functor<acsch_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<typename T, eve::callable_options O> constexpr auto acsch_(POLYFLOAT_DELAY(), O const& o, T a0) noexcept
  {
    if constexpr (dimension_v<T> == 1) return eve::acsch[o](a0);
    else
    {
      auto r = if_else(plf::is_eqz(a0), plf::signnz[eve::pedantic](a0) * inf(eve::as(a0)), plf::asinh(plf::rec(a0)));
      r = if_else(plf::is_infinite(a0), plf::signnz[eve::pedantic](a0) * zero(eve::as(a0)), r);
      return r;
    }
  }
}
