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
#include <polyfloat/module/core/minus.hpp>
#include <polyfloat/module/core/is_negative.hpp>

namespace plf
{

  template<typename Options> struct ulp_t : eve::elementwise_callable<ulp_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    {
     return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(ulp_t, ulp_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var ulp
  //!   @brief return the ulpolute value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto ulp(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the ulpolute value of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/ulp.cpp}
  //======================================================================================================================

  inline constexpr auto ulp = eve::functor<ulp_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto ulp_(POLYFLOAT_DELAY(), O const& , Z const& z) noexcept
  {
    if constexpr(dimension_v<Z> == 1)
      return eve::ulp(z);
    else if constexpr(dimension_v<Z> == 2)
    {
      auto [h, l] = z;
      return if_else(is_nez(l), ulp(l), ulp(h));
    }
    else if constexpr(dimension_v<Z> == 3)
    {
      auto [h, m, l] = z;
      return plf::if_else(eve::is_nez(l),
                          eve::ulp(l),
                          plf::if_else(eve::is_nez(m),
                                       eve::ulp(m),
                                       eve::ulp(h)
                                      )
                         );
    }
  }
}
