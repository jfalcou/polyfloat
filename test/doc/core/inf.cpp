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
  using d1_t = double;
  using d2_t = plf::double_real_t<double>;
  using d3_t = plf::triple_real_t<double>;
  using f1_t = float;
  using f2_t = plf::double_real_t<float>;
  using f3_t = plf::triple_real_t<float>;
  using plf::inf;
  std::cout << std::hexfloat;
  std::cout << "inf(<as<d1_t>()) = " << inf(eve::as<d1_t>()) << std::endl;
  std::cout << "inf(<as<d2_t>()) = " << inf(eve::as<d2_t>()) << std::endl;
  std::cout << "inf(<as<d3_t>()) = " << inf(eve::as<d3_t>()) << std::endl;
  std::cout << "inf(<as<f1_t>()) = " << inf(eve::as<f1_t>()) << std::endl;
  std::cout << "inf(<as<f2_t>()) = " << inf(eve::as<f2_t>()) << std::endl;
  std::cout << "inf(<as<f3_t>()) = " << inf(eve::as<f3_t>()) << std::endl;
  using wd1_t = eve::wide<double>;
  using wd2_t = eve::wide<plf::double_real_t<double>>;
  using wd3_t = eve::wide<plf::triple_real_t<double>>;
  using wf1_t = eve::wide<float>;
  using wf2_t = eve::wide<plf::double_real_t<float>>;
  using wf3_t = eve::wide<plf::triple_real_t<float>>;
  std::cout << std::hexfloat;
  std::cout << "inf(<as<wd1_t>()) = " << inf(eve::as<wd1_t>()) << std::endl;
  std::cout << "inf(<as<wd2_t>()) = " << inf(eve::as<wd2_t>()) << std::endl;
  std::cout << "inf(<as<wd3_t>()) = " << inf(eve::as<wd3_t>()) << std::endl;
  std::cout << "inf(<as<wf1_t>()) = " << inf(eve::as<wf1_t>()) << std::endl;
  std::cout << "inf(<as<wf2_t>()) = " << inf(eve::as<wf2_t>()) << std::endl;
  std::cout << "inf(<as<wf3_t>()) = " << inf(eve::as<wf3_t>()) << std::endl;
};
