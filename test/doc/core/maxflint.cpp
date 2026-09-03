#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>
#include <polyfloat/details/printing.hpp>

int main()
{
  std::cout << std::setprecision(16);
  auto mxfl1 = plf::maxflint(eve::as<double>());
  auto mxfl2 = plf::maxflint(eve::as<plf::polyfloat<double, 2>>());
  auto mxfl3 = plf::maxflint(eve::as<plf::polyfloat<double, 3>>());
  std::cout << "mxfl1 " << mxfl1 << std::endl;
  std::cout << "mxfl2 " << mxfl2 << std::endl;
  std::cout << "mxfl3 " << mxfl3 << std::endl;
}
