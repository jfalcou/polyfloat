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
  template<typename Options> struct inf_t : eve::constant_callable<inf_t, Options>
  {
    template<typename T> POLYFLOAT_FORCEINLINE static constexpr auto value(eve::as<T> const&, auto const&)
    {
      using u_t = eve::underlying_type_t<T>;
      return T(eve::inf(eve::as<u_t>()));
    }

    template<concepts::polyfloat_like T> POLYFLOAT_FORCEINLINE constexpr T operator()(as<T> const& v) const
    {
      return POLYFLOAT_CALL(v);
    }

    POLYFLOAT_CALLABLE_OBJECT(inf_t, inf_);
  };
  //======================================================================================================================
  //! @addtogroup constants
  //! @{
  //!   @var inf
  //!   @brief return the infinite value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto inf(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `T`: type to return.
  //!
  //!   **Return value**
  //!
  //!     Returns the inf value in type T.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/inf.cpp}
  //======================================================================================================================

  inline constexpr auto inf = eve::functor<inf_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}
