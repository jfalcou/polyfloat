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
#include <polyfloat/module/core/trunc.hpp>

namespace plf
{

  template<typename Options> struct frac_t : eve::elementwise_callable<frac_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_ABI constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(frac_t, frac_);
  };
  //======================================================================================================================
  //! @defgroup plf_frac plf::frac
  //! @ingroup core
  //! @brief return the fractional part of the value.
  //! @{
  //!   @var frac
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <polyfloat/polyfloat.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace plf
  //!   {
  //!      template<concepts::polyfloat_like T> constexpr auto frac(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the fractional part of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/frac.cpp}
  //======================================================================================================================

  inline constexpr auto frac = eve::functor<frac_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O> constexpr auto frac_(POLYFLOAT_DELAY(), O const&, Z const& z) noexcept
  {
    return z - trunc(z);
  }
}
