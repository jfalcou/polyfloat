#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  using namespace plf;
  std::cout <<  std::setprecision(15);

  auto a = polyfloat(1.0);
  auto b = polyfloat(1.0, 1.0e-300);
  auto c = polyfloat(1.0, 1.0e-10, 1.0e-300);
  auto d = polyfloat(1.0, 1.0e-10, 1.0e-30, 1.0e-300);
  std::cout << dimension_v<decltype(a)> << std::endl;
  std::cout << dimension_v<decltype(b)> << std::endl;
  std::cout << dimension_v<decltype(c)> << std::endl;
  std::cout << dimension_v<decltype(d)> << std::endl;
  return 0;
}
