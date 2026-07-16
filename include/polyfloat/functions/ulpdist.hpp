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
#include <iostream>

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

  template <typename T> constexpr T epsi(){ //TODO create constants
    using u_t = as_component_type_t<T>;
    if constexpr(plf::dimension_v<T> == 1)
      return  (sizeof(u_t) == 4 ? 2.384185791015625e-07 :  2.220446049250313e-16);
    else if constexpr(plf::dimension_v<T> == 2)
      return (sizeof(u_t) == 4 ? 2.842170943040401e-14 :  3.388131789017201e-21);
    else if constexpr(plf::dimension_v<T> == 3)
      return (sizeof(u_t) == 4 ? 2.465190328815662e-32 :  2.736911063134408e-48); ;
  }

  template<typename Z0, typename Z1, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto ulpdist_(POLYFLOAT_DELAY(), O const& , Z0 const& z0, Z1 const& z1) noexcept
  {
    using r_t = as_polyfloat_like_t<Z0, Z1>;
    using u_t = as_component_type_t<r_t>;
    if constexpr(dimension_v<r_t> == 1)
      return eve::ulpdist(z0, z1);
    else
    {
      auto reps = eve::rec[pedantic](epsi<u_t>());
      auto [ m1, e1] = frexp(z0);
      auto [ m2, e2] = frexp(z1);
      auto expo = -max(e1, e2);
      std::cout << std::endl << "eps " << epsi<r_t>() <<std::endl;
      std::cout << std::endl << "reps " << reps <<std::endl;
      std::cout << std::endl << "e1 " << e1 << " e2 " << e2 <<std::endl;
      std::cout << std::endl << "m1 " << m1 << " m2 " << m2 <<std::endl;
      auto e = abs(if_else( e1 == e2
                          , m1-m2
                          , ldexp(z0, expo)-ldexp(z1, expo)
                          )
                  );
      std::cout << std::endl << "m1 - m2 " << m1 - m2 <<std::endl;
      std::cout << std::endl << "e       " << e       <<std::endl;
      return if_else( (is_nan(z0) && is_nan(z1)) || (z0 == z1)
                    , eve::zero
                    , e*reps
                    );
    }
  }
}
