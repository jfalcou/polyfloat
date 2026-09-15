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
#include <polyfloat/module/math/sinh.hpp>
#include <polyfloat/module/math/log.hpp>

namespace plf
{

  template<typename Options> struct tanh_t : eve::elementwise_callable<tanh_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(tanh_t, tanh_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var tanh
  //!   @brief return the hyperbolic tangent value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto tanh(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the  hyperbolic tangent of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/tanh.cpp}
  //======================================================================================================================

  inline constexpr auto tanh = eve::functor<tanh_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename T, eve::callable_options O> constexpr auto tanh_(POLYFLOAT_DELAY(), O const& o, T a0) noexcept
  {
    if constexpr (dimension_v<T> == 1) return eve::tanh[o](a0);
    else
    {
      auto x = plf::abs(a0 + a0);
      auto test = x > T(0.5493) * 2;
      auto t = plf::expm1[o](x);
      auto rt2 = plf::rec[eve::pedantic](t + T(2));
      auto z1 = plf::fnma(T(2), rt2, T(1));
      auto z2 = t * rt2;
      auto r = plf::if_else(test, z1, z2);
      return if_else(is_infinite(a0), a0, plf::copysign(r, a0));
    }
  }
}
