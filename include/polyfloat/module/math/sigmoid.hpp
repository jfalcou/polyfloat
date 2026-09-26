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

namespace plf
{

  template<typename Options>
  struct sigmoid_t : eve::elementwise_callable<sigmoid_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(sigmoid_t, sigmoid_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var sigmoid
  //!   @brief return the sigmoidonential value.
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
  //!
  //!   {
  //!      // Regular overload
  //!      constexpr auto sigmoid( auto x)                              noexcept; // 1
  //!
  //!      // Lanes masking
  //!      constexpr auto sigmoid[conditional_expr auto c]( auto x)     noexcept; // 2
  //!      constexpr auto sigmoid[logical_value auto m]( auto x)        noexcept; // 2
  //!   }
  //!   @endcode
  //!
  //! **Parameters**
  //!
  //!    * `x`: [floating value](@ref eve::floating_value).
  //!    * `c`: [Conditional expression](@ref eve::conditional_expr) masking the operation.
  //!    * `m`: [Logical value](@ref eve::logical_value) masking the operation.
  //!
  //! **Return value**
  //!
  //!   1.  Returns \f$\frac{1}{1+e^{-x}}\f$. In particular:
  //!       * If the element is \f$1/2\f$, \f$1\f$ is returned
  //!       * If the element is \f$-\infty\f$, \f$+0\f$ is returned
  //!       * If the element is \f$\infty\f$, \f$1\f$ is returned
  //!       * If the element is a `NaN`, `NaN` is returned
  //!   2. [The operation is performed conditionally](@ref conditional).
  //!
  //!  @groupheader{External references}
  //!   *  [Wolfram MathWorld](https://www.wolframalpha.com/input/?i=sigmoid)
  //!   *  [Wikipedia](https://en.wikipedia.org/wiki/Sigmoid_function)
  //!
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/sigmoid.cpp}
  //======================================================================================================================

  inline constexpr auto sigmoid = eve::functor<sigmoid_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<typename T, eve::callable_options O> constexpr auto sigmoid_(POLYFLOAT_DELAY(), O const& o, T xx) noexcept
  {
    if constexpr (dimension_v<T> == 1) return eve::sigmoid(xx);
    else return plf::rec[eve::pedantic](plf::inc(plf::exp[o](-xx)));
  }
}
