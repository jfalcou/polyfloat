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
  using plf::catalan;
  std::cout << std::hexfloat;
  std::cout << "catalan(<as<d1_t>()) = " << catalan(eve::as<d1_t>()) << std::endl;
  std::cout << "catalan(<as<d2_t>()) = " << catalan(eve::as<d2_t>()) << std::endl;
  std::cout << "catalan(<as<d3_t>()) = " << catalan(eve::as<d3_t>()) << std::endl;
  std::cout << "catalan(<as<f1_t>()) = " << catalan(eve::as<f1_t>()) << std::endl;
  std::cout << "catalan(<as<f2_t>()) = " << catalan(eve::as<f2_t>()) << std::endl;
  std::cout << "catalan(<as<f3_t>()) = " << catalan(eve::as<f3_t>()) << std::endl;
};
