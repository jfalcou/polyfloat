#include <iomanip>
#include <iostream>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // 2 + eps/2: rounded to 2 in double, exact in double_real_t<double> and in triple_real_t<double> read from a string.
  auto half_eps = eve::eps(eve::as<double>()) / 2;
  auto z1 = 2.0 + half_eps;
  auto z2 = plf::double_real_t<double>(2.0, half_eps);
  auto z3 =
    plf::from_string("2.00000000000000011102230246251565404236316680908203125", eve::as<plf::triple_real_t<double>>());

  std::cout << std::setprecision(16) << "z1       = " << z1 << "\n";
  std::cout << std::setprecision(32) << "z2       = " << z2 << "\n";
  std::cout << std::setprecision(48) << "z3       = " << z3 << "\n";
  std::cout << std::setprecision(16) << "sqrt(z1) = " << plf::sqrt(z1) << "\n";
  std::cout << std::setprecision(32) << "sqrt(z2) = " << plf::sqrt(z2) << "\n";
  std::cout << std::setprecision(48) << "sqrt(z3) = " << plf::sqrt(z3) << "\n";
  std::cout << plf::showparts << "z3       = " << z3 << "\n";
  std::cout << plf::noshowparts << std::hexfloat << "z3       = " << z3 << "\n";
}
