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
#include <polyfloat/module/core/trunc.hpp>
#include <polyfloat/module/core/nearest.hpp>
#include <polyfloat/module/core/ceil.hpp>
#include <polyfloat/module/core/floor.hpp>

namespace plf
{

  template<typename Options>
  struct sign_alternate_t : eve::callable<sign_alternate_t,
                                          Options,
                                          raw_option,
                                          pedantic_option,
                                          to_nearest_option,
                                          toward_zero_option,
                                          downward_option,
                                          upward_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_ABI Z operator()(Z z) const noexcept { return POLYFLOAT_CALL(z); }

    POLYFLOAT_CALLABLE_OBJECT(sign_alternate_t, sign_alternate_);
  };
  //======================================================================================================================
  //! @defgroup plf_sign_alternate plf::sign_alternate
  //! @ingroup core
  //! @brief return \f$(-1)^n\f$.
  //! @{
  //!   @var sign_alternate
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <polyfloat/polyfloat.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace plf
  //!   {
  //!      template<concepts::polyfloat_like T1, concepts::polyfloat_like T2> constexpr auto sign_alternate(T1 x, T2 y) noexcept; //1
  //!
  //!      // Semantic exclusive options
  //!      constexpr auto sign_alternate[upward](/*any of the above overloads*/)                   noexcept; // 2
  //!      constexpr auto sign_alternate[downward](/*any of the above overloads*/)                 noexcept; // 2
  //!      constexpr auto sign_alternate[toward_zero](/*any of the above overloads*/)              noexcept; // 2
  //!      constexpr auto sign_alternate[to_nearest](/*any of the above overloads*/)               noexcept; // 2
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z1`: Value to process.
  //!
  //!   **Return value**
  //!
  //!      1. Returns \f$(-1)^{\tilde n}\f$,  where \f$\tilde n\f$ is the truncation of `n`.
  //!      2. The chosen rounding option is applied to `n` before computation, instead of truncation.
  //!
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/sign_alternate.cpp}
  //======================================================================================================================

  inline constexpr auto sign_alternate = eve::functor<sign_alternate_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename T, eve::callable_options O>
  constexpr auto sign_alternate_(POLYFLOAT_DELAY(), O const& o, T n) noexcept
  {
    if constexpr (O::contains_any(upward, downward, to_nearest, toward_zero))
      return plf::if_else(is_odd(plf::round[o](n)), eve::mone, plf::one(as(n)));
    else return plf::if_else(is_odd(plf::trunc(n)), eve::mone, plf::one(as(n)));
  }
}
