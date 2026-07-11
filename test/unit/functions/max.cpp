//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_TPL( "Check minus", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
  using pv_t  = plf::polyfloat<T, 2>;
  using wpv_t = eve::wide<pv_t, eve::fixed<2>>;
//   using wT    = eve::wide<T>;

  pv_t pva(1.0, 1.0e-300);
  pv_t pvb(-1.0, -1.0e-300);
  TTS_EQUAL(plf::max(pvb, pva), pva);
  wpv_t ab(pva, pvb);
  wpv_t ba(pvb, pva);
  wpv_t aa(pva, pva);
  TTS_EQUAL(plf::max(ab, ba), aa);
 //  std::cout << plf::maax(ab, ba) << std::endl;
//   std::cout << plf::is_ltz(ab) <<  std::endl;
//   std::cout << plf::minus[plf::is_ltz(ab)](ab) << std::endl;


};
