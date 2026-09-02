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
#include <polyfloat/module/core/is_not_finite.hpp>

namespace plf
{

  template<typename Options> struct mul_t : eve::strict_tuple_callable<mul_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z1, concepts::polyfloat_like Z2>
    POLYFLOAT_FORCEINLINE constexpr as_polyfloat_like_t<Z1, Z2> operator()(Z1 z1, Z2 z2) const noexcept
    {
      return POLYFLOAT_CALL(z1, z2);
    }

    POLYFLOAT_CALLABLE_OBJECT(mul_t, mul_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var mul
  //!   @brief return the product of the values.
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
  //!      template<polyfloat::concepts::polyfloat_like T1, polyfloat_like Z2> constexpr auto mul(T1 z1, T2 z2) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the product of the arguments.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/mul.cpp}
  //======================================================================================================================

  inline constexpr auto mul = eve::functor<mul_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================

  template<typename Options> constexpr auto neutral(mul_t<Options>) noexcept
  {
    return plf::one;
  }

  // Required for optimisation detections
  using callable_mul_ = eve::tag_t<mul>;

}

namespace plf::_
{
  template<typename Z1, typename Z2, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto mul_(POLYFLOAT_DELAY(), O const&, Z1 const& z1, Z2 const& z2) noexcept
  {
    return z1 * z2;
  }
}
