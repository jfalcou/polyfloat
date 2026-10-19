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
#include <polyfloat/module/math/asin.hpp>

namespace plf
{

  template<typename Options>
  struct acsc_t : plf::elementwise_callable<acsc_t, eve::acsc_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_ABI constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(acsc_t, acsc_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var acsc
  //!   @brief return the arc secant value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto acsc(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the arc cosecant of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/acsc.cpp}
  //======================================================================================================================

  inline constexpr auto acsc = eve::functor<acsc_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<typename T, eve::callable_options O> constexpr auto acsc_(POLYFLOAT_DELAY(), O const& o, T a0) noexcept
  {
    return if_else(plf::is_eqz(a0), plf::signnz[eve::pedantic](a0) * inf(eve::as(a0)), plf::asin[o](plf::rec(a0)));
  }
}
