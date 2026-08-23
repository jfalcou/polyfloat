//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check maxmag two params",
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
  using plf::maxmag;
  {
    using pv_t  = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    TTS_EQUAL(maxmag(pa, pb), plf::if_else(plf::abs(pa) < plf::abs(pb), pb, pa));
    TTS_EQUAL(maxmag(a0, pa), maxmag(pv_t(a0), pa));
    TTS_EQUAL(maxmag(pa, a0), maxmag(pa, pv_t(a0)));
    TTS_EQUAL(maxmag(pa, pa, pb), maxmag(pa, pb));
  }
  {
    using pv_t  = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t pb(a3, a4, a5);
    TTS_EQUAL(maxmag(pa, pb), plf::if_else(plf::abs(pa) < plf::abs(pb), pb, pa));
    TTS_EQUAL(maxmag(a0, pa), maxmag(pv_t(a0), pa));
    TTS_EQUAL(maxmag(pa, a0), maxmag(pa, pv_t(a0)));
    TTS_EQUAL(maxmag(pa, pa, pb), maxmag(pa, pb));
  }
};
