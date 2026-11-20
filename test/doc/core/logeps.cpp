#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // Each expected value rounds log(plf::eps) to nearest part by part, from mpmath at 600 bits.
  {
    using t1_t = double;
    using t2_t = plf::polyfloat<double, 2>;
    using t3_t = plf::polyfloat<double, 3>;

    std::cout << std::hexfloat << std::endl;
    std::cout << "expected -0x1.205966f2b4f12p+5" << std::endl;
    std::cout << "logeps   " << plf::logeps(eve::as<t1_t>()) << std::endl;
    std::cout << "expected -0x1.205966f2b4f125b7281203d7068p+6" << std::endl;
    std::cout << "logeps   " << plf::logeps(eve::as<t2_t>()) << std::endl;
    std::cout << "expected -0x1.b0861a6c0f69b892bc1b05c289a0394b2e50f3aep+6" << std::endl;
    std::cout << "logeps   " << plf::logeps(eve::as<t3_t>()) << std::endl;
  }
  {
    using t1_t = float;
    using t2_t = plf::polyfloat<float, 2>;
    using t3_t = plf::polyfloat<float, 3>;

    std::cout << std::hexfloat << std::endl;
    std::cout << "expected -0x1.fe2804p+3" << std::endl;
    std::cout << "logeps   " << plf::logeps(eve::as<t1_t>()) << std::endl;
    std::cout << "expected -0x1.fe2804e87b34p+4" << std::endl;
    std::cout << "logeps   " << plf::logeps(eve::as<t2_t>()) << std::endl;
    std::cout << "expected -0x1.7e9e03ae5c675e5a6b4p+5" << std::endl;
    std::cout << "logeps   " << plf::logeps(eve::as<t3_t>()) << std::endl;
  }
}
