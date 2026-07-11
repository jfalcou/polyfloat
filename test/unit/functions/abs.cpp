//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

//==================================================================================================
// Types tests
//==================================================================================================
TTS_CASE_TPL( "Check abs", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
  using pv_t  = plf::polyfloat<T, 2>;
//  using wpv_t = eve::wide<pv_t>;
//   using wT    = eve::wide<T>;

  pv_t pva(1.0, 1.0e-300);
  pv_t pvb(-1.0, -1.0e-300);
  TTS_EQUAL(plf::abs(pvb), pva);
  TTS_EQUAL(plf::abs(pva), pva);



};
