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
  // The largest argument of a finite base 2 exponential in each type.
  using d1_t = double;
  using d2_t = plf::double_real_t<double>;
  using d3_t = plf::triple_real_t<double>;
  using f1_t = float;
  using f2_t = plf::double_real_t<float>;
  using f3_t = plf::triple_real_t<float>;
  using plf::maxlog2;
  std::cout << std::hexfloat;
  std::cout << "maxlog2(as<d1_t>()) = " << maxlog2(eve::as<d1_t>()) << std::endl;
  std::cout << "maxlog2(as<d2_t>()) = " << maxlog2(eve::as<d2_t>()) << std::endl;
  std::cout << "maxlog2(as<d3_t>()) = " << maxlog2(eve::as<d3_t>()) << std::endl;
  std::cout << "maxlog2(as<f1_t>()) = " << maxlog2(eve::as<f1_t>()) << std::endl;
  std::cout << "maxlog2(as<f2_t>()) = " << maxlog2(eve::as<f2_t>()) << std::endl;
  std::cout << "maxlog2(as<f3_t>()) = " << maxlog2(eve::as<f3_t>()) << std::endl;
}
