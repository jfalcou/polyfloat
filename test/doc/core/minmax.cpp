#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // Each pair mixes values of the same or of different dimensions.
  using plf::minmax;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::cout << std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "minmax(f, f) = " << minmax(f, f) << std::endl;
  std::cout << "minmax(a, a) = " << minmax(a, a) << std::endl;
  std::cout << "minmax(b, b) = " << minmax(b, b) << std::endl;
  std::cout << "minmax(c, c) = " << minmax(c, c) << std::endl;
  std::cout << "minmax(a, f) = " << minmax(a, f) << std::endl;
  std::cout << "minmax(b, a) = " << minmax(b, a) << std::endl;
  std::cout << "minmax(c, b) = " << minmax(c, b) << std::endl;
  std::cout << "minmax(f, a) = " << minmax(f, a) << std::endl;
  std::cout << "minmax(a, b) = " << minmax(a, b) << std::endl;
  std::cout << "minmax(b, c) = " << minmax(b, c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "minmax(wb, wb) = " << minmax(wb, wb) << std::endl;
  std::cout << "minmax(wc, wc) = " << minmax(wc, wc) << std::endl;
  std::cout << "minmax(wc, wb) = " << minmax(wc, wb) << std::endl;
}
