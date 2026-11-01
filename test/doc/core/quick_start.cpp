#include <iostream>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // eps is the epsilon machine so that  1.0+eve::eps(eve::as<double>())/2 is 1.0
  auto z = plf::triple_real_t<double>(1.0, eve::eps(eve::as<double>()) / 2);

  std::cout << "z      = " << z << "\n";
  std::cout << "|z|    = " << plf::abs(z) << "\n";
  std::cout << "log(z) = " << plf::log(z) << "\n";

  // A negative real has no real square root, so a nan comes back. Only the first part of the number is a Nan value.
  std::cout << "sqrt(-z) = " << plf::sqrt(-z) << "\n";
}
