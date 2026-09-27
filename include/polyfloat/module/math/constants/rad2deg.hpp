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
  template<typename Options> struct rad2deg_t : eve::constant_callable<rad2deg_t, Options>
  {
    template<typename T> static POLYFLOAT_FORCEINLINE constexpr auto value(eve::as<T> const&, auto const&)
    {
      using u_t = eve::underlying_type_t<T>;

      if constexpr (plf::dimension_v<T> == 1)
      {
        return 180 / eve::pi(eve::as(u_t()));
      }
      if constexpr (plf::dimension_v<T> == 2)
      {
        if constexpr (std::same_as<u_t, float>)
          return plf::_::from_pair<u_t>(0x1.ca5dc20000000p+5, -0x1.670f820000000p-21);
        else if constexpr (std::same_as<u_t, double>)
          return plf::_::from_pair<u_t>(0x1.ca5dc1a63c1f8p+5, -0x1.1e7ab456405f9p-49);
      }
      else if constexpr (plf::dimension_v<T> == 3)
      {
        if constexpr (std::same_as<u_t, float>)
          return plf::_::from_triple<u_t>(0x1.ca5dc20000000p+5, -0x1.670f820000000p-21, -0x1.1e7ab40000000p-49);
        else if constexpr (std::same_as<u_t, double>)
          return plf::_::from_triple<u_t>(0x1.ca5dc1a63c1f8p+5, -0x1.1e7ab456405f9p-49, -0x1.b505196fabb41p-103);
      }
    }

    template<concepts::polyfloat_like T> POLYFLOAT_FORCEINLINE constexpr T operator()(as<T> const& v) const
    {
      return POLYFLOAT_CALL(v);
    }

    EVE_CALLABLE_OBJECT(rad2deg_t, rad2deg_);
  };
  //======================================================================================================================
  //! @addtogroup constants
  //! @{
  //!   @var rad2deg
  //!   @brief return the rad2deg value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto rad2deg(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the rad2deg value as T.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/rad2deg.cpp}
  //======================================================================================================================

  inline constexpr auto rad2deg = eve::functor<rad2deg_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}
