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
#include <polyfloat/module/math/atan.hpp>
#include <polyfloat/module/math/tanh.hpp>

namespace plf
{

  template<typename Options>
  struct gd_t : plf::elementwise_callable<gd_t, eve::gd_t, Options, raw_option, pedantic_option>

  {
    template<concepts::polyfloat_like Z> POLYFLOAT_ABI constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(gd_t, gd_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var gd
  //!   @brief return the gudermanian gd: \f$\int_0^\infty 1/\cosh x dx\f$.
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
  //!      constexpr auto gd(auto auto x)                          noexcept; // 1
  //!
  //!      // Lanes masking
  //!      constexpr auto gd[conditional_expr auto c](auto auto x) noexcept; // 2
  //!      constexpr auto gd[logical_value auto m](auto auto x)    noexcept; // 2
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!    * `x`: polyfloat like value.
  //!    * `c`: [Conditional expression](@ref eve::conditional_expr) masking the operation.
  //!    * `m`: [Logical value](@ref eve::logical_value) masking the operation.
  //!
  //! **Return value**
  //!
  //!     1.  Returns the [elementwise](@ref glossary_elementwise) gudermanian of the input.
  //!         In particular:
  //!            * If the element is \f$\pm0\f$, \f$0\f$ is returned.
  //!            * If the element is \f$\pm\infty\f$, \f$\pm\pi/2\f$ is returned.
  //!            * If the element is a `NaN`, `NaN` is returned.
  //!     2. [The operation is performed conditionally](@ref conditional).
  //!
  //!  @groupheader{External references}
  //!   *  [Wolfram MathWorld: Gudermannian](https://mathworld.wolfram.com/Gudermannian.html)
  //!   *  [Wikipedia: Gudermannian function](https://en.wikipedia.org/wiki/Gudermannian_function)
  //!   *  [DLMF: gudermannian functions: gudermannian functions](https://dlmf.nist.gov/4.23#viii)
  //!
  //!  @groupheader{External references}
  //!   *  [C++ standard reference](https://en.cppreference.com/w/cpp/numeric/complex/gd)
  //!
  //!  @godbolt_todo{doc/core/gd.cpp}
  //======================================================================================================================

  inline constexpr auto gd = eve::functor<gd_t>;

  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename T, eve::callable_options O> constexpr auto gd_(POLYFLOAT_DELAY(), O const& o, T x) noexcept
  {
    return 2 * plf::atan[o](plf::tanh[o](x * plf::half(eve::as(x))));
  }
}
