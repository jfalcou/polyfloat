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
  struct acos_t : plf::elementwise_callable<acos_t,
                                            eve::acos_t,
                                            Options,
                                            raw_option,
                                            pedantic_option,
                                            eve::rad_option,
                                            eve::radpi_option,
                                            eve::deg_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_ABI constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(acos_t, acos_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var acos
  //!   @brief return the arc cosine value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto acos(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!      Returns the [elementwise](@ref glossary_elementwise) arc cosine in radians of the
  //!      input in the range \f$[0 , \pi]\f$.
  //!      In particular:
  //!      * If `x` is \f$1\f$, \f$+0\f$ is returned.
  //!      * If \f$|x| > 1\f$, `NaN` is returned.
  //!      * If `x` is a `NaN`, `NaN` is returned.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/math/acos.cpp}
  //======================================================================================================================

  inline constexpr auto acos = eve::functor<acos_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename T, eve::callable_options O> constexpr auto acos_(POLYFLOAT_DELAY(), O const& o, T a0) noexcept
  {
    return plf::atan2[o](plf::sqrt(oneminus(plf::sqr(a0))), a0);
  }

  constexpr auto acosd = plf::acos[eve::deg];
  constexpr auto acospi = plf::acos[eve::radpi];
}
