#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>
#include <mpreal.h>

int main()
{
  using  mpfr::mpreal;
  std::cout <<  std::setprecision(15);
  const int bindigits = 106;
  mpreal::set_default_prec(mpfr::digits2bits(bindigits));

//  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  mpreal mpa = mpreal(plf::hi(a))+mpreal(plf::lo(a));
  std::cout << "mpa "<< mpa << std::endl;

//   std::cout << "a  "<< a << std::endl;
//   std::cout << "b  "<< b << std::endl;
//   std::cout << "aob " << aob << std::endl;
//   std::cout << "aobb "<< aob*b << std::endl;
//   std::cout << "(aobb-a)" << (aob*b-a) << std::endl;

  return 0;
}
