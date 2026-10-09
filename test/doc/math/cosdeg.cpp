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
  using plf::cos;
  using d1_t = double;
  using d2_t = plf::double_real_t<double>;
  using d3_t = plf::triple_real_t<double>;
  using eve::deg;
  std::cout << "d1_t " << plf::cos[deg](d1_t(30.0)) << std::endl;
  std::cout << "d2_t " << plf::cos[deg](d2_t(30.0)) << std::endl;
  std::cout << "d3_t " << plf::cos[deg](d3_t(30.0)) << std::endl;
};
