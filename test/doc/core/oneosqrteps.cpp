#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // Each expected value rounds 1/sqrt(plf::eps) to nearest part by part, from mpmath at 600 bits.
  {
    using t1_t = double;
    using t2_t = plf::polyfloat<double, 2>;
    using t3_t = plf::polyfloat<double, 3>;

    std::cout << std::hexfloat << std::endl;
    std::cout << "expected    0x1p+26" << std::endl;
    std::cout << "oneosqrteps " << plf::oneosqrteps(eve::as<t1_t>()) << std::endl;
    std::cout << "expected    0x1p+52" << std::endl;
    std::cout << "oneosqrteps " << plf::oneosqrteps(eve::as<t2_t>()) << std::endl;
    std::cout << "expected    0x1p+78" << std::endl;
    std::cout << "oneosqrteps " << plf::oneosqrteps(eve::as<t3_t>()) << std::endl;
  }
  {
    using t1_t = float;
    using t2_t = plf::polyfloat<float, 2>;
    using t3_t = plf::polyfloat<float, 3>;

    std::cout << std::hexfloat << std::endl;
    std::cout << "expected    0x1.6a09e6p+11" << std::endl;
    std::cout << "oneosqrteps " << plf::oneosqrteps(eve::as<t1_t>()) << std::endl;
    std::cout << "expected    0x1p+23" << std::endl;
    std::cout << "oneosqrteps " << plf::oneosqrteps(eve::as<t2_t>()) << std::endl;
    std::cout << "expected    0x1.6a09e667f3bcc908b3p+34" << std::endl;
    std::cout << "oneosqrteps " << plf::oneosqrteps(eve::as<t3_t>()) << std::endl;
  }
}
