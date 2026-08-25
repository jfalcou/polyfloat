#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  std::cout <<  std::setprecision(15);
  using plf::exp;
  auto f = 1.0;
   auto a = plf::polyfloat(1.0, 0.0);
//   auto b = plf::polyfloat(1.0, -1.0e-55);
   auto c = plf::polyfloat(1.0, 0.0, 0.0);
  std::setprecision(15);
  std::cout << "f  "<< f << std::endl;
   std::cout << "a  "<< a << std::endl;
//   std::cout << "b  "<< b << std::endl;
//   std::cout << "c  "<< c << std::endl;
  std::cout << "exp(f) " << exp(f) << std::endl;
   std::cout << "exp(a) " << exp(a) << std::endl;
//   std::cout << "exp(b) " << exp(b) << std::endl;
   std::cout << "exp(c) "<<  exp(c) << std::endl;

 //  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
//   using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
//   pf2_t wb(b);
//   pf3_t wc(c);
//   std::cout << "wb      "<< wb << std::endl;
//   std::cout << "wc      "<< wc << std::endl;
//   std::cout << "exp(wb) "<< exp(wb) << std::endl;
//   std::cout << "exp(wc) "<< exp(wc) << std::endl;
//   return 0;
}
