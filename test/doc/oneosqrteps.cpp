#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>
#include <polyfloat/details/printing.hpp>

int main()
{
  using  mpfr::mpreal;
  using  plf::_::to_mpreal;
  {
    using t1_t = double;
    using t2_t = plf::polyfloat<double, 2>;
    using t3_t = plf::polyfloat<double, 3>;

    mpfr::mpreal::set_default_prec(200);
    mpreal leps1 = 1/mpfr::sqrt(to_mpreal(plf::eps(eve::as<t1_t>())));
    mpreal leps2 = 1/mpfr::sqrt(to_mpreal(plf::eps(eve::as<t2_t>())));
    mpreal leps3 = 1/mpfr::sqrt(to_mpreal(plf::eps(eve::as<t3_t>())));
    std::cout << std::hexfloat << std::endl;
    std::cout << eve::oneosqrteps(eve::as<double>())<< std::endl;
    std::cout << plf::_::to_polyfloat(leps1, eve::as(t1_t()))<< std::endl;
    std::cout << plf::_::to_polyfloat(leps2, eve::as(t2_t()))<< std::endl;
    std::cout << plf::_::to_polyfloat(leps3, eve::as(t3_t()))<< std::endl;
  }
  {
    using t1_t = float;
    using t2_t = plf::polyfloat<float, 2>;
    using t3_t = plf::polyfloat<float, 3>;

    mpfr::mpreal::set_default_prec(200);
    mpreal leps1 = 1/mpfr::sqrt(to_mpreal(plf::eps(eve::as<t1_t>())));
    mpreal leps2 = 1/mpfr::sqrt(to_mpreal(plf::eps(eve::as<t2_t>())));
    mpreal leps3 = 1/mpfr::sqrt(to_mpreal(plf::eps(eve::as<t3_t>())));
    std::cout << std::hexfloat << std::endl;
    std::cout << eve::oneosqrteps(eve::as<float>())<< std::endl;
    std::cout << plf::_::to_polyfloat(leps1, eve::as(t1_t()))<< std::endl;
    std::cout << plf::_::to_polyfloat(leps2, eve::as(t2_t()))<< std::endl;
    std::cout << plf::_::to_polyfloat(leps3, eve::as(t3_t()))<< std::endl;
  }
}
