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
  using plf::radinpi;
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
  std::cout << "radinpi(d1_t(xd)) = " << radinpi(d1_t(xd)) << std::endl;
  std::cout << "radinpi(d2_t(xd)) = " << radinpi(d2_t(xd)) << std::endl;
  std::cout << "radinpi(d3_t(xd)) = " << radinpi(d3_t(xd)) << std::endl;
  std::cout << "radinpi(f1_t(xf)) = " << radinpi(f1_t(xf)) << std::endl;
  std::cout << "radinpi(f2_t(xf)) = " << radinpi(f2_t(xf)) << std::endl;
  std::cout << "radinpi(f3_t(xf)) = " << radinpi(f3_t(xf)) << std::endl;
};
