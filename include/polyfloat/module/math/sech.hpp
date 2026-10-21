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
#include <polyfloat/module/math/cosh.hpp>

namespace plf
{

  template<typename Options>
  struct sech_t : plf::elementwise_callable<sech_t, eve::sech_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_ABI constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(sech_t, sech_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var sech
  //!   @brief return the hyperbolic secant value.
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <polyfloat/math.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace polyfloat
  //!   {
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto sech(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the hyperbolic secant of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/math/sech.cpp}
  //======================================================================================================================

  inline constexpr auto sech = eve::functor<sech_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename T, eve::callable_options O> constexpr auto sech_(POLYFLOAT_DELAY(), O const& o, T a0) noexcept
  {
    return plf::rec[pedantic](plf::cosh[o](a0));
  }
}
