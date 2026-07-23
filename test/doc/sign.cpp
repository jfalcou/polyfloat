#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  std::cout <<  std::setprecision(15);
  using plf::sign;
  auto f = -1.0;
  auto a = plf::polyfloat(-1.3);
  auto b = plf::polyfloat(1.0, -1.0e-300);
  auto c = plf::polyfloat(-1.0, 1.0e-10, -1.0e-300);
  std::setprecision(15);
  std::cout << "f  "<< f << std::endl;
  std::cout << "a  "<< a << std::endl;
  std::cout << "b  "<< b << std::endl;
  std::cout << "c  "<< c << std::endl;
  std::cout << "sign(f) " << sign(f) << std::endl;
  std::cout << "sign(a) " << sign(a) << std::endl;
  std::cout << "sign(b) " << sign(b) << std::endl;
  std::cout << "sign(c) "<<  sign(c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb      "<< wb << std::endl;
  std::cout << "wc      "<< wc << std::endl;
  std::cout << "sign(wb) "<< sign(wb) << std::endl;
  std::cout << "sign(wc) "<< sign(wc) << std::endl;

  return 0;
}
