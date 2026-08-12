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
#include <polyfloat/module/core/abs.hpp>
#include <polyfloat/module/core/is_infinite.hpp>
#include <polyfloat/module/core/is_eqz.hpp>
#include <polyfloat/module/core/max.hpp>


namespace plf
{

  template<typename Options> struct reldist_t : eve::strict_elementwise_callable<reldist_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z1,  concepts::polyfloat_like Z2>
      POLYFLOAT_FORCEINLINE constexpr as_polyfloat_like_t<Z1, Z2> operator()(Z1 z1, Z2 z2) const noexcept
    {
     return POLYFLOAT_CALL(z1, z2);
    }

    POLYFLOAT_CALLABLE_OBJECT(reldist_t, reldist_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var reldist
  //!   @brief return the relative distance value.
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
  //!      template<polyfloat::concepts::polyfloat_like T1, polyfloat_like Z2> constexpr auto reldist(T1 z1, T2 z2) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!      Returns the the relative distance computed as the absolute value of the arguments difference given by `dist`
  //!        divided by the maximum of their absolute values and 1.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/reldist.cpp}
  //======================================================================================================================

  inline constexpr auto reldist = eve::functor<reldist_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z1, typename Z2, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto reldist_(POLYFLOAT_DELAY(), O const& o, Z1 const& z1, Z2 const& z2) noexcept
  {
    auto d = dist[o](z1, z2);
    return if_else(is_infinite(d) || is_eqz(d), d,
                   d / plf::max(abs(z1), abs(z2), eve::one(eve::as(abs(hi(z1))))));
  }
}
