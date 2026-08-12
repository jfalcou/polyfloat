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

  template<typename Options> struct is_not_infinite_t : eve::elementwise_callable<is_not_infinite_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_FORCEINLINE constexpr eve::as_logical_t<plf::as_component_type_t<Z>> operator()(Z z) const noexcept
    {
     return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(is_not_infinite_t, is_not_infinite_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var is_eqz
  //!   @brief test the parameter for being not infinite.
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <polyfloat/module/core.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace polyfloat
  //!   {
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto is_not_infinite(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns true if the value is not \f$\pm\infty\f$.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/is_not_infinite.cpp}
  //======================================================================================================================

  inline constexpr auto is_not_infinite = eve::functor<is_not_infinite_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto is_not_infinite_(POLYFLOAT_DELAY(), O const& , Z const& z) noexcept
  {
    return eve::is_not_infinite(hi(z));
  }
}
