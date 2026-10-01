//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

#include <eve/eve.hpp>
#include <polyfloat/details/callable.hpp>
#include <polyfloat/types/concepts.hpp>
#include <polyfloat/types/traits.hpp>

namespace plf
{
  template<typename Options> struct minf_t : eve::constant_callable<minf_t, Options>
  {
    template<typename T> static POLYFLOAT_FORCEINLINE constexpr auto value(eve::as<T> const&, auto const&)
    {
      using u_t = eve::underlying_type_t<T>;
      return T(eve::minf(eve::as<u_t>()));
    }

    template<concepts::polyfloat_like T> POLYFLOAT_FORCEINLINE constexpr T operator()(as<T> const& v) const
    {
      return POLYFLOAT_CALL(v);
    }

    EVE_CALLABLE_OBJECT(minf_t, minf_);
  };
  //======================================================================================================================
  //! @addtogroup constants
  //! @{
  //!   @var minf
  //!   @brief return the minus infinity value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto minf(as<T>) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `T`: type to return.
  //!
  //!   **Return value**
  //!
  //!     Returns the minf value in type T.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/minf.cpp}
  //======================================================================================================================

  inline constexpr auto minf = eve::functor<minf_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}
