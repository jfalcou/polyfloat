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
TTS_CASE_TPL( "Check the hi part of a value", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
  using pv_t  = plf::polyfloat<T, 2>;
  using wpv_t = eve::wide<pv_t>;
  using wT    = eve::wide<T>;

  pv_t pva(1.0, 1.0e-30);
  pv_t pvb(4.0, 0.1);
  wpv_t wpva{pva};
  T a = 1.3;
  wT wa(a);
  TTS_EQUAL(plf::hi(a), a);
  TTS_EQUAL(plf::hi(pva), 1.0);
  TTS_EQUAL(plf::hi(wa), wa);
  TTS_EQUAL(plf::hi(wpva), wT(1.0));
};
