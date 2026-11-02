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
#include <polyfloat/types/traits.hpp>
#include <polyfloat/module/core/parts.hpp>

namespace plf
{

  template<typename Options>
  struct is_normalized_t : eve::elementwise_callable<is_normalized_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_ABI constexpr eve::as_logical_t<plf::as_component_type_t<Z>> operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(is_normalized_t, is_normalized_);
  };

  //================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var is_normalized
  //!   @brief returns a logical true  if and only if the element value is normalized i.e. its
  //!   successive components satisfy Zhang condition of strong domination.
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <eve/module/module/core.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace plf
  //!   {
  //!      // Regular overloads
  //!      constexpr auto is_normalized(auto x)                 noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `x`: [argument](@ref eve::value).
  //!
  //!   **Return value**
  //!
  //!     returns true if and only if x represent an normalized number.
  //!
  //!   @note this condition is mandatory. If you want to write any function that returns a polyfloat,
  //!     the polyfloat returned MUST satisfy is_normalized.
  //!
  //!  @groupheader{Example}
  //!  @godbolt_todo{doc/core/is_normalized.cpp}
  //================================================================================================
  inline constexpr auto is_normalized = eve::functor<is_normalized_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O>
  constexpr auto is_normalized_(POLYFLOAT_DELAY(), O const&, Z const& z) noexcept
  {
    auto eqnum = eve::is_equal[eve::numeric];
    if constexpr (plf::dimension_v<Z> == 1)
    {
      return eve::true_(eve::as(z));
    }
    else if constexpr (plf::dimension_v<Z> == 2)
    {
      auto [h, l] = z;
      return eqnum(h + l, h);
    }
    else if constexpr (plf::dimension_v<Z> == 3)
    {
      auto [h, m, l] = z;
      return eqnum(h + m, h) && eqnum(m + l, m);
    }
  }
}
