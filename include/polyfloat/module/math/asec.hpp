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
  struct asec_t : plf::elementwise_callable<asec_t, eve::asec_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_ABI constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(asec_t, asec_);
  };
  //======================================================================================================================
  //! @addtogroup math
  //! @{
  //!   @var asec
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto asec(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the arc secant of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/asec.cpp}
  //======================================================================================================================

  inline constexpr auto asec = eve::functor<asec_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<typename T, eve::callable_options O> constexpr auto asec_(POLYFLOAT_DELAY(), O const&, T a0) noexcept
  {
    return if_else(plf::is_eqpz(a0), plf::inf(eve::as(a0)), plf::acos(plf::rec(a0)));
  }
}
