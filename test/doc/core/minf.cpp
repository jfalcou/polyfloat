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
  // Minus infinity in each type.
  using d1_t = double;
  using d2_t = plf::double_real_t<double>;
  using d3_t = plf::triple_real_t<double>;
  using f1_t = float;
  using f2_t = plf::double_real_t<float>;
  using f3_t = plf::triple_real_t<float>;
  using plf::minf;
  std::cout << "minf(as<d1_t>()) = " << minf(eve::as<d1_t>()) << std::endl;
  std::cout << "minf(as<d2_t>()) = " << minf(eve::as<d2_t>()) << std::endl;
  std::cout << "minf(as<d3_t>()) = " << minf(eve::as<d3_t>()) << std::endl;
  std::cout << "minf(as<f1_t>()) = " << minf(eve::as<f1_t>()) << std::endl;
  std::cout << "minf(as<f2_t>()) = " << minf(eve::as<f2_t>()) << std::endl;
  std::cout << "minf(as<f3_t>()) = " << minf(eve::as<f3_t>()) << std::endl;
}
