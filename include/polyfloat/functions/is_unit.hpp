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
#include <polyfloat/functions/is_equal.hpp>
#include <polyfloat/functions/abs.hpp>

namespace plf
{

  template<typename Options> struct is_unit_t : eve::elementwise_callable<is_unit_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_FORCEINLINE constexpr eve::as_logical_t<plf::as_component_type_t<Z>> operator()(Z z) const noexcept
    {
     return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(is_unit_t, is_unit_);
  };
  //======================================================================================================================
  //! @addtogroup functions
  //! @{
  //!   @var is_unit
  //!   @brief test the parameter for equality to is\f$\pm1\f$.
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <kyosu/functions.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace kyosu
  //!   {
  //!      template<kyosu::concepts::polyfloat_like T> constexpr auto is_unit(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns true iff z is\f$\pm1\f$.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/is_unit.cpp}
  //======================================================================================================================

  inline constexpr auto is_unit = eve::functor<is_unit_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto is_unit_(POLYFLOAT_DELAY(), O const& , Z const& z) noexcept
  {
    return is_equal(abs(z), Z(1));
  }
}
