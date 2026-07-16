#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
//  std::cout <<  std::setprecision(15);
  using plf::frexp;
  auto f = -1.0;
  auto a = plf::polyfloat(-1.3);
  auto b = plf::polyfloat(1.0, -1.0e-300);
  auto c = plf::polyfloat(-1.0, 1.0e-10, -1.0e-300);
  std::setprecision(15);
  std::cout << "f  "<< f << std::endl;
  std::cout << "a  "<< a << std::endl;
  std::cout << "b  "<< b << std::endl;
  std::cout << "c  "<< c << std::endl;
  std::cout << "frexp(f) " << frexp(f) << std::endl;
  std::cout << "frexp(a) " << frexp(a) << std::endl;
  std::cout << "frexp(b) " << frexp(b) << std::endl;
  std::cout << "frexp(c) "<<  frexp(c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb      "<< wb << std::endl;
  std::cout << "wc      "<< wc << std::endl;
  std::cout << "frexp(wb) "<< frexp(wb) << std::endl;
  std::cout << "frexp(wc) "<< frexp(wc) << std::endl;

  return 0;
}
