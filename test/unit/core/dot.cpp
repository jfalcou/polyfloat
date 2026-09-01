//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check dot three params",
              plf::scalar_real_types,
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000))
<typename T>(T const& a0,
             T const& a1,
             T const& a2,
             T const& a3,
             T const& a4,
             T const& a5,
             T const& a6,
             T const& a7,
             T const& a8,
             T const& a9,
             T const& a10,
             T const& a11)
{
  using mpfr::mpreal;
  auto mdot = [](auto a, auto b, auto c, auto d) { return a * c + b * d; };
  using plf::dot;
  {
    using pv_t = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    pv_t pc(a6, a7);
    pv_t pd(a9, a10);
    TTS_RELATIVE_EQUAL(dot(pa, pb, pc, pd), tts::mpfr_exec(mdot, pa, pb, pc, pd), tts::epsprec<T>());
    TTS_RELATIVE_EQUAL(dot(kumi::make_tuple(pa, pb), kumi::make_tuple(pc, pd)), tts::mpfr_exec(mdot, pa, pb, pc, pd),
                       tts::epsprec<T>());
    TTS_RELATIVE_EQUAL(dot[eve::kahan](pa, pb, pc, pd), tts::mpfr_exec(mdot, pa, pb, pc, pd), tts::epsprec<T>());
    using wpv_t = eve::wide<pv_t, eve::fixed<2>>;
    wpv_t wpab(pa, pb);
    wpv_t wpcd(pc, pd);
    TTS_RELATIVE_EQUAL(dot(wpab, wpcd), wpab * wpcd, tts::epsprec<T>());
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t pb(a3, a4, a5);
    pv_t pc(a6, a7, a8);
    pv_t pd(a9, a10, a11);
    TTS_RELATIVE_EQUAL(dot(pa, pb, pc, pd), tts::mpfr_exec(mdot, pa, pb, pc, pd), tts::epsprec<T>());
    TTS_RELATIVE_EQUAL(dot[eve::kahan](pa, pb, pc, pd), tts::mpfr_exec(mdot, pa, pb, pc, pd), tts::epsprec<T>());
    using wpv_t = eve::wide<pv_t, eve::fixed<2>>;
    wpv_t wpab(pa, pb);
    wpv_t wpcd(pc, pd);
    TTS_RELATIVE_EQUAL(dot(wpab, wpcd), wpab * wpcd, tts::epsprec<T>());
  }
};
