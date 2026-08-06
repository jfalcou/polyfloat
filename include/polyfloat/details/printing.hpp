//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once
#include <polyfloat/details/abi.hpp>
#include <eve/traits/overload.hpp>
#include <mpreal.h>
#include <string>

namespace plf::_
{
  ////////////////////////////////////////////////////////////////////////////////
  // printing on decimal form form
  ////////////////////////////////////////////////////////////////////////////////

  template < typename T > T to_polyfloat(mpfr::mpreal mpa, eve::as<T> )
  {
    using u_t = decltype(plf::hi(T()));
    using mu_t = decltype(mpa);
   if constexpr(plf::dimension_v<T> == 1)
    {
      auto h = u_t(mpa);
      return h;
    }
    else     if constexpr(plf::dimension_v<T> == 2)
    {
      auto h = u_t(mpa);
      auto l = u_t(mpa-mu_t(h));
      return plf::as_polyfloat_n_t<2, u_t>(h, l);
    }
    else if constexpr(plf::dimension_v<T> == 3)
    {
      auto h = u_t(mpa);
      auto m = u_t(mpa-mu_t(h));
//       auto [z1, e1] =  eve::two_add(h, m);
//       auto l = u_t(mpa - mpfr::mpreal((mu_t(z1)+mu_t(e1))));
      auto l = u_t(mpa - mpfr::mpreal(mu_t(h)+mu_t(m)));
      return plf::as_polyfloat_n_t<3, u_t>(h, m, l);
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

  template <typename T> auto from_string(std::string const & s, eve::as<T> target)
  {
    using  mpfr::mpreal;
    mpfr::mpreal::set_default_prec(bitprec<T>()*10);
    auto a = mpreal(s);
    return to_polyfloat(a, target);
  }

  template <typename T> auto to_mpreal(T a)
  {
    using  mpfr::mpreal;
    mpfr::mpreal::set_default_prec(bitprec<T>()*10);
    if constexpr(plf::dimension_v<T>  == 1)
      return mpreal(a);
    else if constexpr(plf::dimension_v<T>  == 2)
      return mpreal(plf::hi(a))+mpreal(plf::lo(a));
    else if constexpr(plf::dimension_v<T>  == 3)
      return mpreal(plf::hi(a))+mpreal(plf::md(a))+mpreal(plf::lo(a));
  }


  template <typename T> void print(std::string s, T a)
  {
    auto prec = 2*int(std::log10(std::exp2(bitprec<T>())))+1;
    auto oldprec = std::cout.precision();
    std::cout << s;
    std::cout << std::setprecision(prec) << to_mpreal(a) << std::setprecision(oldprec);
  }

  template <typename T> void println(std::string s, T a)
  {
    auto prec = 2*int(std::log10(std::exp2(bitprec<T>())))+1;
    auto oldprec = std::cout.precision();
    std::cout << s;
    std::cout << std::setprecision(prec) << to_mpreal(a) << std::setprecision(oldprec) << std::endl;
  }
}
