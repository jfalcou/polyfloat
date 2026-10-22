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
#include <polyfloat/module/math/exp.hpp>

namespace plf
{

  template<typename Options>
  struct log1p_t : plf::elementwise_callable<log1p_t, eve::log1p_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_ABI constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(log1p_t, log1p_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var log1p
  //!   @brief return the natural logarithm value of one plus the argument.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto log1p(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the expolute,natural log1parithm of of 1+z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/math/log1p.cpp}
  //======================================================================================================================

  inline constexpr auto log1p = eve::functor<log1p_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<typename T, eve::callable_options O> constexpr auto log1p_(POLYFLOAT_DELAY(), O const&, T x) noexcept
  {
    return plf::log(inc(x));
    //     this seems to be good to use in eve TO DO
    //     auto [incx, e] = plf::two_add(plf::one(eve::as(x)), x);
    //     auto r = plf::log(incx);
    //     if constexpr(O::contains(eve::raw))
    //       return r;
    //     else
    //     {
    //       return plf::if_else(plf::is_eqz(r), e, r);
    //     }
  }
}
