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
#include <polyfloat/module/math/atan2.hpp>

namespace plf
{

  template<typename Options>
  struct asin_t : plf::elementwise_callable<asin_t, eve::asin_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(asin_t, asin_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var asin
  //!   @brief return the arcsine value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto asin(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //! **Return value**
  //!
  //!    Returns the [elementwise](@ref glossary_elementwise) arc sine of the
  //!      input in the range  \f$[-\frac\pi2, \frac\pi2]\f$.
  //!      In particular:
  //!      * If the element is \f$\pm0\f$, \f$\pm0\f$ is returned unmodified.
  //!      * If the element \f$|x| > 1\f$, `NaN` is returned.
  //!      * If the element is a `NaN`, `NaN` is returned.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/asin.cpp}
  //======================================================================================================================

  inline constexpr auto asin = eve::functor<asin_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename T, eve::callable_options O> constexpr auto asin_(POLYFLOAT_DELAY(), O const&, T a0) noexcept
  {
    return plf::atan2(a0, plf::sqrt(oneminus(plf::sqr(a0))));
  }
}
