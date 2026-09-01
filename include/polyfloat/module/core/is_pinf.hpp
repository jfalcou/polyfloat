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
  struct is_pinf_t : eve::elementwise_callable<is_pinf_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_FORCEINLINE constexpr eve::as_logical_t<plf::as_component_type_t<Z>> operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(is_pinf_t, is_pinf_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var is_pinf
  //!   @brief test the parameter equal \f$\infty\f$.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto is_pinf(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the true if z value is \f$\infty\f$.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/is_pinf.cpp}
  //======================================================================================================================

  inline constexpr auto is_pinf = eve::functor<is_pinf_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto is_pinf_(POLYFLOAT_DELAY(), O const&, Z const& z) noexcept
  {
    return eve::is_pinf(hi(z));
  }
}
