#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  std::cout <<  std::setprecision(15);
  using plf::max;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::setprecision(15);
  std::cout << "f  "<< f << std::endl;
  std::cout << "a  "<< a << std::endl;
  std::cout << "b  "<< b << std::endl;
  std::cout << "c  "<< c << std::endl;
  std::cout << "max(f, f) " << max(f, f) << std::endl;
  std::cout << "max(a, a) " << max(a, a) << std::endl;
  std::cout << "max(b, b) " << max(b, b) << std::endl;
  std::cout << "max(c, c) "<<  max(c, c) << std::endl;
  std::cout << "max(a, f) " << max(a, f) << std::endl;
  std::cout << "max(b, a) " << max(b, a) << std::endl;
  std::cout << "max(c, b) "<<  max(c, b) << std::endl;
  std::cout << "max(f, a) " << max(f, a) << std::endl;
  std::cout << "max(a, b) " << max(a, b) << std::endl;
  std::cout << "max(b, c) "<<  max(b, c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          "<< wb << std::endl;
  std::cout << "wc          "<< wc << std::endl;
  std::cout << "max(wb, wb) "<< max(wb, wb) << std::endl;
  std::cout << "max(wc, wc) "<< max(wc, wc) << std::endl;
  // std::cout << "max(wc, wb) "<< max(wc, wb) << std::endl;

  return 0;
}
