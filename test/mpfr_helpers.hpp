//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

namespace tts
{
  //================================================================================================
  // helpers to compare to mpfr results
  //================================================================================================

  template <typename T> auto to_mpreal(T a)
  {
    using  mpfr::mpreal;
    if constexpr(plf::dimension_v<T>  == 1)
      return mpreal(a);
    else if constexpr(plf::dimension_v<T>  == 2)
      return mpreal(plf::hi(a))+mpreal(plf::lo(a));
    else if constexpr(plf::dimension_v<T>  == 3)
      return mpreal(plf::hi(a))+mpreal(plf::md(a))+mpreal(plf::lo(a));
  }

  template <typename T> constexpr auto bitprec(){
    using u_t = decltype(plf::hi(T()));
    if constexpr(plf::dimension_v<T> == 2)
      return (sizeof(u_t) == 8 ? 106 : 46);
    else if constexpr(plf::dimension_v<T> == 3)
      return (sizeof(u_t) == 8 ? 159 : 69);
  }


  template <typename T> constexpr auto epsprec(){
    using u_t = decltype(plf::hi(T()));
    if constexpr(plf::dimension_v<T> == 2)
      return (sizeof(u_t) == 8 ? 1.2326e-32 : 1.4211e-14);
    else if constexpr(plf::dimension_v<T> == 3)
      return (sizeof(u_t) == 8 ? 1.3685e-48 : 1.6941e-21);
  }



}
