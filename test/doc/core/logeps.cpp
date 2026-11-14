#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // The expected components are log(plf::eps) from mpmath at 600 bits, each rounded to nearest.
  {
    using t1_t = double;
    using t2_t = plf::polyfloat<double, 2>;
    using t3_t = plf::polyfloat<double, 3>;

    std::cout << std::hexfloat << std::endl;
    std::cout << "expected -0x1.205966f2b4f12p+5" << std::endl;
    std::cout << "logeps   " << plf::logeps(eve::as<t1_t>()) << std::endl;
    std::cout << "expected -0x1.205966f2b4f12p+6 - 0x1.6dca0480f5c1ap-48" << std::endl;
    std::cout << "logeps   " << plf::logeps(eve::as<t2_t>()) << std::endl;
    std::cout << "expected -0x1.b0861a6c0f69cp+6 + 0x1.db50f93e8f5d9p-48 + 0x1.fc6b4d1af0c52p-102" << std::endl;
    std::cout << "logeps   " << plf::logeps(eve::as<t3_t>()) << std::endl;
  }
  {
    using t1_t = float;
    using t2_t = plf::polyfloat<float, 2>;
    using t3_t = plf::polyfloat<float, 3>;

    std::cout << std::hexfloat << std::endl;
    std::cout << "expected -0x1.fe2804p+3" << std::endl;
    std::cout << "logeps   " << plf::logeps(eve::as<t1_t>()) << std::endl;
    std::cout << "expected -0x1.0a2b24p+5 + 0x1.88a91ap-24" << std::endl;
    std::cout << "logeps   " << plf::logeps(eve::as<t2_t>()) << std::endl;
    std::cout << "expected -0x1.8f40b6p+5 + 0x1.267ed2p-23 + 0x1.c7af38p-48" << std::endl;
    std::cout << "logeps   " << plf::logeps(eve::as<t3_t>()) << std::endl;
  }
}
