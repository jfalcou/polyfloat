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
  using plf::pow_abs;
  using d1_t = double;
  using d2_t = plf::double_real_t<double>;
  using d3_t = plf::triple_real_t<double>;
  using f1_t = float;
  using f2_t = plf::double_real_t<float>;
  using f3_t = plf::triple_real_t<float>;

  f1_t xf(1.5f), yf(2.5);
  d1_t xd(1.5), yd(2.5);

  std::cout << "xf " << xf << std::endl;
  std::cout << "xd " << xd << std::endl;
  std::cout << "yf " << yf << std::endl;
  std::cout << "yd " << yd << std::endl;
  std::cout << "pow_abs(d1_t(xd), d1_t(yd)) = " << pow_abs(d1_t(xd), d1_t(yd)) << std::endl;
  std::cout << "pow_abs(d2_t(xd), d2_t(yd)) = " << pow_abs(d2_t(xd), d2_t(yd)) << std::endl;
  std::cout << "pow_abs(d3_t(xd), d3_t(yd)) = " << pow_abs(d3_t(xd), d3_t(yd)) << std::endl;
  std::cout << "pow_abs(f1_t(xf), f1_t(yf)) = " << pow_abs(f1_t(xf), f1_t(yf)) << std::endl;
  std::cout << "pow_abs(f2_t(xf), f2_t(yf)) = " << pow_abs(f2_t(xf), f2_t(yf)) << std::endl;
  std::cout << "pow_abs(f3_t(xf), f3_t(yf)) = " << pow_abs(f3_t(xf), f3_t(yf)) << std::endl;

  using wd1_t = eve::wide<d1_t, eve::fixed<4>>;
  using wd2_t = eve::wide<d2_t, eve::fixed<4>>;
  using wf1_t = eve::wide<f1_t, eve::fixed<4>>;
  using wf2_t = eve::wide<f2_t, eve::fixed<4>>;

  wf1_t wxf([](auto i, auto) { return 0.51f + i; });
  wf1_t wyf([](auto i, auto) { return 2.0f + i; });
  wd1_t wxd([](auto i, auto) { return 0.51 + i; });
  wd1_t wyd([](auto i, auto) { return 2.0 + i; });

  std::cout << "wxf " << wxf << std::endl;
  std::cout << "wxd " << wxd << std::endl;
  std::cout << "wyf " << wyf << std::endl;
  std::cout << "wyd " << wyd << std::endl;
  std::cout << "pow_abs(wxf, wyf) = " << pow_abs(wxf, wyf) << std::endl;
  std::cout << "pow_abs(wxd, wyd) = " << pow_abs(wxd, wyd) << std::endl;

  wf2_t wxf2([](auto i, auto) { return f1_t(0.51f + i); });
  wf2_t wyf2([](auto i, auto) { return f1_t(2.0f + i); });
  wd2_t wxd2([](auto i, auto) { return d1_t(0.51 + i); });
  wd2_t wyd2([](auto i, auto) { return d1_t(2.0 + i); });
  std::cout << "wxf2 = " << wxf2 << std::endl;
  std::cout << "wyf2 = " << wyf2 << std::endl;
  std::cout << "wxd2 = " << wxd2 << std::endl;
  std::cout << "wyd2 = " << wyd2 << std::endl;
  std::cout << "pow_abs(wxf2, wyf2 ) = " << pow_abs(wxf2, wyf2) << std::endl;
  std::cout << "pow_abs(wxd2, wyd2 ) = " << pow_abs(wxd2, wyd2) << std::endl;

  using wd3_t = eve::wide<d3_t, eve::fixed<4>>;
  using wf3_t = eve::wide<f3_t, eve::fixed<4>>;
  wf3_t wxf3([](auto i, auto) { return f1_t(0.51f + i); });
  wf3_t wyf3([](auto i, auto) { return f1_t(2.0f + i); });
  wd3_t wxd3([](auto i, auto) { return d1_t(0.51 + i); });
  wd3_t wyd3([](auto i, auto) { return d1_t(2.0 + i); });

  std::cout << "wxf3 = " << wxf3 << std::endl;
  std::cout << "wyf3 = " << wyf3 << std::endl;
  std::cout << "wxd3 = " << wxd3 << std::endl;
  std::cout << "wyd3 = " << wyd3 << std::endl;
  std::cout << "pow_abs(wxf3, wyf3 ) = " << pow_abs(wxf3, wyf3) << std::endl;
  std::cout << "pow_abs(wxd3, wyd3 ) = " << pow_abs(wxd3, wyd3) << std::endl;
};
