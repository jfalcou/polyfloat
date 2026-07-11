#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  std::cout <<  std::setprecision(15);

  auto a = plf::polyfloat(1.0);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::cout << get<0>(a) << std::endl;
  std::cout << get<0>(b) << std::endl;
  std::cout << get<0>(c) << std::endl;
  std::cout << get<1>(b) << std::endl;
  std::cout << get<1>(c) << std::endl;
  std::cout << get<2>(c) << std::endl;
  return 0;
}
