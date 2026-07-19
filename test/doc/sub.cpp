#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  std::cout <<  std::setprecision(15);
  using plf::sub;
  auto f = 1.20;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::setprecision(15);
  std::cout << "f  "<< f << std::endl;
  std::cout << "a  "<< a << std::endl;
  std::cout << "b  "<< b << std::endl;
  std::cout << "c  "<< c << std::endl;
  std::cout << "sub(f, f) " << sub(f, f) << std::endl;
  std::cout << "sub(a, a) " << sub(a, a) << std::endl;
  std::cout << "sub(b, b) " << sub(b, b) << std::endl;
  std::cout << "sub(c, c) "<<  sub(c, c) << std::endl;
  std::cout << "sub(a, f) " << sub(a, f) << std::endl;
  std::cout << "sub(b, a) " << sub(b, a) << std::endl;
  std::cout << "sub(c, b) "<<  sub(c, b) << std::endl;
  std::cout << "sub(f, a) " << sub(f, a) << std::endl;
  std::cout << "sub(a, b) " << sub(a, b) << std::endl;
  std::cout << "sub(b, c) "<<  sub(b, c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          "<< wb << std::endl;
  std::cout << "wc          "<< wc << std::endl;
  std::cout << "sub(wb, wb) "<< sub(wb, wb) << std::endl;
  std::cout << "sub(wc, wc) "<< sub(wc, wc) << std::endl;
  std::cout << "sub(wc, wb) "<< sub(wc, wb) << std::endl;
  std::cout << "sub(wb, wc) "<< sub(wb, wc) << std::endl;

  return 0;
}
