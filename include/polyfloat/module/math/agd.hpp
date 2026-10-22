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
#include <polyfloat/module/math/atanh.hpp>
#include <polyfloat/module/math/tan.hpp>

namespace plf
{

  template<typename Options>
  struct agd_t : plf::elementwise_callable<agd_t, eve::agd_t, Options, raw_option, pedantic_option>

  {
    template<concepts::polyfloat_like Z> POLYFLOAT_ABI constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(agd_t, agd_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var agd
  //!   @brief return the inverse gudermannian agd : \f$2\tanh(\tan(x/2))\f$..
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
  //!      constexpr auto agd(auto auto x)                          noexcept; // 1
  //!
  //!      // Lanes masking
  //!      constexpr auto agd[conditional_expr auto c](auto auto x) noexcept; // 2
  //!      constexpr auto agd[logical_value auto m](auto auto x)    noexcept; // 2
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
  //!    1. Returns the [elementwise](@ref glossary_elementwise) inverse
  //!      [gudermannian](@ref plf::gd) of the input for x angle in the superior half circle.
  //!      In particular:
  //!      * If the element is \f$\pm0\f$, \f$0\f$ is returned.
  //!      * If the element is \f$\pm\pi/2\f$, \f$\infty\f$ is returned.
  //!      * If the element is not in \f$[-\pi/2, \pi/2] \f$, `NaN` is returned.
  //!    2. [The operation is performed conditionally](@ref conditional).
  //!
  //!  @groupheader{External references}
  //!   *  [Wolfram MathWorld: Inverse Gudermannian](https://mathworld.wolfram.com/InverseGudermannian.html)
  //!   *  [Wikipedia: Gudermannian function](https://en.wikipedia.org/wiki/Gudermannian_function)
  //!   *  [DLMF: gudermannian functions](https://dlmf.nist.gov/4.23#viii)
  //!
  //!
  //!  @groupheader{Example}
  //!
  //!  @groupheader{External references}
  //!   *  [C++ standard reference](https://en.cppreference.com/w/cpp/numeric/complex/agd)
  //!
  //!  @godbolt_todo{doc/core/agd.cpp}
  //======================================================================================================================

  inline constexpr auto agd = eve::functor<agd_t>;

  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename T, eve::callable_options O> constexpr auto agd_(POLYFLOAT_DELAY(), O const& o, T x) noexcept
  {
    return 2 * plf::atanh[o](plf::tan[o][eve::quarter_circle](x * plf::half(eve::as(x))));
  }

}
