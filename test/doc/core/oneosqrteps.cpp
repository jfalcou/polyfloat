#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // The expected components are 1/sqrt(plf::eps) from mpmath at 600 bits, each rounded to nearest.
  {
    using t1_t = double;
    using t2_t = plf::polyfloat<double, 2>;
    using t3_t = plf::polyfloat<double, 3>;

    std::cout << std::hexfloat << std::endl;
    std::cout << "expected    0x1p+26" << std::endl;
    std::cout << "oneosqrteps " << plf::oneosqrteps(eve::as<t1_t>()) << std::endl;
    std::cout << "expected    0x1p+52 + 0x0p+0" << std::endl;
    std::cout << "oneosqrteps " << plf::oneosqrteps(eve::as<t2_t>()) << std::endl;
    std::cout << "expected    0x1p+78 + 0x0p+0 + 0x0p+0" << std::endl;
    std::cout << "oneosqrteps " << plf::oneosqrteps(eve::as<t3_t>()) << std::endl;
  }
  {
    using t1_t = float;
    using t2_t = plf::polyfloat<float, 2>;
    using t3_t = plf::polyfloat<float, 3>;

    std::cout << std::hexfloat << std::endl;
    std::cout << "expected    0x1.6a09e6p+11" << std::endl;
    std::cout << "oneosqrteps " << plf::oneosqrteps(eve::as<t1_t>()) << std::endl;
    std::cout << "expected    0x1p+24 + 0x0p+0" << std::endl;
    std::cout << "oneosqrteps " << plf::oneosqrteps(eve::as<t2_t>()) << std::endl;
    std::cout << "expected    0x1p+36 + 0x0p+0 + 0x0p+0" << std::endl;
    std::cout << "oneosqrteps " << plf::oneosqrteps(eve::as<t3_t>()) << std::endl;
  }
}
