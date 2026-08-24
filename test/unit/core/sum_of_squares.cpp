//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check sum_of_squares two params",
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
  using plf::sum_of_squares;
  auto msum_of_squares = [](auto&&... as){return ((as*as) +...); };
  {
    using pv_t  = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    TTS_RELATIVE_EQUAL(sum_of_squares(pa, pb), tts::mpfr_exec(msum_of_squares, pa, pb), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(sum_of_squares(a0, pa), sum_of_squares(pv_t(a0), pa), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(sum_of_squares(pa, a0), sum_of_squares(pa, pv_t(a0)), tts::epsprec<pv_t>());
    using wpv_t  = eve::wide<pv_t, eve::fixed<2>>;
    wpv_t wpab(pa, pb);
    TTS_RELATIVE_EQUAL(sum_of_squares(wpab), plf::sqr(wpab), tts::epsprec<T>());
  }
  {
    using pv_t  = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t pb(a3, a4, a5);
    TTS_RELATIVE_EQUAL(sum_of_squares(pa, pb), tts::mpfr_exec(msum_of_squares, pa, pb), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(sum_of_squares(a0, pa), sum_of_squares(pv_t(a0), pa), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(sum_of_squares(pa, a0), sum_of_squares(pa, pv_t(a0)), tts::epsprec<pv_t>());
    using wpv_t  = eve::wide<pv_t, eve::fixed<2>>;
    wpv_t wpab(pa, pb);
    TTS_RELATIVE_EQUAL(sum_of_squares(wpab, wpab), 2*plf::sqr(wpab), tts::epsprec<T>());
  }
};

TTS_CASE_WITH("Check sum_of_squares three params",
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
  using plf::sum_of_squares;
  auto msos = [](auto&&... as){return ((as*as) +...); };
  {
    using pv_t  = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    pv_t pc(a6, a7);
    TTS_RELATIVE_EQUAL( sum_of_squares(pa, pb, pc), tts::mpfr_exec(msos, pa, pb, pc),  tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(sum_of_squares(a0, pa, pc), sum_of_squares(pv_t(a0), pa, pc), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(sum_of_squares(pa, a0, pc), sum_of_squares(pa, pv_t(a0), pc), tts::epsprec<pv_t>());
  }
  {
    using pv_t  = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t pb(a3, a4, a5);
    pv_t pc(a6, a7, a8);
    TTS_RELATIVE_EQUAL( sum_of_squares(pa, pb, pc), tts::mpfr_exec(msos, pa, pb, pc),  tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(sum_of_squares(a0, pa, pc), sum_of_squares(pv_t(a0), pa, pc), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(sum_of_squares(pa, a0, pc), sum_of_squares(pa, pv_t(a0), pc), tts::epsprec<pv_t>());
  }
};
