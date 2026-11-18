//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include <benchmark.hpp>
#include <polyfloat/polyfloat.hpp>

TTS_CASE_TPL("Benchmark plf::cos", float, double)
<typename T>(tts::type<T>)
{
  using pf2_t = plf::polyfloat<T, 2>;
  using pf3_t = plf::polyfloat<T, 3>;

  auto pio_4 = eve::pio_4(eve::as<T>());
  auto x2 = plf::bench::random<pf2_t>(0, pio_4);
  auto x3 = plf::bench::random<pf3_t>(0, pio_4);

  auto cosqc = plf::cos[eve::quarter_circle];
  {
    plf::bench::benchmark _("polyfloat<" + tts::as_text(tts::typename_<T>) + ", 2> cos");
    TTS_RUN_BENCHMARK_TPL(_, pf2_t, "plf::scalar", cosqc, x2);
    TTS_RUN_BENCHMARK_TPL(_, mpfr::mpreal, "MPFR", plf::bench::mpfr_call<pf2_t>(mpfr_cos), x2);
    TTS_RUN_BENCHMARK_TPL(_, eve::wide<pf2_t>, "plf::wide", cosqc, x2);
  }

  {
    plf::bench::benchmark _("polyfloat<" + tts::as_text(tts::typename_<T>) + ", 3> cos");
    TTS_RUN_BENCHMARK_TPL(_, pf3_t, "plf::scalar", cosqc, x3);
    TTS_RUN_BENCHMARK_TPL(_, mpfr::mpreal, "MPFR", plf::bench::mpfr_call<pf3_t>(mpfr_cos), x3);
    TTS_RUN_BENCHMARK_TPL(_, eve::wide<pf3_t>, "plf::wide", cosqc, x3);
  }

  TTS_PASS("Benchmarks - SUCCESS");
};
