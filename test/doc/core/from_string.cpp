#include <iomanip>
#include <iostream>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // Strings read exactly into double_real_t<double>, printed with its 32 digits.
  using d2_t = plf::double_real_t<double>;
  auto tenth = plf::from_string("0.1", eve::as<d2_t>());
  auto grouped = plf::from_string("3'125'569.000'000'000'000'1", eve::as<d2_t>());
  auto spaced = plf::from_string("3 125 569", eve::as<d2_t>(), ' ');
  auto bad = plf::from_string("0.1x", eve::as<d2_t>());
  auto checked = plf::from_string[plf::pedantic]("0.1x", eve::as<d2_t>());

  std::cout << std::setprecision(32);
  std::cout << "tenth   = " << tenth << "\n";
  std::cout << "grouped = " << grouped << "\n";
  std::cout << "spaced  = " << spaced << "\n";
  std::cout << "bad     = " << bad << "\n";
  std::cout << "checked = " << (checked ? "a value" : "no value") << "\n";
}
