#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  std::cout << std::setprecision(15);
  using plf::add;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "add(f, f) " << add(f, f) << std::endl;
  std::cout << "add(a, a) " << add(a, a) << std::endl;
  std::cout << "add(b, b) " << add(b, b) << std::endl;
  std::cout << "add(c, c) " << add(c, c) << std::endl;
  std::cout << "add(a, f) " << add(a, f) << std::endl;
  std::cout << "add(b, a) " << add(b, a) << std::endl;
  std::cout << "add(c, b) " << add(c, b) << std::endl;
  std::cout << "add(f, a) " << add(f, a) << std::endl;
  std::cout << "add(a, b) " << add(a, b) << std::endl;
  std::cout << "add(b, c) " << add(b, c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "add(wb, wb) " << add(wb, wb) << std::endl;
  std::cout << "add(wc, wc) " << add(wc, wc) << std::endl;
  std::cout << "add(wc, wb) " << add(wc, wb) << std::endl;
  std::cout << "add(wc, wb, b) " << add(wb, wb, wb, b, c, 1) << std::endl;

  auto inf = plf::inf(plf::as(a));
  auto bb = plf::add[eve::pedantic](inf, -1);
  std::cout << "bb " << bb << std::endl;
  auto cc = plf::add[eve::pedantic](inf, +1);
  std::cout << "cc " << cc << std::endl;
  std::cout << "inf+1 " << inf + 1 << std::endl;
  std::cout << "inf-1 " << inf - 1 << std::endl;

  return 0;
}
