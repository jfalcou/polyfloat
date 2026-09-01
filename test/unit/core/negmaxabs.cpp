//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check negmaxabs two params",
              plf::scalar_real_types,
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax))
<typename T>(T const& a0, T const& a1, T const& a2, T const& a3, T const& a4, T const& a5)
{
  using mpfr::mpreal;
  using plf::negmaxabs;
  {
    using pv_t = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    TTS_EQUAL(negmaxabs(pa, pb), -plf::if_else(plf::abs(pa) < plf::abs(pb), plf::abs(pb), plf::abs(pa)));
    TTS_EQUAL(negmaxabs(a0, pa), negmaxabs(pv_t(a0), pa));
    TTS_EQUAL(negmaxabs(pa, a0), negmaxabs(pa, pv_t(a0)));
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t pb(a3, a4, a5);
    TTS_EQUAL(negmaxabs(pa, pb), -plf::if_else(plf::abs(pa) < plf::abs(pb), plf::abs(pb), plf::abs(pa)));
    TTS_EQUAL(negmaxabs(a0, pa), negmaxabs(pv_t(a0), pa));
    TTS_EQUAL(negmaxabs(pa, a0), negmaxabs(pa, pv_t(a0)));
  }
};
