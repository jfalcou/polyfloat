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
  template<typename Options> struct nan_t : eve::constant_callable<nan_t, Options>
  {
    template<typename T> POLYFLOAT_ABI static constexpr auto value(eve::as<T> const&, auto const&)
    {
      using u_t = eve::underlying_type_t<T>;
      return T(eve::nan(eve::as<u_t>()));
    }

    template<concepts::polyfloat_like T> POLYFLOAT_ABI constexpr T operator()(as<T> const& v) const
    {
      return POLYFLOAT_CALL(v);
    }

    POLYFLOAT_CALLABLE_OBJECT(nan_t, nan_);
  };
  //======================================================================================================================
  //! @addtogroup constants
  //! @{
  //!   @var nan
  //!   @brief return the naninite value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto nan(as<T>) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `T`: type to return.
  //!
  //!   **Return value**
  //!
  //!     Returns the nan value in type T.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/nan.cpp}
  //======================================================================================================================

  inline constexpr auto nan = eve::functor<nan_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}
