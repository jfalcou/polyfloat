#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  std::cout << std::setprecision(15);
  using plf::cumsum;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "cumsum(f, f) " << cumsum(kumi::make_tuple(f, f)) << std::endl;
  std::cout << "cumsum(f, f) " << cumsum(f, f) << std::endl;
  std::cout << "cumsum(a, a) " << cumsum(a, a) << std::endl;
  std::cout << "cumsum(b, b) " << cumsum(b, b) << std::endl;
  std::cout << "cumsum(c, c) " << cumsum(c, c) << std::endl;
  std::cout << "cumsum(a, f) " << cumsum(a, f) << std::endl;
  std::cout << "cumsum(b, a) " << cumsum(b, a) << std::endl;
  std::cout << "cumsum(c, b) " << cumsum(c, b) << std::endl;
  std::cout << "cumsum(f, a) " << cumsum(f, a) << std::endl;
  std::cout << "cumsum(a, b) " << cumsum(a, b) << std::endl;
  std::cout << "cumsum(b, c) " << cumsum(b, c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "cumsum(wb, wb) " << cumsum(wb, wb) << std::endl;
  std::cout << "cumsum(wc, wc) " << cumsum(wc, wc) << std::endl;
  std::cout << "cumsum(wc, wb) " << cumsum(wc, wb) << std::endl;
  std::cout << "cumsum(wc, wb, b) " << cumsum(wb, wb, wb, b, c, 1) << std::endl;

  return 0;
}
