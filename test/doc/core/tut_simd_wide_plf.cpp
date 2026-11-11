#include <iostream>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // A register of double_real_t<double>, lane i holding -1 + i.
  using d2_t = plf::double_real_t<double>;
  eve::wide<d2_t> x = [](auto i, auto) { return d2_t(-1.0 + i); };

  std::cout << "size    = " << eve::wide<d2_t>::size() << "\n";
  std::cout << "x       = " << x << "\n";
  std::cout << "x * x   = " << x * x << "\n";
  std::cout << "sqrt(x) = " << plf::sqrt(x) << "\n";
}
