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
  struct is_not_denormal_t : eve::elementwise_callable<is_not_denormal_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_ABI constexpr eve::as_logical_t<plf::as_component_type_t<Z>> operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(is_not_denormal_t, is_not_denormal_);
  };

  //================================================================================================
  //! @defgroup plf_is_not_denormal plf::is_not_denormal
  //! @ingroup core
  //! @brief returns a logical true  if and only if the element value
  //!   is not a denormal value
  //! @{
  //!   @var is_not_denormal
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
  //!      constexpr auto is_not_denormal(eve::floating_value auto x)                 noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `x`: [argument](@ref eve::value).
  //!
  //!   **Return value**
  //!
  //!     returns true if and only if x is not a denormal number
  //!
  //!  @groupheader{Example}
  //!  @godbolt{doc/core/is_not_denormal.cpp}
  //================================================================================================
  inline constexpr auto is_not_denormal = eve::functor<is_not_denormal_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O>
  constexpr auto is_not_denormal_(POLYFLOAT_DELAY(), O const&, Z const& z) noexcept
  {
    return eve::is_not_denormal(hi(z));
  }
}
