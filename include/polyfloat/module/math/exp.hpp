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

  template<typename Options> struct exp_t : eve::elementwise_callable<exp_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    {
     return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(exp_t, exp_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var exp
  //!   @brief return the expolute value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto exp(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the expolute value of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/exp.cpp}
  //======================================================================================================================

  inline constexpr auto exp = eve::functor<exp_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto exp_(POLYFLOAT_DELAY(), O const& , Z const& z) noexcept
  {
    if constexpr(dimension_v<Z> == 1)
      return eve::exp(z);
    else
    {
      auto [m, e] = plf::frexp(z);
      std::cout << "m " << m << std::endl;
      std::cout << "e"  << e << std::endl;
    }
  }
}
