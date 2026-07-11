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
TTS_CASE_TPL( "Check is_negative", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
  using pv_t  = plf::polyfloat<T, 2>;
  using wpv_t = eve::wide<pv_t>;
  using wT    = eve::wide<T>;

  pv_t pva(1.0, 1.0e-300);
  pv_t pvb(0.0);
  pv_t pvc(-0.0);
  wpv_t wpva{pva};
  T a = 1.3;
  wT wa(a);
  TTS_EQUAL(plf::is_negative(a), eve::is_negative(plf::hi(a)));
  TTS_EQUAL(plf::is_negative(pva), eve::is_negative(plf::hi(pva)));
  TTS_EQUAL(plf::is_negative(wa),  eve::is_negative(plf::hi(wa)));
  TTS_EQUAL(plf::is_negative(wpva),  eve::is_negative(plf::hi(wpva)));
  TTS_EQUAL(plf::is_negative(pvb), eve::is_negative(plf::hi(pvb)));
  TTS_EQUAL(plf::is_negative(pvc), eve::is_negative(plf::hi(pvc)));
  TTS_NOT_EQUAL(plf::is_negative(pvb), eve::is_negative(plf::hi(pvc)));


};
