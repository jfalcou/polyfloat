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
TTS_CASE_TPL( "Check return types of arithmetic operators", plf::scalar_real_types)
<typename T>(tts::type<T>)
{

  using pv2_t  = plf::polyfloat<T, 2>;
  using wpv2_t = eve::wide<pv2_t>;
  using pv3_t  = plf::polyfloat<T, 3>;
  using wpv3_t = eve::wide<pv3_t>;
  using wT    = eve::wide<T>;

  TTS_EQUAL(plf::dimension_v<pv2_t>, 2u);
  TTS_EQUAL(plf::dimension_v<wpv2_t>, 2u);
  TTS_EQUAL(plf::dimension_v<pv3_t>, 3u);
  TTS_EQUAL(plf::dimension_v<wpv3_t>, 3u);
  TTS_EQUAL(plf::dimension_v<T>, 1u);
  TTS_EQUAL(plf::dimension_v<wT>, 1u);


};
