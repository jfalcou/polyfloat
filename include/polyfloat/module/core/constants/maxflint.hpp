//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

#include <eve/eve.hpp>
#include <polyfloat/details/callable.hpp>
#include <polyfloat/types/concepts.hpp>
#include <polyfloat/types/traits.hpp>

namespace plf
{
  template<typename Options>
  struct maxflint_t : plf::constant_callable<maxflint_t, eve::maxflint_t, Options, lower_option, upper_option>
  {
    template<typename T> POLYFLOAT_ABI static constexpr auto value(eve::as<T> const&, auto const&)
    {
      if constexpr (dimension_v<T> == 2) return T(ldexp(1.0, 106), ldexp(1.0, 53));
      else if constexpr (dimension_v<T> == 3) return T(ldexp(1.0, 159), ldexp(1.0, 106), ldexp(1.0, 53));
    }

    template<concepts::polyfloat_like T> POLYFLOAT_ABI constexpr T operator()(as<T> const& v) const
    {
      return POLYFLOAT_CALL(v);
    }

    POLYFLOAT_CALLABLE_OBJECT(maxflint_t, maxflint_);
  };
  //======================================================================================================================
  //! @defgroup plf_maxflint plf::maxflint
  //! @ingroup constants
  //! @brief return the integer beyond which not every integer is representable in the type.
  //! @{
  //!   @var maxflint
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
  //!      template<concepts::polyfloat_like T> constexpr auto maxflint(eve::as<T> z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: [Type wrapper](@ref eve::as) of the type of the constant.
  //!
  //!   **Return value**
  //!
  //!     Returns the maximal representable flint value.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/maxflint.cpp}
  //======================================================================================================================

  inline constexpr auto maxflint = eve::functor<maxflint_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}
