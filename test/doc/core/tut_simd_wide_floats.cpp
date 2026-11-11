#include <iostream>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // Lane i holds -1 + i. The second argument of the lambda, the width, is unused.
  eve::wide<double> x = [](auto i, auto) { return -1.0 + i; };

  std::cout << "size  = " << eve::wide<double>::size() << "\n";
  std::cout << "x     = " << x << "\n";
  std::cout << "x * x = " << x * x << "\n";
}
