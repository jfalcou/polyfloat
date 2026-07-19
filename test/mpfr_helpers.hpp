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

  template < typename T > T to_polyfloat(mpfr::mpreal mpa, eve::as<T> )
  {
    using u_t = decltype(plf::hi(T()));
    using mu_t = decltype(mpa);
    auto h = u_t(mpa);
    auto m = u_t(mpa-mu_t(h));
    if constexpr(plf::dimension_v<T> == 1)
    {
      return h;
    }
    else     if constexpr(plf::dimension_v<T> == 2)
    {
      return T(h, m);
    }
    else if constexpr(plf::dimension_v<T> == 3)
    {
      auto l = u_t(mpa - (mu_t(h)+mu_t(m)));
      return T(h, m, l);
    }
  }

  template <typename T> constexpr auto bitprec(){
    using u_t = decltype(plf::hi(T()));
    if constexpr(plf::dimension_v<T> == 1)
      return (sizeof(u_t) == 8 ? 53 : 23);
    if constexpr(plf::dimension_v<T> == 2)
      return (sizeof(u_t) == 8 ? 106 : 46);
    else if constexpr(plf::dimension_v<T> == 3)
      return (sizeof(u_t) == 8 ? 159 : 69);
  }

  template <typename T> auto to_mpreal(T a)
  {
    using  mpfr::mpreal;
    mpfr::mpreal::set_default_prec(bitprec<T>());
    if constexpr(plf::dimension_v<T>  == 1)
      return mpreal(a);
    else if constexpr(plf::dimension_v<T>  == 2)
      return mpreal(plf::hi(a))+mpreal(plf::lo(a));
    else if constexpr(plf::dimension_v<T>  == 3)
      return mpreal(plf::hi(a))+mpreal(plf::md(a))+mpreal(plf::lo(a));
  }



  template <typename T> constexpr auto epsprec(){
    using u_t = decltype(plf::hi(T()));
    if constexpr(plf::dimension_v<T> == 1)
      return  (sizeof(u_t) == 4 ? 2.384185791015625e-07 :  2.220446049250313e-16);
    else if constexpr(plf::dimension_v<T> == 2)
      return (sizeof(u_t) == 4 ? 2.842170943040401e-14 :  3.388131789017201e-21);
    else if constexpr(plf::dimension_v<T> == 3)
      return (sizeof(u_t) == 4 ? 2.465190328815662e-32 :  2.736911063134408e-48); ;
  }

  template < typename F, typename T,  typename ...Ts> auto mpfr_exec(F f, T a,  Ts ...b)
  {
    return tts::to_polyfloat(f(tts::to_mpreal(a), tts::to_mpreal(b)...), eve::as<T>());
  }

  template < typename F, typename T,  typename ...Ts> auto lmpfr_exec(F f, T a,  Ts ...b)
  {
    return f(tts::to_mpreal(a), tts::to_mpreal(b)...);
  }

  template < typename F, typename T,  typename N> auto mpfr_exec2(F f, T a,  N n)
  {
    return tts::to_polyfloat(f(tts::to_mpreal(a), n), eve::as<T>());
  }

}
