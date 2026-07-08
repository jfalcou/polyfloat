#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  using namespace plf;
  std::cout <<  std::setprecision(15);

  std::cout << plf::_::clean0s(0.0,  0.0, 1.0) << std::endl;
  std::cout << plf::_::clean0s(1.0,  0.0, 0.0) << std::endl;
  std::cout << plf::_::clean0s(0.0,  1.0, 0.0) << std::endl;

  std::cout << plf::_::clean0s(0.0,  2.0, 1.0) << std::endl;
  std::cout << plf::_::clean0s(1.0,  1.0, 0.0) << std::endl;
  std::cout << plf::_::clean0s(0.0,  0.0, 1.0) << std::endl;

}
