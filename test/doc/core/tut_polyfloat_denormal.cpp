#include <iostream>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // The smallest positive denormal of double, then a value built from three denormals.
  auto d1 = plf::mindenormal(eve::as<double>());
  auto d3 = plf::mindenormal(eve::as<plf::triple_real_t<double>>());

  std::cout << "d1        = " << d1 << "\n";
  std::cout << "d3        = " << d3 << "\n";
  std::cout << "d3 + d3   = " << d3 + d3 << "\n";
  std::cout << "rec(d3)   = " << plf::rec(d3) << "\n";

  auto a = plf::triple_real_t<double>(1.0e-20);
  auto b = plf::triple_real_t<double>(d1, d1, d1);

  std::cout << "b         = " << b << "\n";
  std::cout << "a / b     = " << a / b << "\n";
}
