#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // Each pair compares values of the same or of different dimensions.
  using plf::is_greater;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::cout << std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "is_greater(f, f) = " << is_greater(f, f) << std::endl;
  std::cout << "is_greater(a, a) = " << is_greater(a, a) << std::endl;
  std::cout << "is_greater(b, b) = " << is_greater(b, b) << std::endl;
  std::cout << "is_greater(c, c) = " << is_greater(c, c) << std::endl;
  std::cout << "is_greater(a, f) = " << is_greater(a, f) << std::endl;
  std::cout << "is_greater(b, a) = " << is_greater(b, a) << std::endl;
  std::cout << "is_greater(c, b) = " << is_greater(c, b) << std::endl;
  std::cout << "is_greater(f, a) = " << is_greater(f, a) << std::endl;
  std::cout << "is_greater(a, b) = " << is_greater(a, b) << std::endl;
  std::cout << "is_greater(b, c) = " << is_greater(b, c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "is_greater(wb, wb) = " << is_greater(wb, wb) << std::endl;
  std::cout << "is_greater(wc, wc) = " << is_greater(wc, wc) << std::endl;
  std::cout << "is_greater(wc, wb) = " << is_greater(wc, wb) << std::endl;
}
