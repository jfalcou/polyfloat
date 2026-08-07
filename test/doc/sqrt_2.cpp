#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>
#include <polyfloat/details/printing.hpp>

int main()
{
  using  mpfr::mpreal;
  {
    using t1_t = double;
    using t2_t = plf::polyfloat<double, 2>;
    using t3_t = plf::polyfloat<double, 3>;

    mpfr::mpreal::set_default_prec(200);
    mpreal sqt2 = mpfr::sqrt(2);
    std::cout << std::hexfloat << std::endl;
    std::cout << plf::_::to_polyfloat(sqt2, eve::as(t1_t()))<< std::endl;
    std::cout << plf::_::to_polyfloat(sqt2, eve::as(t2_t()))<< std::endl;
    std::cout << plf::_::to_polyfloat(sqt2, eve::as(t3_t()))<< std::endl;
    std::cout << plf::sqrt_2(eve::as(t1_t()))<< std::endl;
    std::cout << plf::sqrt_2(eve::as(t2_t()))<< std::endl;
    std::cout << plf::sqrt_2(eve::as(t3_t()))<< std::endl;
    std::cout << plf::sqr(plf::sqrt_2(eve::as(t1_t())))<< std::endl;
    std::cout << plf::sqr(plf::sqrt_2(eve::as(t2_t())))<< std::endl;
    std::cout << plf::sqr(plf::sqrt_2(eve::as(t3_t())))<< std::endl;
  }

  {
    using t1_t = float;
    using t2_t = plf::polyfloat<float, 2>;
    using t3_t = plf::polyfloat<float, 3>;

    mpfr::mpreal::set_default_prec(200);
    mpreal sqt2 = mpfr::sqrt(2);
    std::cout << std::hexfloat << std::endl;
    std::cout << plf::_::to_polyfloat(sqt2, eve::as(t1_t()))<< std::endl;
    std::cout << plf::_::to_polyfloat(sqt2, eve::as(t2_t()))<< std::endl;
    std::cout << plf::_::to_polyfloat(sqt2, eve::as(t3_t()))<< std::endl;
    std::cout << plf::sqrt_2(eve::as(t1_t()))<< std::endl;
    std::cout << plf::sqrt_2(eve::as(t2_t()))<< std::endl;
    std::cout << plf::sqrt_2(eve::as(t3_t()))<< std::endl;
    std::cout << plf::sqr(plf::sqrt_2(eve::as(t1_t())))<< std::endl;
    std::cout << plf::sqr(plf::sqrt_2(eve::as(t2_t())))<< std::endl;
    std::cout << plf::sqr(plf::sqrt_2(eve::as(t3_t())))<< std::endl;
  }
}
