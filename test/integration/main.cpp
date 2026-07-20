#include <iostream>
#include <polyfloat/polyfloat.hpp>

int main()
{
  std::cout << plf::polyfloat<float, 2>(3.4f, 6.7e-10f) << "\n";
  return 0;
}
