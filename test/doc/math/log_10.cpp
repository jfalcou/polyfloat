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
  // log 10 in each type.
  using d1_t = double;
  using d2_t = plf::double_real_t<double>;
  using d3_t = plf::triple_real_t<double>;
  using f1_t = float;
  using f2_t = plf::double_real_t<float>;
  using f3_t = plf::triple_real_t<float>;
  using plf::log_10;
  std::cout << std::hexfloat;
  std::cout << "log_10(as<d1_t>()) = " << log_10(eve::as<d1_t>()) << std::endl;
  std::cout << "log_10(as<d2_t>()) = " << log_10(eve::as<d2_t>()) << std::endl;
  std::cout << "log_10(as<d3_t>()) = " << log_10(eve::as<d3_t>()) << std::endl;
  std::cout << "log_10(as<f1_t>()) = " << log_10(eve::as<f1_t>()) << std::endl;
  std::cout << "log_10(as<f2_t>()) = " << log_10(eve::as<f2_t>()) << std::endl;
  std::cout << "log_10(as<f3_t>()) = " << log_10(eve::as<f3_t>()) << std::endl;
}
