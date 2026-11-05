#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>
#include <polyfloat/details/printing.hpp>

int main()
{
  using plf::hi;
  using plf::lo;
  using plf::md;
  std::cout << std::setprecision(16);
  auto mxfl1 = plf::valmin(eve::as<double>());
  auto mxfl2 = plf::valmin(eve::as<plf::polyfloat<double, 2>>());
  auto mxfl3 = plf::valmin(eve::as<plf::polyfloat<double, 3>>());
  std::cout << std::hexfloat << "mxfl1 " << mxfl1 << std::endl;
  std::cout << "mxfl2 " << mxfl2 << std::endl;
  std::cout << "mxfl3 " << mxfl3 << std::endl;

  //   plf::_::println("double valmin               ", mxfl1);
  //   plf::_::println("polyfloat<double, 2> valmin ", mxfl2);
  //   plf::_::println("polyfloat<double, 3> valmin ", mxfl3);
  //   plf::_::println("double next(valmin)               ", plf::next(mxfl1));
  //   plf::_::println("polyfloat<double, 2> next(valmin) ", plf::next(mxfl2));
  //   plf::_::println("polyfloat<double, 3> next(valmin) ", plf::next(mxfl3));
  //   plf::_::println("double prev(valmin)               ", plf::prev(mxfl1));
  //   plf::_::println("polyfloat<double, 2> prev(valmin) ", plf::prev(mxfl2));
  //   plf::_::println("polyfloat<double, 3> prev(valmin) ", plf::prev(mxfl3));

  std::cout << "mxfl1/2 " << mxfl1 / 2 << std::endl;
  std::cout << "mxfl2/2 " << mxfl2 / 2 << std::endl;
  std::cout << "mxfl3/2 " << mxfl3 / 2 << std::endl;
  std::cout << "mxfl1/2+1 " << mxfl1 / 2 + 1 << std::endl;
  std::cout << "mxfl2/2+1 " << mxfl2 / 2 + 1 << std::endl;
  std::cout << "mxfl3/2+1 " << mxfl3 / 2 + 1 << std::endl;
}
