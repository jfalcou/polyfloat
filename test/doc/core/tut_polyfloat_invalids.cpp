#include <iostream>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // The largest finite value of each type, doubled past the exponent range of double.
  auto x1 = plf::valmax(eve::as<double>());
  auto x2 = plf::valmax(eve::as<plf::double_real_t<double>>());
  auto x3 = plf::valmax(eve::as<plf::triple_real_t<double>>());

  auto y1 = x1 + x1;
  auto y2 = x2 + x2;
  auto y3 = x3 + x3;

  std::cout << "x2        = " << x2 << "\n";
  std::cout << "x3        = " << x3 << "\n";
  std::cout << "y1        = " << y1 << "\n";
  std::cout << "y2        = " << y2 << "\n";
  std::cout << "y3        = " << y3 << "\n";
  std::cout << "rec(y2)   = " << plf::rec(y2) << "\n";
  std::cout << "1 / y3    = " << 1 / y3 << "\n";
  std::cout << "y2 - y2   = " << y2 - y2 << "\n";
  std::cout << "y3 - y3   = " << y3 - y3 << "\n";
}
