#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // Each pair mixes values of the same or of different dimensions.
  using plf::maxmag;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::cout << std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "maxmag(f, f) = " << maxmag(f, f) << std::endl;
  std::cout << "maxmag(a, a) = " << maxmag(a, a) << std::endl;
  std::cout << "maxmag(b, b) = " << maxmag(b, b) << std::endl;
  std::cout << "maxmag(c, c) = " << maxmag(c, c) << std::endl;
  std::cout << "maxmag(a, f) = " << maxmag(a, f) << std::endl;
  std::cout << "maxmag(b, a) = " << maxmag(b, a) << std::endl;
  std::cout << "maxmag(c, b) = " << maxmag(c, b) << std::endl;
  std::cout << "maxmag(f, a) = " << maxmag(f, a) << std::endl;
  std::cout << "maxmag(a, b) = " << maxmag(a, b) << std::endl;
  std::cout << "maxmag(b, c) = " << maxmag(b, c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "maxmag(wb, wb) = " << maxmag(wb, wb) << std::endl;
  std::cout << "maxmag(wc, wc) = " << maxmag(wc, wc) << std::endl;
  std::cout << "maxmag(wc, wb) = " << maxmag(wc, wb) << std::endl;
}
