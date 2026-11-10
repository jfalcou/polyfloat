#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // Each pair compares values of the same or of different dimensions.
  using plf::is_not_less;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::cout << std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "is_not_less(f, f) = " << is_not_less(f, f) << std::endl;
  std::cout << "is_not_less(a, a) = " << is_not_less(a, a) << std::endl;
  std::cout << "is_not_less(b, b) = " << is_not_less(b, b) << std::endl;
  std::cout << "is_not_less(c, c) = " << is_not_less(c, c) << std::endl;
  std::cout << "is_not_less(a, f) = " << is_not_less(a, f) << std::endl;
  std::cout << "is_not_less(b, a) = " << is_not_less(b, a) << std::endl;
  std::cout << "is_not_less(c, b) = " << is_not_less(c, b) << std::endl;
  std::cout << "is_not_less(f, a) = " << is_not_less(f, a) << std::endl;
  std::cout << "is_not_less(a, b) = " << is_not_less(a, b) << std::endl;
  std::cout << "is_not_less(b, c) = " << is_not_less(b, c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "is_not_less(wb, wb) = " << is_not_less(wb, wb) << std::endl;
  std::cout << "is_not_less(wc, wc) = " << is_not_less(wc, wc) << std::endl;
  std::cout << "is_not_less(wc, wb) = " << is_not_less(wc, wb) << std::endl;
}
