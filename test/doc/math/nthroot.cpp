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
  using plf::nthroot;
  using d1_t = double;
  using d2_t = plf::double_real_t<double>;
  using d3_t = plf::triple_real_t<double>;
  using f1_t = float;
  using f2_t = plf::double_real_t<float>;
  using f3_t = plf::triple_real_t<float>;

  f1_t xf(81.0f);
  d1_t xd(81.0);

  std::cout << "xf " << xf << std::endl;
  std::cout << "xd " << xd << std::endl;
  std::cout << "nthroot(d1_t(xd), 4) = " << nthroot(d1_t(xd), 4) << std::endl;
  std::cout << "nthroot(d2_t(xd), 4) = " << nthroot(d2_t(xd), 4) << std::endl;
  std::cout << "nthroot(d3_t(xd), 4) = " << nthroot(d3_t(xd), 4) << std::endl;
  std::cout << "nthroot(f1_t(xf), 4) = " << nthroot(f1_t(xf), 4) << std::endl;
  std::cout << "nthroot(f2_t(xf), 4) = " << nthroot(f2_t(xf), 4) << std::endl;
  std::cout << "nthroot(f3_t(xf), 4) = " << nthroot(f3_t(xf), 4) << std::endl;

  using wd1_t = eve::wide<d1_t, eve::fixed<4>>;
  using wd2_t = eve::wide<d2_t, eve::fixed<4>>;
  using wf1_t = eve::wide<f1_t, eve::fixed<4>>;
  using wf2_t = eve::wide<f2_t, eve::fixed<4>>;

  wf1_t wxf([](auto i, auto) { return 0.5f + i; });
  wd1_t wxd([](auto i, auto) { return 0.5 + i; });

  std::cout << "wxf " << wxf << std::endl;
  std::cout << "wxd " << wxd << std::endl;
  std::cout << "nthroot(wxf, 4) = " << nthroot(wxf, 4) << std::endl;
  std::cout << "nthroot(wxd, 4) = " << nthroot(wxd, 4) << std::endl;

  wf2_t wxf2([](auto i, auto) { return f1_t(0.5f + i); });
  wd2_t wxd2([](auto i, auto) { return d1_t(0.5 + i); });
  std::cout << "wxf2 = " << wxf2 << std::endl;
  std::cout << "wxd2 = " << wxd2 << std::endl;
  std::cout << "nthroot(wxf2, 4 ) = " << nthroot(wxf2, 4) << std::endl;
  std::cout << "nthroot(wxd2, 4 ) = " << nthroot(wxd2, 4) << std::endl;

  using wd3_t = eve::wide<d3_t, eve::fixed<4>>;
  using wf3_t = eve::wide<f3_t, eve::fixed<4>>;
  wf3_t wxf3([](auto i, auto) { return f1_t(0.5f + i); });
  wd3_t wxd3([](auto i, auto) { return d1_t(0.5 + i); });

  std::cout << "wxf3 = " << wxf3 << std::endl;
  std::cout << "wxd3 = " << wxd3 << std::endl;
  std::cout << "nthroot(wxf3, 4 ) = " << nthroot(wxf3, 4) << std::endl;
  std::cout << "nthroot(wxd3, 4 ) = " << nthroot(wxd3, 4) << std::endl;
};
