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
  template<typename Options> struct egamma_t : eve::constant_callable<egamma_t, Options>
  {
    template<typename T> static POLYFLOAT_FORCEINLINE constexpr auto value(eve::as<T> const&, auto const&)
    {
      using u_t = eve::underlying_type_t<T>;

      if constexpr (plf::dimension_v<T> == 1)
      {
        return eve::egamma(eve::as(u_t()));
      }
      if constexpr (plf::dimension_v<T> == 2)
      {
        if constexpr (std::same_as<u_t, float>)
          return plf::_::from_pair<u_t>(0x1.2788d00000000p-1, -0x1.c824f40000000p-28);
        else if constexpr (std::same_as<u_t, double>)
          return plf::_::from_pair<u_t>(0x1.2788cfc6fb619p-1, -0x1.6cb90701fbfabp-58);
      }
      else if constexpr (plf::dimension_v<T> == 3)
      {
        if constexpr (std::same_as<u_t, float>)
          return plf::_::from_triple<u_t>(0x1.2788d00000000p-1, -0x1.c824f40000000p-28, 0x1.e934700000000p-54);
        else if constexpr (std::same_as<u_t, double>)
          return plf::_::from_triple<u_t>(0x1.2788cfc6fb619p-1, -0x1.6cb90701fbfabp-58, -0x1.34a95e3133c51p-112);
      }
    }

    template<concepts::polyfloat_like T> POLYFLOAT_FORCEINLINE constexpr T operator()(as<T> const& v) const
    {
      return POLYFLOAT_CALL(v);
    }

    EVE_CALLABLE_OBJECT(egamma_t, egamma_);
  };
  //======================================================================================================================
  //! @addtogroup constants
  //! @{
  //!   @var egamma
  //!   @brief return the egamma value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto egamma(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the egamma value as T.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/egamma.cpp}
  //======================================================================================================================

  inline constexpr auto egamma = eve::functor<egamma_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}
