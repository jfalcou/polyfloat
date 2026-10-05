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
#include <polyfloat/module/math/details/pio_2_splitting.hpp>

namespace plf
{

  template<typename Options> struct cos_t : eve::elementwise_callable<cos_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(cos_t, cos_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var cos
  //!   @brief return the inverse hyperbolic cosine value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto cos(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the invese hyperbolic cosine of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/cos.cpp}
  //======================================================================================================================

  inline constexpr auto cos = eve::functor<cos_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename T, eve::callable_options O> constexpr auto cos_(POLYFLOAT_DELAY(), O const& o, T a0) noexcept
  {
    if constexpr (dimension_v<T> == 1) return eve::cos[o](a0);
    else
    {
      using e_t = eve::element_type_t<T>;
      auto a02 = plf::sqr(a0);
      auto t = cos_coefs<e_t>();
      //      std::cout << t << std::endl;
      //   return plf::reverse_horner(a02, cos_coefs<T>());
      auto r = kumi::apply([a02](auto... m) { return plf::reverse_horner(a02, m...); }, t);
      return r;
      //    return plf::reverse_horner(a02, kumi::tuple{T(1.0), T(0.5)});
    }
  }
}
