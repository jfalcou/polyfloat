//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check pow ",
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
  using plf::pow;
  auto mpow = [](auto a, auto b) { return mpfr::pow(mpfr::abs(a), b); };
  {
    using pv_t = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    TTS_RELATIVE_EQUAL(plf::pow(pa, pb), tts::mpfr_exec(mpow, pa, pb), 12800 * tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(plf::pow(pv_t(1) / 2, pv_t(1) / 4), tts::mpfr_exec(mpow, pv_t(1) / 2, pv_t(1) / 4),
                       1000 * tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(plf::pow(pv_t(1) / 2, pv_t(5) / 2), tts::mpfr_exec(mpow, pv_t(1) / 2, pv_t(5) / 2),
                       1000 * tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(plf::pow(pv_t(10), pv_t(10)), tts::mpfr_exec(mpow, pv_t(10), pv_t(10)),
                       1000 * tts::epsprec<pv_t>());
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t pb(a3, a4, a5);
    TTS_RELATIVE_EQUAL(plf::pow(pa, pb), tts::mpfr_exec(mpow, pa, pb), 51200 * tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(plf::pow(pv_t(1) / 2, pv_t(1) / 4), tts::mpfr_exec(mpow, pv_t(1) / 2, pv_t(1) / 4),
                       5000 * tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(plf::pow(pv_t(1) / 2, pv_t(5) / 2), tts::mpfr_exec(mpow, pv_t(1) / 2, pv_t(5) / 2),
                       3000 * tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(plf::pow(pv_t(10), pv_t(10)), tts::mpfr_exec(mpow, pv_t(10), pv_t(10)),
                       1000 * tts::epsprec<pv_t>());
  }
};

TTS_CASE_TPL("Check limits of pow", plf::scalar_real_types)
<typename T>(tts::type<T>){

  {using pv_t = plf::polyfloat<T, 2>;
auto z = pv_t(0);
auto o = pv_t(1);
auto inf = plf::inf(eve::as(o));
auto minf = plf::minf(eve::as(o));
auto nan = plf::nan(eve::as(o));
auto two = pv_t(2);
auto hlf = plf::half(eve::as(o));
TTS_IEEE_EQUAL(plf::pow(z, -o), inf);
TTS_IEEE_EQUAL(plf::pow(-z, -o), minf);
TTS_IEEE_EQUAL(plf::pow(z, -two), inf);
TTS_IEEE_EQUAL(plf::pow(-z, -two), inf);
TTS_IEEE_EQUAL(plf::pow(z, minf), inf);
TTS_IEEE_EQUAL(plf::pow(-z, minf), inf);
TTS_IEEE_EQUAL(plf::pow(o, minf), o);
TTS_IEEE_EQUAL(plf::pow(o, inf), o);
TTS_IEEE_EQUAL(plf::pow(o, nan), o);
TTS_IEEE_EQUAL(plf::pow(nan, z), o);
TTS_IEEE_EQUAL(plf::pow(nan, -z), o);
TTS_IEEE_EQUAL(plf::pow(hlf, inf), z);
TTS_IEEE_EQUAL(plf::pow(two, inf), inf);
TTS_IEEE_EQUAL(plf::pow(-hlf, inf), z);
TTS_IEEE_EQUAL(plf::pow(-two, inf), inf);
TTS_IEEE_EQUAL(plf::pow(-hlf, minf), inf);
TTS_IEEE_EQUAL(plf::pow(-two, minf), z);
TTS_IEEE_EQUAL(plf::pow(minf, pv_t(-3)), -z);
TTS_IEEE_EQUAL(plf::pow(minf, pv_t(-4)), z);
TTS_IEEE_EQUAL(plf::pow(inf, pv_t(-4)), z);
TTS_IEEE_EQUAL(plf::pow(inf, pv_t(4)), inf);
}
{
  using pv_t = plf::polyfloat<T, 3>;
  auto z = pv_t(0);
  auto o = pv_t(1);
  auto inf = plf::inf(eve::as(o));
  auto minf = plf::minf(eve::as(o));
  auto nan = plf::nan(eve::as(o));
  auto two = pv_t(2);
  auto hlf = plf::half(eve::as(o));
  TTS_IEEE_EQUAL(plf::pow(z, -o), inf);
  TTS_IEEE_EQUAL(plf::pow(-z, -o), minf);
  TTS_IEEE_EQUAL(plf::pow(z, -two), inf);
  TTS_IEEE_EQUAL(plf::pow(-z, -two), inf);
  TTS_IEEE_EQUAL(plf::pow(z, minf), inf);
  TTS_IEEE_EQUAL(plf::pow(-z, minf), inf);
  TTS_IEEE_EQUAL(plf::pow(o, minf), o);
  TTS_IEEE_EQUAL(plf::pow(o, inf), o);
  TTS_IEEE_EQUAL(plf::pow(o, nan), o);
  TTS_IEEE_EQUAL(plf::pow(nan, z), o);
  TTS_IEEE_EQUAL(plf::pow(nan, -z), o);
  TTS_IEEE_EQUAL(plf::pow(hlf, inf), z);
  TTS_IEEE_EQUAL(plf::pow(two, inf), inf);
  TTS_IEEE_EQUAL(plf::pow(-hlf, inf), z);
  TTS_IEEE_EQUAL(plf::pow(-two, inf), inf);
  TTS_IEEE_EQUAL(plf::pow(-hlf, minf), inf);
  TTS_IEEE_EQUAL(plf::pow(-two, minf), z);
  TTS_IEEE_EQUAL(plf::pow(minf, pv_t(-3)), -z);
  TTS_IEEE_EQUAL(plf::pow(minf, pv_t(-4)), z);
  TTS_IEEE_EQUAL(plf::pow(inf, pv_t(-4)), z);
  TTS_IEEE_EQUAL(plf::pow(inf, pv_t(4)), inf);
}
}
;
