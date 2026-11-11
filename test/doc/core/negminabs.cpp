#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // Each pair mixes values of the same or of different dimensions.
  using plf::negminabs;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::cout << std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "negminabs(f, f) = " << negminabs(f, f) << std::endl;
  std::cout << "negminabs(a, a) = " << negminabs(a, a) << std::endl;
  std::cout << "negminabs(b, b) = " << negminabs(b, b) << std::endl;
  std::cout << "negminabs(c, c) = " << negminabs(c, c) << std::endl;
  std::cout << "negminabs(a, f) = " << negminabs(a, f) << std::endl;
  std::cout << "negminabs(b, a) = " << negminabs(b, a) << std::endl;
  std::cout << "negminabs(c, b) = " << negminabs(c, b) << std::endl;
  std::cout << "negminabs(f, a) = " << negminabs(f, a) << std::endl;
  std::cout << "negminabs(a, b) = " << negminabs(a, b) << std::endl;
  std::cout << "negminabs(b, c) = " << negminabs(b, c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "negminabs(wb, wb) = " << negminabs(wb, wb) << std::endl;
  std::cout << "negminabs(wc, wc) = " << negminabs(wc, wc) << std::endl;
  std::cout << "negminabs(wc, wb) = " << negminabs(wc, wb) << std::endl;
}
