#include <iomanip>
#include <iostream>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // 2 + eps/2 in double, in double_real_t<double>, and in triple_real_t<double>.
  auto half_eps = eve::eps(eve::as<double>()) / 2;
  auto z1 = 2.0 + half_eps;
  auto z2 = plf::double_real_t<double>(2.0, half_eps);
  auto z3 = plf::triple_real_t<double>(2.0, half_eps, 0.0);

  std::cout << std::setprecision(16);
  std::cout << "z1       = " << z1 << "\n";
  std::cout << "z2       = " << z2 << "\n";
  std::cout << "z3       = " << z3 << "\n";
  std::cout << "sqrt(z1) = " << plf::sqrt(z1) << "\n";
  std::cout << "sqrt(z2) = " << plf::sqrt(z2) << "\n";
  std::cout << "sqrt(z3) = " << plf::sqrt(z3) << "\n";
}
