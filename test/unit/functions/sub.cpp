//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check sub two params",
              plf::scalar_real_types,
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax)
             )
  <typename T>(T const& a0, T const& a1, T const& a2,
               T const& a3, T const& a4, T const& a5)
{
  using  mpfr::mpreal;
  using plf::sub;
  auto msub = [](auto a,  auto b){return a-b; };
  {
    {
      using pv_t  = plf::polyfloat<T, 2>;
      pv_t pa(a0, a1);
      pv_t pb(a3, a4);
      TTS_RELATIVE_EQUAL(plf::sub(pa, pb), tts::mpfr_exec(msub, pa, pb), tts::epsprec<pv_t>());
      TTS_RELATIVE_EQUAL(sub(a0, pa), sub(pv_t(a0), pa), tts::epsprec<pv_t>());
      TTS_RELATIVE_EQUAL(sub(pa, a0), sub(pa, pv_t(a0)), tts::epsprec<pv_t>());
    }
    {
      using pv_t  = plf::polyfloat<T, 3>;
      pv_t pa(a0, a1, a2);
      pv_t pb(a3, a4, a5);
      TTS_RELATIVE_EQUAL(plf::sub(pa, pb), tts::mpfr_exec(msub, pa, pb), tts::epsprec<pv_t>());
      TTS_RELATIVE_EQUAL(sub(a0, pa), sub(pv_t(a0), pa), tts::epsprec<pv_t>());
      TTS_RELATIVE_EQUAL(sub(pa, a0), sub(pa, pv_t(a0)), tts::epsprec<pv_t>());
    }
  }
};


TTS_CASE_WITH("Check sub two params",
              plf::scalar_real_types,
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000)
             )
  <typename T>(T const& a0, T const& a1, T const& a2,
               T const& a3, T const& a4, T const& a5)
{
  using  mpfr::mpreal;
  using plf::sub;
  auto msub = [](auto a,  auto b){return a-b; };
  {
    {
      using pv_t  = plf::polyfloat<T, 2>;
      pv_t pa(a0, a1);
      pv_t pb(a3, a4);
      TTS_RELATIVE_EQUAL(plf::sub(pa, pb), tts::mpfr_exec(msub, pa, pb), tts::epsprec<pv_t>());
      TTS_RELATIVE_EQUAL(sub(a0, pa), sub(pv_t(a0), pa), tts::epsprec<pv_t>());
      TTS_RELATIVE_EQUAL(sub(pa, a0), sub(pa, pv_t(a0)), tts::epsprec<pv_t>());
    }
    {
      using pv_t  = plf::polyfloat<T, 3>;
      pv_t pa(a0, a1, a2);
      pv_t pb(a3, a4, a5);
      TTS_RELATIVE_EQUAL(plf::sub(pa, pb), tts::mpfr_exec(msub, pa, pb), tts::epsprec<pv_t>());
      TTS_RELATIVE_EQUAL(sub(a0, pa), sub(pv_t(a0), pa), tts::epsprec<pv_t>());
      TTS_RELATIVE_EQUAL(sub(pa, a0), sub(pa, pv_t(a0)), tts::epsprec<pv_t>());
    }
  }
};
