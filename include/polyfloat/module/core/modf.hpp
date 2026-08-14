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
#include <polyfloat/module/core/trunc.hpp>

namespace plf
{

  template<typename Options> struct modf_t : eve::elementwise_callable<modf_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_FORCEINLINE constexpr kumi::tuple<Z, Z> operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(modf_t, modf_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var modf
  //!   @brief returns fractionnal and trncated parts of the value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto modf(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the  fractionnal and trncated parts of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/modf.cpp}
  //======================================================================================================================

  inline constexpr auto modf = eve::functor<modf_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto modf_(POLYFLOAT_DELAY(), O const& , Z const& z) noexcept
  {
    auto t = trunc(z);
    return kumi::tuple {z - t, t};
  }
}
