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
#include <type_traits>
#include <polyfloat/module/core/if_else.hpp>
#include <polyfloat/module/core/inc.hpp>
#include <polyfloat/module/core/is_negative.hpp>

namespace plf
{

  template<typename Options> struct ceil_t : eve::elementwise_callable<ceil_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(ceil_t, ceil_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var ceil
  //!   @brief return the ceil value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto ceil(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the ceil value of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/ceil.cpp}
  //======================================================================================================================

  inline constexpr auto ceil = eve::functor<ceil_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto ceil_(POLYFLOAT_DELAY(), O const&, Z const& z) noexcept
  {
    if constexpr (dimension_v<Z> == 1) return eve::ceil(z);
    else if constexpr (dimension_v<Z> == 2)
    {
      auto [h, l] = z;

      auto iflh = eve::is_flint(h);
      auto ifll = eve::is_flint(l);
      auto ch = ceil(h);
      auto z1 = if_else(!iflh, Z(ch), Z(ch, ceil(l)));
      return if_else(iflh && ifll, z, z1);
    }
    else if constexpr (dimension_v<Z> == 3)
    {
      auto [h, m, l] = z;
      auto iflh = eve::is_flint(h);
      auto iflm = eve::is_flint(m);
      auto ifll = eve::is_flint(l);
      auto ch = ceil(h);
      auto cm = ceil(m);
      auto cl = ceil(l);
      auto z1 = if_else(!iflh, Z(ch), if_else(!iflm, Z(ch, cm), Z(ch, cm, cl)));
      return if_else(iflh && iflm && ifll, z, z1);
    }
  }
}
