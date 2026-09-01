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
  template<typename Options> struct maxflint_t : eve::constant_callable<maxflint_t, Options>
  {
    template<typename T> static POLYFLOAT_FORCEINLINE constexpr auto value(eve::as<T> const&, auto const&)
    {
      using u_t = eve::underlying_type_t<T>;
      if constexpr (dimension_v<T> == 1) return T(eve::maxflint(eve::as<u_t>()));
      else if constexpr (dimension_v<T> == 2) return T(ldexp(1.0, 106), ldexp(1.0, 53));
      else if constexpr (dimension_v<T> == 3) return T(ldexp(1.0, 159), ldexp(1.0, 106), ldexp(1.0, 53));
    }

    template<concepts::polyfloat_like T> POLYFLOAT_FORCEINLINE constexpr T operator()(as<T> const& v) const
    {
      return POLYFLOAT_CALL(v);
    }

    EVE_CALLABLE_OBJECT(maxflint_t, maxflint_);
  };
  //======================================================================================================================
  //! @addtogroup constants
  //! @{
  //!   @var maxflint
  //!   @brief return the maximal representable flint value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto maxflint(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the maximal representable flint value.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/maxflint.cpp}
  //======================================================================================================================

  inline constexpr auto maxflint = eve::functor<maxflint_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}
