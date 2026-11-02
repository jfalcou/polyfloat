#include <iostream>
#include <polyfloat/polyfloat.hpp>

int main()
{
  auto z = plf::double_real_t<double>(1.0, eve::eps(eve::as<double>()) / 2);

  std::cout << "z      = " << z << "\n";
  std::cout << "|z|    = " << plf::abs(z) << "\n";
  std::cout << "log(z) = " << plf::log(z) << "\n";

  // A negative real has no real square root, so a nan comes back.
  std::cout << "sqrt(-z) = " << plf::sqrt(-z) << "\n";

  // The very same name, on a triple real value.
  auto z1 = 1.0 + eve::eps(eve::as<double>()) / 2;
  auto z2 = plf::double_real_t<double>(1.0, eve::eps(eve::as<double>()) / 2);
  auto z3 = plf::triple_real_t<double>(1.0, eve::eps(eve::as<double>()) / 2, 0.0);
  std::cout << "z1 " << z1 << std::endl;
  std::cout << "z2 " << z3 << std::endl;
  std::cout << "z3 " << z3 << std::endl;
  std::cout << "sqrt(z1)    = " << plf::sqrt(z1) << "\n";
  std::cout << "sqrt(z2)    = " << plf::sqrt(z2) << "\n";
  std::cout << "sqrt(z3)    = " << plf::sqrt(z3) << "\n";
}
