//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include <mpreal.h>
#include "../../mpfr_helpers.hpp"
#include <polyfloat/polyfloat.hpp>

template<typename aT> auto mk(auto mval, aT)
{
  mpfr::mpreal::set_default_prec(200);
  return tts::to_polyfloat(mval, aT());
} ;

int main()
{
  using  mpfr::mpreal;

  {
    std::cout << "T(" << std::hexfloat << mk(mpfr::exp(1), eve::as<float>()) << ")" << std::endl;
    std::cout << "T(" <<  std::hexfloat << mk(mpfr::exp(1), eve::as<double>()) << ")" << std::endl;
    std::cout << "T(" <<  std::hexfloat << mk(mpfr::exp(1), eve::as<plf::double_real_t<float>>()) << ")" << std::endl;
    std::cout << "T(" <<  std::hexfloat << mk(mpfr::exp(1), eve::as<plf::double_real_t<double>>()) << ")" << std::endl;
    std::cout << "T(" <<  std::hexfloat << mk(mpfr::exp(1), eve::as<plf::triple_real_t<float>>()) <<  ")" <<std::endl;
    std::cout << "T(" <<  std::hexfloat << mk(mpfr::exp(1), eve::as<plf::triple_real_t<double>>()) <<  ")" <<std::endl;

  }
  return 0;
};
