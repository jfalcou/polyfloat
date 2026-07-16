#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  std::cout <<  std::setprecision(15);
  using plf::div;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::setprecision(15);
  std::cout << "f  "<< f << std::endl;
  std::cout << "a  "<< a << std::endl;
  std::cout << "b  "<< b << std::endl;
  std::cout << "c  "<< c << std::endl;
  std::cout << "div(f, f) " << div(f, f) << std::endl;
  std::cout << "div(a, a) " << div(a, a) << std::endl;
  std::cout << "div(b, b) " << div(b, b) << std::endl;
  std::cout << "div(c, c) "<<  div(c, c) << std::endl;
  std::cout << "div(a, f) " << div(a, f) << std::endl;
  std::cout << "div(b, a) " << div(b, a) << std::endl;
  std::cout << "div(c, b) "<<  div(c, b) << std::endl;
  std::cout << "div(f, a) " << div(f, a) << std::endl;
  std::cout << "div(a, b) " << div(a, b) << std::endl;
  std::cout << "div(b, c) "<<  div(b, c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          "<< wb << std::endl;
  std::cout << "wc          "<< wc << std::endl;
  std::cout << "div(wb, wb) "<< div(wb, wb) << std::endl;
  std::cout << "div(wc, wc) "<< div(wc, wc) << std::endl;
//  std::cout << "div(wc, wb) "<< div(wc, wb) << std::endl;

  return 0;
}
