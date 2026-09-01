//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check add two params",
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
  using plf::pown;
  using plf::sqr;
  auto mpow2 = [](auto a) { return a * a; };
  auto mpow3 = [](auto a) { return a * a * a; };
  {
    using pv_t = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    TTS_RELATIVE_EQUAL(pown(pa, 2.0), tts::mpfr_exec(mpow2, pa), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(pown(pa, 3.0), tts::mpfr_exec(mpow3, pa), 3 * tts::epsprec<pv_t>());
    using wpv_t = eve::wide<pv_t, eve::fixed<2>>;
    wpv_t wpab(pa, pb);
    TTS_RELATIVE_EQUAL(pown(wpab, 2.0), sqr(wpab), tts::epsprec<T>());
    TTS_RELATIVE_EQUAL(pown(wpab, 3.0), wpab * sqr(wpab), tts::epsprec<T>());
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t pb(a3, a4, a5);
    TTS_RELATIVE_EQUAL(pown(pa, 2.0), tts::mpfr_exec(mpow2, pa), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(pown(pa, 3.0), tts::mpfr_exec(mpow3, pa), 3 * tts::epsprec<pv_t>());
    using wpv_t = eve::wide<pv_t, eve::fixed<2>>;
    wpv_t wpab(pa, pb);
    TTS_RELATIVE_EQUAL(pown(wpab, 2.0), sqr(wpab), tts::epsprec<T>());
    TTS_RELATIVE_EQUAL(pown(wpab, 3.0), wpab * sqr(wpab), tts::epsprec<T>());
  }
};
