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
  using plf::acoth;
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
  std::cout << "acoth(d1_t(xd)) = " << acoth(d1_t(xd)) << std::endl;
  std::cout << "acoth(d2_t(xd)) = " << acoth(d2_t(xd)) << std::endl;
  std::cout << "acoth(d3_t(xd)) = " << acoth(d3_t(xd)) << std::endl;
  std::cout << "acoth(f1_t(xf)) = " << acoth(f1_t(xf)) << std::endl;
  std::cout << "acoth(f2_t(xf)) = " << acoth(f2_t(xf)) << std::endl;
  std::cout << "acoth(f3_t(xf)) = " << acoth(f3_t(xf)) << std::endl;

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
  std::cout << "acoth(wxf) = " << acoth(wxf) << std::endl;
  std::cout << "acoth(wxd) = " << acoth(wxd) << std::endl;

  wf2_t wxf2([](auto i, auto) { return f1_t(-0.5f + i); });
  wd2_t wxd2([](auto i, auto) { return d1_t(-0.5 + i); });

  std::cout << "wxf2 = " << wxf2 << std::endl;
  std::cout << "wxd2 = " << wxd2 << std::endl;
  std::cout << "acoth(wxf2) = " << acoth(wxf2) << std::endl;
  std::cout << "acoth(wxd2) = " << acoth(wxd2) << std::endl;
  std::cout << "acoth(wd3_t(xd)) = " << acoth(wd3_t(wxd)) << std::endl;
  std::cout << "acoth(wf1_t(xf)) = " << acoth(wf1_t(wxf)) << std::endl;
  std::cout << "acoth(wf2_t(xf)) = " << acoth(wf2_t(wxf)) << std::endl;
  std::cout << "acoth(wf3_t(xf)) = " << acoth(wf3_t(wxf)) << std::endl;
};
