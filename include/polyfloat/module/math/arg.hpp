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
  struct arg_t : plf::elementwise_callable<arg_t,
                                           eve::arg_t,
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

    POLYFLOAT_CALLABLE_OBJECT(arg_t, arg_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var arg
  //!   @brief return the the phase angle (in radians).
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
  //!      // Regular overload
  //!      constexpr auto arg(floating_value auto x)                  noexcept; // 1
  //!
  //!      // Lanes masking
  //!      constexpr auto arg[conditional_expr auto c](value auto x)  noexcept; // 2
  //!      constexpr auto arg[logical_value auto m](value auto x)     noexcept; // 2
  //!
  //!      // Semantic option
  //!      constexpr auto arg[pedantic](floating_value auto x)        noexcept; // 3
  //!      constexpr auto arg[rad](floating_value auto x)             noexcept; // 1
  //!      constexpr auto arg[deg](floating_value auto x)             noexcept; // 4
  //!      constexpr auto arg[radpi](floating_value auto x)           noexcept; // 5
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //! **Return value**
  //!
  //!    1. Returns [elementwise](@ref glossary_elementwise) the phase angle (in radians) of the
  //!       input (0 or\f$\pi\f$) depending of the bit of sign of the input
  //!    2. [The operation is performed conditionally](@ref conditional).
  //!    3. If the entry is `NaN` the result is `NaN`.
  //!    4. Result in degrees
  //!    5. Result in \f$\pi\f$ multiples
  //!
  //!    @note phase can be used as an alias
  //!
  //!  @groupheader{Example}
  //!
  //!  @groupheader{External references}
  //!   *  [C++ standard reference](https://en.cppreference.com/w/cpp/numeric/complex/arg)
  //!
  //!  @godbolt_todo{doc/core/arg.cpp}
  //======================================================================================================================

  inline constexpr auto arg = eve::functor<arg_t>;
  inline constexpr auto phase = eve::functor<arg_t>;

  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename T, eve::callable_options O> constexpr auto arg_(POLYFLOAT_DELAY(), O const& o, T a) noexcept
  {
    auto valneg = [](auto x) {
      if constexpr (O::contains(eve::deg)) return T(180);
      else if constexpr (O::contains(eve::radpi)) return plf::one(eve::as(x));
      else return plf::pi(eve::as(x));
    };
    auto z = plf::if_else(is_negative(a), valneg(a), eve::zero);
    if constexpr (eve::platform::supports_nans && O::contains(pedantic))
      return plf::if_else(plf::is_nan(a), plf::nan(eve::as(z)), z);
    else return z;
  }

  constexpr auto argd = plf::arg[eve::deg];
  constexpr auto argpi = plf::arg[eve::radpi];
  constexpr auto phased = plf::arg[eve::deg];
  constexpr auto phasepi = plf::arg[eve::radpi];
}
