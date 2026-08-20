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
  using plf::negabsmin;
  using plf::abs;
  auto mnegabsmin = [](auto a,  auto b){ return -mpfr::abs(mpfr::min(a, b)); };
  {
    using pv_t  = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    TTS_EQUAL(negabsmin(pa, pb), tts::mpfr_exec(mnegabsmin, pa, pb));
    TTS_EQUAL(negabsmin(pa, pb), -plf::if_else(pa < pb, abs(pa), abs(pb)));
    TTS_EQUAL(negabsmin(a0, pa), negabsmin(pv_t(a0), pa));
    TTS_EQUAL(negabsmin(pa, a0), negabsmin(pa, pv_t(a0)));
  }
  {
    using pv_t  = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t pb(a3, a4, a5);
    TTS_EQUAL(negabsmin(pa, pb), tts::mpfr_exec(mnegabsmin, pa, pb));
    TTS_EQUAL(negabsmin(pa, pb), -plf::if_else(pa < pb, abs(pa), abs(pb)));
    TTS_EQUAL(negabsmin(a0, pa), negabsmin(pv_t(a0), pa));
    TTS_EQUAL(negabsmin(pa, a0), negabsmin(pa, pv_t(a0)));
  }
};
