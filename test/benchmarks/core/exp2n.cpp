//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include <benchmark.hpp>
#include <polyfloat/polyfloat.hpp>

TTS_CASE_TPL("Benchmark plf::exp2n", float, double)
<typename T>(tts::type<T>)
{
  using pf2_t = plf::polyfloat<T, 2>;
  using pf3_t = plf::polyfloat<T, 3>;

  auto x = plf::bench::random<int>(-10, 10);
  auto exp2n2 = [](auto n) { return exp2(n, eve::as<pf2_t>()); };
  auto exp2n3 = [](auto n) { return exp2(n, eve::as<pf3_t>()); };

  {
    plf::bench::benchmark _("polyfloat<" + tts::as_text(tts::typename_<T>) + ", 2> exp2n");
    TTS_RUN_BENCHMARK_TPL(_, pf2_t, "plf::scalar", exp2n2, x);
    TTS_RUN_BENCHMARK_TPL(_, mpfr::mpreal, "MPFR", plf::bench::mpfr_call<pf2_t>(mpfr_exp2), x);
    TTS_RUN_BENCHMARK_TPL(_, eve::wide<pf2_t>, "plf::wide", exp2n2, x);
  }

  {
    plf::bench::benchmark _("polyfloat<" + tts::as_text(tts::typename_<T>) + ", 3> exp2n");
    TTS_RUN_BENCHMARK_TPL(_, pf3_t, "plf::scalar", exp2n3, x);
    TTS_RUN_BENCHMARK_TPL(_, mpfr::mpreal, "MPFR", plf::bench::mpfr_call<pf3_t>(mpfr_exp2), x);
    TTS_RUN_BENCHMARK_TPL(_, eve::wide<pf3_t>, "plf::wide", exp2n3, x);
  }

  TTS_PASS("Benchmarks - SUCCESS");
};
