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
#include <polyfloat/module/math/sinh.hpp>

namespace plf
{

  template<typename Options>
  struct csch_t : plf::elementwise_callable<csch_t, eve::csch_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_ABI constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(csch_t, csch_);
  };
  //======================================================================================================================
  //! @addtogroup math
  //! @{
  //!   @var csch
  //!   @brief return the hyperbolic cosecant value.
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <polyfloat/math.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace polyfloat
  //!   {
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto csch(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the hyperbolic cosecant of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/math/csch.cpp}
  //======================================================================================================================

  inline constexpr auto csch = eve::functor<csch_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename T, eve::callable_options O> constexpr auto csch_(POLYFLOAT_DELAY(), O const& o, T a0) noexcept
  {
    return plf::rec[pedantic](plf::sinh[o](a0));
  }
}
