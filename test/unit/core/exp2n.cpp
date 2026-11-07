//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH(
  "Check exp2n", plf::scalar_real_types, tts::randoms(-10, 10), tts::randoms(-10, 10), tts::randoms(-10, 10))
<typename T>(T const& a0, T const& a1, T const& a2)
{
  using plf::exp2n;
  {
    {
      using pv_t = plf::polyfloat<T, 2>;
      pv_t pa(a0, a1);
      pv_t tpa(trunc(plf::hi(pa)));
      TTS_RELATIVE_EQUAL(exp2n(tpa), plf::exp2(tpa), tts::epsprec<pv_t>());
      auto maxe = pv_t(eve::maxexponent(eve::as<T>()));
      TTS_RELATIVE_EQUAL(exp2n(maxe), plf::exp2(pv_t(maxe)), tts::epsprec<pv_t>());
      TTS_RELATIVE_EQUAL(exp2n[eve::raw](maxe), plf::exp2(pv_t(maxe)), tts::epsprec<pv_t>());
      auto mine = pv_t(eve::minexponent(eve::as<T>()));
      TTS_RELATIVE_EQUAL(exp2n(mine), plf::exp2(pv_t(mine)), tts::epsprec<pv_t>());
      TTS_RELATIVE_EQUAL(exp2n[eve::raw](mine), plf::exp2(pv_t(mine)), tts::epsprec<pv_t>());
    }
    {
      using pv_t = plf::polyfloat<T, 3>;
      pv_t pa(a0, a1, a2);
      pv_t tpa(trunc(plf::hi(pa)));
      TTS_RELATIVE_EQUAL(exp2n(tpa), plf::exp2(tpa), tts::epsprec<pv_t>());
      auto maxe = pv_t(eve::maxexponent(eve::as<T>()));
      TTS_RELATIVE_EQUAL(exp2n(maxe), plf::exp2(pv_t(maxe)), tts::epsprec<pv_t>());
      TTS_RELATIVE_EQUAL(exp2n[eve::raw](maxe), plf::exp2(pv_t(maxe)), tts::epsprec<pv_t>());
      auto mine = pv_t(eve::minexponent(eve::as<T>()));
      TTS_RELATIVE_EQUAL(exp2n(mine), plf::exp2(pv_t(mine)), tts::epsprec<pv_t>());
      TTS_RELATIVE_EQUAL(exp2n[eve::raw](mine), plf::exp2(pv_t(mine)), tts::epsprec<pv_t>());
    }
  }
};
