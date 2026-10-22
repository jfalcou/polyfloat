//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check log1p ",
              plf::scalar_real_types,
              tts::randoms(0.0, 1000.0),
              tts::randoms(0.0, 1.e-20),
              tts::randoms(0.0, 1.e-30))
<typename T>(T const& a0, T const& a1, T const& a2)
{
  using mpfr::mpreal;
  using plf::log1p;
  auto mlog1p = [](auto a) { return mpfr::log1p(a); };
  {
    using pv_t = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    TTS_RELATIVE_EQUAL(log1p(pa), tts::mpfr_exec(mlog1p, pa), 256 * tts::epsprec<pv_t>());
    pv_t o(T(1), T(0));
    pv_t z(T(0), T(0));
    pv_t inf(plf::inf(eve::as<pv_t>()));
    pv_t minf(plf::minf(eve::as<pv_t>()));
    pv_t nan(plf::nan(eve::as<pv_t>()));
    TTS_EQUAL(plf::log1p(z), z);
    TTS_EQUAL(log1p(inf), inf);
    TTS_IEEE_EQUAL(log1p(minf), inf);
    TTS_IEEE_EQUAL(log1p(nan), nan);
    TTS_IEEE_EQUAL(log1p(-o), minf);
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    TTS_RELATIVE_EQUAL(log1p(pa), tts::mpfr_exec(mlog1p, pa), 204804 * tts::epsprec<pv_t>());
    pv_t o(T(1), T(0));
    pv_t z(T(0), T(0));
    pv_t inf(plf::inf(eve::as<pv_t>()));
    pv_t minf(plf::minf(eve::as<pv_t>()));
    pv_t nan(plf::nan(eve::as<pv_t>()));
    TTS_EQUAL(plf::log1p(z), z);
    TTS_EQUAL(log1p(inf), inf);
    TTS_IEEE_EQUAL(log1p(minf), inf);
    TTS_IEEE_EQUAL(log1p(nan), nan);
    TTS_IEEE_EQUAL(log1p(-o), minf);
  }
};
