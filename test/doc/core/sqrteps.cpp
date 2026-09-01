#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>
#include <polyfloat/details/printing.hpp>

int main()
{
  using mpfr::mpreal;
  {
    using t1_t = double;
    using t2_t = plf::polyfloat<double, 2>;
    using t3_t = plf::polyfloat<double, 3>;

    std::cout << std::hexfloat << std::endl;
    std::cout << std::hexfloat << std::endl;
    std::cout << plf::sqrteps(eve::as(t1_t())) << std::endl;
    std::cout << plf::sqrteps(eve::as(t2_t())) << std::endl;
    std::cout << plf::sqrteps(eve::as(t3_t())) << std::endl;
    std::cout << plf::sqrt(plf::eps(eve::as(t1_t()))) << std::endl;
    std::cout << plf::sqrt(plf::eps(eve::as(t2_t()))) << std::endl;
    std::cout << plf::sqrt(plf::eps(eve::as(t3_t()))) << std::endl;
  }

  {
    using t1_t = float;
    using t2_t = plf::polyfloat<float, 2>;
    using t3_t = plf::polyfloat<float, 3>;

    std::cout << std::hexfloat << std::endl;
    std::cout << plf::sqrteps(eve::as(t1_t())) << std::endl;
    std::cout << plf::sqrteps(eve::as(t2_t())) << std::endl;
    std::cout << plf::sqrteps(eve::as(t3_t())) << std::endl;
    std::cout << plf::sqrt(plf::eps(eve::as(t1_t()))) << std::endl;
    std::cout << plf::sqrt(plf::eps(eve::as(t2_t()))) << std::endl;
    std::cout << plf::sqrt(plf::eps(eve::as(t3_t()))) << std::endl;
  }
}
