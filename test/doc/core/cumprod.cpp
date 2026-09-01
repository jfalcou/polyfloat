#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  std::cout << std::setprecision(15);
  using plf::add;
  using plf::cumprod;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "cumprod(f, f) " << cumprod(kumi::make_tuple(f, f)) << std::endl;
  std::cout << "cumprod(f, f) " << cumprod(f, f) << std::endl;
  std::cout << "cumprod(a, a) " << cumprod(a, a) << std::endl;
  std::cout << "cumprod(b, b) " << cumprod(b, b) << std::endl;
  std::cout << "cumprod(c, c) " << cumprod(c, c) << std::endl;
  std::cout << "cumprod(a, f) " << cumprod(a, f) << std::endl;
  std::cout << "cumprod(b, a) " << cumprod(b, a) << std::endl;
  std::cout << "cumprod(c, b) " << cumprod(c, b) << std::endl;
  std::cout << "cumprod(f, a) " << cumprod(f, a) << std::endl;
  std::cout << "cumprod(a, b) " << cumprod(a, b) << std::endl;
  std::cout << "cumprod(b, c) " << cumprod(b, c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "cumprod(wb, wb) " << cumprod(wb, wb) << std::endl;
  std::cout << "cumprod(wc, wc) " << cumprod(wc, wc) << std::endl;
  std::cout << "cumprod(wc, wb) " << cumprod(wc, wb) << std::endl;
  std::cout << "cumprod(wc, wb, b) " << cumprod(wb, wb, wb, b, c, 1) << std::endl;

  return 0;
}
