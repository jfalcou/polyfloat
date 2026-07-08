#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  using namespace plf;
  std::cout <<  std::setprecision(15);

  auto a = polyfloat(1.0);
  auto b = polyfloat(1.0,  1.0e-300);
  auto d0 = polyfloat(1.0, 1.0e-10, 1.0e-30, 1.0e-300);
  auto d1 = polyfloat(1.0, 1.0e-10, 1.0e-30, 1.0e-200);
  std::cout << (a != a) << std::endl;
  std::cout << (a != b) << std::endl;
  std::cout << (d0 != d1) << std::endl;
  std::cout << (d0 != d0) << std::endl;
  return 0;
}
