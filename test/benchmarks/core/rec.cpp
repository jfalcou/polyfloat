//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include <benchmark.hpp>
#include <polyfloat/polyfloat.hpp>

TTS_CASE_TPL("Benchmark plf::rec", float, double)
<typename T>(tts::type<T>)
{
  using pf2_t = plf::polyfloat<T, 2>;
  using pf3_t = plf::polyfloat<T, 3>;

  auto x2 = plf::bench::random<pf2_t>(0, 1);
  auto x3 = plf::bench::random<pf3_t>(0, 1);

  auto my_rec = [](mpfr_t b, mpfr_t const a, mpfr_rnd_t rnd) { return mpfr_ui_div(b, 1UL, a, rnd); };

  {
    plf::bench::benchmark _("polyfloat<" + tts::as_text(tts::typename_<T>) + ", 2> rec");
    TTS_RUN_BENCHMARK_TPL(_, pf2_t, "plf::scalar", plf::rec, x2);
    TTS_RUN_BENCHMARK_TPL(_, mpfr::mpreal, "MPFR", plf::bench::mpfr_call<pf2_t>(my_rec), x2);
    TTS_RUN_BENCHMARK_TPL(_, eve::wide<pf2_t>, "plf::wide", plf::rec, x2);
  }

  {
    plf::bench::benchmark _("polyfloat<" + tts::as_text(tts::typename_<T>) + ", 3> rec");
    TTS_RUN_BENCHMARK_TPL(_, pf3_t, "plf::scalar", plf::rec, x3);
    TTS_RUN_BENCHMARK_TPL(_, mpfr::mpreal, "MPFR", plf::bench::mpfr_call<pf3_t>(my_rec), x3);
    TTS_RUN_BENCHMARK_TPL(_, eve::wide<pf3_t>, "plf::wide", plf::rec, x3);
  }

  TTS_PASS("Benchmarks - SUCCESS");
};
