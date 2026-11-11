#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // Each pair mixes values of the same or of different dimensions.
  using plf::negabsmax;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::cout << std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "negabsmax(f, f) = " << negabsmax(f, f) << std::endl;
  std::cout << "negabsmax(a, a) = " << negabsmax(a, a) << std::endl;
  std::cout << "negabsmax(b, b) = " << negabsmax(b, b) << std::endl;
  std::cout << "negabsmax(c, c) = " << negabsmax(c, c) << std::endl;
  std::cout << "negabsmax(a, f) = " << negabsmax(a, f) << std::endl;
  std::cout << "negabsmax(b, a) = " << negabsmax(b, a) << std::endl;
  std::cout << "negabsmax(c, b) = " << negabsmax(c, b) << std::endl;
  std::cout << "negabsmax(f, a) = " << negabsmax(f, a) << std::endl;
  std::cout << "negabsmax(a, b) = " << negabsmax(a, b) << std::endl;
  std::cout << "negabsmax(b, c) = " << negabsmax(b, c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "negabsmax(wb, wb) = " << negabsmax(wb, wb) << std::endl;
  std::cout << "negabsmax(wc, wc) = " << negabsmax(wc, wc) << std::endl;
  std::cout << "negabsmax(wc, wb) = " << negabsmax(wc, wb) << std::endl;
}
