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
  "Check tanh ", plf::scalar_real_types, tts::randoms(0.0, 88.0), tts::randoms(0.0, 1.e-20), tts::randoms(0.0, 1.e-30))
<typename T>(T const& a0, T const& a1, T const& a2)
{
  using mpfr::mpreal;
  using plf::tanh;
  auto mtanh = [](auto a) { return (mpfr::exp(a) - mpfr::exp(-a)) / (mpfr::exp(a) + mpfr::exp(-a)); };
  {
    using pv_t = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    TTS_RELATIVE_EQUAL(tanh(pa), tts::mpfr_exec(mtanh, pa), 128 * tts::epsprec<pv_t>());
    pv_t o(T(1), T(0));
    TTS_RELATIVE_EQUAL(tanh(o), tts::mpfr_exec(mtanh, o), 64 * tts::epsprec<pv_t>());
    pv_t z(T(0), T(0));
    TTS_EQUAL(plf::tanh(z), z);
    pv_t inf(plf::inf(eve::as<pv_t>()));
    TTS_EQUAL(tanh(inf), inf);
    pv_t nan(plf::nan(eve::as<pv_t>()));
    TTS_IEEE_EQUAL(tanh(nan), nan);
    pv_t minf(plf::minf(eve::as<pv_t>()));
    TTS_EQUAL(tanh(minf), minf);
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    TTS_RELATIVE_EQUAL(tanh(pa), tts::mpfr_exec(mtanh, pa), 80000 * tts::epsprec<pv_t>());
    pv_t o(T(1), T(0), T(0));
    TTS_RELATIVE_EQUAL(tanh(o), tts::mpfr_exec(mtanh, o), 3 * tts::epsprec<pv_t>());
    pv_t z(T(0), T(0), T(0));
    TTS_RELATIVE_EQUAL(tanh(z), z, tts::epsprec<pv_t>());
    pv_t inf(plf::inf(eve::as<pv_t>()));
    TTS_EQUAL(tanh(inf), inf);
    pv_t nan(plf::nan(eve::as<pv_t>()));
    TTS_IEEE_EQUAL(tanh(nan), nan);
    pv_t minf(plf::minf(eve::as<pv_t>()));
    TTS_EQUAL(tanh(minf), minf);
  }
};
