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
#include <polyfloat/module/math/log.hpp>

namespace plf
{

  template<typename Options> struct atanh_t : eve::elementwise_callable<atanh_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(atanh_t, atanh_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var atanh
  //!   @brief return the inverse hyperbolic tangent value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto atanh(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the inverse hyperbolic tangent of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/atanh.cpp}
  //======================================================================================================================

  inline constexpr auto atanh = eve::functor<atanh_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<typename T, eve::callable_options O> constexpr auto atanh_(POLYFLOAT_DELAY(), O const& o, T a0) noexcept
  {
    if constexpr (dimension_v<T> == 1) return eve::atanh[o](a0);
    else
    {
      auto r = plf::half(eve::as(a0)) * plf::log(plf::inc(a0) / plf::oneminus(a0));
      return if_else(plf::is_unit(a0), plf::sign(a0) * plf::inf(eve::as(a0)), r);
    }
  }
}
