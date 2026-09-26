//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include <polyfloat/polyfloat.hpp>
#include <iostream>

int main()
{
  using d1_t = double;
  using d2_t = plf::double_real_t<double>;
  using d3_t = plf::triple_real_t<double>;
  using f1_t = float;
  using f2_t = plf::double_real_t<float>;
  using f3_t = plf::triple_real_t<float>;
  using plf::egamma;
  std::cout << std::hexfloat;
  std::cout << "egamma(<as<d1_t>()) = " << egamma(eve::as<d1_t>()) << std::endl;
  std::cout << "egamma(<as<d2_t>()) = " << egamma(eve::as<d2_t>()) << std::endl;
  std::cout << "egamma(<as<d3_t>()) = " << egamma(eve::as<d3_t>()) << std::endl;
  std::cout << "egamma(<as<f1_t>()) = " << egamma(eve::as<f1_t>()) << std::endl;
  std::cout << "egamma(<as<f2_t>()) = " << egamma(eve::as<f2_t>()) << std::endl;
  std::cout << "egamma(<as<f3_t>()) = " << egamma(eve::as<f3_t>()) << std::endl;
};
