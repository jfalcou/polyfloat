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
  using plf::div_180;
  using d1_t = double;
  using d2_t = plf::double_real_t<double>;
  using d3_t = plf::triple_real_t<double>;
  using f1_t = float;
  using f2_t = plf::double_real_t<float>;
  using f3_t = plf::triple_real_t<float>;

  f1_t xf(1.5f);
  d1_t xd(1.5);
  std::cout << std::hexfloat;
  std::cout << "xf " << xf << std::endl;
  std::cout << "xd " << xd << std::endl;
  std::cout << "div_180(d1_t(xd)) = " << div_180(d1_t(xd)) << std::endl;
  std::cout << "div_180(d2_t(xd)) = " << div_180(d2_t(xd)) << std::endl;
  std::cout << "div_180(d3_t(xd)) = " << div_180(d3_t(xd)) << std::endl;
  std::cout << "div_180(f1_t(xf)) = " << div_180(f1_t(xf)) << std::endl;
  std::cout << "div_180(f2_t(xf)) = " << div_180(f2_t(xf)) << std::endl;
  std::cout << "div_180(f3_t(xf)) = " << div_180(f3_t(xf)) << std::endl;
};
