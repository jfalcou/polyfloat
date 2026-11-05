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
  auto mnfl1 = plf::valmin(eve::as<double>());
  auto mnfl2 = plf::valmin(eve::as<plf::polyfloat<double, 2>>());
  auto mnfl3 = plf::valmin(eve::as<plf::polyfloat<double, 3>>());
  std::cout << std::hexfloat << "mnfl1 " << mnfl1 << std::endl;
  std::cout << "mnfl2 " << mnfl2 << std::endl;
  std::cout << "mnfl3 " << mnfl3 << std::endl;
  std::cout << "is_morn 2  " << plf::_::inner_is_normalized(hi(mnfl2), lo(mnfl2)) << std::endl;
  std::cout << "is_morn 3  " << plf::_::inner_is_normalized(hi(mnfl3), md(mnfl3), lo(mnfl3)) << std::endl;

  //   plf::_::println("double valmin               ", mnfl1);
  //   plf::_::println("polyfloat<double, 2> valmin ", mnfl2);
  //   plf::_::println("polyfloat<double, 3> valmin ", mnfl3);
  //   plf::_::println("double next(valmin)               ", plf::next(mnfl1));
  //   plf::_::println("polyfloat<double, 2> next(valmin) ", plf::next(mnfl2));
  //   plf::_::println("polyfloat<double, 3> next(valmin) ", plf::next(mnfl3));
  //   plf::_::println("double prev(valmin)               ", plf::prev(mnfl1));
  //   plf::_::println("polyfloat<double, 2> prev(valmin) ", plf::prev(mnfl2));
  //   plf::_::println("polyfloat<double, 3> prev(valmin) ", plf::prev(mnfl3));

  std::cout << "mnfl1/2 " << mnfl1 / 2 << std::endl;
  std::cout << "mnfl2/2 " << mnfl2 / 2 << std::endl;
  std::cout << "mnfl3/2 " << mnfl3 / 2 << std::endl;
  std::cout << "mnfl1/2+1 " << mnfl1 / 2 + 1 << std::endl;
  std::cout << "mnfl2/2+1 " << mnfl2 / 2 + 1 << std::endl;
  std::cout << "mnfl3/2+1 " << mnfl3 / 2 + 1 << std::endl;
}
