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

namespace plf
{

  template<typename Options> struct fsm_t : eve::strict_tuple_callable<fsm_t, Options, raw_option, pedantic_option>
  {
    template<typename... Ts> struct result : as_polyfloat_like<Ts...>
    {
    };

    template<concepts::polyfloat_like Z0, concepts::polyfloat_like Z1, concepts::polyfloat_like Z2>
    EVE_FORCEINLINE typename result<Z0, Z1, Z2>::type constexpr operator()(Z0 z0, Z1 z1, Z2 z2) const noexcept
    {
      return POLYFLOAT_CALL(z0, z1, z2);
    }

    POLYFLOAT_CALLABLE_OBJECT(fsm_t, fsm_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var fsm
  //!   @brief return the fused asubtract multiply  of the parameters.
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
  //!      template<polyfloat::concepts::polyfloat_like Z1, polyfloat_like Z2, polyfloat_like Z3> constexpr auto fsm(Z1 z1, Z2 z2, Z3 z3) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z1`, `z2`, `z3`: Values to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the fused subtract multiply of the arguments.
  //!
  //! @note contrarily to `eve::fsm`,  `plf::fsm` garanties the correct fused multiply add rounding behaviour,  even if it has to be emulated.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/fsm.cpp}
  //======================================================================================================================

  inline constexpr auto fsm = eve::functor<fsm_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z1, typename Z2, typename Z3, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto fsm_(POLYFLOAT_DELAY(), O const&, Z1 const& x, Z2 const& y, Z3 const& z) noexcept
  {
    return plf::fma(y, z, -x);
  }
}
