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

  template<typename Options> struct three_add_t : eve::strict_tuple_callable<three_add_t, Options, raw_option, pedantic_option>
  {
    template<typename... Ts> struct result : kumi::tuple<as_polyfloat_like<Ts...>,
                                                         as_polyfloat_like<Ts...>,
                                                         as_polyfloat_like<Ts...>>

    {
    };

    template<concepts::polyfloat_like Z0, concepts::polyfloat_like Z1, concepts::polyfloat_like Z2>
    EVE_FORCEINLINE //typename result<Z0, Z1, Z2>::type
    kumi::tuple<Z0, Z0, Z0>
    constexpr operator()(Z0 z0, Z1 z1, Z2 z2) const noexcept
    {
      return POLYFLOAT_CALL(z0, z1, z2);
    }


    POLYFLOAT_CALLABLE_OBJECT(three_add_t, three_add_);
  };
  //======================================================================================================================
  //! @three_addtogroup core
  //! @{
  //!   @var three_add
  //!   @brief return the sum of the parameters with errors.
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <kyosu/module/core.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace kyosu
  //!   {
  //!      template<kyosu::concepts::polyfloat_like Z1, polyfloat_like Z2, polyfloat_like Z3> constexpr auto three_add(Z1 z1, Z2 z2, Z3 z3) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z1`, `z2`, `z3`: Values to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the sum of the arguments and two errors .
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/three_add.cpp}
  //======================================================================================================================

  inline constexpr auto three_add = eve::functor<three_add_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<typename Z1, typename Z2, typename Z3, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto three_add_(POLYFLOAT_DELAY(), O const& , Z1 const& x, Z2 const& y, Z3 const& z) noexcept
  {

    using r_t = as_polyfloat_t<Z1, Z2, Z3>;
    auto cvt =  [](auto a){return plf::convert(a, eve::as<eve::element_type_t<r_t>>());};

    auto [xh, xl] = two_add(cvt(x), cvt(y));
    return cr_dw_fp_add_with_err(xl, xh, cvt(z));
  }
}
