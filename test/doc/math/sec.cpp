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
  using plf::sec;
  using d1_t = double;
  using d2_t = plf::double_real_t<double>;
  using d3_t = plf::triple_real_t<double>;
  using f1_t = float;
  using f2_t = plf::double_real_t<float>;
  using f3_t = plf::triple_real_t<float>;

  f1_t xf(0.5f);
  d1_t xd(0.5);

  std::cout << "xf " << xf << std::endl;
  std::cout << "xd " << xd << std::endl;
  std::cout << "sec(d1_t(xd)) = " << sec(d1_t(xd)) << std::endl;
  std::cout << "sec(d2_t(xd)) = " << sec(d2_t(xd)) << std::endl;
  std::cout << "sec(d3_t(xd)) = " << sec(d3_t(xd)) << std::endl;
  std::cout << "sec(f1_t(xf)) = " << sec(f1_t(xf)) << std::endl;
  std::cout << "sec(f2_t(xf)) = " << sec(f2_t(xf)) << std::endl;
  std::cout << "sec(f3_t(xf)) = " << sec(f3_t(xf)) << std::endl;

  using wd1_t = eve::wide<d1_t, 4>;
  using wd2_t = eve::wide<d2_t, 4>;
  using wd3_t = eve::wide<d3_t, 4>;
  using wf1_t = eve::wide<f1_t, 4>;
  using wf2_t = eve::wide<f2_t, 4>;
  using wf3_t = eve::wide<f3_t, 4>;

  wf1_t wxf([](auto i, auto) { return i / 20.0f; });
  wd1_t wxd([](auto i, auto) { return i / 20.0; });

  std::cout << "wxf " << wxf << std::endl;
  std::cout << "wxd " << wxd << std::endl;
  std::cout << "sec(wxf) = " << sec(wxf) << std::endl;
  std::cout << "sec(wxd) = " << sec(wxd) << std::endl;

  wf2_t wxf2([](auto i, auto) { return f1_t(i / 20.0f); });
  wd2_t wxd2([](auto i, auto) { return d1_t(i / 20.0f); });

  std::cout << "wxf2 = " << wxf2 << std::endl;
  std::cout << "wxd2 = " << wxd2 << std::endl;
  std::cout << "sec(wxf2) = " << sec(wxf2) << std::endl;
  std::cout << "sec(wxd2) = " << sec(wxd2) << std::endl;
  std::cout << "sec(wd3_t(xd)) = " << sec(wd3_t(wxd)) << std::endl;
  std::cout << "sec(wf1_t(xf)) = " << sec(wf1_t(wxf)) << std::endl;
  std::cout << "sec(wf2_t(xf)) = " << sec(wf2_t(wxf)) << std::endl;
  std::cout << "sec(wf3_t(xf)) = " << sec(wf3_t(wxf)) << std::endl;

  using pl2_t = plf::polyfloat<double, 2>;
  auto x = plf::pio_3(eve::as<pl2_t>());
  auto hx = plf::hi(x);
  std::cout << std::hexfloat;
  std::cout << "x " << x << std::endl;
  std::cout << "eve::sec[eve::medium](x) = " << eve::sec[eve::medium](hx) << std::endl;
  std::cout << "plf::sec[eve::medium](x) = " << plf::sec[eve::medium](x) << std::endl;
  std::cout << "eve::sec[eve::medium](-x) = " << eve::sec[eve::medium](-hx) << std::endl;
  std::cout << "plf::sec[eve::medium](-x) = " << plf::sec[eve::medium](-x) << std::endl;
  x += plf::pio_3(eve::as<pl2_t>());
  hx = plf::hi(x);
  std::cout << std::endl << "x " << x << std::endl;

  std::cout << "eve::sec[eve::medium](x) = " << eve::sec[eve::medium](hx) << std::endl;
  std::cout << "plf::sec[eve::medium](x) = " << plf::sec[eve::medium](x) << std::endl;
  std::cout << "eve::sec[eve::medium](-x) = " << eve::sec[eve::medium](-hx) << std::endl;
  std::cout << "plf::sec[eve::medium](-x) = " << plf::sec[eve::medium](-x) << std::endl;
  x += plf::pio_3(eve::as<pl2_t>());
  hx = plf::hi(x);
  std::cout << std::endl << "x " << x << std::endl;

  std::cout << "eve::sec[eve::medium](x) = " << eve::sec[eve::medium](hx) << std::endl;
  std::cout << "plf::sec[eve::medium](x) = " << plf::sec[eve::medium](x) << std::endl;
  std::cout << "eve::sec[eve::medium](-x) = " << eve::sec[eve::medium](-hx) << std::endl;
  std::cout << "plf::sec[eve::medium](-x) = " << plf::sec[eve::medium](-x) << std::endl;
  x += plf::pio_3(eve::as<pl2_t>());
  hx = plf::hi(x);
  std::cout << std::endl << "x " << x << std::endl;

  std::cout << "eve::sec[eve::medium](x) = " << eve::sec[eve::medium](hx) << std::endl;
  std::cout << "plf::sec[eve::medium](x) = " << plf::sec[eve::medium](x) << std::endl;
  std::cout << "eve::sec[eve::medium](-x) = " << eve::sec[eve::medium](-hx) << std::endl;
  std::cout << "plf::sec[eve::medium](-x) = " << plf::sec[eve::medium](-x) << std::endl;
};
