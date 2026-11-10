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
  template<typename Options> struct nbmantissabits_t : eve::constant_callable<nbmantissabits_t, Options>
  {
    template<typename T> POLYFLOAT_ABI static constexpr auto value(eve::as<T> const&, auto const&)
    {
      using u_t = eve::underlying_type_t<T>;
      return eve::nbmantissabits(eve::as<u_t>()) * dimension_v<T>;
    }

    template<concepts::polyfloat_like T>
    POLYFLOAT_ABI constexpr eve::as_integer_t<eve::underlying_type_t<T>> operator()(as<T> const& v) const
    {
      return POLYFLOAT_CALL(v);
    }

    POLYFLOAT_CALLABLE_OBJECT(nbmantissabits_t, nbmantissabits_);
  };
  //======================================================================================================================
  //! @addtogroup constants
  //! @{
  //!   @var nbmantissabits
  //!   @brief return the number of stored mantissa bits of the type, the implicit bit of each part excluded.
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
  //!      template<concepts::polyfloat_like T> constexpr auto nbmantissabits(eve::as<T> z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: [Type wrapper](@ref eve::as) of the type of the constant.
  //!
  //!   **Return value**
  //!
  //!     Returns the number of available  mantissa bits.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/nbmantissabits.cpp}
  //======================================================================================================================

  inline constexpr auto nbmantissabits = eve::functor<nbmantissabits_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}
