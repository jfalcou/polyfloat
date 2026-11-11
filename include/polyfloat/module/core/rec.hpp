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

  template<typename Options> struct rec_t : eve::elementwise_callable<rec_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_ABI Z operator()(Z z) const noexcept { return POLYFLOAT_CALL(z); }

    POLYFLOAT_CALLABLE_OBJECT(rec_t, rec_);
  };
  //======================================================================================================================
  //! @defgroup plf_rec plf::rec
  //! @ingroup core
  //! @brief return the inverse \f$1/x\f$.
  //! @{
  //!   @var rec
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
  //!      template<concepts::polyfloat_like T> constexpr auto rec(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the inverse of `z`, \f$1/z\f$.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/rec.cpp}
  //======================================================================================================================

  inline constexpr auto rec = eve::functor<rec_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O> constexpr auto rec_(POLYFLOAT_DELAY(), O const&, Z const& z) noexcept
  {
    if constexpr (dimension_v<Z> == 1) return eve::rec[eve::pedantic](z);
    else return _::rec(z);
  }
}
