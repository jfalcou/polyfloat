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
  // The stored mantissa bits of each type.
  using d1_t = double;
  using d2_t = plf::double_real_t<double>;
  using d3_t = plf::triple_real_t<double>;
  using f1_t = float;
  using f2_t = plf::double_real_t<float>;
  using f3_t = plf::triple_real_t<float>;
  using plf::nbmantissabits;
  std::cout << "nbmantissabits(as<d1_t>()) = " << nbmantissabits(eve::as<d1_t>()) << std::endl;
  std::cout << "nbmantissabits(as<d2_t>()) = " << nbmantissabits(eve::as<d2_t>()) << std::endl;
  std::cout << "nbmantissabits(as<d3_t>()) = " << nbmantissabits(eve::as<d3_t>()) << std::endl;
  std::cout << "nbmantissabits(as<f1_t>()) = " << nbmantissabits(eve::as<f1_t>()) << std::endl;
  std::cout << "nbmantissabits(as<f2_t>()) = " << nbmantissabits(eve::as<f2_t>()) << std::endl;
  std::cout << "nbmantissabits(as<f3_t>()) = " << nbmantissabits(eve::as<f3_t>()) << std::endl;
}
