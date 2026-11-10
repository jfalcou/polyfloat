#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // The second argument, of the same type, gives the direction.
  using plf::nextafter;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::cout << std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "nextafter(f, 2.0) = " << nextafter(f, 2.0) << std::endl;
  std::cout << "nextafter(a, b) = " << nextafter(a, b) << std::endl;
  std::cout << "nextafter(b, a) = " << nextafter(b, a) << std::endl;
  std::cout << "nextafter(c, -c) = " << nextafter(c, -c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "nextafter(wb, pf2_t(a)) = " << nextafter(wb, pf2_t(a)) << std::endl;
  std::cout << "nextafter(wc, -wc) = " << nextafter(wc, -wc) << std::endl;
}
