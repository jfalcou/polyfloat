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
  // The constant e in each type.
  using d1_t = double;
  using d2_t = plf::double_real_t<double>;
  using d3_t = plf::triple_real_t<double>;
  using f1_t = float;
  using f2_t = plf::double_real_t<float>;
  using f3_t = plf::triple_real_t<float>;
  using plf::euler;
  std::cout << std::hexfloat;
  std::cout << "euler(as<d1_t>()) = " << euler(eve::as<d1_t>()) << std::endl;
  std::cout << "euler(as<d2_t>()) = " << euler(eve::as<d2_t>()) << std::endl;
  std::cout << "euler(as<d3_t>()) = " << euler(eve::as<d3_t>()) << std::endl;
  std::cout << "euler(as<f1_t>()) = " << euler(eve::as<f1_t>()) << std::endl;
  std::cout << "euler(as<f2_t>()) = " << euler(eve::as<f2_t>()) << std::endl;
  std::cout << "euler(as<f3_t>()) = " << euler(eve::as<f3_t>()) << std::endl;
}
