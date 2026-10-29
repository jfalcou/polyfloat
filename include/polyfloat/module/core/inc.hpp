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
#include <polyfloat/module/core/minus.hpp>
#include <polyfloat/module/core/is_negative.hpp>
#include <polyfloat/module/core/dec.hpp>
#include <iostream>

namespace plf
{

  template<typename Options>
  struct inc_t : plf::elementwise_callable<inc_t, eve::inc_t, Options, raw_option, pedantic_option, eve::mod_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_ABI constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(inc_t, inc_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var inc
  //!   @brief return the value plus one.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto inc(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the value of z+1.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/inc.cpp}
  //======================================================================================================================

  inline constexpr auto inc = eve::functor<inc_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O> constexpr auto inc_(POLYFLOAT_DELAY(), O const& o, Z const& a) noexcept
  {
    if constexpr (O::contains(eve::mod))
    {
      auto p = o[eve::mod].value(eve::as(a));
      return plf::if_else(a == plf::dec(p), plf::zero(eve::as(a)), plf::inc(a));
    }
    else return add[o](a, plf::one(eve::as(a)));
  }
}
