#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // Each pair mixes values of the same or of different dimensions.
  using plf::hypot;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::cout << std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "hypot(f, f) = " << hypot(f, f) << std::endl;
  std::cout << "hypot(a, a) = " << hypot(a, a) << std::endl;
  std::cout << "hypot(b, b) = " << hypot(b, b) << std::endl;
  std::cout << "hypot(c, c) = " << hypot(c, c) << std::endl;
  std::cout << "hypot(a, f) = " << hypot(a, f) << std::endl;
  std::cout << "hypot(b, a) = " << hypot(b, a) << std::endl;
  std::cout << "hypot(c, b) = " << hypot(c, b) << std::endl;
  std::cout << "hypot(f, a) = " << hypot(f, a) << std::endl;
  std::cout << "hypot(a, b) = " << hypot(a, b) << std::endl;
  std::cout << "hypot(b, c) = " << hypot(b, c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "hypot(wb, wb) = " << hypot(wb, wb) << std::endl;
  std::cout << "hypot(wc, wc) = " << hypot(wc, wc) << std::endl;
  std::cout << "hypot(wc, wb) = " << hypot(wc, wb) << std::endl;
}
