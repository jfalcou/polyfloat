//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check hypot two params",
              plf::scalar_real_types,
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000))
<typename T>(T const& a0, T const& a1, T const& a2, T const& a3, T const& a4, T const& a5)
{
  using mpfr::mpreal;
  using plf::hypot;
  auto mhypot = [](auto a, auto b) { return sqrt(a * a + b * b); };
  {
    using pv_t = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    TTS_RELATIVE_EQUAL(hypot[eve::raw](pa, pb), tts::mpfr_exec(mhypot, pa, pb), 2 * tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(hypot(pa, pb), tts::mpfr_exec(mhypot, pa, pb), 2 * tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(hypot[eve::pedantic](pa, pb), tts::mpfr_exec(mhypot, pa, pb), 2 * tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(hypot(a0, pa), hypot(pv_t(a0), pa), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(hypot(pa, a0), hypot(pa, pv_t(a0)), tts::epsprec<pv_t>());
    using wpv_t = eve::wide<pv_t, eve::fixed<2>>;
    wpv_t wpab(pa, pb);
    TTS_RELATIVE_EQUAL(hypot(wpab, wpab), plf::sqrt(2 * wpab * wpab), tts::epsprec<T>());
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t pb(a3, a4, a5);
    TTS_RELATIVE_EQUAL(hypot(pa, pb), tts::mpfr_exec(mhypot, pa, pb), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(hypot(a0, pa), hypot(pv_t(a0), pa), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(hypot(pa, a0), hypot(pa, pv_t(a0)), tts::epsprec<pv_t>());
    using wpv_t = eve::wide<pv_t, eve::fixed<2>>;
    wpv_t wpab(pa, pb);
    TTS_RELATIVE_EQUAL(hypot(wpab, wpab), plf::sqrt(2 * wpab * wpab), tts::epsprec<T>());
  }
};

TTS_CASE_WITH("Check hypot three params",
              plf::scalar_real_types,
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000))
<typename T>(
  T const& a0, T const& a1, T const& a2, T const& a3, T const& a4, T const& a5, T const& a6, T const& a7, T const& a8)
{
  using mpfr::mpreal;
  using plf::hypot;
  auto mhypot = [](auto a, auto b, auto c) { return sqrt(a * a + b * b + c * c); };
  {
    using pv_t = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    pv_t pc(a6, a7);
    TTS_RELATIVE_EQUAL(hypot(pa, pb, pc), tts::mpfr_exec(mhypot, pa, pb, pc), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(hypot(a0, pa, pc), hypot(pv_t(a0), pa, pc), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(hypot(pa, a0, pc), hypot(pa, pv_t(a0), pc), tts::epsprec<pv_t>());
    using wpv_t = eve::wide<pv_t, eve::fixed<2>>;
    wpv_t wpab(pa, pb);
    TTS_RELATIVE_EQUAL(hypot(wpab, wpab, wpab), plf::sqrt(3 * wpab * wpab), tts::epsprec<T>());
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t pb(a3, a4, a5);
    pv_t pc(a6, a7, a8);
    TTS_RELATIVE_EQUAL(hypot(pa, pb, pc), tts::mpfr_exec(mhypot, pa, pb, pc), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(hypot(a0, pa, pc), hypot(pv_t(a0), pa, pc), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(hypot(pa, a0, pc), hypot(pa, pv_t(a0), pc), tts::epsprec<pv_t>());
    using wpv_t = eve::wide<pv_t, eve::fixed<2>>;
    wpv_t wpab(pa, pb);
    TTS_RELATIVE_EQUAL(hypot(wpab, wpab, wpab), plf::sqrt(3 * wpab * wpab), tts::epsprec<T>());
  }
};
