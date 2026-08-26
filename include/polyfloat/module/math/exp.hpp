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
#include <polyfloat/module/core/minus.hpp>
#include <polyfloat/module/core/is_negative.hpp>
#include <iostream>
#include <iomanip>

namespace plf
{

  template<typename Options> struct exp_t : eve::elementwise_callable<exp_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z>
    POLYFLOAT_FORCEINLINE constexpr Z operator()(Z z) const noexcept
    {
     return POLYFLOAT_CALL(z);
    }

    POLYFLOAT_CALLABLE_OBJECT(exp_t, exp_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var exp
  //!   @brief return the expolute value.
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
  //!      template<polyfloat::concepts::polyfloat_like T> constexpr auto exp(T z) noexcept;
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!     * `z`: Value to process.
  //!
  //!   **Return value**
  //!
  //!     Returns the expolute value of z.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/exp.cpp}
  //======================================================================================================================

  inline constexpr auto exp = eve::functor<exp_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
//   template<typename T, eve::callable_options O>
//   constexpr auto exp_(POLYFLOAT_DELAY(), O const& , T const& x) noexcept
//   {
//     using e_t = eve::underlying_type_t<T>;
//     auto invlog2 = [](){
//       if constexpr (dimension_v<T> == 2)
//       {
//         if constexpr(std::same_as<T, double>) return T( 0x1.71547652b82fep+0, 0x1.777d0ffda0d24p-56);
//         else if constexpr(std::same_as<T, float>) return T(0x1.715476p+0, 0x1.4ae0cp-26);
//       }
//       else if constexpr (dimension_v<T> == 3)
//       {
//         if constexpr(std::same_as<T, double>) return T( 0x1.71547652b82fep+0, 0x1.777d0ffda0d24p-56, - 0x1.60bb8a5442ab9p-110 );
//         else if constexpr(std::same_as<T, float>) return T(0x1.715476p+0, 0x1.4ae0cp-26, - 0x1p-51);
//       }
//       return T();
//     };
//     auto c_1 = [](){
//       if constexpr (dimension_v<T> == 2)
//       {
//         if constexpr(std::same_as<T, double>) return T(0x1.62e42fefa39fp-1, 0x0p+0);
//         else if constexpr(std::same_as<T, float>) return T(0x1.62e43p-1, 0x0p+0);
//       }
//       else if constexpr (dimension_v<T> == 3)
//       {
//         if constexpr(std::same_as<T, double>) return T(0x1.62e42fefa39fp-1, -0x0p+0, -0x0p+0 );
//         else if constexpr(std::same_as<T, float>) return T( 0x1.62e43p-1, -0x0p+0, -0x0p+0);
//       }
//       return T();
//     };
//     auto c_2 = [](){
//       if constexpr (dimension_v<T> == 2)
//       {
//         if constexpr(std::same_as<T, double>) return T(-0x1.950d871319ffp-54, -0x1p-108);
//         else if constexpr(std::same_as<T, float>) return T(-0x1.05c61p-29, 0x0p+0);
//       }
//       else if constexpr (dimension_v<T> == 3)
//       {
//         if constexpr(std::same_as<T, double>) return T( -0x1.950d871319ffp-54, -0x1.a12a17e1979b3p-109, +0x0p+0);
//         else if constexpr(std::same_as<T, float>) return T(-0x1.05c61p-29, -0x1.950d88p-54, + 0x0p+0);
//       }
//       return T();
//     };
//  //    std::cout << invlog2() << std::endl;
// //     std::cout << c1()      << std::endl;
//     if constexpr(dimension_v<T> == 1)
//       return eve::exp(x);
//     else
//     {
//       auto c = invlog2();
//       auto c1= c_1();
//       auto c2= c_2();
// //       std::cout << " reduction " << x << std::endl;
// //       std::cout << "c " << c << std::endl;
//       auto z = plf::nearest(x*c);
// //       std::cout << "zz " << z << std::endl;
//       auto u = plf::fma(-z, c1, x);
// //       std::cout << "u " << u << std::endl;
//       auto v1 = plf::fma(-z, c2, u);
// //       std::cout << "u-v " << u-v1 << std::endl;

//       auto num = plf::horner(v1, 1.0, 156.0, 12012.0, 600600.0, 21621600.0 ,
//                               588107520.0, 12350257920.0, 201132771840.0, 2514159648000.0,
//                               23465490048000.0, 154872234316800.0,
//                               647647525324800.0, + 1295295050649600.0);
//       auto den = plf::horner(v1, -156.0, 12012.0, -600600.0, 21621600.0 ,
//                               -588107520.0, 12350257920.0, -201132771840.0, 2514159648000.0,
//                               -23465490048000.0, 154872234316800.0,
//                               -647647525324800.0, + 1295295050649600.0);
//       return plf::ldexp(num/den, hi(z));
//     }
//   }

  template<typename T, eve::callable_options O>
  constexpr auto exp_(POLYFLOAT_DELAY(), O const& , T xx) noexcept
  {
    if constexpr(dimension_v<T> == 1)
      return eve::exp(xx);
    else
    {
      using u_t = eve::underlying_type_t<T>;
      auto negative = plf::is_ltz(xx);
      auto nan      = plf::is_nan(xx);
      auto out_of_range = plf::is_greater(plf::abs(xx), plf::maxlog(eve::as<u_t>()));
      xx = plf::if_else(out_of_range, inf, xx);
      auto x = plf::if_else(out_of_range || nan, zero, xx);

      constexpr int  shift = dimension_v<T> == 2 ? -6 : -16;
      constexpr u_t  p     = 1ul << (-shift);
      auto e = plf::euler(eve::as<eve::element_type_t<T>>());
      auto n = plf::hi(nearest(x));
      auto xf = x-n;
      xf = plf::ldexp(xf, shift);
//       std::cout << std::hexfloat << "xf " << xf << std::endl;
//       std::cout << "n  " << n << std::endl;
//       std::cout << "pown(e, n)  " << n   << std::endl;



      auto nn = (xf*(xf*(xf*(xf*(xf*(xf*(xf*(xf*(xf*(xf + 110) + 5940) + 205920) + 5045040) + 90810720) + 1210809600) + 11762150400) + 79394515200) + 335221286400) + 670442572800);
      auto dd = (xf*(xf*(xf*(xf*(xf*(xf*(xf*(xf*(xf*(xf - 110) + 5940) - 205920) + 5045040) - 90810720) + 1210809600) - 11762150400) + 79394515200) - 335221286400) + 670442572800);
      auto nod = if_else(nn == dd, eve::one, nn/dd);
//       std::cout << "n           " << nn   << std::endl;
//       std::cout << "d           " << dd   << std::endl;
//       std::cout << "kn -dd      " << nn-dd   << std::endl;
//       std::cout << "p           " << p   << std::endl;
//       std::cout << "nod         " << nod << std::endl;
//       std::cout << "pown(nod, p)" << pown(nod, p)<< std::endl;
//       std::cout << "pown(nod, p)*pown(e, n) " << pown(e, n)*pown(nod, p) <<  std::endl;
//       auto num = plf::horner(xf, 1.0, 156.0, 12012.0, 600600.0, 21621600.0 ,
//                              588107520.0, 12350257920.0, 201132771840.0, 2514159648000.0,
//                              23465490048000.0, 154872234316800.0,
//                              647647525324800.0, + 1295295050649600.0);
//       auto den = plf::horner(xf, -156.0, 12012.0, -600600.0, 21621600.0 ,
//                              -588107520.0, 12350257920.0, -201132771840.0, 2514159648000.0,
//                              -23465490048000.0, 154872234316800.0,
//                              -647647525324800.0, + 1295295050649600.0);
//       return pown(e, n)* pown((num/den), p);
      auto r = pown(e, n)* pown(nod, p);
      r = if_else(out_of_range, if_else(negative, eve::zero, plf::inf(eve::as<T>())), r);
      r = if_else(nan, xx, r);

      return r;
    }
  }
}
