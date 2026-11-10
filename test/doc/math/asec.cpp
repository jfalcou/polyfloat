//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include <polyfloat/polyfloat.hpp>
#include <iostream>

int main()
{
  // The arc secant is defined for |x| at least 1.
  using plf::asec;
  using d1_t = double;
  using d2_t = plf::double_real_t<double>;
  using d3_t = plf::triple_real_t<double>;
  using f1_t = float;
  using f2_t = plf::double_real_t<float>;
  using f3_t = plf::triple_real_t<float>;

  f1_t xf(1.5f);
  d1_t xd(1.5);

  std::cout << "xf " << xf << std::endl;
  std::cout << "xd " << xd << std::endl;
  std::cout << "asec(d1_t(xd)) = " << asec(d1_t(xd)) << std::endl;
  std::cout << "asec(d2_t(xd)) = " << asec(d2_t(xd)) << std::endl;
  std::cout << "asec(d3_t(xd)) = " << asec(d3_t(xd)) << std::endl;
  std::cout << "asec(f1_t(xf)) = " << asec(f1_t(xf)) << std::endl;
  std::cout << "asec(f2_t(xf)) = " << asec(f2_t(xf)) << std::endl;
  std::cout << "asec(f3_t(xf)) = " << asec(f3_t(xf)) << std::endl;

  using wd2_t = eve::wide<d2_t, 4>;
  wd2_t wxd2([](auto i, auto) { return d1_t(1.5 + i); });
  std::cout << "wxd2 = " << wxd2 << std::endl;
  std::cout << "asec(wxd2) = " << asec(wxd2) << std::endl;
}
