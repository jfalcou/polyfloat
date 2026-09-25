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
  using plf::cos_1;
  std::cout << std::hexfloat;
  std::cout << "cos_1(<as<d1_t>()) = " << cos_1(eve::as<d1_t>()) << std::endl;
  std::cout << "cos_1(<as<d2_t>()) = " << cos_1(eve::as<d2_t>()) << std::endl;
  std::cout << "cos_1(<as<d3_t>()) = " << cos_1(eve::as<d3_t>()) << std::endl;
  std::cout << "cos_1(<as<f1_t>()) = " << cos_1(eve::as<f1_t>()) << std::endl;
  std::cout << "cos_1(<as<f2_t>()) = " << cos_1(eve::as<f2_t>()) << std::endl;
  std::cout << "cos_1(<as<f3_t>()) = " << cos_1(eve::as<f3_t>()) << std::endl;
};
