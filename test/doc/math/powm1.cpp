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
  using plf::powm1;
  using d1_t = double;
  using d2_t = plf::double_real_t<double>;
  using d3_t = plf::triple_real_t<double>;
  using f1_t = float;
  using f2_t = plf::double_real_t<float>;
  using f3_t = plf::triple_real_t<float>;

  f1_t xf(1.5f);
  d1_t xd(1.5);
  f1_t yf(0.5f);
  d1_t yd(0.5);

  std::cout << "yf " << yf << std::endl;
  std::cout << "yd " << yd << std::endl;
  std::cout << "xf " << xf << std::endl;
  std::cout << "xd " << xd << std::endl;
  std::cout << "powm1(d1_t(yd), d1_t(xd)) = " << powm1(d1_t(yd), d1_t(xd)) << std::endl;
  std::cout << "powm1(d2_t(yd), d2_t(xd)) = " << powm1(d2_t(yd), d2_t(xd)) << std::endl;
  std::cout << "powm1(d3_t(yd), d3_t(xd)) = " << powm1(d3_t(yd), d3_t(xd)) << std::endl;
  std::cout << "powm1(f1_t(yf), f1_t(xf)) = " << powm1(f1_t(yf), f1_t(xf)) << std::endl;
  std::cout << "powm1(f2_t(yf), f2_t(xf)) = " << powm1(f2_t(yf), f2_t(xf)) << std::endl;
  std::cout << "powm1(f3_t(yf), f3_t(xf)) = " << powm1(f3_t(yf), f3_t(xf)) << std::endl;

  using wd1_t = eve::wide<d1_t, 4>;
  using wd2_t = eve::wide<d2_t, 4>;
  using wd3_t = eve::wide<d3_t, 4>;
  using wf1_t = eve::wide<f1_t, 4>;
  using wf2_t = eve::wide<f2_t, 4>;
  using wf3_t = eve::wide<f3_t, 4>;

  wf1_t wyf([](auto i, auto) { return -0.5f + i; });
  wd1_t wyd([](auto i, auto) { return -0.5 + i; });
  wf1_t wxf([](auto i, auto) { return 0.5f - i; });
  wd1_t wxd([](auto i, auto) { return 0.5 - i; });

  std::cout << "wyf " << wyf << std::endl;
  std::cout << "wyd " << wyd << std::endl;
  std::cout << "wxf " << wxf << std::endl;
  std::cout << "wxd " << wxd << std::endl;
  std::cout << "powm1(wyf, wxf) = " << powm1(wyf, wxf) << std::endl;
  std::cout << "powm1(wyd, wxd) = " << powm1(wyd, wxd) << std::endl;

  wf2_t wyf2([](auto i, auto) { return f1_t(0.5f - i); });
  wd2_t wyd2([](auto i, auto) { return d1_t(0.5 - i); });
  wf2_t wxf2([](auto i, auto) { return f1_t(-0.5f + i); });
  wd2_t wxd2([](auto i, auto) { return d1_t(-0.5 + i); });

  std::cout << "wxf2 = " << wxf2 << std::endl;
  std::cout << "wxd2 = " << wxd2 << std::endl;
  std::cout << "powm1(wyf2, wxf2) = " << powm1(wyf2, wxf2) << std::endl;
  std::cout << "powm1(wyd2, wxd2) = " << powm1(wyd2, wxd2) << std::endl;
  std::cout << "powm1(wd3_t(yd), wd3_t(xd)) = " << powm1(wd3_t(yd), wd3_t(wxd)) << std::endl;
  std::cout << "powm1(wf1_t(yf), wf1_t(xf)) = " << powm1(wf1_t(yf), wf1_t(wxf)) << std::endl;
  std::cout << "powm1(wf2_t(yf), wf2_t(xf)) = " << powm1(wf2_t(yf), wf2_t(wxf)) << std::endl;
  std::cout << "powm1(wf3_t(yf), wf3_t(xf)) = " << powm1(wf3_t(yf), wf3_t(wxf)) << std::endl;
};
