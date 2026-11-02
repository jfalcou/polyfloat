#include <iostream>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // eve is at hand as soon as polyfloat is
  eve::wide<double> x = [](auto i, auto) { return -1.0 + i; };

  std::cout << "cardinal            = " << eve::wide<double>::size() << " values at a time\n";
  std::cout << "x                   = " << x << "\n";
  std::cout << "x * x               = " << x * x << "\n";
}
