//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once
#include <iostream>
#include <iomanip>

namespace tts
{
  //================================================================================================
  // helpers to compare to mpfr results
  //================================================================================================

  template<typename T> T to_polyfloat(mpfr::mpreal mpa, eve::as<T>)
  {
    using mu_t = decltype(mpa);
    if constexpr (plf::dimension_v<T> == 1)
    {
      return T(mpa);
    }
    else
    {
      using u_t = decltype(plf::hi(T()));
      auto h = u_t(mpa);
      auto m = u_t(mpa - mu_t(h));
      if constexpr (plf::dimension_v<T> == 2)
      {
        return plf::as_polyfloat_n_t<2, u_t>(h, m);
      }
      else if constexpr (plf::dimension_v<T> == 3)
      {
        auto l = u_t(mpa - (mu_t(h) + mu_t(m)));
        return plf::as_polyfloat_n_t<3, u_t>(h, m, l);
      }
    }
  }

  template<typename T> constexpr auto bitprec()
  {
    using u_t = decltype(plf::hi(T()));
    if constexpr (plf::dimension_v<T> == 1) return (sizeof(u_t) == 8 ? 53 : 24);
    if constexpr (plf::dimension_v<T> == 2) return (sizeof(u_t) == 8 ? 106 : 48);
    else if constexpr (plf::dimension_v<T> == 3) return (sizeof(u_t) == 8 ? 159 : 72);
  }

  template<typename T> auto to_mpreal(T a)
  {
    using mpfr::mpreal;
    mpfr::mpreal::set_default_prec(bitprec<T>() * 10);
    if constexpr (plf::dimension_v<T> == 1) return mpreal(a);
    else if constexpr (plf::dimension_v<T> == 2) return mpreal(plf::hi(a)) + mpreal(plf::lo(a));
    else if constexpr (plf::dimension_v<T> == 3) return mpreal(plf::hi(a)) + mpreal(plf::md(a)) + mpreal(plf::lo(a));
  }

  template<typename T> constexpr auto epsprec()
  {
    using u_t = decltype(plf::hi(T()));
    return std::ldexp(u_t(1), -bitprec<T>());
  }

  template<typename F, typename T, typename... Ts> auto mpfr_exec(F f, T a, Ts... b)
  {
    mpfr::mpreal::set_default_prec(bitprec<T>() * 10);
    return tts::to_polyfloat(f(tts::to_mpreal(a), tts::to_mpreal(b)...), eve::as<T>());
  }

  template<typename F, typename T, typename... Ts> auto lmpfr_exec(F f, T a, Ts... b)
  {
    mpfr::mpreal::set_default_prec(bitprec<T>() * 10);
    return f(tts::to_mpreal(a), tts::to_mpreal(b)...);
  }

  template<typename F, typename T, typename N> auto mpfr_exec2(F f, T a, N n)
  {
    mpfr::mpreal::set_default_prec(bitprec<T>() * 10);
    return tts::to_polyfloat(f(tts::to_mpreal(a), n), eve::as<T>());
  }
}
