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
  using plf::four_pio_3;
  std::cout << std::hexfloat;
  std::cout << "four_pio_3(<as<d1_t>()) = " << four_pio_3(eve::as<d1_t>()) << std::endl;
  std::cout << "four_pio_3(<as<d2_t>()) = " << four_pio_3(eve::as<d2_t>()) << std::endl;
  std::cout << "four_pio_3(<as<d3_t>()) = " << four_pio_3(eve::as<d3_t>()) << std::endl;
  std::cout << "four_pio_3(<as<f1_t>()) = " << four_pio_3(eve::as<f1_t>()) << std::endl;
  std::cout << "four_pio_3(<as<f2_t>()) = " << four_pio_3(eve::as<f2_t>()) << std::endl;
  std::cout << "four_pio_3(<as<f3_t>()) = " << four_pio_3(eve::as<f3_t>()) << std::endl;
};
