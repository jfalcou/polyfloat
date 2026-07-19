#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  std::cout <<  std::setprecision(15);

  auto a = plf::polyfloat(1.0);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::cout << "a = " << a << std::endl;
  std::cout << "b = " << b << std::endl;
  std::cout << "c = " << c << std::endl;
  double pi = eve::pi(eve::as<double>());

  {
    plf::polyfloat<float, 2> ppi(pi);
    std::cout << std::setprecision(7) << "ppi = " << ppi << std::endl;
    std::cout << "get<0>(ppi)" << get<0>(ppi) << std::endl;
    std::cout << "get<1>(ppi)" << get<1>(ppi) << std::endl;
    double rpi = double(get<0>(ppi)) + double(get<1>(ppi));

    std::cout << std::setprecision(15) << "rpi = " << rpi << std::endl;
    std::cout << std::setprecision(15) << "pi  = " <<  pi << std::endl;
    std::cout << rpi-pi << std::endl;
  }
  {
    plf::polyfloat<float, 3> ppi(pi);
    std::cout << std::setprecision(7) << "ppi = " << ppi << std::endl;
    std::cout << "get<0>(ppi)" << get<0>(ppi) << std::endl;
    std::cout << "get<1>(ppi)" << get<1>(ppi) << std::endl;
    std::cout << "get<2>(ppi)" << get<2>(ppi) << std::endl;
    double rpi = double(get<0>(ppi)) + double(get<1>(ppi)) + double(get<2>(ppi));

    std::cout << std::setprecision(15) << "rpi = " << rpi << std::endl;
    std::cout << std::setprecision(15) << "pi  = " <<  pi << std::endl;
    std::cout << rpi-pi << std::endl;
  }
  return 0;
}
