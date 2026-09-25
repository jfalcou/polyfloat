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

namespace plf
{
  template<typename Options> struct catalan_t : eve::constant_callable<catalan_t, Options>
  {
    template<typename T> static POLYFLOAT_FORCEINLINE constexpr auto value(eve::as<T> const&, auto const&)
    {
      using u_t = eve::underlying_type_t<T>;

      if constexpr (plf::dimension_v<T> == 1)
      {
        return eve::catalan(eve::as(u_t()));
      }
      if constexpr (plf::dimension_v<T> == 2)
      {
        if constexpr (std::same_as<u_t, float>)
          return plf::_::from_pair<u_t>(0x1.d4f9720000000p-1, -0x1.82fd940000000p-26);
        else if constexpr (std::same_as<u_t, double>)
          return plf::_::from_pair<u_t>(0x1.d4f9713e8135dp-1, 0x1.1485608b8df4dp-58);
      }
      else if constexpr (plf::dimension_v<T> == 3)
      {
        if constexpr (std::same_as<u_t, float>)
          return plf::_::from_triple<u_t>(0x1.d4f9720000000p-1, -0x1.82fd940000000p-26, -0x1.7badea0000000p-52);
        else if constexpr (std::same_as<u_t, double>)
          return plf::_::from_triple<u_t>(0x1.d4f9713e8135dp-1, 0x1.1485608b8df4dp-58, -0x1.2f39c13bc1ec8p-112);
      }
    }

    template<concepts::polyfloat_like T> POLYFLOAT_FORCEINLINE constexpr T operator()(as<T> const& v) const
    {
      return POLYFLOAT_CALL(v);
    }

    EVE_CALLABLE_OBJECT(catalan_t, catalan_);
  };
  //======================================================================================================================
  //! @addtogroup constants
  //! @{
  //!   @var catalan
  //!   @brief return the catalan value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto catalan(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the catalan value as T.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/catalan.cpp}
  //======================================================================================================================

  inline constexpr auto catalan = eve::functor<catalan_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}
