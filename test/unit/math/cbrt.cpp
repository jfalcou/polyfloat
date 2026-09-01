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
  "Check cbrt ", plf::scalar_real_types, tts::randoms(0.0, 88.0), tts::randoms(0.0, 1.e-20), tts::randoms(0.0, 1.e-30))
<typename T>(T const& a0, T const& a1, T const& a2)
{
  using mpfr::mpreal;
  using plf::cbrt;
  {
    using pv_t = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    auto pa3 = cbrt(pa);
    TTS_RELATIVE_EQUAL(pa3 * pa3 * pa3, pa, 128 * tts::epsprec<pv_t>());
    pv_t o(T(1), T(0));
    TTS_RELATIVE_EQUAL(cbrt(o), o, 64 * tts::epsprec<pv_t>());
    pv_t z(T(0), T(0));
    TTS_EQUAL(plf::cbrt(z), z);
    pv_t inf(plf::inf(eve::as<pv_t>()));
    TTS_EQUAL(cbrt(inf), inf);
    pv_t nan(plf::nan(eve::as<pv_t>()));
    TTS_IEEE_EQUAL(cbrt(nan), nan);
    pv_t minf(plf::minf(eve::as<pv_t>()));
    TTS_EQUAL(cbrt(minf), minf);
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    auto pa3 = cbrt(pa);
    TTS_RELATIVE_EQUAL(pa3 * pa3 * pa3, pa, 128 * tts::epsprec<pv_t>());
    pv_t o(T(1), T(0));
    TTS_RELATIVE_EQUAL(cbrt(o), o, 64 * tts::epsprec<pv_t>());
    pv_t z(T(0), T(0));
    TTS_EQUAL(plf::cbrt(z), z);
    pv_t inf(plf::inf(eve::as<pv_t>()));
    TTS_EQUAL(cbrt(inf), inf);
    pv_t nan(plf::nan(eve::as<pv_t>()));
    TTS_IEEE_EQUAL(cbrt(nan), nan);
    pv_t minf(plf::minf(eve::as<pv_t>()));
    TTS_EQUAL(cbrt(minf), minf);
  }
};
