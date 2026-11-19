//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include <benchmark.hpp>
#include <polyfloat/polyfloat.hpp>

TTS_CASE_TPL("Benchmark plf::ldexp", float, double)
<typename T>(tts::type<T>)
{
  using pf2_t = plf::polyfloat<T, 2>;
  using pf3_t = plf::polyfloat<T, 3>;

  auto x2 = plf::bench::random<pf2_t>(-10, 10);
  auto x3 = plf::bench::random<pf3_t>(-10, 10);
  auto n = plf::bench::random<int>(-20, 20);

  {
    plf::bench::benchmark _("polyfloat<" + tts::as_text(tts::typename_<T>) + ", 2> ldexp");
    TTS_RUN_BENCHMARK_TPL(_, pf2_t, "plf::scalar", plf::ldexp, x2, n);
    TTS_RUN_BENCHMARK_TPL(_, mpfr::mpreal, "MPFR", plf::bench::mpfr_call<pf2_t>(mpfr_mul_2si), x2, n);
    TTS_RUN_BENCHMARK_TPL(_, eve::wide<pf2_t>, "plf::wide", plf::ldexp, x2, n);
  }

  {
    plf::bench::benchmark _("polyfloat<" + tts::as_text(tts::typename_<T>) + ", 3> ldexp");
    TTS_RUN_BENCHMARK_TPL(_, pf3_t, "plf::scalar", plf::ldexp, x3, n);
    TTS_RUN_BENCHMARK_TPL(_, mpfr::mpreal, "MPFR", plf::bench::mpfr_call<pf3_t>(mpfr_mul_2si), x3, n);
    TTS_RUN_BENCHMARK_TPL(_, eve::wide<pf3_t>, "plf::wide", plf::ldexp, x3, n);
  }

  TTS_PASS("Benchmarks - SUCCESS");
};
