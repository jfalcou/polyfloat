#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  using plf::is_ordered;
  auto f = eve::nan(eve::as<double>());
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(f, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-300, 0.0);
  std::cout << std::setprecision(15) << std::hexfloat;
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "is_ordered(f, f) " << is_ordered(f, f) << std::endl;
  std::cout << "is_ordered(a, a) " << is_ordered(a, a) << std::endl;
  std::cout << "is_ordered(b, b) " << is_ordered(b, b) << std::endl;
  std::cout << "is_ordered(c, c) " << is_ordered(c, c) << std::endl;
  std::cout << "is_ordered(a, f) " << is_ordered(a, f) << std::endl;
  std::cout << "is_ordered(b, a) " << is_ordered(b, a) << std::endl;
  std::cout << "is_ordered(c, b) " << is_ordered(c, b) << std::endl;
  std::cout << "is_ordered(f, a) " << is_ordered(f, a) << std::endl;
  std::cout << "is_ordered(a, b) " << is_ordered(a, b) << std::endl;
  std::cout << "is_ordered(b, c) " << is_ordered(b, c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "is_ordered(wb, wb) " << is_ordered(wb, wb) << std::endl;
  std::cout << "is_ordered(wc, wc) " << is_ordered(wc, wc) << std::endl;
  std::cout << "is_ordered(wc, wb) " << is_ordered(wc, wb) << std::endl;
  std::cout << "is_ordered(wc, wb) " << (wc < wb) << std::endl;

  return 0;
}
