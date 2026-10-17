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
  using plf::tan;
  using d1_t = double;
  using d2_t = plf::double_real_t<double>;
  using d3_t = plf::triple_real_t<double>;
  auto a = plf::pio_6(eve::as<double>());
  std::cout << a << std::endl;
  std::cout << "d1_t " << plf::tan[eve::medium](d1_t(a)) << std::endl;
  std::cout << "d2_t " << plf::tan[eve::medium](d2_t(a)) << std::endl;
  std::cout << "d3_t " << plf::tan[eve::medium](d3_t(a)) << std::endl;
};
