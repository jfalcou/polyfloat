#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // Each pair mixes values of the same or of different dimensions.
  using plf::minmag;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::cout << std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "minmag(f, f) = " << minmag(f, f) << std::endl;
  std::cout << "minmag(a, a) = " << minmag(a, a) << std::endl;
  std::cout << "minmag(b, b) = " << minmag(b, b) << std::endl;
  std::cout << "minmag(c, c) = " << minmag(c, c) << std::endl;
  std::cout << "minmag(a, f) = " << minmag(a, f) << std::endl;
  std::cout << "minmag(b, a) = " << minmag(b, a) << std::endl;
  std::cout << "minmag(c, b) = " << minmag(c, b) << std::endl;
  std::cout << "minmag(f, a) = " << minmag(f, a) << std::endl;
  std::cout << "minmag(a, b) = " << minmag(a, b) << std::endl;
  std::cout << "minmag(b, c) = " << minmag(b, c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "minmag(wb, wb) = " << minmag(wb, wb) << std::endl;
  std::cout << "minmag(wc, wc) = " << minmag(wc, wc) << std::endl;
  std::cout << "minmag(wc, wb) = " << minmag(wc, wb) << std::endl;
}
