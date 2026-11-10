#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // A negative non-integer value is added to the usual ones.
  using plf::nextint;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::cout << std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  auto d = plf::polyfloat(-2.5, 1.0e-20);
  std::cout << "d  " << d << std::endl;
  std::cout << "nextint(f) = " << nextint(f) << std::endl;
  std::cout << "nextint(a) = " << nextint(a) << std::endl;
  std::cout << "nextint(b) = " << nextint(b) << std::endl;
  std::cout << "nextint(c) = " << nextint(c) << std::endl;
  std::cout << "nextint(d) = " << nextint(d) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "nextint(wb) = " << nextint(wb) << std::endl;
  std::cout << "nextint(wc) = " << nextint(wc) << std::endl;
}
