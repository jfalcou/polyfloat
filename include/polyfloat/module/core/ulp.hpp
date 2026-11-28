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
#include <polyfloat/module/core/is_nez.hpp>

namespace plf
{

  template<typename Options>
  struct ulp_t : plf::elementwise_callable<ulp_t,
                                           eve::ulp_t,
                                           Options,
                                           raw_option,
                                           pedantic_option> //, effective_option, structural_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_ABI constexpr Z operator()(Z z) const noexcept
    {
      return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(ulp_t, ulp_);
  };
  //======================================================================================================================
  //! @defgroup plf_ulp plf::ulp
  //! @ingroup core
  //! @brief return the effective unit in the last place of the value.
  //! @{
  //!   @var ulp
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
  //!      template<concepts::polyfloat_like T> constexpr auto ulp(T z) noexcept;                //1
  //!      template<concepts::polyfloat_like T> constexpr auto ulp[effective](T z) noexcept;     //1
  //!      template<concepts::polyfloat_like T> constexpr auto ulp[structural](T z) noexcept;    //2
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     1. Returns the effective unit in the last place of `z`.
  //!     2. Returns the structural unit in the last place of `z`.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/ulp.cpp}
  //======================================================================================================================

  inline constexpr auto ulp = eve::functor<ulp_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<typename Z, eve::callable_options O> constexpr auto ulp_(POLYFLOAT_DELAY(), O const&, Z const& z) noexcept
  {
    //     if constexpr(O::contains(plf::structural))
    //     {
    //       if constexpr (limbs_v<Z> == 2)
    //       {
    //         auto [h, l] = z;
    //         return if_else(is_nez(l), ulp(l), ulp(h));
    //       }
    //       else if constexpr (limbs_v<Z> == 3)
    //       {
    //         auto [h, m, l] = z;
    //         return plf::if_else(eve::is_nez(l), eve::ulp(l), plf::if_else(eve::is_nez(m), eve::ulp(m), eve::ulp(h)));
    //       }
    //     }
    //     else
    {
      return exp2n(exponent(hi(x) - nbmantissabits(as(z)) + 1));
    }
  }
}
