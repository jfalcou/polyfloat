//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check acsch ",
              plf::scalar_real_types,
              tts::randoms(-100.0, 100.0),
              tts::randoms(-1.e-20, 1.e-20),
              tts::randoms(-1.e-30, 1.e-30))
<typename T>(T const& a0, T const& a1, T const& a2)
{
  using mpfr::mpreal;
  using plf::acsch;
  auto macsch = [](auto b) {
    auto a = 1 / b;
    return mpfr::log(a + mpfr::sqrt(a * a + 1));
  };
  {
    using pv_t = plf::polyfloat<T, 2>;
    pv_t nan(plf::nan(eve::as<pv_t>()));
    pv_t pa(a0, a1);
    TTS_RELATIVE_EQUAL(acsch(pa), tts::mpfr_exec(macsch, pa), 128 * tts::epsprec<pv_t>());
    pv_t o(T(1), T(0));
    pv_t z(T(0), T(0));
    pv_t inf(plf::inf(eve::as<pv_t>()));
    TTS_RELATIVE_EQUAL(acsch(o), tts::mpfr_exec(macsch, o), 128 * tts::epsprec<pv_t>());
    TTS_IEEE_EQUAL(plf::acsch(z), inf);
    TTS_IEEE_EQUAL(plf::acsch(-z), -inf);
    TTS_IEEE_EQUAL(acsch(inf), z);
    TTS_IEEE_EQUAL(acsch(nan), nan);
    pv_t minf(plf::minf(eve::as<pv_t>()));
    TTS_IEEE_EQUAL(acsch(minf), z);
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    TTS_RELATIVE_EQUAL(acsch(pa), tts::mpfr_exec(macsch, pa), 128000 * tts::epsprec<pv_t>());
    pv_t nan(plf::nan(eve::as<pv_t>()));
    pv_t o(T(1), T(0));
    pv_t z(T(0), T(0));
    pv_t inf(plf::inf(eve::as<pv_t>()));
    TTS_RELATIVE_EQUAL(acsch(o), tts::mpfr_exec(macsch, o), 128000 * tts::epsprec<pv_t>());
    TTS_IEEE_EQUAL(plf::acsch(z), inf);
    TTS_IEEE_EQUAL(plf::acsch(-z), -inf);
    TTS_IEEE_EQUAL(acsch(inf), z);
    TTS_IEEE_EQUAL(acsch(nan), nan);
    pv_t minf(plf::minf(eve::as<pv_t>()));
    TTS_IEEE_EQUAL(acsch(minf), z);
  }
};
