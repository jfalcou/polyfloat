//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check three_add params",
              plf::scalar_real_types,
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000))
<typename T>(T const& a0, T const& a1, T const& a2)
{
  using mpfr::mpreal;
  using plf::three_add;
  auto madd = [](auto a, auto b, auto c) { return a + b + c; };
  {
    auto [s, e0, e1] = plf::three_add(a0, a1, a2);
    auto z0 = tts::mpfr_exec(madd, a0, a1, a2);
    auto z1 = tts::mpfr_exec(madd, s, e0, e1);
    TTS_EQUAL(z0, z1);
  }
};

TTS_CASE_WITH("Check three_add polyfloat",
              plf::scalar_real_types,
              tts::randoms(-1000, 1000),
              tts::randoms(-1e-30, 1e-30),
              tts::randoms(-1e-35, 1e-35),
              tts::randoms(-1000, 1000),
              tts::randoms(-1e-30, 1e-30),
              tts::randoms(-1e-35, 1e-35),
              tts::randoms(-1000, 1000),
              tts::randoms(-1e-30, 1e-30),
              tts::randoms(-1e-35, 1e-35))
<typename T>(
  T const& a0, T const& a1, T const& a2, T const& a3, T const& a4, T const& a5, T const& a6, T const& a7, T const& a8)
{
  using mpfr::mpreal;
  using plf::three_add;
  auto madd = [](auto a, auto b, auto c) { return a + b + c; };
  {
    using pv_t = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    pv_t pc(a7, a8);
    auto [s, e0, e1] = plf::three_add(pa, pb, pc);
    auto z0 = tts::mpfr_exec(madd, pa, pb, pc);
    auto z1 = tts::mpfr_exec(madd, s, e0, e1);
    TTS_EQUAL(z0, z1);
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t pb(a3, a4, a5);
    pv_t pc(a6, a7, a8);
    auto [s, e0, e1] = plf::three_add(pa, pb, pc);
    auto z0 = tts::mpfr_exec(madd, pa, pb, pc);
    auto z1 = tts::mpfr_exec(madd, s, e0, e1);
    TTS_EQUAL(z0, z1);
  }
};
