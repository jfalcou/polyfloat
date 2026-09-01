#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>
#include <polyfloat/details/printing.hpp>

int main()
{
  std::cout << std::setprecision(16);
  auto mxfl1 = plf::valmax(eve::as<double>());
  auto mxfl2 = plf::valmax(eve::as<plf::polyfloat<double, 2>>());
  auto mxfl3 = plf::valmax(eve::as<plf::polyfloat<double, 3>>());
  std::cout << "mxfl1 " << mxfl1 << std::endl;
  std::cout << "mxfl2 " << mxfl2 << std::endl;
  std::cout << "mxfl3 " << mxfl3 << std::endl;
  //   plf::_::println("double valmax               ", mxfl1);
  //   plf::_::println("polyfloat<double, 2> valmax ", mxfl2);
  //   plf::_::println("polyfloat<double, 3> valmax ", mxfl3);
  //   plf::_::println("double next(valmax)               ", plf::next(mxfl1));
  //   plf::_::println("polyfloat<double, 2> next(valmax) ", plf::next(mxfl2));
  //   plf::_::println("polyfloat<double, 3> next(valmax) ", plf::next(mxfl3));
  //   plf::_::println("double prev(valmax)               ", plf::prev(mxfl1));
  //   plf::_::println("polyfloat<double, 2> prev(valmax) ", plf::prev(mxfl2));
  //   plf::_::println("polyfloat<double, 3> prev(valmax) ", plf::prev(mxfl3));

  std::cout << "mxfl1/2 " << mxfl1 / 2 << std::endl;
  std::cout << "mxfl2/2 " << mxfl2 / 2 << std::endl;
  std::cout << "mxfl3/2 " << mxfl3 / 2 << std::endl;
  std::cout << "mxfl1/2+1 " << mxfl1 / 2 + 1 << std::endl;
  std::cout << "mxfl2/2+1 " << mxfl2 / 2 + 1 << std::endl;
  std::cout << "mxfl3/2+1 " << mxfl3 / 2 + 1 << std::endl;
}
