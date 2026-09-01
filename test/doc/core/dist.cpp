#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  std::cout << std::setprecision(15);
  using plf::dist;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "dist(f, f) " << dist(f, f) << std::endl;
  std::cout << "dist(a, a) " << dist(a, a) << std::endl;
  std::cout << "dist(b, b) " << dist(b, b) << std::endl;
  std::cout << "dist(c, c) " << dist(c, c) << std::endl;
  std::cout << "dist(a, f) " << dist(a, f) << std::endl;
  std::cout << "dist(b, a) " << dist(b, a) << std::endl;
  std::cout << "dist(c, b) " << dist(c, b) << std::endl;
  std::cout << "dist(f, a) " << dist(f, a) << std::endl;
  std::cout << "dist(a, b) " << dist(a, b) << std::endl;
  std::cout << "dist(b, c) " << dist(b, c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "dist(wb, wb) " << dist(wb, wb) << std::endl;
  std::cout << "dist(wc, wc) " << dist(wc, wc) << std::endl;
  std::cout << "dist(wc, wb) " << dist(wc, wb) << std::endl;

  return 0;
}
