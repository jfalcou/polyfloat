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
#include <polyfloat/module/core/floor.hpp>

namespace plf
{

  template<typename Options>
  struct quadrant_t : eve::elementwise_callable<quadrant_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    requires(!eve::integral_value<Z>)
    {
      return POLYFLOAT_CALL(z);
    }

    template<eve::integral_value Z> POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }
    POLYFLOAT_CALLABLE_OBJECT(quadrant_t, quadrant_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var quadrant
  //!   @brief return the quadrant value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto quadrant(T n) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `n`: Value to process. Must be of  integral type or a [flint](@ref is_flint)
  //!
  //!   **Return value**
  //!
  //!      return a value of the same type as `n` containing the quadrant number where `n` (supposed an
  //!      integer) lies.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/quadrant.cpp}
  //======================================================================================================================

  inline constexpr auto quadrant = eve::functor<quadrant_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto quadrant_(POLYFLOAT_DELAY(), O const&, Z const& a) noexcept
  {
    if constexpr (dimension_v<Z> == 1 || eve::integral_value<Z>) return eve::quadrant(a);
    else
    {
      Z b = plf::trunc(a) / 4;
      return (b - plf::floor(b)) * 4;
    }
  }
}
