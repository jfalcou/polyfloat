#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // The second argument gives its sign, never zero.
  using plf::negatenz;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::cout << std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "negatenz(a, f) = " << negatenz(a, f) << std::endl;
  std::cout << "negatenz(b, -f) = " << negatenz(b, -f) << std::endl;
  std::cout << "negatenz(c, -a) = " << negatenz(c, -a) << std::endl;
  std::cout << "negatenz(a, b) = " << negatenz(a, b) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "negatenz(wb, wb) = " << negatenz(wb, wb) << std::endl;
  std::cout << "negatenz(wc, wc) = " << negatenz(wc, wc) << std::endl;
  std::cout << "negatenz(wc, wb) = " << negatenz(wc, wb) << std::endl;
}
