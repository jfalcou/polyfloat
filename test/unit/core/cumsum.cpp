//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check cumsum two params",
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
  using plf::cumsum;
  auto msum = [](auto... as) { return (as + ...); };
  auto mcs = [msum](auto a0, auto a1) {
    return kumi::make_tuple(tts::mpfr_exec(msum, a0), tts::mpfr_exec(msum, a0, a1));
  };
  {
    using pv_t = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    TTS_RELATIVE_EQUAL(kumi::get<0>(cumsum(pa, pb)), kumi::get<0>(mcs(pa, pb)), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(kumi::get<1>(cumsum(pa, pb)), kumi::get<1>(mcs(pa, pb)), tts::epsprec<pv_t>());
    using wpv_t = eve::wide<pv_t, eve::fixed<2>>;
    wpv_t wpab(pa, pb);
    TTS_RELATIVE_EQUAL(kumi::get<0>(cumsum(wpab, wpab, wpab)), wpab, tts::epsprec<T>());
    TTS_RELATIVE_EQUAL(kumi::get<1>(cumsum(wpab, wpab, wpab)), 2 * wpab, tts::epsprec<T>());
    TTS_RELATIVE_EQUAL(kumi::get<2>(cumsum(wpab, wpab, wpab)), 3 * wpab, tts::epsprec<T>());
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t pb(a3, a4, a5);
    TTS_RELATIVE_EQUAL(kumi::get<0>(cumsum(pa, pb)), kumi::get<0>(mcs(pa, pb)), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(kumi::get<1>(cumsum(pa, pb)), kumi::get<1>(mcs(pa, pb)), tts::epsprec<pv_t>());
    using wpv_t = eve::wide<pv_t, eve::fixed<2>>;
    wpv_t wpab(pa, pb);
    TTS_RELATIVE_EQUAL(kumi::get<0>(cumsum(wpab, wpab, wpab)), wpab, tts::epsprec<T>());
    TTS_RELATIVE_EQUAL(kumi::get<1>(cumsum(wpab, wpab, wpab)), 2 * wpab, tts::epsprec<T>());
    TTS_RELATIVE_EQUAL(kumi::get<2>(cumsum(wpab, wpab, wpab)), 3 * wpab, tts::epsprec<T>());
  }
};

TTS_CASE_WITH("Check cumsum three params",
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
  using plf::cumsum;
  auto msum = [](auto... as) { return (as + ...); };
  auto mcs = [msum](auto a0, auto a1, auto a2) {
    return kumi::make_tuple(tts::mpfr_exec(msum, a0), tts::mpfr_exec(msum, a0, a1), tts::mpfr_exec(msum, a0, a1, a2));
  };
  {
    using pv_t = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    pv_t pc(a6, a7);
    TTS_RELATIVE_EQUAL(kumi::get<0>(cumsum(pa, pb, pc)), kumi::get<0>(mcs(pa, pb, pc)), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(kumi::get<1>(cumsum(pa, pb, pc)), kumi::get<1>(mcs(pa, pb, pc)), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(kumi::get<2>(cumsum(pa, pb, pc)), kumi::get<2>(mcs(pa, pb, pc)), tts::epsprec<pv_t>());
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t pb(a3, a4, a5);
    pv_t pc(a6, a7, a8);
    TTS_RELATIVE_EQUAL(kumi::get<0>(cumsum(pa, pb, pc)), kumi::get<0>(mcs(pa, pb, pc)), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(kumi::get<1>(cumsum(pa, pb, pc)), kumi::get<1>(mcs(pa, pb, pc)), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(kumi::get<2>(cumsum(pa, pb, pc)), kumi::get<2>(mcs(pa, pb, pc)), tts::epsprec<pv_t>());
  }
};
