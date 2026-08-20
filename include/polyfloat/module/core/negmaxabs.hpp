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
#include <polyfloat/module/core/if_else.hpp>
#include <polyfloat/module/core/is_less.hpp>
#include <polyfloat/module/core/parts.hpp>

namespace plf
{

  template<typename Options> struct negmaxabs_t : eve::strict_tuple_callable<negmaxabs_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z1,  concepts::polyfloat_like ...Zs>
      POLYFLOAT_FORCEINLINE constexpr as_polyfloat_like_t<Z1, Zs...> operator()(Z1 z1, Zs ...zs) const noexcept
    {
     return POLYFLOAT_CALL(z1, zs...);
    }

    POLYFLOAT_CALLABLE_OBJECT(negmaxabs_t, negmaxabs_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var negmaxabs
  //!   @brief return the negated maximum of the absolute values.
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
  //!      template<polyfloat::concepts::polyfloat_like T1, polyfloat_like Z2> constexpr auto negmaxabs(T1 z1, T2 z2) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z, zs...`: Values to process.
  //!
  //!   **Return value**
  //!
  //!      Returns the negated maximum value of  the absolute values of the parameters.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/negmaxabs.cpp}
  //======================================================================================================================

  inline constexpr auto negmaxabs = eve::functor<negmaxabs_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================

}

namespace plf::_
{
  template<typename Z1, typename ... Zs, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto negmaxabs_(POLYFLOAT_DELAY(), O const& , Z1 z1, Zs ...zs) noexcept
  {
    return -plf::maxabs(z1, zs...);
  }
}
