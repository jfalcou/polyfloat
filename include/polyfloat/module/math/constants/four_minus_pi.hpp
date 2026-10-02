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
  template<typename Options> struct four_minus_pi_t : eve::constant_callable<four_minus_pi_t, Options>
  {
    template<typename T> static POLYFLOAT_FORCEINLINE constexpr auto value(eve::as<T> const&, auto const&)
    {
      using u_t = eve::underlying_type_t<T>;

      if constexpr (plf::dimension_v<T> == 1)
      {
        return eve::four_minus_pi(eve::as(u_t()));
      }
      if constexpr (plf::dimension_v<T> == 2)
      {
        if constexpr (std::same_as<u_t, float>)
          return plf::_::from_pair<u_t>(0x1.b7812a0000000p-1, 0x1.dde9740000000p-26);
        else if constexpr (std::same_as<u_t, double>)
          return plf::_::from_pair<u_t>(0x1.b7812aeef4b9fp-1, -0x1.a62633145c06ep-57);
      }
      else if constexpr (plf::dimension_v<T> == 3)
      {
        if constexpr (std::same_as<u_t, float>)
          return plf::_::from_triple<u_t>(0x1.b7812a0000000p-1, 0x1.dde9740000000p-26, -0x1.1a62640000000p-53);
        else if constexpr (std::same_as<u_t, double>)
          return plf::_::from_triple<u_t>(0x1.b7812aeef4b9fp-1, -0x1.a62633145c06ep-57, -0x1.cd129024e088ap-114);
      }
    }

    template<concepts::polyfloat_like T> POLYFLOAT_FORCEINLINE constexpr T operator()(as<T> const& v) const
    {
      return POLYFLOAT_CALL(v);
    }

    EVE_CALLABLE_OBJECT(four_minus_pi_t, four_minus_pi_);
  };
  //======================================================================================================================
  //! @addtogroup constants
  //! @{
  //!   @var four_minus_pi
  //!   @brief return the four_minus_pi value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto four_minus_pi(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the four_minus_pi value as T.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/four_minus_pi.cpp}
  //======================================================================================================================

  inline constexpr auto four_minus_pi = eve::functor<four_minus_pi_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}
