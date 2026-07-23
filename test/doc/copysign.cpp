#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  std::cout <<  std::setprecision(15);
  using plf::copysign;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(-1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::setprecision(15);
  std::cout << "f  "<< f << std::endl;
  std::cout << "a  "<< a << std::endl;
  std::cout << "b  "<< b << std::endl;
  std::cout << "c  "<< c << std::endl;
  std::cout << "copysign(f, f) " << copysign(f, f) << std::endl;
  std::cout << "copysign(a, a) " << copysign(a, a) << std::endl;
  std::cout << "copysign(b, b) " << copysign(b, b) << std::endl;
  std::cout << "copysign(c, c) "<<  copysign(c, c) << std::endl;
  std::cout << "copysign(a, f) " << copysign(a, f) << std::endl;
  std::cout << "copysign(b, a) " << copysign(b, a) << std::endl;
  std::cout << "copysign(c, b) "<<  copysign(c, b) << std::endl;
  std::cout << "copysign(f, a) " << copysign(f, a) << std::endl;
  std::cout << "copysign(a, b) " << copysign(a, b) << std::endl;
  std::cout << "copysign(b, c) "<<  copysign(b, c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          "<< wb << std::endl;
  std::cout << "wc          "<< wc << std::endl;
  std::cout << "copysign(wb, wb) "<< copysign(wb, wb) << std::endl;
  std::cout << "copysign(wc, wc) "<< copysign(wc, wc) << std::endl;
  std::cout << "copysign(wc, wb) "<< copysign(wc, wb) << std::endl;

  return 0;
}
