#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  std::cout <<  std::setprecision(15);
  using plf::maxabs;
  auto f = -21.0;
  auto a = plf::polyfloat(1.3);
  auto b = -plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::setprecision(15);
  std::cout << "f  "<< f << std::endl;
  std::cout << "a  "<< a << std::endl;
  std::cout << "b  "<< b << std::endl;
  std::cout << "c  "<< c << std::endl;
  std::cout << "maxabs(f, f) " << maxabs(f, f) << std::endl;
  std::cout << "maxabs(a, a) " << maxabs(a, a) << std::endl;
  std::cout << "maxabs(b, b) " << maxabs(b, b) << std::endl;
  std::cout << "maxabs(c, c) "<<  maxabs(c, c) << std::endl;
  std::cout << "maxabs(a, f) " << maxabs(a, f) << std::endl;
  std::cout << "maxabs(b, a) " << maxabs(b, a) << std::endl;
  std::cout << "maxabs(c, b) "<<  maxabs(c, b) << std::endl;
  std::cout << "maxabs(f, a) " << maxabs(f, a) << std::endl;
  std::cout << "maxabs(a, b) " << maxabs(a, b) << std::endl;
  std::cout << "maxabs(b, c) "<<  maxabs(b, c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          "<< wb << std::endl;
  std::cout << "wc          "<< wc << std::endl;
  std::cout << "maxabs(wb, wb) "<< maxabs(wb, wb) << std::endl;
  std::cout << "maxabs(wc, wc) "<< maxabs(wc, wc) << std::endl;
  std::cout << "maxabs(wc, wb) "<< maxabs(wc, wb) << std::endl;

  return 0;
}
