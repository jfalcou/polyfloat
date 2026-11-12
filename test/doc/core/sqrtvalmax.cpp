#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  {
    std::cout << std::hexfloat;
    auto mxfl1 = plf::sqrtvalmax(eve::as<double>());
    auto mxfl2 = plf::sqrtvalmax(eve::as<plf::polyfloat<double, 2>>());
    auto mxfl3 = plf::sqrtvalmax(eve::as<plf::polyfloat<double, 3>>());
    std::cout << "mxfl1 " << mxfl1 << std::endl;
    std::cout << "mxfl2 " << mxfl2 << std::endl;
    std::cout << "mxfl3 " << mxfl3 << std::endl;
  }
  {
    std::cout << std::hexfloat;
    auto mxfl1 = plf::sqrtvalmax(eve::as<float>());
    auto mxfl2 = plf::sqrtvalmax(eve::as<plf::polyfloat<float, 2>>());
    auto mxfl3 = plf::sqrtvalmax(eve::as<plf::polyfloat<float, 3>>());
    std::cout << "mxfl1 " << mxfl1 << std::endl;
    std::cout << "mxfl2 " << mxfl2 << std::endl;
    std::cout << "mxfl3 " << mxfl3 << std::endl;
  }
}
