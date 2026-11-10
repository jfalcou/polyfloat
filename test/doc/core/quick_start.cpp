#include <iostream>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // Half the machine epsilon of double: 1 + eps/2 rounds to 1 in double, and is kept here.
  auto z = plf::triple_real_t<double>(1.0, eve::eps(eve::as<double>()) / 2);

  std::cout << "z        = " << z << "\n";
  std::cout << "|z|      = " << plf::abs(z) << "\n";
  std::cout << "log(z)   = " << plf::log(z) << "\n";
  std::cout << "sqrt(-z) = " << plf::sqrt(-z) << "\n";
}
