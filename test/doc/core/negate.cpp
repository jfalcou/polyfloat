#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // The second argument gives its sign, positive or negative.
  using plf::negate;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::cout << std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "negate(a, f) = " << negate(a, f) << std::endl;
  std::cout << "negate(b, -f) = " << negate(b, -f) << std::endl;
  std::cout << "negate(c, -a) = " << negate(c, -a) << std::endl;
  std::cout << "negate(a, b) = " << negate(a, b) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "negate(wb, wb) = " << negate(wb, wb) << std::endl;
  std::cout << "negate(wc, wc) = " << negate(wc, wc) << std::endl;
  std::cout << "negate(wc, wb) = " << negate(wc, wb) << std::endl;
}
