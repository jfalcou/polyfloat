#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  std::cout << std::setprecision(15);
  using plf::min;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "min(f, f) " << min(f, f) << std::endl;
  std::cout << "min(a, a) " << min(a, a) << std::endl;
  std::cout << "min(b, b) " << min(b, b) << std::endl;
  std::cout << "min(c, c) " << min(c, c) << std::endl;
  std::cout << "min(a, f) " << min(a, f) << std::endl;
  std::cout << "min(b, a) " << min(b, a) << std::endl;
  std::cout << "min(c, b) " << min(c, b) << std::endl;
  std::cout << "min(f, a) " << min(f, a) << std::endl;
  std::cout << "min(a, b) " << min(a, b) << std::endl;
  std::cout << "min(b, c) " << min(b, c) << std::endl;
  std::cout << "min(b, c) " << min(c, f) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "min(wb, wb) " << min(wb, wb) << std::endl;
  std::cout << "min(wc, wc) " << min(wc, wc) << std::endl;
  std::cout << "min(wc, wb) " << min(wc, wb) << std::endl;
  std::cout << "min(wc, f)  " << min(wc, f) << std::endl;

  return 0;
}
