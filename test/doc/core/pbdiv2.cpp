#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  std::cout << std::setprecision(15);
  using plf::ldexp;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "a/2 " << a / 2 << std::endl;
  std::cout << "b/2 " << b / 2 << std::endl;
  std::cout << "c/2 " << c / 2 << std::endl;
  std::cout << "f/2 " << f / 2 << std::endl;
  std::cout << "ldexpa,-1) " << ldexp(a, -1) << std::endl;
  std::cout << "ldexpb,-1) " << ldexp(b, -1) << std::endl;
  std::cout << "ldexpc,-1) " << ldexp(c, -1) << std::endl;
  std::cout << "ldexpf,-1) " << ldexp(f, -1) << std::endl;

  return 0;
}
