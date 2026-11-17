//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include <benchmark.hpp>
#include <polyfloat/polyfloat.hpp>

TTS_CASE_TPL("Benchmark plf::rsqrt", float, double)
<typename T>(tts::type<T>)
{
  using pf2_t = plf::polyfloat<T, 2>;
  using pf3_t = plf::polyfloat<T, 3>;

  auto x2 = plf::bench::random<pf2_t>(0, 1);
  auto x3 = plf::bench::random<pf3_t>(0, 1);

  auto my_rsqrt = [](mpfr_t b, mpfr_t const a, mpfr_rnd_t rnd) {
    mpfr_sqrt(b, a, rnd);
    return mpfr_ui_div(b, 1UL, b, rnd);
  };

  {
    plf::bench::benchmark _("polyfloat<" + tts::as_text(tts::typename_<T>) + ", 2> rsqrt");
    TTS_RUN_BENCHMARK_TPL(_, pf2_t, "plf::scalar", plf::rsqrt, x2);
    TTS_RUN_BENCHMARK_TPL(_, mpfr::mpreal, "MPFR", plf::bench::mpfr_call<pf2_t>(my_rsqrt), x2);
    TTS_RUN_BENCHMARK_TPL(_, eve::wide<pf2_t>, "plf::wide", plf::rsqrt, x2);
  }

  {
    plf::bench::benchmark _("polyfloat<" + tts::as_text(tts::typename_<T>) + ", 3> rsqrt");
    TTS_RUN_BENCHMARK_TPL(_, pf3_t, "plf::scalar", plf::rsqrt, x3);
    TTS_RUN_BENCHMARK_TPL(_, mpfr::mpreal, "MPFR", plf::bench::mpfr_call<pf3_t>(my_rsqrt), x3);
    TTS_RUN_BENCHMARK_TPL(_, eve::wide<pf3_t>, "plf::wide", plf::rsqrt, x3);
  }

  TTS_PASS("Benchmarks - SUCCESS");
};
