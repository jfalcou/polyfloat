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
#include <polyfloat/module/core/abs.hpp>

namespace plf
{

  template<typename Options>
  struct is_greater_t
    : plf::strict_tuple_callable<is_greater_t, eve::is_greater_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z1, concepts::polyfloat_like Z2>
    POLYFLOAT_ABI constexpr eve::as_logical_t<as_polyfloat_like_t<Z1, Z2>> operator()(Z1 z1, Z2 z2) const noexcept
    {
      return POLYFLOAT_CALL(z1, z2);
    }

    POLYFLOAT_CALLABLE_OBJECT(is_greater_t, is_greater_);
  };
  //======================================================================================================================
  //! @defgroup plf_is_greater plf::is_greater
  //! @ingroup core
  //! @brief return true if z1 > z2
  //! @{
  //!   @var is_greater
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
  //!      template<concepts::polyfloat_like T1, concepts::polyfloat_like T2> constexpr auto is_greater(T1 z1, T2 z2) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns true if z1 > z2.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/is_greater.cpp}
  //======================================================================================================================

  inline constexpr auto is_greater = eve::functor<is_greater_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z1, typename Z2, eve::callable_options O>
  constexpr auto is_greater_(POLYFLOAT_DELAY(), O const&, Z1 const& z1, Z2 const& z2) noexcept
  {
    return z1 > z2;
  }
}
