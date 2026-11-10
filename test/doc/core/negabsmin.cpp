#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // Each pair mixes values of the same or of different dimensions.
  using plf::negabsmin;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::cout << std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "negabsmin(f, f) = " << negabsmin(f, f) << std::endl;
  std::cout << "negabsmin(a, a) = " << negabsmin(a, a) << std::endl;
  std::cout << "negabsmin(b, b) = " << negabsmin(b, b) << std::endl;
  std::cout << "negabsmin(c, c) = " << negabsmin(c, c) << std::endl;
  std::cout << "negabsmin(a, f) = " << negabsmin(a, f) << std::endl;
  std::cout << "negabsmin(b, a) = " << negabsmin(b, a) << std::endl;
  std::cout << "negabsmin(c, b) = " << negabsmin(c, b) << std::endl;
  std::cout << "negabsmin(f, a) = " << negabsmin(f, a) << std::endl;
  std::cout << "negabsmin(a, b) = " << negabsmin(a, b) << std::endl;
  std::cout << "negabsmin(b, c) = " << negabsmin(b, c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "negabsmin(wb, wb) = " << negabsmin(wb, wb) << std::endl;
  std::cout << "negabsmin(wc, wc) = " << negabsmin(wc, wc) << std::endl;
  std::cout << "negabsmin(wc, wb) = " << negabsmin(wc, wb) << std::endl;
}
