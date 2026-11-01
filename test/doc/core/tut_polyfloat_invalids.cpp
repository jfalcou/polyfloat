#include <iostream>
#include <polyfloat/polyfloat.hpp>

int main()
{

  // The very same name, on a triple real value.
  auto z1 = plf::valmax(eve::as<double>());
  auto z2 = plf::valmax(eve::as<plf::double_real_t<double>>());
  auto z3 = plf::valmax(eve::as<plf::triple_real_t<double>>());

  std::cout << "z1    = " << z1 << "\n";
  std::cout << "z2    = " << z3 << "\n";
  std::cout << "z3    = " << z3 << "\n";
  auto zz1 = z1 + z1;
  auto zz2 = z2 + z2;
  auto zz3 = z3 + z3;
  std::cout << "z1+z1 = " << zz1 << "\n";
  std::cout << "z2+z2 = " << zz2 << "\n";
  std::cout << "z3+z3 = " << zz3 << "\n";
  std::cout << "1/(z1+z1) = " << 1 / zz1 << "\n";
  std::cout << "1/(z2+z2) = " << 1 / zz2 << "\n";
  std::cout << "1/(z3+z3) = " << 1 / zz3 << "\n";

  std::cout << "zz1-zz1 = " << zz1 - zz1 << "\n";
  std::cout << "zz2+zz2 = " << zz2 - zz2 << "\n";
  std::cout << "zz3+zz3 = " << zz3 - zz3 << "\n";
}
