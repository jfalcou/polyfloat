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
  using plf::cos;
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
  std::cout << "cos(d1_t(xd)) = " << cos(d1_t(xd)) << std::endl;
  std::cout << "cos(d2_t(xd)) = " << cos(d2_t(xd)) << std::endl;
  std::cout << "cos(d3_t(xd)) = " << cos(d3_t(xd)) << std::endl;
  std::cout << "cos(f1_t(xf)) = " << cos(f1_t(xf)) << std::endl;
  std::cout << "cos(f2_t(xf)) = " << cos(f2_t(xf)) << std::endl;
  std::cout << "cos(f3_t(xf)) = " << cos(f3_t(xf)) << std::endl;

  using wd1_t = eve::wide<d1_t, eve::fixed<4>>;
  using wd2_t = eve::wide<d2_t, eve::fixed<4>>;
  using wd3_t = eve::wide<d3_t, eve::fixed<4>>;
  using wf1_t = eve::wide<f1_t, eve::fixed<4>>;
  using wf2_t = eve::wide<f2_t, eve::fixed<4>>;
  using wf3_t = eve::wide<f3_t, eve::fixed<4>>;

  wf1_t wxf([](auto i, auto) { return i / 20.0f; });
  wd1_t wxd([](auto i, auto) { return i / 20.0; });

  std::cout << "wxf " << wxf << std::endl;
  std::cout << "wxd " << wxd << std::endl;
  std::cout << "cos(wxf) = " << cos(wxf) << std::endl;
  std::cout << "cos(wxd) = " << cos(wxd) << std::endl;

  wf2_t wxf2([](auto i, auto) { return f1_t(i / 20.0f); });
  wd2_t wxd2([](auto i, auto) { return d1_t(i / 20.0f); });

  std::cout << "wxf2 = " << wxf2 << std::endl;
  std::cout << "wxd2 = " << wxd2 << std::endl;
  std::cout << "cos(wxf2) = " << cos(wxf2) << std::endl;
  std::cout << "cos(wxd2) = " << cos(wxd2) << std::endl;
  std::cout << "cos(wd3_t(xd)) = " << cos(wd3_t(wxd)) << std::endl;
  std::cout << "cos(wf1_t(xf)) = " << cos(wf1_t(wxf)) << std::endl;
  std::cout << "cos(wf2_t(xf)) = " << cos(wf2_t(wxf)) << std::endl;
  std::cout << "cos(wf3_t(xf)) = " << cos(wf3_t(wxf)) << std::endl;
};
