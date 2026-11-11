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
  // The mantissa bits of each type, the implicit bits included.
  using d1_t = double;
  using d2_t = plf::double_real_t<double>;
  using d3_t = plf::triple_real_t<double>;
  using f1_t = float;
  using f2_t = plf::double_real_t<float>;
  using f3_t = plf::triple_real_t<float>;
  using plf::effective_mantissa_bits;
  std::cout << "effective_mantissa_bits(as<d1_t>()) = " << effective_mantissa_bits(eve::as<d1_t>()) << std::endl;
  std::cout << "effective_mantissa_bits(as<d2_t>()) = " << effective_mantissa_bits(eve::as<d2_t>()) << std::endl;
  std::cout << "effective_mantissa_bits(as<d3_t>()) = " << effective_mantissa_bits(eve::as<d3_t>()) << std::endl;
  std::cout << "effective_mantissa_bits(as<f1_t>()) = " << effective_mantissa_bits(eve::as<f1_t>()) << std::endl;
  std::cout << "effective_mantissa_bits(as<f2_t>()) = " << effective_mantissa_bits(eve::as<f2_t>()) << std::endl;
  std::cout << "effective_mantissa_bits(as<f3_t>()) = " << effective_mantissa_bits(eve::as<f3_t>()) << std::endl;
}
