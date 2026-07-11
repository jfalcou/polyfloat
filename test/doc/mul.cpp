#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  std::cout <<  std::setprecision(15);

//  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
//  auto c = polyfloat(1.0, 1.0e-10, 1.0e-300);
//  std::cout << c << std::endl;
  auto ba = b*a;
  auto ab = a*b;
  std::cout << "a  "<< a << std::endl;
  std::cout << "b  "<< b << std::endl;
  std::cout << "ab " << ab << std::endl;
  std::cout << "ba "<< ba << std::endl;
  std::cout << "(ab-ba)" << (ab-ba) << std::endl;

  return 0;
}
