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
TTS_CASE_TPL("Check the hi md and lo part of a value", plf::scalar_real_types)
<typename T>(tts::type<T>){{using wT = eve::wide<T>;
T a = 1.3;
wT wa(a);
TTS_EQUAL(plf::hi(a), a);
TTS_EQUAL(plf::hi(wa), wa);

TTS_EQUAL(plf::md(a), T(0));
TTS_EQUAL(plf::md(wa), wT(0));

TTS_EQUAL(plf::lo(a), T(0));
TTS_EQUAL(plf::lo(wa), wT(0));
}
{
  using pv_t = plf::polyfloat<T, 2>;
  using wpv_t = eve::wide<pv_t>;
  using wT = eve::wide<T>;

  pv_t pva(1.0, 1.0e-300);
  wpv_t wpva{pva};

  TTS_EQUAL(plf::hi(pva), 1.0);
  TTS_EQUAL(plf::hi(wpva), wT(1.0));

  TTS_EQUAL(plf::md(pva), get<1>(pva));
  TTS_EQUAL(plf::md(wpva), wT(get<1>(pva)));

  TTS_EQUAL(plf::lo(pva), get<1>(pva));
  TTS_EQUAL(plf::lo(wpva), wT(get<1>(pva)));
}
{
  using pv_t = plf::polyfloat<T, 3>;
  using wpv_t = eve::wide<pv_t>;
  using wT = eve::wide<T>;

  pv_t pva(1.0, 1.0e-30, 1.0e-300);
  wpv_t wpva{pva};
  TTS_EQUAL(plf::hi(pva), 1.0);
  TTS_EQUAL(plf::hi(wpva), wT(1.0));

  TTS_EQUAL(plf::md(pva), get<1>(pva));
  TTS_EQUAL(plf::md(wpva), wT(get<1>(pva)));

  TTS_EQUAL(plf::lo(pva), get<2>(pva));
  TTS_EQUAL(plf::lo(wpva), wT(get<2>(pva)));
}
}
;
