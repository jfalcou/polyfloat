#include <iostream>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // eve is at hand as soon as polyfloat is
  using d2_t = plf::double_real_t<double>;
  eve::wide<d2_t> x = [](auto i, auto) { return d2_t(-1.0 + i); };

  std::cout << "cardinal            = " << eve::wide<d2_t>::size() << " values at a time\n";
  std::cout << "x                   = " << x << "\n";
  std::cout << "x * x               = " << x * x << "\n";

  // The rule from the previous page still holds: a square root may leave the reals,
  std::cout << "sqrt(x)             = " << plf::sqrt(x) << "\n";
}
