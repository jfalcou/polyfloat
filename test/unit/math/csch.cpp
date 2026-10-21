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
  "Check csch ", plf::scalar_real_types, tts::randoms(0.0, 88.0), tts::randoms(0.0, 1.e-20), tts::randoms(0.0, 1.e-30))
<typename T>(T const& a0, T const& a1, T const& a2)
{
  using mpfr::mpreal;
  using plf::csch;
  auto mcsch = [](auto a) { return 2 / (mpfr::exp(a) - mpfr::exp(-a)); };
  {
    using pv_t = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    TTS_RELATIVE_EQUAL(csch(pa), tts::mpfr_exec(mcsch, pa), 128 * tts::epsprec<pv_t>());
    pv_t o(T(1), T(0));
    TTS_RELATIVE_EQUAL(csch(o), tts::mpfr_exec(mcsch, o), 64 * tts::epsprec<pv_t>());
    pv_t z(T(0), T(0));
    pv_t inf(plf::inf(eve::as<pv_t>()));
    TTS_EQUAL(plf::csch(z), inf);
    TTS_EQUAL(plf::csch(-z), minf);
    TTS_EQUAL(csch(inf), z);
    TTS_EQUAL(csch(-inf), z);
    pv_t nan(plf::nan(eve::as<pv_t>()));
    TTS_IEEE_EQUAL(csch(nan), nan);
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    TTS_RELATIVE_EQUAL(csch(pa), tts::mpfr_exec(mcsch, pa), 80000 * tts::epsprec<pv_t>());
    pv_t o(T(1), T(0), T(0));
    TTS_RELATIVE_EQUAL(csch(o), tts::mpfr_exec(mcsch, o), 3 * tts::epsprec<pv_t>());
    pv_t z(T(0), T(0), T(0));
    pv_t inf(plf::inf(eve::as<pv_t>()));
    TTS_EQUAL(plf::csch(z), inf);
    TTS_EQUAL(plf::csch(-z), minf);
    TTS_EQUAL(csch(inf), z);
    TTS_EQUAL(csch(-inf), z);
    pv_t nan(plf::nan(eve::as<pv_t>()));
    TTS_IEEE_EQUAL(csch(nan), nan);
  }
};
