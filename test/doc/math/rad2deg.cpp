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
  using plf::rad2deg;
  std::cout << std::hexfloat;
  std::cout << "rad2deg(<as<d1_t>()) = " << rad2deg(eve::as<d1_t>()) << std::endl;
  std::cout << "rad2deg(<as<d2_t>()) = " << rad2deg(eve::as<d2_t>()) << std::endl;
  std::cout << "rad2deg(<as<d3_t>()) = " << rad2deg(eve::as<d3_t>()) << std::endl;
  std::cout << "rad2deg(<as<f1_t>()) = " << rad2deg(eve::as<f1_t>()) << std::endl;
  std::cout << "rad2deg(<as<f2_t>()) = " << rad2deg(eve::as<f2_t>()) << std::endl;
  std::cout << "rad2deg(<as<f3_t>()) = " << rad2deg(eve::as<f3_t>()) << std::endl;
};
