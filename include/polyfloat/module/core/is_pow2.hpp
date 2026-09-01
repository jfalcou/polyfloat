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
#include <polyfloat/module/core/mantissa.hpp>
#include <polyfloat/module/core/is_unit.hpp>

namespace plf
{

  template<typename Options>
  struct is_pow2_t : eve::elementwise_callable<is_pow2_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_FORCEINLINE constexpr eve::as_logical_t<plf::as_component_type_t<Z>> operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(is_pow2_t, is_pow2_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var is_pow2
  //!   @brief test the parameter for equality to a power of 2.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto is_pow2(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns true iff z is a power of 2.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/is_pow2.cpp}
  //======================================================================================================================

  inline constexpr auto is_pow2 = eve::functor<is_pow2_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto is_pow2_(POLYFLOAT_DELAY(), O const&, Z const& z) noexcept
  {
    return is_unit(mantissa(z));
  }
}
