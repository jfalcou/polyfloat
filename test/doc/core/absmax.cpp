#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  std::cout << std::setprecision(15);
  using plf::absmax;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "absmax(f, f) " << absmax(f, f) << std::endl;
  std::cout << "absmax(a, a) " << absmax(a, a) << std::endl;
  std::cout << "absmax(b, b) " << absmax(b, b) << std::endl;
  std::cout << "absmax(c, c) " << absmax(c, c) << std::endl;
  std::cout << "absmax(a, f) " << absmax(a, f) << std::endl;
  std::cout << "absmax(b, a) " << absmax(b, a) << std::endl;
  std::cout << "absmax(c, b) " << absmax(c, b) << std::endl;
  std::cout << "absmax(f, a) " << absmax(f, a) << std::endl;
  std::cout << "absmax(a, b) " << absmax(a, b) << std::endl;
  std::cout << "absmax(b, c) " << absmax(b, c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "absmax(wb, wb) " << absmax(wb, wb) << std::endl;
  std::cout << "absmax(wc, wc) " << absmax(wc, wc) << std::endl;
  std::cout << "absmax(wc, wb) " << absmax(wc, wb) << std::endl;
  std::cout << "absmax(wc, wb, b, c, 1) " << absmax(wb, wb, wb, b, c, 1) << std::endl;

  return 0;
}
