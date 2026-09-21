#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  std::cout << std::setprecision(15);
  using plf::average;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "average(f, f) " << average(f, f) << std::endl;
  std::cout << "average(a, a) " << average(a, a) << std::endl;
  std::cout << "average(b, b) " << average(b, b) << std::endl;
  std::cout << "average(c, c) " << average(c, c) << std::endl;
  std::cout << "average(a, f) " << average(a, f) << std::endl;
  std::cout << "average(b, a) " << average(b, a) << std::endl;
  std::cout << "average(c, b) " << average(c, b) << std::endl;
  std::cout << "average(f, a) " << average(f, a) << std::endl;
  std::cout << "average(a, b) " << average(a, b) << std::endl;
  std::cout << "average(b, c) " << average(b, c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "average(wb, wb) " << average(wb, wb) << std::endl;
  std::cout << "average(wc, wc) " << average(wc, wc) << std::endl;
  std::cout << "average(wc, wb) " << average(wc, wb) << std::endl;
  std::cout << "average(wc, wb, b) " << average(wb, wb, wb, b, c, 1) << std::endl;

  auto inf = plf::inf(plf::as(a));
  auto bb = plf::average[eve::pedantic](inf, -1);
  std::cout << "bb " << bb << std::endl;
  auto cc = plf::average[eve::pedantic](inf, +1);
  std::cout << "cc " << cc << std::endl;
  return 0;
}
