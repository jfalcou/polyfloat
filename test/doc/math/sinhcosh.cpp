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
  using plf::sinhcosh;
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
  std::cout << "sinhcosh(d1_t(xd)) = " << sinhcosh(d1_t(xd)) << std::endl;
  std::cout << "sinhcosh(d2_t(xd)) = " << sinhcosh(d2_t(xd)) << std::endl;
  std::cout << "sinhcosh(d3_t(xd)) = " << sinhcosh(d3_t(xd)) << std::endl;
  std::cout << "sinhcosh(f1_t(xf)) = " << sinhcosh(f1_t(xf)) << std::endl;
  std::cout << "sinhcosh(f2_t(xf)) = " << sinhcosh(f2_t(xf)) << std::endl;
  std::cout << "sinhcosh(f3_t(xf)) = " << sinhcosh(f3_t(xf)) << std::endl;

  using wd1_t = eve::wide<d1_t, eve::fixed<4>>;
  using wd2_t = eve::wide<d2_t, eve::fixed<4>>;
  using wd3_t = eve::wide<d3_t, eve::fixed<4>>;
  using wf1_t = eve::wide<f1_t, eve::fixed<4>>;
  using wf2_t = eve::wide<f2_t, eve::fixed<4>>;
  using wf3_t = eve::wide<f3_t, eve::fixed<4>>;

  wf1_t wxf([](auto i, auto) { return -0.5f + i; });
  wd1_t wxd([](auto i, auto) { return -0.5 + i; });

  std::cout << "wxf " << wxf << std::endl;
  std::cout << "wxd " << wxd << std::endl;
  std::cout << "sinhcosh(wxf) = " << sinhcosh(wxf) << std::endl;
  std::cout << "sinhcosh(wxd) = " << sinhcosh(wxd) << std::endl;

  wf2_t wxf2([](auto i, auto) { return f1_t(-0.5f + i); });
  wd2_t wxd2([](auto i, auto) { return d1_t(-0.5 + i); });

  std::cout << "wxf2 = " << wxf2 << std::endl;
  std::cout << "wxd2 = " << wxd2 << std::endl;
  std::cout << "sinhcosh(wxf2) = " << sinhcosh(wxf2) << std::endl;
  std::cout << "sinhcosh(wxd2) = " << sinhcosh(wxd2) << std::endl;
  std::cout << "sinhcosh(wd3_t(xd)) = " << sinhcosh(wd3_t(wxd)) << std::endl;
  std::cout << "sinhcosh(wf1_t(xf)) = " << sinhcosh(wf1_t(wxf)) << std::endl;
  std::cout << "sinhcosh(wf2_t(xf)) = " << sinhcosh(wf2_t(wxf)) << std::endl;
  std::cout << "sinhcosh(wf3_t(xf)) = " << sinhcosh(wf3_t(wxf)) << std::endl;
};
