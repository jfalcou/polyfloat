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
#include <polyfloat/module/math/details/sincos_coefs.hpp>

namespace plf
{

  template<typename Options> struct sin_t : eve::elementwise_callable<sin_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(sin_t, sin_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var sin
  //!   @brief return the inverse hyperbolic sinine value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto sin(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the invese hyperbolic sinine of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/sin.cpp}
  //======================================================================================================================

  inline constexpr auto sin = eve::functor<sin_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename T, eve::callable_options O> constexpr auto sin_(POLYFLOAT_DELAY(), O const& o, T a0) noexcept
  {
    if constexpr (dimension_v<T> == 1) return eve::sin[o](a0);
    else
    {
      using e_t = eve::element_type_t<T>;
      auto a02 = plf::sqr(a0);
      auto t = sino_x_coefs<e_t>();
      //      std::cout << t << std::endl;
      //   return plf::reverse_horner(a02, sin_coefs<T>());
      auto r = kumi::apply([a02](auto... m) { return plf::reverse_horner(a02, m...); }, t);
      return a0 * r;
      //    return plf::reverse_horner(a02, kumi::tuple{T(1.0), T(0.5)});
    }
  }
}
