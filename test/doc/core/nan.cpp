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
  // A quiet NaN in each type.
  using d1_t = double;
  using d2_t = plf::double_real_t<double>;
  using d3_t = plf::triple_real_t<double>;
  using f1_t = float;
  using f2_t = plf::double_real_t<float>;
  using f3_t = plf::triple_real_t<float>;
  using plf::nan;
  std::cout << "nan(as<d1_t>()) = " << nan(eve::as<d1_t>()) << std::endl;
  std::cout << "nan(as<d2_t>()) = " << nan(eve::as<d2_t>()) << std::endl;
  std::cout << "nan(as<d3_t>()) = " << nan(eve::as<d3_t>()) << std::endl;
  std::cout << "nan(as<f1_t>()) = " << nan(eve::as<f1_t>()) << std::endl;
  std::cout << "nan(as<f2_t>()) = " << nan(eve::as<f2_t>()) << std::endl;
  std::cout << "nan(as<f3_t>()) = " << nan(eve::as<f3_t>()) << std::endl;
}
