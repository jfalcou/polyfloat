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
namespace plf
{

  template<typename Options>
  struct dec_t : plf::elementwise_callable<dec_t, eve::dec_t, Options, raw_option, pedantic_option, eve::mod_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_ABI constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(dec_t, dec_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var dec
  //!   @brief return the value minus one.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto dec(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the value of z-1.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/dec.cpp}
  //======================================================================================================================

  inline constexpr auto dec = eve::functor<dec_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O> constexpr auto dec_(POLYFLOAT_DELAY(), O const& o, Z const& a) noexcept
  {
    if constexpr (O::contains(eve::mod))
    {
      auto p = o[eve::mod].value(eve::as(a));
      return plf::if_else(plf::is_eqz(a), plf::dec(p), plf::dec(a));
    }
    else return a - eve::one(eve::as(hi(a)));
  }
}
