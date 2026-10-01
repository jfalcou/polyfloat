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
  using plf::kolmmean;
  using d1_t = double;
  using d2_t = plf::double_real_t<double>;
  using d3_t = plf::triple_real_t<double>;
  using f1_t = float;
  using f2_t = plf::double_real_t<float>;
  using f3_t = plf::triple_real_t<float>;

  auto f = plf::abs;
  auto g = plf::abs;
  f1_t xf(1.5f), yf(2.5), zf(3.5);
  d1_t xd(1.5), yd(2.5), zd(3.5);

  std::cout << "xf " << xf << std::endl;
  std::cout << "xd " << xd << std::endl;
  std::cout << "kolmmean(f, g, d1_t(xd), d1_t(yd), (d1_t(zd)) = " << kolmmean(f, g, d1_t(xd), d1_t(yd), d1_t(zd))
            << std::endl;
  std::cout << "kolmmean(f, g, d2_t(xd), d2_t(yd), (d2_t(zd)) = " << kolmmean(f, g, d2_t(xd), d2_t(yd), d2_t(zd))
            << std::endl;
  std::cout << "kolmmean(f, g, d3_t(xd), d3_t(yd), (d3_t(zd)) = " << kolmmean(f, g, d3_t(xd), d3_t(yd), d3_t(zd))
            << std::endl;
  std::cout << "kolmmean(f, g, f1_t(xf), f1_t(yf), (f1_t(zf)) = " << kolmmean(f, g, f1_t(xf), f1_t(yf), f1_t(zf))
            << std::endl;
  std::cout << "kolmmean(f, g, f2_t(xf), f2_t(yf), (f2_t(zf)) = " << kolmmean(f, g, f2_t(xf), f2_t(yf), f2_t(zf))
            << std::endl;
  std::cout << "kolmmean(f, g, f3_t(xf), f3_t(yf), (f3_t(zf)) = " << kolmmean(f, g, f3_t(xf), f3_t(yf), f3_t(zf))
            << std::endl;

  using wd1_t = eve::wide<d1_t, eve::fixed<4>>;
  using wd2_t = eve::wide<d2_t, eve::fixed<4>>;
  using wf1_t = eve::wide<f1_t, eve::fixed<4>>;
  using wf2_t = eve::wide<f2_t, eve::fixed<4>>;

  wf1_t wxf([](auto i, auto) { return -0.5f + i; });
  wf1_t wyf([](auto i, auto) { return -2.0f + i; });
  wd1_t wxd([](auto i, auto) { return -0.5 + i; });
  wd1_t wyd([](auto i, auto) { return -2.0 + i; });

  std::cout << "wxf " << wxf << std::endl;
  std::cout << "wxd " << wxd << std::endl;
  std::cout << "kolmmean(f, g, wxf, wyf) = " << kolmmean(f, g, wxf, wyf) << std::endl;
  std::cout << "kolmmean(f, g, wxd, wyd) = " << kolmmean(f, g, wxd, wyd) << std::endl;

  wf2_t wxf2([](auto i, auto) { return f1_t(-0.5f + i); });
  wf1_t wyf2([](auto i, auto) { return f1_t(-2.0f + i); });
  wd2_t wxd2([](auto i, auto) { return d1_t(-0.5 + i); });
  wd2_t wyd2([](auto i, auto) { return d1_t(-2.0f + i); });
  std::cout << "wxf2 = " << wxf2 << std::endl;
  std::cout << "wyf2 = " << wyf2 << std::endl;
  std::cout << "wxd2 = " << wxd2 << std::endl;
  std::cout << "wyd2 = " << wyd2 << std::endl;
  std::cout << "kolmmean(f, g, wxf2, wyf2 ) = " << kolmmean(f, g, wxf2, wyf2) << std::endl;
  std::cout << "kolmmean(f, g, wxd2, wyd2 ) = " << kolmmean(f, g, wxd2, wyd2) << std::endl;

  using wd3_t = eve::wide<d3_t, eve::fixed<4>>;
  using wf3_t = eve::wide<f3_t, eve::fixed<4>>;
  wf3_t wxf3([](auto i, auto) { return f1_t(-0.5f + i); });
  wf3_t wyf3([](auto i, auto) { return f1_t(-2.0f + i); });
  wd3_t wxd3([](auto i, auto) { return d1_t(-0.5 + i); });
  wd3_t wyd3([](auto i, auto) { return d1_t(-2.0 + i); });

  std::cout << "wxf3 = " << wxf3 << std::endl;
  std::cout << "wyf3 = " << wyf3 << std::endl;
  std::cout << "wxd3 = " << wxd3 << std::endl;
  std::cout << "wyd3 = " << wyd3 << std::endl;
  std::cout << "kolmmean(f, g, wxf3, wyf3 ) = " << kolmmean(f, g, wxf3, wyf3) << std::endl;
  std::cout << "kolmmean(f, g, wxd3, wyd3 ) = " << kolmmean(f, g, wxd3, wyd3) << std::endl;
};
