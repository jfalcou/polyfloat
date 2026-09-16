//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check pow_abs ",
              plf::scalar_real_types,
              tts::randoms(0.0, 10.0),
              tts::randoms(0.0, 1.e-20),
              tts::randoms(0.0, 1.e-30),
              tts::randoms(2.0, 10.0),
              tts::randoms(0.0, 1.e-20),
              tts::randoms(0.0, 1.e-30))
<typename T>(T const& a0, T const& a1, T const& a2, T const& a3, T const& a4, T const& a5)
{
  using mpfr::mpreal;
  using plf::pow_abs;
  auto mpow_abs = [](auto a, auto b) { return mpfr::pow(mpfr::abs(a), b); };
  {
    using pv_t = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    TTS_RELATIVE_EQUAL(plf::pow_abs(pa, pb), tts::mpfr_exec(mpow_abs, pa, pb), 12800 * tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(plf::pow_abs(pv_t(1) / 2, pv_t(1) / 4), tts::mpfr_exec(mpow_abs, pv_t(1) / 2, pv_t(1) / 4),
                       1000 * tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(plf::pow_abs(pv_t(1) / 2, pv_t(5) / 2), tts::mpfr_exec(mpow_abs, pv_t(1) / 2, pv_t(5) / 2),
                       1000 * tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(plf::pow_abs(pv_t(10), pv_t(10)), tts::mpfr_exec(mpow_abs, pv_t(10), pv_t(10)),
                       1000 * tts::epsprec<pv_t>());
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t pb(a3, a4, a5);
    TTS_RELATIVE_EQUAL(plf::pow_abs(pa, pb), tts::mpfr_exec(mpow_abs, pa, pb), 51200 * tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(plf::pow_abs(pv_t(1) / 2, pv_t(1) / 4), tts::mpfr_exec(mpow_abs, pv_t(1) / 2, pv_t(1) / 4),
                       5000 * tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(plf::pow_abs(pv_t(1) / 2, pv_t(5) / 2), tts::mpfr_exec(mpow_abs, pv_t(1) / 2, pv_t(5) / 2),
                       3000 * tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(plf::pow_abs(pv_t(10), pv_t(10)), tts::mpfr_exec(mpow_abs, pv_t(10), pv_t(10)),
                       1000 * tts::epsprec<pv_t>());
  }
};

TTS_CASE_TPL("Check limits of pow_abs", plf::scalar_real_types)
<typename T>(tts::type<T>){

  {using pv_t = plf::polyfloat<T, 2>;
TTS_IEEE_EQUAL(plf::pow_abs(plf::minf(plf::as<pv_t>()), plf::minf(plf::as<pv_t>())), T(0));

TTS_IEEE_EQUAL(plf::pow_abs(plf::inf(plf::as<pv_t>()), pv_t(-0.5)), pv_t(0));
TTS_IEEE_EQUAL(plf::pow_abs(plf::inf(plf::as<pv_t>()), pv_t(0.5)), plf::inf(plf::as<pv_t>()));
TTS_IEEE_EQUAL(plf::pow_abs(plf::inf(plf::as<pv_t>()), plf::inf(plf::as<pv_t>())), plf::inf(plf::as<pv_t>()));
TTS_IEEE_EQUAL(plf::pow_abs(plf::nan(plf::as<pv_t>()), plf::nan(plf::as<pv_t>())), plf::nan(plf::as<pv_t>()));

TTS_IEEE_EQUAL(plf::pow_abs(pv_t(2), plf::minf(plf::as<pv_t>())), T(0));
TTS_IEEE_EQUAL(plf::pow_abs(pv_t(2), plf::inf(plf::as<pv_t>())), plf::inf(plf::as<pv_t>()));

TTS_IEEE_EQUAL(plf::pow_abs(pv_t(0), pv_t(-1)), plf::inf(plf::as<pv_t>()));
TTS_IEEE_EQUAL(plf::pow_abs(pv_t(0), pv_t(-2)), plf::inf(plf::as<pv_t>()));
TTS_IEEE_EQUAL(plf::pow_abs(pv_t(0.5), plf::inf(plf::as<pv_t>())), T(0));
TTS_IEEE_EQUAL(plf::pow_abs(pv_t(0.5), plf::minf(plf::as<pv_t>())), plf::inf(plf::as<pv_t>()));
TTS_IEEE_EQUAL(plf::pow_abs(pv_t(-1), pv_t(-1)), pv_t(1));
TTS_IEEE_EQUAL(plf::pow_abs(pv_t(-1), pv_t(5)), pv_t(1));
TTS_IEEE_EQUAL(plf::pow_abs(pv_t(-1), pv_t(6)), pv_t(1));
}
{
  using pv_t = plf::polyfloat<T, 3>;
  TTS_IEEE_EQUAL(plf::pow_abs(plf::minf(plf::as<pv_t>()), plf::minf(plf::as<pv_t>())), T(0));

  TTS_IEEE_EQUAL(plf::pow_abs(plf::inf(plf::as<pv_t>()), pv_t(-0.5)), pv_t(0));
  TTS_IEEE_EQUAL(plf::pow_abs(plf::inf(plf::as<pv_t>()), pv_t(0.5)), plf::inf(plf::as<pv_t>()));
  TTS_IEEE_EQUAL(plf::pow_abs(plf::inf(plf::as<pv_t>()), plf::inf(plf::as<pv_t>())), plf::inf(plf::as<pv_t>()));
  TTS_IEEE_EQUAL(plf::pow_abs(plf::nan(plf::as<pv_t>()), plf::nan(plf::as<pv_t>())), plf::nan(plf::as<pv_t>()));

  TTS_IEEE_EQUAL(plf::pow_abs(pv_t(2), plf::minf(plf::as<pv_t>())), T(0));
  TTS_IEEE_EQUAL(plf::pow_abs(pv_t(2), plf::inf(plf::as<pv_t>())), plf::inf(plf::as<pv_t>()));

  TTS_IEEE_EQUAL(plf::pow_abs(pv_t(0), pv_t(-1)), plf::inf(plf::as<pv_t>()));
  TTS_IEEE_EQUAL(plf::pow_abs(pv_t(0), pv_t(-2)), plf::inf(plf::as<pv_t>()));
  TTS_IEEE_EQUAL(plf::pow_abs(pv_t(0.5), plf::inf(plf::as<pv_t>())), T(0));
  TTS_IEEE_EQUAL(plf::pow_abs(pv_t(0.5), plf::minf(plf::as<pv_t>())), plf::inf(plf::as<pv_t>()));
  TTS_IEEE_EQUAL(plf::pow_abs(pv_t(-1), pv_t(-1)), pv_t(1));
  TTS_IEEE_EQUAL(plf::pow_abs(pv_t(-1), pv_t(5)), pv_t(1));
  TTS_IEEE_EQUAL(plf::pow_abs(pv_t(-1), pv_t(6)), pv_t(1));
}
}
;
