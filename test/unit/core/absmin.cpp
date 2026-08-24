//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check min two params",
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
  using plf::absmin;
  using plf::abs;
  auto mabsmin = [](auto a,  auto b){ return mpfr::abs(mpfr::min(a, b)); };
  {
    using pv_t  = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    TTS_EQUAL(absmin(pa, pb), tts::mpfr_exec(mabsmin, pa, pb));
    TTS_EQUAL(absmin(pa, pb), plf::if_else(pa < pb, abs(pa), abs(pb)));
    TTS_EQUAL(absmin(a0, pa), absmin(pv_t(a0), pa));
    TTS_EQUAL(absmin(pa, a0), absmin(pa, pv_t(a0)));
  }
  {
    using pv_t  = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t pb(a3, a4, a5);
    TTS_EQUAL(absmin(pa, pb), tts::mpfr_exec(mabsmin, pa, pb));
    TTS_EQUAL(absmin(pa, pb), plf::if_else(pa < pb, abs(pa), abs(pb)));
    TTS_EQUAL(absmin(a0, pa), absmin(pv_t(a0), pa));
    TTS_EQUAL(absmin(pa, a0), absmin(pa, pv_t(a0)));
  }
};
