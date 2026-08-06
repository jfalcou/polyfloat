#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>
#include <polyfloat/details/printing.hpp>

int main()
{
  std::cout <<  std::setprecision(15);
  using plf::abs;
  auto f = -1.0;
  auto a = plf::polyfloat(-1.3);
  auto b = plf::polyfloat(1.0, -1.0e-55);
  auto c = plf::polyfloat(-1.0, 1.0e-10, -1.0e-50);
  std::cout << "c  "<< c << std::endl;
  plf::_::println("c ", c);
  std::cout << "plf c  "<< plf::_::from_string("-0.99999999989999999999999999635678026845022584208345529344003603910103605927837862420982599309164", eve::as(c)) << std::endl;
  std::setprecision(15);
  std::cout << "f  "<< f << std::endl;
  std::cout << "a  "<< a << std::endl;
  std::cout << "b  "<< b << std::endl;
  std::cout << "c  "<< c << std::endl;
  std::cout << "abs(f) " << abs(f) << std::endl;
  std::cout << "abs(a) " << abs(a) << std::endl;
  std::cout << "abs(b) " << abs(b) << std::endl;
  std::cout << "abs(c) "<<  abs(c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb      "<< wb << std::endl;
  std::cout << "wc      "<< wc << std::endl;
  std::cout << "abs(wb) "<< abs(wb) << std::endl;
  std::cout << "abs(wc) "<< abs(wc) << std::endl;
  return 0;
}
