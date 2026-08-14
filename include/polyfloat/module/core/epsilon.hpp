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

  template<typename Options> struct epsilon_t : eve::elementwise_callable<epsilon_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_FORCEINLINE constexpr as_component_type_t<Z> operator()(Z z) const noexcept
    {
     return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(epsilon_t, epsilon_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var epsilon
  //!   @brief return the epsilon value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto epsilon(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the epsilon of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/epsilon.cpp}
  //======================================================================================================================

  inline constexpr auto epsilon = eve::functor<epsilon_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto epsilon_(POLYFLOAT_DELAY(), O const& , Z const& z) noexcept
  {
    if constexpr(dimension_v<Z> == 1)
      return eve::epsilon(z);
    else if constexpr(dimension_v<Z> == 2)
    {
      auto [h, l] = z;
      return if_else(eve::is_nez(l), eve::epsilon(l), eve::epsilon(eve::sulp(h)));
    }
    else if constexpr(dimension_v<Z> == 3)
    {
      auto [h, m, l] = z;
      return plf::if_else(eve::is_nez(l),
                          eve::epsilon(l),
                          plf::if_else(eve::is_nez(m),
                                       eve::epsilon(eve::sulp(m)),
                                       eve::epsilon(eve::sulp(eve::sulp(h)))
                                      )
                         );
    }
  }
}
