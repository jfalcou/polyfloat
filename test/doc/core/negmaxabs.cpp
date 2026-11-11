#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // Each pair mixes values of the same or of different dimensions.
  using plf::negmaxabs;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::cout << std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "negmaxabs(f, f) = " << negmaxabs(f, f) << std::endl;
  std::cout << "negmaxabs(a, a) = " << negmaxabs(a, a) << std::endl;
  std::cout << "negmaxabs(b, b) = " << negmaxabs(b, b) << std::endl;
  std::cout << "negmaxabs(c, c) = " << negmaxabs(c, c) << std::endl;
  std::cout << "negmaxabs(a, f) = " << negmaxabs(a, f) << std::endl;
  std::cout << "negmaxabs(b, a) = " << negmaxabs(b, a) << std::endl;
  std::cout << "negmaxabs(c, b) = " << negmaxabs(c, b) << std::endl;
  std::cout << "negmaxabs(f, a) = " << negmaxabs(f, a) << std::endl;
  std::cout << "negmaxabs(a, b) = " << negmaxabs(a, b) << std::endl;
  std::cout << "negmaxabs(b, c) = " << negmaxabs(b, c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "negmaxabs(wb, wb) = " << negmaxabs(wb, wb) << std::endl;
  std::cout << "negmaxabs(wc, wc) = " << negmaxabs(wc, wc) << std::endl;
  std::cout << "negmaxabs(wc, wb) = " << negmaxabs(wc, wb) << std::endl;
}
