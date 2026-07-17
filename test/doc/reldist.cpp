#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  std::cout <<  std::setprecision(15);
  using plf::reldist;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::setprecision(15);
  std::cout << "f  "<< f << std::endl;
  std::cout << "a  "<< a << std::endl;
  std::cout << "b  "<< b << std::endl;
  std::cout << "c  "<< c << std::endl;
  std::cout << "reldist(f, f) " << reldist(f, f) << std::endl;
  std::cout << "reldist(a, a) " << reldist(a, a) << std::endl;
  std::cout << "reldist(b, b) " << reldist(b, b) << std::endl;
  std::cout << "reldist(c, c) "<<  reldist(c, c) << std::endl;
  std::cout << "reldist(a, f) " << reldist(a, f) << std::endl;
  std::cout << "reldist(b, a) " << reldist(b, a) << std::endl;
  std::cout << "reldist(c, b) "<<  reldist(c, b) << std::endl;
  std::cout << "reldist(f, a) " << reldist(f, a) << std::endl;
  std::cout << "reldist(a, b) " << reldist(a, b) << std::endl;
  std::cout << "reldist(b, c) "<<  reldist(b, c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          "<< wb << std::endl;
  std::cout << "wc          "<< wc << std::endl;
  std::cout << "reldist(wb, wb) "<< reldist(wb, wb) << std::endl;
  std::cout << "reldist(wc, wc) "<< reldist(wc, wc) << std::endl;
  // std::cout << "reldist(wc, wb) "<< reldist(wc, wb) << std::endl;

  return 0;
}
