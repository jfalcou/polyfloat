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

namespace plf
{

  template<typename Options> struct fnma_t : eve::strict_tuple_callable<fnma_t, Options, raw_option, pedantic_option>
  {
    template<typename... Ts> struct result : as_polyfloat_like<Ts...>
    {
    };

    template<concepts::polyfloat_like Z0, concepts::polyfloat_like Z1, concepts::polyfloat_like Z2>
    EVE_FORCEINLINE typename result<Z0, Z1, Z2>::type constexpr operator()(Z0 z0, Z1 z1, Z2 z2) const noexcept
    {
      return POLYFLOAT_CALL(z0, z1, z2);
    }


    POLYFLOAT_CALLABLE_OBJECT(fnma_t, fnma_);
  };
  //======================================================================================================================
  //! @fnmatogroup core
  //! @{
  //!   @var fnma
  //!   @brief return the fused negated-multiply add of the parameters.
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <polyfloat/module/core.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace polyfloat
  //!   {
  //!      template<polyfloat::concepts::polyfloat_like Z1, polyfloat_like Z2, polyfloat_like Z3> constexpr auto fnma(Z1 z1, Z2 z2, Z3 z3) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z1`, `z2`, `z3`: Values to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the fused negated-multiply add of the arguments (-z1*z2+z3z).
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/fnma.cpp}
  //======================================================================================================================

  inline constexpr auto fnma = eve::functor<fnma_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z1, typename Z2, typename Z3, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto fnma_(POLYFLOAT_DELAY(), O const& , Z1 const& x, Z2 const& y, Z3 const& z) noexcept
  {
    return fma(minus(x), y, z);
  }
}
