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
#include <polyfloat/functions/abs.hpp>
#include <polyfloat/functions/frexp.hpp>
#include <polyfloat/functions/ldexp.hpp>

namespace plf
{

  template<typename Options> struct ulpdist_t : eve::elementwise_callable<ulpdist_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z1,  concepts::polyfloat_like Z2>
      POLYFLOAT_FORCEINLINE constexpr as_polyfloat_like_t<Z1, Z2> operator()(Z1 z1, Z2 z2) const noexcept
    {
     return POLYFLOAT_CALL(z1, z2);
    }

    POLYFLOAT_CALLABLE_OBJECT(ulpdist_t, ulpdist_);
  };
  //======================================================================================================================
  //! @addtogroup functions
  //! @{
  //!   @var ulpdist
  //!   @brief return the ulpdistance value.
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <kyosu/functions.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace kyosu
  //!   {
  //!      template<kyosu::concepts::polyfloat_like T1, polyfloat_like Z2> constexpr auto ulpdist(T1 z1, T2 z2) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the ulpdistolute value of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/ulpdist.cpp}
  //======================================================================================================================

  inline constexpr auto ulpdist = eve::functor<ulpdist_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template <typename T> constexpr auto epsi(){ //TODO create constants
    using u_t = decltype(plf::hi(T()));
    if constexpr(plf::dimension_v<T> == 1)
      return  (sizeof(u_t) == 8 ? 1.1102e-16 : 1.1921e-07)*4;
    if constexpr(plf::dimension_v<T> == 2)
      return (sizeof(u_t) == 8 ? 1.2326e-32 : 1.4211e-14)*4;
    else if constexpr(plf::dimension_v<T> == 3)
      return (sizeof(u_t) == 8 ? 1.3685e-48 : 1.6941e-21)*4;
  }

  template<typename Z0, typename Z1, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto ulpdist_(POLYFLOAT_DELAY(), O const& , Z0 const& z0, Z1 const& z1) noexcept
  {
    using r_t = as_polyfloat_like_t<Z0, Z1>;
    using u_t = decltype(hi(r_t()));
    if constexpr(dimension_v<r_t> == 1)
      return eve::ulpdist(z0, z1);
    else
    {
      auto [ m1, e1] = frexp(z0);
      auto [ m2, e2] = frexp(z1);
      auto expo = -max(e1, e2);
      auto e = abs(if_else( e1 == e2
                          , m1-m2
                          , ldexp(z0, expo)-ldexp(z1, expo)
                          )
                  );
      return if_else( (is_nan(z0) && is_nan(z1)) || (z0 == z1)
                    , eve::zero
                    , e/r_t(epsi<u_t>())
                    );
    }
  }
}
