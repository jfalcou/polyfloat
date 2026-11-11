#include <iostream>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // The second part is larger than the first: the constructor reorders and renormalizes them.
  auto z = plf::double_real_t<double>(2.123456e49, 2.4527e51);

  std::cout << "z                = " << z << "\n";
  std::cout << "is_normalized(z) = " << plf::is_normalized(z) << "\n";
}
