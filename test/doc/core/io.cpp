#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  std::cout << std::setprecision(15);

  auto a = plf::polyfloat(1.0);
  auto b = plf::polyfloat<double, 2>(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << c << std::endl;
  return 0;
}
