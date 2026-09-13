//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check atanh ",
              plf::scalar_real_types,
              tts::randoms(0.0, 1.0),
              tts::randoms(-1.e-20, 0.0),
              tts::randoms(-1.e-30, 0.0))
<typename T>(T const& a0, T const& a1, T const& a2)
{
  using mpfr::mpreal;
  using plf::atanh;
  auto matanh = [](auto a) { return mpfr::log((a + 1) / (1 - a)) / 2; };
  {
    using pv_t = plf::polyfloat<T, 2>;
    pv_t nan(plf::nan(eve::as<pv_t>()));
    pv_t pa(a0, a1);
    TTS_RELATIVE_EQUAL(atanh(pa), tts::mpfr_exec(matanh, pa), 12800 * tts::epsprec<pv_t>());
    pv_t o(T(1), T(0));
    TTS_EQUAL(atanh(o), plf::inf(eve::as(pa)));
    pv_t z(T(0), T(0));
    TTS_IEEE_EQUAL(plf::atanh(z), z);
    pv_t inf(plf::inf(eve::as<pv_t>()));
    TTS_IEEE_EQUAL(atanh(inf), nan);
    TTS_IEEE_EQUAL(atanh(nan), nan);
    pv_t minf(plf::minf(eve::as<pv_t>()));
    TTS_IEEE_EQUAL(atanh(minf), nan);
    pv_t two(2);
    TTS_IEEE_EQUAL(atanh(two), nan);
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t nan(plf::nan(eve::as<pv_t>()));
    TTS_RELATIVE_EQUAL(atanh(pa), tts::mpfr_exec(matanh, pa), 20000 * tts::epsprec<pv_t>());
    pv_t o(T(1), T(0));
    TTS_EQUAL(atanh(o), plf::inf(eve::as(pa)));
    pv_t z(T(0), T(0));
    TTS_IEEE_EQUAL(plf::atanh(z), z);
    pv_t inf(plf::inf(eve::as<pv_t>()));
    TTS_IEEE_EQUAL(atanh(inf), nan);
    TTS_IEEE_EQUAL(atanh(nan), nan);
    pv_t minf(plf::minf(eve::as<pv_t>()));
    TTS_IEEE_EQUAL(atanh(minf), nan);
    pv_t two(2);
    TTS_IEEE_EQUAL(atanh(two), nan);
  }
};
