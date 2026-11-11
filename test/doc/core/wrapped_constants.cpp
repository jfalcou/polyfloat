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
  // Each constant takes the type of its result, here a value of dimension 2 and a register of dimension 3.
  using d2_t = plf::double_real_t<double>;
  using wf3_t = eve::wide<plf::triple_real_t<float>>;
  std::cout << std::hexfloat;
  std::cout << "allbits        " << plf::allbits(eve::as<d2_t>()) << std::endl;
  std::cout << "bitincrement   " << plf::bitincrement(eve::as<d2_t>()) << std::endl;
  std::cout << "half           " << plf::half(eve::as<d2_t>()) << std::endl;
  std::cout << "maxexponent    " << plf::maxexponent(eve::as<d2_t>()) << std::endl;
  std::cout << "maxexponentm1  " << plf::maxexponentm1(eve::as<d2_t>()) << std::endl;
  std::cout << "maxexponentp1  " << plf::maxexponentp1(eve::as<d2_t>()) << std::endl;
  std::cout << "mhalf          " << plf::mhalf(eve::as<d2_t>()) << std::endl;
  std::cout << "mindenormal    " << plf::mindenormal(eve::as<d2_t>()) << std::endl;
  std::cout << "minexponent    " << plf::minexponent(eve::as<d2_t>()) << std::endl;
  std::cout << "mone           " << plf::mone(eve::as<d2_t>()) << std::endl;
  std::cout << "mzero          " << plf::mzero(eve::as<d2_t>()) << std::endl;
  std::cout << "one            " << plf::one(eve::as<d2_t>()) << std::endl;
  std::cout << "smallestposval " << plf::smallestposval(eve::as<d2_t>()) << std::endl;
  std::cout << "zero           " << plf::zero(eve::as<d2_t>()) << std::endl;
  std::cout << "false_         " << plf::false_(eve::as<d2_t>()) << std::endl;
  std::cout << "true_          " << plf::true_(eve::as<d2_t>()) << std::endl;
  std::cout << "one, register  " << plf::one(eve::as<wf3_t>()) << std::endl;
}
