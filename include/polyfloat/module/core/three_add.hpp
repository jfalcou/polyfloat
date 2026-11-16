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
#include <polyfloat/module/core/is_not_equal.hpp>
#include <polyfloat/details/graillat.hpp>

namespace plf
{

  template<typename Options>
  struct three_add_t : eve::strict_tuple_callable<three_add_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_ABI eve::zipped<Z, Z, Z> constexpr operator()(Z z0, Z z1, Z z2) const noexcept
    {
      return POLYFLOAT_CALL(z0, z1, z2);
    }

    POLYFLOAT_CALLABLE_OBJECT(three_add_t, three_add_);
  };
  //======================================================================================================================
  //! @defgroup plf_three_add plf::three_add
  //! @ingroup core_accuracy
  //! @brief Computes the triple of the rounded sum of three values and its two error terms.
  //! @{
  //!   @var three_add
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
  //!      template<concepts::polyfloat_like Z> constexpr auto three_add(Z z1, Z z2, Z z3) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z1`, `z2`, `z3`: three values of the same type, `float` or `double`, or their registers.
  //!
  //!   **Return value**
  //!
  //!     A triple \f$(s, e_1, e_2)\f$ where \f$s\f$ is the sum \f$z_1 + z_2 + z_3\f$ rounded to nearest, computed by
  //!     plf::two_add then Algorithm 7 of Graillat and Muller, which returns \f$s + e_1 + e_2\f$ equal to the
  //!     exact sum in rounding to nearest, without overflow or underflow.
  //!
  //!  @groupheader{External references}
  //!   *  [S. Graillat, J.-M. Muller, Emulation of the FMA and the correctly-rounded sum of three numbers](https://hal.science/hal-04575249)
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/three_add.cpp}
  //======================================================================================================================

  inline constexpr auto three_add = eve::functor<three_add_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<typename Z, eve::callable_options O>
  constexpr auto three_add_(POLYFLOAT_DELAY(), O const&, Z const& x, Z const& y, Z const& z) noexcept
  {
    auto [xh, xl] = two_add(x, y);
    return cr_dw_fp_add_with_err(xh, xl, z);
  }
}
