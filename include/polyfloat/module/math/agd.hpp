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
  //! @defgroup plf_agd plf::agd
  //! @ingroup math
  //! @brief return the inverse Gudermannian function, \f$2\,\mathrm{atanh}(\tan(x/2))\f$.
  //! @{
  //!   @var agd
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <polyfloat/polyfloat.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace plf
  //!   {
  //!      // Regular overload
  //!      constexpr auto agd(concepts::polyfloat_like auto x)                          noexcept; // 1
  //!
  //!      // Lanes masking
  //!      constexpr auto agd[eve::conditional_expr auto c](concepts::polyfloat_like auto x) noexcept; // 2
  //!      constexpr auto agd[eve::logical_value auto m](concepts::polyfloat_like auto x)    noexcept; // 2
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
  //!  @godbolt{doc/math/agd.cpp}
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
