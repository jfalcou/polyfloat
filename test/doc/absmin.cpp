#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  std::cout <<  std::setprecision(15);
  using plf::absmin;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::setprecision(15);
  std::cout << "f  "<< f << std::endl;
  std::cout << "a  "<< a << std::endl;
  std::cout << "b  "<< b << std::endl;
  std::cout << "c  "<< c << std::endl;
  std::cout << "absmin(f, f) " << absmin(f, f) << std::endl;
  std::cout << "absmin(a, a) " << absmin(a, a) << std::endl;
  std::cout << "absmin(b, b) " << absmin(b, b) << std::endl;
  std::cout << "absmin(c, c) "<<  absmin(c, c) << std::endl;
  std::cout << "absmin(a, f) " << absmin(a, f) << std::endl;
  std::cout << "absmin(b, a) " << absmin(b, a) << std::endl;
  std::cout << "absmin(c, b) "<<  absmin(c, b) << std::endl;
  std::cout << "absmin(f, a) " << absmin(f, a) << std::endl;
  std::cout << "absmin(a, b) " << absmin(a, b) << std::endl;
  std::cout << "absmin(b, c) "<<  absmin(b, c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          "<< wb << std::endl;
  std::cout << "wc          "<< wc << std::endl;
  std::cout << "absmin(wb, wb) "<< absmin(wb, wb) << std::endl;
  std::cout << "absmin(wc, wc) "<< absmin(wc, wc) << std::endl;
  std::cout << "absmin(wc, wb) "<< absmin(wc, wb) << std::endl;
  std::cout << "absmin(wc, wb, b, c, 1) "<< absmin(wb, wb, wb, b, c, 1) << std::endl;

  return 0;
}
