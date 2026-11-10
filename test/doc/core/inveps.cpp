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
  // The inverse of the machine epsilon of each type.
  using d1_t = double;
  using d2_t = plf::double_real_t<double>;
  using d3_t = plf::triple_real_t<double>;
  using f1_t = float;
  using f2_t = plf::double_real_t<float>;
  using f3_t = plf::triple_real_t<float>;
  using plf::inveps;
  std::cout << std::hexfloat;
  std::cout << "inveps(as<d1_t>()) = " << inveps(eve::as<d1_t>()) << std::endl;
  std::cout << "inveps(as<d2_t>()) = " << inveps(eve::as<d2_t>()) << std::endl;
  std::cout << "inveps(as<d3_t>()) = " << inveps(eve::as<d3_t>()) << std::endl;
  std::cout << "inveps(as<f1_t>()) = " << inveps(eve::as<f1_t>()) << std::endl;
  std::cout << "inveps(as<f2_t>()) = " << inveps(eve::as<f2_t>()) << std::endl;
  std::cout << "inveps(as<f3_t>()) = " << inveps(eve::as<f3_t>()) << std::endl;
}
