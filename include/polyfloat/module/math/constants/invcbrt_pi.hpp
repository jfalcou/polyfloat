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
  template<typename Options> struct invcbrt_pi_t : eve::constant_callable<invcbrt_pi_t, Options>
  {
    template<typename T> static POLYFLOAT_FORCEINLINE constexpr auto value(eve::as<T> const&, auto const&)
    {
      using u_t = eve::underlying_type_t<T>;

      if constexpr (plf::dimension_v<T> == 1)
      {
        return eve::invcbrt_pi(eve::as(u_t()));
      }
      if constexpr (plf::dimension_v<T> == 2)
      {
        if constexpr (std::same_as<u_t, float>)
          return plf::_::from_pair<u_t>(0x1.5d95e00000000p-1, -0x1.285aa20000000p-26);
        else if constexpr (std::same_as<u_t, double>)
          return plf::_::from_pair<u_t>(0x1.5d95df6bd2aeep-1, -0x1.9749756e80c72p-55);
      }
      else if constexpr (plf::dimension_v<T> == 3)
      {
        if constexpr (std::same_as<u_t, float>)
          return plf::_::from_triple<u_t>(0x1.5d95e00000000p-1, -0x1.285aa20000000p-26, -0x1.32e92e0000000p-52);
        else if constexpr (std::same_as<u_t, double>)
          return plf::_::from_triple<u_t>(0x1.5d95df6bd2aeep-1, -0x1.9749756e80c72p-55, -0x1.279bb37a6148fp-109);
      }
    }

    template<concepts::polyfloat_like T> POLYFLOAT_FORCEINLINE constexpr T operator()(as<T> const& v) const
    {
      return POLYFLOAT_CALL(v);
    }

    EVE_CALLABLE_OBJECT(invcbrt_pi_t, invcbrt_pi_);
  };
  //======================================================================================================================
  //! @addtogroup constants
  //! @{
  //!   @var invcbrt_pi
  //!   @brief return the invcbrt_pi value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto invcbrt_pi(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the invcbrt_pi value as T.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/invcbrt_pi.cpp}
  //======================================================================================================================

  inline constexpr auto invcbrt_pi = eve::functor<invcbrt_pi_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}
