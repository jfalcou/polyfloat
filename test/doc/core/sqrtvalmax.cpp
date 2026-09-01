#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>
#include <polyfloat/details/printing.hpp>

int main()
{
  //  using  mpfr::mpreal;
  //   using  plf::_::to_mpreal;
  //   {
  //     using t1_t = double;
  //     using t2_t = plf::polyfloat<double, 2>;
  //     using t3_t = plf::polyfloat<double, 3>;

  //     mpfr::mpreal::set_default_prec(200);
  //     mpreal lvalmax1 = mpfr::sqrt(to_mpreal(plf::valmax(eve::as<t1_t>())));
  //     mpreal lvalmax2 = mpfr::sqrt(to_mpreal(plf::valmax(eve::as<t2_t>())));
  //     mpreal lvalmax3 = mpfr::sqrt(to_mpreal(plf::valmax(eve::as<t3_t>())));
  //     std::cout << std::hexfloat << std::endl;
  //     std::cout << eve::sqrtvalmax(eve::as<double>())<< std::endl;
  //     std::cout << plf::_::to_polyfloat(lvalmax1, eve::as(t1_t()))<< std::endl;
  //     std::cout << plf::_::to_polyfloat(lvalmax2, eve::as(t2_t()))<< std::endl;
  //     std::cout << plf::_::to_polyfloat(lvalmax3, eve::as(t3_t()))<< std::endl;
  //   }
  //   {
  //     using t1_t = float;
  //     using t2_t = plf::polyfloat<float, 2>;
  //     using t3_t = plf::polyfloat<float, 3>;

  //     mpfr::mpreal::set_default_prec(200);
  //     mpreal lvalmax1 = mpfr::sqrt(to_mpreal(plf::valmax(eve::as<t1_t>())));
  //     mpreal lvalmax2 = mpfr::sqrt(to_mpreal(plf::valmax(eve::as<t2_t>())));
  //     mpreal lvalmax3 = mpfr::sqrt(to_mpreal(plf::valmax(eve::as<t3_t>())));
  //     std::cout << std::hexfloat << std::endl;
  //     std::cout << eve::sqrtvalmax(eve::as<float>())<< std::endl;
  //     std::cout << plf::_::to_polyfloat(lvalmax1, eve::as(t1_t()))<< std::endl;
  //     std::cout << plf::_::to_polyfloat(lvalmax2, eve::as(t2_t()))<< std::endl;
  //     std::cout << plf::_::to_polyfloat(lvalmax3, eve::as(t3_t()))<< std::endl;
  //   }

  {
    std::cout << std::hexfloat;
    auto mxfl1 = plf::sqrtvalmax(eve::as<double>());
    auto mxfl2 = plf::sqrtvalmax(eve::as<plf::polyfloat<double, 2>>());
    auto mxfl3 = plf::sqrtvalmax(eve::as<plf::polyfloat<double, 3>>());
    std::cout << "mxfl1 " << mxfl1 << std::endl;
    std::cout << "mxfl2 " << mxfl2 << std::endl;
    std::cout << "mxfl3 " << mxfl3 << std::endl;
  }
  {
    std::cout << std::hexfloat;
    auto mxfl1 = plf::sqrtvalmax(eve::as<float>());
    auto mxfl2 = plf::sqrtvalmax(eve::as<plf::polyfloat<float, 2>>());
    auto mxfl3 = plf::sqrtvalmax(eve::as<plf::polyfloat<float, 3>>());
    std::cout << "mxfl1 " << mxfl1 << std::endl;
    std::cout << "mxfl2 " << mxfl2 << std::endl;
    std::cout << "mxfl3 " << mxfl3 << std::endl;
  }
}
