//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check div two params",
              plf::scalar_real_types,
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(1, eve::valmax),
              tts::randoms(1, eve::valmax),
              tts::randoms(1, eve::valmax)
             )
  <typename T>(T const& a0, T const& a1, T const& a2,
               T const& a3, T const& a4, T const& a5)
{
  using  mpfr::mpreal;
  using plf::div;
   auto mdiv = [](auto a,  auto b){return a/b; };
 {
    using pv_t  = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    TTS_ULP_EQUAL(div(pa, pb), tts::mpfr_exec(mdiv, pa, pb), 0.5);
    TTS_ULP_EQUAL(div(a0, pa), div(pv_t(a0), pa), 0.5);
    TTS_ULP_EQUAL(div(pa, a3), div(pa, pv_t(a3)), 0.5);
  }
  {
    using pv_t  = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t pb(a3, a4, a5);
    TTS_ULP_EQUAL(div(pa, pb), tts::mpfr_exec(mdiv, pa, pb), 0.5);
    TTS_ULP_EQUAL(div(a0, pa), div(pv_t(a0), pa), 0.5);
    TTS_ULP_EQUAL(div(pa, a3), div(pa, pv_t(a3)), 0.5);
  }
};
