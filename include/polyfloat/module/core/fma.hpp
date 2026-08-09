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


namespace plf
{

  template<typename Options> struct fma_t : eve::strict_tuple_callable<fma_t, Options, raw_option, pedantic_option>
  {
    template<typename... Ts> struct result : as_polyfloat_like<Ts...>
    {
    };

    template<concepts::polyfloat_like Z0, concepts::polyfloat_like Z1, concepts::polyfloat_like Z2>
    EVE_FORCEINLINE typename result<Z0, Z1, Z2>::type constexpr operator()(Z0 z0, Z1 z1, Z2 z2) const noexcept
    {
      return POLYFLOAT_CALL(z0, z1, z2);
    }


    POLYFLOAT_CALLABLE_OBJECT(fma_t, fma_);
  };
  //======================================================================================================================
  //! @fmatogroup core
  //! @{
  //!   @var fma
  //!   @brief return the fused multiply add of the parameters.
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
  //!      template<kyosu::concepts::polyfloat_like Z1, polyfloat_like Z2, polyfloat_like Z3> constexpr auto fma(Z1 z1, Z2 z2, Z3 z3) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z1`, `z2`, `z3`: Values to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the fused multiply add of the arguments.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/fma.cpp}
  //======================================================================================================================

  inline constexpr auto fma = eve::functor<fma_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

   template<typename T>
   constexpr auto is_not_1or3_times_pow2(T x) noexcept
   {
     using u_t = eve::underlying_type_t<T>;
     constexpr unsigned long Q = 1ul << (eve::nbmantissabits(eve::as(u_t()))-2);
     constexpr unsigned long P = Q+1;
     auto l = P*x;
     auto r = Q*x;
     return plf::is_not_equal(l-r, x);
   }

   template<typename T>
   constexpr auto cr_dw_fp_add(T xh, T xl, T c) noexcept // Graillat & Muller algorithm
                                                         // https://hal.science/hal-04575249
   {
     using u_t = eve::underlying_type_t<T>;
     constexpr T c9_8 = u_t(9)/8;
     constexpr T c7_8 = u_t(7)/8;
     auto [sh, sl] = two_add(xh, c);
     auto [vh, vl] = two_add(xl, sl);
     auto in =  is_not_1or3_times_pow2(vh) || is_eqz(vl);
     auto samsgn = eve::sign(vl) == sign(vh);
     return add(sh, if_else(in,
                    vh,
                    if_else(samsgn, c9_8, c7_8)
                   )
               );
   }


  template<typename Z1, typename Z2, typename Z3, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto fma_(POLYFLOAT_DELAY(), O const& , Z1 const& x, Z2 const& y, Z3 const& z) noexcept
  {
    using r_t = as_polyfloat_t<Z1, Z2, Z3>;
//     if constexpr((dimension_v<Z1> > 2) && (dimension_v<Z2> > 2) &&(dimension_v<Z3> > 2))
//     {
//       return x*y+z; //TODO
//     }
    if constexpr((dimension_v<Z1> == 2) && (dimension_v<Z2> == 2) &&(dimension_v<Z3> == 2))
    {
      auto [xhi, xlo] = x;
      auto [yhi, ylo] = y;
      auto [zhi, zlo] = z;
      auto [chi, c1] = eve::two_prod(xhi, yhi);
      auto t0 = xlo * ylo;
      auto t1 = eve::fma(xhi, ylo, t0);
      auto c2 = eve::fma(xlo, yhi, t1);
      auto c3 = c1 + c2;
      auto [dhi, dlo] = eve::two_add[eve::raw](chi, c3);

      auto [shi, slo] = eve::two_add(zhi, dhi);
      auto [thi, tlo] = eve::two_add(zlo, dlo);
      auto c = slo + thi;
      auto [vhi, vlo] = eve::two_add[eve::raw](shi, c);
      auto w = tlo + vlo;
      auto [hi, lo] = eve::two_add[eve::raw](vhi, w);
      return r_t(hi, lo);
    }
    else  if constexpr ((dimension_v<Z1> == 1) && (dimension_v<Z2> == 1))
    {
      if constexpr(dimension_v<Z3> == 1)
        return eve::fma(x, y, z);
      else if constexpr(dimension_v<Z3> == 2)
      {
        auto [zhi, zlo] = z;
        auto [chi, c1] = eve::two_prod(x, y);
        auto [shi, slo] = eve::two_add(zhi, chi);
        auto [thi, tlo] = eve::two_add(zlo, c1);
        auto c = slo + thi;
        auto [vhi, vlo] = eve::two_add[eve::raw](shi, c);
        auto w = tlo + vlo;
        auto [hi, lo] = eve::two_add[eve::raw](vhi, w);
        return r_t(hi, lo);
      }
    }
    else
    {
      using r_t = as_polyfloat_t<Z1, Z2, Z3>;
      auto cvt =  [](auto a){return plf::convert(a, eve::as<eve::element_type_t<r_t>>());};

      auto [xh, xl] = two_prod(cvt(x), cvt(y));
      return cr_dw_fp_add(xl, xh, cvt(z));
    }
  }
}
