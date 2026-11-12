#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // The expected components come from mpmath at 600 bits, each rounded to nearest.
  {
    using t1_t = double;
    using t2_t = plf::polyfloat<double, 2>;
    using t3_t = plf::polyfloat<double, 3>;

    std::cout << std::hexfloat << std::endl;
    std::cout << "expected 0x1.6a09e667f3bcdp+0" << std::endl;
    std::cout << "sqrt_2   " << plf::sqrt_2(eve::as(t1_t())) << std::endl;
    std::cout << "expected 0x1.6a09e667f3bcdp+0 - 0x1.bdd3413b26456p-54" << std::endl;
    std::cout << "sqrt_2   " << plf::sqrt_2(eve::as(t2_t())) << std::endl;
    std::cout << "expected 0x1.6a09e667f3bcdp+0 - 0x1.bdd3413b26456p-54 + 0x1.57d3e3adec175p-108" << std::endl;
    std::cout << "sqrt_2   " << plf::sqrt_2(eve::as(t3_t())) << std::endl;
    std::cout << plf::sqr(plf::sqrt_2(eve::as(t1_t()))) << std::endl;
    std::cout << plf::sqr(plf::sqrt_2(eve::as(t2_t()))) << std::endl;
    std::cout << plf::sqr(plf::sqrt_2(eve::as(t3_t()))) << std::endl;
  }

  {
    using t1_t = float;
    using t2_t = plf::polyfloat<float, 2>;
    using t3_t = plf::polyfloat<float, 3>;

    std::cout << std::hexfloat << std::endl;
    std::cout << "expected 0x1.6a09e6p+0" << std::endl;
    std::cout << "sqrt_2   " << plf::sqrt_2(eve::as(t1_t())) << std::endl;
    std::cout << "expected 0x1.6a09e6p+0 + 0x1.9fcef4p-26" << std::endl;
    std::cout << "sqrt_2   " << plf::sqrt_2(eve::as(t2_t())) << std::endl;
    std::cout << "expected 0x1.6a09e6p+0 + 0x1.9fcef4p-26 - 0x1.b7ba68p-51" << std::endl;
    std::cout << "sqrt_2   " << plf::sqrt_2(eve::as(t3_t())) << std::endl;
    std::cout << plf::sqr(plf::sqrt_2(eve::as(t1_t()))) << std::endl;
    std::cout << plf::sqr(plf::sqrt_2(eve::as(t2_t()))) << std::endl;
    std::cout << plf::sqr(plf::sqrt_2(eve::as(t3_t()))) << std::endl;
  }
}
