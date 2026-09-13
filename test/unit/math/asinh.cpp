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
  "Check asinh ", plf::scalar_real_types, tts::randoms(1.0, 88.0), tts::randoms(0.0, 1.e-20), tts::randoms(0.0, 1.e-30))
<typename T>(T const& a0, T const& a1, T const& a2)
{
  using mpfr::mpreal;
  using plf::asinh;
  auto masinh = [](auto a) { return mpfr::log(a + mpfr::sqrt(a * a + 1)); };
  {
    using pv_t = plf::polyfloat<T, 2>;
    pv_t nan(plf::nan(eve::as<pv_t>()));
    pv_t pa(a0, a1);
    TTS_RELATIVE_EQUAL(asinh(pa), tts::mpfr_exec(masinh, pa), 128 * tts::epsprec<pv_t>());
    pv_t o(T(1), T(0));
    TTS_RELATIVE_EQUAL(asinh(o), tts::mpfr_exec(masinh, o), 64 * tts::epsprec<pv_t>());
    pv_t oe = plf::inc(plf::eps(eve::as(o)));
    TTS_RELATIVE_EQUAL(asinh(oe), tts::mpfr_exec(masinh, oe), 64 * tts::epsprec<pv_t>());
    pv_t z(T(0), T(0));
    TTS_IEEE_EQUAL(plf::asinh(z), z);
    pv_t inf(plf::inf(eve::as<pv_t>()));
    TTS_EQUAL(asinh(inf), inf);
    TTS_IEEE_EQUAL(asinh(nan), nan);
    pv_t minf(plf::minf(eve::as<pv_t>()));
    TTS_IEEE_EQUAL(asinh(minf), nan);
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t nan(plf::nan(eve::as<pv_t>()));
    TTS_RELATIVE_EQUAL(asinh(pa), tts::mpfr_exec(masinh, pa), 8000 * tts::epsprec<pv_t>());
    pv_t o(T(1), T(0), T(0));
    TTS_RELATIVE_EQUAL(asinh(o), tts::mpfr_exec(masinh, o), 27000 * tts::epsprec<pv_t>());
    pv_t z(T(0), T(0), T(0));
    TTS_IEEE_EQUAL(asinh(z), z);
    pv_t inf(plf::inf(eve::as<pv_t>()));
    TTS_EQUAL(asinh(inf), inf);
    TTS_IEEE_EQUAL(asinh(nan), nan);
    pv_t minf(plf::minf(eve::as<pv_t>()));
    TTS_IEEE_EQUAL(asinh(minf), nan);
  }
};
