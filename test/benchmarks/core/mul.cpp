//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include <benchmark.hpp>
#include <polyfloat/polyfloat.hpp>

TTS_CASE_TPL("Benchmark plf::mul", float, double)
<typename T>(tts::type<T>)
{
  using pf2_t = plf::polyfloat<T, 2>;
  using pf3_t = plf::polyfloat<T, 3>;

  auto rnd2 = plf::bench::random<pf2_t>(-10, 10);
  auto rnd3 = plf::bench::random<pf3_t>(-10, 10);
  auto mp2 = plf::bench::random<pf2_t>(-10, 10);
  auto mp3 = plf::bench::random<pf3_t>(-10, 10);

  {
    plf::bench::benchmark _("polyfloat<" + tts::as_text(tts::typename_<T>) + ", 2> mul");
    TTS_RUN_BENCHMARK_TPL(_, pf2_t, "plf::scalar", plf::mul, rnd2, rnd2);
    TTS_RUN_BENCHMARK_TPL(_, mpfr::mpreal, "MPFR", plf::bench::mpfr_call<pf2_t>(mpfr_mul), mp2, mp2);
    TTS_RUN_BENCHMARK_TPL(_, eve::wide<pf2_t>, "plf::wide", plf::mul, rnd2, rnd2);
  }

  {
    plf::bench::benchmark _("polyfloat<" + tts::as_text(tts::typename_<T>) + ", 3> mul");
    TTS_RUN_BENCHMARK_TPL(_, pf3_t, "plf::scalar", plf::mul, rnd3, rnd3);
    TTS_RUN_BENCHMARK_TPL(_, mpfr::mpreal, "MPFR", plf::bench::mpfr_call<pf3_t>(mpfr_mul), mp3, mp3);
    TTS_RUN_BENCHMARK_TPL(_, eve::wide<pf3_t>, "plf::wide", plf::mul, rnd3, rnd3);
  }

  TTS_PASS("Benchmarks - SUCCESS");
};
