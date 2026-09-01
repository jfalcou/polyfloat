#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>
#include <polyfloat/details/printing.hpp>

int main()
{
  std::cout << std::setprecision(16);
  using t1_t = double;
  using t2_t = plf::double_real_t<double>;
  using t3_t = plf::triple_real_t<double>;
  using at1_t = eve::as<t1_t>;
  using at2_t = eve::as<t2_t>;
  using at3_t = eve::as<t3_t>;

  std::cout << plf::inf(at1_t()) << std::endl;
  std::cout << plf::inf(at2_t()) << std::endl;
  std::cout << plf::inf(at3_t()) << std::endl;
  std::cout << plf::minf(at3_t()) << std::endl;
  std::cout << plf::minf(at2_t()) << std::endl;
  std::cout << plf::minf(at3_t()) << std::endl;
  std::cout << plf::inf(at3_t()) << std::endl;
  //   std::cout << plf::allbits(at3_t()) << std::endl;
  //   std::cout << plf::allbits(at2_t()) << std::endl;
  //   std::cout << plf::allbits(at3_t()) << std::endl;
  std::cout << plf::nan(at3_t()) << std::endl;
  std::cout << plf::nan(at2_t()) << std::endl;
  std::cout << plf::nan(at3_t()) << std::endl;
  std::cout << plf::mhalf(at3_t()) << std::endl;
  std::cout << plf::mhalf(at2_t()) << std::endl;
  std::cout << plf::mhalf(at3_t()) << std::endl;
  std::cout << plf::one(at3_t()) << std::endl;
  std::cout << plf::one(at2_t()) << std::endl;
  std::cout << plf::one(at3_t()) << std::endl;
  std::cout << plf::mone(at3_t()) << std::endl;
  std::cout << plf::mone(at2_t()) << std::endl;
  std::cout << plf::mone(at3_t()) << std::endl;
}
