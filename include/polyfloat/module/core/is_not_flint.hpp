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
  struct is_not_flint_t
    : plf::elementwise_callable<is_not_flint_t, eve::is_not_flint_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_ABI constexpr eve::as_logical_t<plf::as_component_type_t<Z>> operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(is_not_flint_t, is_not_flint_);
  };

  //================================================================================================
  //! @defgroup plf_is_not_flint plf::is_not_flint
  //! @ingroup core
  //! @brief returns a logical true if and only if the element value is not a floating value representing an integer.
  //! @{
  //!   @var is_not_flint
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
  //!      // Regular overloads
  //!      constexpr auto is_not_flint(eve::floating_value auto x)                 noexcept; // 1
  //!      constexpr auto is_not_flint(eve::integral_value auto x)                  noexcept; // 2
  //!
  //!      // Lanes masking
  //!      constexpr auto is_not_flint[eve::conditional_expr auto c](eve::value auto x) noexcept; // 3
  //!      constexpr auto is_not_flint[eve::logical_value auto m](eve::value auto x)    noexcept; // 3
  //!
  //!      // Semantic options
  //!      constexpr auto is_not_flint[pedantic](eve::floating_value auto x)       noexcept; // 4
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `x`: [argument](@ref eve::value).
  //!     * `c`: [Conditional expression](@ref eve::conditional_expr) masking the operation.
  //!     * `m`: [Logical value](@ref eve::logical_value) masking the operation.
  //!
  //!   **Return value**
  //!
  //!     1. Returns true if and only if `x` does not represent an integer, the opposite of plf::is_flint.
  //!     2. Always returns `true`
  //!     3. [The operation is performed conditionnaly](@ref conditional).
  //!     4. The call `is_not_flint[pedantic](x)` also check that the input is not greater or equal to the
  //!        largest consecutive integer in the element type of `x` (`maxflint(as(x))`).
  //!
  //!  @groupheader{Example}
  //!  @godbolt{doc/core/is_not_flint.cpp}
  //================================================================================================
  inline constexpr auto is_not_flint = eve::functor<is_not_flint_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O>
  constexpr auto is_not_flint_(POLYFLOAT_DELAY(), O const&, Z const& z) noexcept
  {
    if constexpr (dimension_v<Z> == 2) return eve::is_not_flint(lo(z)) || eve::is_not_flint(hi(z));
    else if constexpr (dimension_v<Z> == 3)
      return eve::is_not_flint(lo(z)) || eve::is_not_flint(md(z)) || (eve::is_not_flint(hi(z)));
  }
}
