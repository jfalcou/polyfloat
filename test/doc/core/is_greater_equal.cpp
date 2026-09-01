#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  using plf::is_greater_equal;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-300, 0.0);
  std::cout << std::setprecision(15) << std::hexfloat;
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "is_greater_equal(f, f) " << is_greater_equal(f, f) << std::endl;
  std::cout << "is_greater_equal(a, a) " << is_greater_equal(a, a) << std::endl;
  std::cout << "is_greater_equal(b, b) " << is_greater_equal(b, b) << std::endl;
  std::cout << "is_greater_equal(c, c) " << is_greater_equal(c, c) << std::endl;
  std::cout << "is_greater_equal(a, f) " << is_greater_equal(a, f) << std::endl;
  std::cout << "is_greater_equal(b, a) " << is_greater_equal(b, a) << std::endl;
  std::cout << "is_greater_equal(c, b) " << is_greater_equal(c, b) << std::endl;
  std::cout << "is_greater_equal(f, a) " << is_greater_equal(f, a) << std::endl;
  std::cout << "is_greater_equal(a, b) " << is_greater_equal(a, b) << std::endl;
  std::cout << "is_greater_equal(b, c) " << is_greater_equal(b, c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "is_greater_equal(wb, wb) " << is_greater_equal(wb, wb) << std::endl;
  std::cout << "is_greater_equal(wc, wc) " << is_greater_equal(wc, wc) << std::endl;
  std::cout << "is_greater_equal(wc, wb) " << is_greater_equal(wc, wb) << std::endl;
  std::cout << "is_greater_equal(wc, wb) " << (wc < wb) << std::endl;

  return 0;
}
