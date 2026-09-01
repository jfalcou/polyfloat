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
  "Check sinh ", plf::scalar_real_types, tts::randoms(0.0, 88.0), tts::randoms(0.0, 1.e-20), tts::randoms(0.0, 1.e-30))
<typename T>(T const& a0, T const& a1, T const& a2)
{
  using mpfr::mpreal;
  using plf::sinh;
  auto msinh = [](auto a) { return (mpfr::exp(a) - mpfr::exp(-a)) / 2; };
  {
    using pv_t = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    TTS_RELATIVE_EQUAL(sinh(pa), tts::mpfr_exec(msinh, pa), 128 * tts::epsprec<pv_t>());
    pv_t o(T(1), T(0));
    TTS_RELATIVE_EQUAL(sinh(o), tts::mpfr_exec(msinh, o), 64 * tts::epsprec<pv_t>());
    pv_t z(T(0), T(0));
    TTS_EQUAL(plf::sinh(z), z);
    pv_t inf(plf::inf(eve::as<pv_t>()));
    TTS_EQUAL(sinh(inf), inf);
    pv_t nan(plf::nan(eve::as<pv_t>()));
    TTS_IEEE_EQUAL(sinh(nan), nan);
    pv_t minf(plf::minf(eve::as<pv_t>()));
    TTS_EQUAL(sinh(minf), minf);
    pv_t maxlog(plf::maxlog(eve::as<pv_t>()));
    TTS_RELATIVE_EQUAL(sinh(maxlog), tts::mpfr_exec(msinh, maxlog), 1024 * tts::epsprec<pv_t>());
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    TTS_RELATIVE_EQUAL(sinh(pa), tts::mpfr_exec(msinh, pa), 1800000 * tts::epsprec<pv_t>()); //TO DO Better
    pv_t o(T(1), T(0), T(0));
    TTS_RELATIVE_EQUAL(sinh(o), tts::mpfr_exec(msinh, o), 3 * tts::epsprec<pv_t>());
    pv_t z(T(0), T(0), T(0));
    TTS_RELATIVE_EQUAL(sinh(z), z, tts::epsprec<pv_t>());
    pv_t inf(plf::inf(eve::as<pv_t>()));
    TTS_EQUAL(sinh(inf), inf);
    pv_t nan(plf::nan(eve::as<pv_t>()));
    TTS_IEEE_EQUAL(sinh(nan), nan);
    pv_t minf(plf::minf(eve::as<pv_t>()));
    TTS_EQUAL(sinh(minf), minf);
    pv_t maxlog(plf::maxlog(eve::as<pv_t>()));
    TTS_RELATIVE_EQUAL(sinh(maxlog), tts::mpfr_exec(msinh, maxlog), 102400 * tts::epsprec<pv_t>());
  }
};
