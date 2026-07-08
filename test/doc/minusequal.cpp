#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  using namespace plf;
  std::cout <<  std::setprecision(15);

  auto f = 1.0;
  auto a = polyfloat(1.0);
  auto b = polyfloat<double, 2>(1.0, 1.0e-300);
  auto c = polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << c << std::endl;
  b -= a;
  std::cout << b << std::endl;
  b -= b;
  std::cout << b << std::endl;
  c-= a;
  std::cout << c << std::endl;
  c -= b;
  std::cout << c << std::endl;
  c -= c;
  std::cout << c << std::endl;
  b-= f;
  std::cout << b << std::endl;
  c-= f;
  std::cout << c << std::endl;
  return 0;
}
