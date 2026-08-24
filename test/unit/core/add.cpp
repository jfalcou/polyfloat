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
              tts::randoms(-1000, 1000)
             )
  <typename T>(T const& a0, T const& a1, T const& a2,
               T const& a3, T const& a4, T const& a5)
{
  using  mpfr::mpreal;
  using plf::add;
  auto madd = [](auto a,  auto b){return a+b; };
  {
    using pv_t  = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    TTS_RELATIVE_EQUAL(add(pa, pb), tts::mpfr_exec(madd, pa, pb), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(add(a0, pa), add(pv_t(a0), pa), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(add(pa, a0), add(pa, pv_t(a0)), tts::epsprec<pv_t>());
    using wpv_t  = eve::wide<pv_t, eve::fixed<2>>;
    wpv_t wpab(pa, pb);
    TTS_RELATIVE_EQUAL(add(wpab, wpab),  2*wpab, tts::epsprec<T>());
  }
  {
    using pv_t  = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t pb(a3, a4, a5);
    TTS_RELATIVE_EQUAL(add(pa, pb), tts::mpfr_exec(madd, pa, pb), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(add(a0, pa), add(pv_t(a0), pa), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(add(pa, a0), add(pa, pv_t(a0)), tts::epsprec<pv_t>());
    using wpv_t  = eve::wide<pv_t, eve::fixed<2>>;
    wpv_t wpab(pa, pb);
    TTS_RELATIVE_EQUAL(add(wpab, wpab),  2*wpab, tts::epsprec<T>());
  }
};

TTS_CASE_WITH("Check add three params",
              plf::scalar_real_types,
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000)
             )
  <typename T>(T const& a0, T const& a1, T const& a2,
               T const& a3, T const& a4, T const& a5,
               T const& a6, T const& a7, T const& a8)
{
  using  mpfr::mpreal;
  using plf::add;
  {
    using pv_t  = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    pv_t pc(a6, a7);
    TTS_EQUAL( tts::to_mpreal(add(pa, pb, pc)), (tts::to_mpreal(pa)+tts::to_mpreal(pb)+tts::to_mpreal(pc)));
    TTS_RELATIVE_EQUAL(add(a0, pa, pc), add(pv_t(a0), pa, pc), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(add(pa, a0, pc), add(pa, pv_t(a0), pc), tts::epsprec<pv_t>());
    using wpv_t  = eve::wide<pv_t, eve::fixed<2>>;
    wpv_t wpab(pa, pb);
    TTS_RELATIVE_EQUAL(add(wpab, wpab, wpab),  3*wpab, tts::epsprec<T>());
  }
  {
    using pv_t  = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t pb(a3, a4, a5);
    pv_t pc(a6, a7, a8);
    TTS_EQUAL( tts::to_mpreal(add(pa, pb, pc)), (tts::to_mpreal(pa)+tts::to_mpreal(pb)+tts::to_mpreal(pc)));
    TTS_RELATIVE_EQUAL(add(a0, pa, pc), add(pv_t(a0), pa, pc), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(add(pa, a0, pc), add(pa, pv_t(a0), pc), tts::epsprec<pv_t>());
    using wpv_t  = eve::wide<pv_t, eve::fixed<2>>;
    wpv_t wpab(pa, pb);
    TTS_RELATIVE_EQUAL(add(wpab, wpab, wpab),  3*wpab, tts::epsprec<T>());
  }
};
