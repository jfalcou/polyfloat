#include <eve/wide.hpp>
#include <iostream>
#include <polyfloat/polyfloat.hpp>

int main()
{
  using namespace plf;
  std::cout << polyfloat(1.0, 1.0e-30) << std::endl;
  return 0;
}
