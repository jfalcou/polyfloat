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
  // The inverse of log 2 in each type.
  using d1_t = double;
  using d2_t = plf::double_real_t<double>;
  using d3_t = plf::triple_real_t<double>;
  using f1_t = float;
  using f2_t = plf::double_real_t<float>;
  using f3_t = plf::triple_real_t<float>;
  using plf::invlog_2;
  std::cout << std::hexfloat;
  std::cout << "invlog_2(as<d1_t>()) = " << invlog_2(eve::as<d1_t>()) << std::endl;
  std::cout << "invlog_2(as<d2_t>()) = " << invlog_2(eve::as<d2_t>()) << std::endl;
  std::cout << "invlog_2(as<d3_t>()) = " << invlog_2(eve::as<d3_t>()) << std::endl;
  std::cout << "invlog_2(as<f1_t>()) = " << invlog_2(eve::as<f1_t>()) << std::endl;
  std::cout << "invlog_2(as<f2_t>()) = " << invlog_2(eve::as<f2_t>()) << std::endl;
  std::cout << "invlog_2(as<f3_t>()) = " << invlog_2(eve::as<f3_t>()) << std::endl;
}
