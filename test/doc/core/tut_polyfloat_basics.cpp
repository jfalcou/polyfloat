#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // The very same name, on a triple real value.
  auto z1 = 2.0 + eve::eps(eve::as<double>()) / 2;
  auto z2 = plf::double_real_t<double>(2.0, eve::eps(eve::as<double>()) / 2);
  auto z3 = plf::triple_real_t<double>(2.0, eve::eps(eve::as<double>()) / 2, 0.0);
  std::cout << std::setprecision(16);
  std::cout << "z1 " << z1 << std::endl;
  std::cout << "z2 " << z3 << std::endl;
  std::cout << "z3 " << z3 << std::endl;
  std::cout << "sqrt(z1)    = " << plf::sqrt(z1) << "\n";
  std::cout << "sqrt(z2)    = " << plf::sqrt(z2) << "\n";
  std::cout << "sqrt(z3)    = " << plf::sqrt(z3) << "\n";

  auto after_twisted_init = plf::double_real_t<double>(2.123456e49, 2.4527e+51);
  std::cout << "plf::double_real_t<double>(2.123456e49, 2.4527e+51) =  " << after_twisted_init << std::endl;
  std::cout << "plf::is_normalized(after_twisted_init) = " << plf::is_normalized(after_twisted_init) << std::endl;
}
