#include <iomanip>
#include <iostream>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // Strings read exactly into double_real_t<double>, printed at 32 digits.
  using d2_t = plf::double_real_t<double>;
  auto tenth = plf::from_string(eve::as<d2_t>(), "0.1");
  auto grouped = plf::from_string(eve::as<d2_t>(), "3'125'569.000'000'000'000'1");
  auto spaced = plf::from_string[plf::separator = ' '](eve::as<d2_t>(), "3 125 569");
  auto bad = plf::from_string(eve::as<d2_t>(), "0.1x");
  auto checked = plf::from_string[plf::pedantic](eve::as<d2_t>(), "0.1x");
  auto lanes = plf::from_string(eve::as<eve::wide<d2_t, 2>>(), "12345678901234567890123456789012",
                                "3.1415926535897932384626433832795");

  std::cout << std::setprecision(32);
  std::cout << "tenth   = " << tenth << "\n";
  std::cout << "grouped = " << grouped << "\n";
  std::cout << "spaced  = " << spaced << "\n";
  std::cout << "bad     = " << bad << "\n";
  std::cout << "checked = " << (checked ? "a value" : "no value") << "\n";
  std::cout << "lanes   = " << lanes << "\n";
}
