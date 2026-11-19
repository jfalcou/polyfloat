//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include <benchmark.hpp>
#include <polyfloat/polyfloat.hpp>

TTS_CASE_TPL("Benchmark plf::add", float, double)
<typename T>(tts::type<T>)
{
  using pf2_t = plf::polyfloat<T, 2>;
  using pf3_t = plf::polyfloat<T, 3>;

  auto x2 = plf::bench::random<pf2_t>(-10, 10);
  auto y2 = plf::bench::random<pf2_t>(-10, 10);
  auto x3 = plf::bench::random<pf3_t>(-10, 10);
  auto y3 = plf::bench::random<pf3_t>(-10, 10);

  {
    plf::bench::benchmark _("polyfloat<" + tts::as_text(tts::typename_<T>) + ", 2> add");
    TTS_RUN_BENCHMARK_TPL(_, pf2_t, "plf::scalar", plf::add, x2, y2);
    TTS_RUN_BENCHMARK_TPL(_, mpfr::mpreal, "MPFR", plf::bench::mpfr_call<pf2_t>(mpfr_add), x2, y2);
    TTS_RUN_BENCHMARK_TPL(_, eve::wide<pf2_t>, "plf::wide", plf::add, x2, y2);
  }

  {
    plf::bench::benchmark _("polyfloat<" + tts::as_text(tts::typename_<T>) + ", 3> add");
    TTS_RUN_BENCHMARK_TPL(_, pf3_t, "plf::scalar", plf::add, x3, y3);
    TTS_RUN_BENCHMARK_TPL(_, mpfr::mpreal, "MPFR", plf::bench::mpfr_call<pf3_t>(mpfr_add), x3, y3);
    TTS_RUN_BENCHMARK_TPL(_, eve::wide<pf3_t>, "plf::wide", plf::add, x3, y3);
  }

  TTS_PASS("Benchmarks - SUCCESS");
};

TTS_CASE_TPL("Benchmark plf::add of a polyfloat and a real", float, double)
<typename T>(tts::type<T>)
{
  using pf2_t = plf::polyfloat<T, 2>;
  using pf3_t = plf::polyfloat<T, 3>;

  auto x2 = plf::bench::random<pf2_t>(-10, 10);
  auto x3 = plf::bench::random<pf3_t>(-10, 10);
  auto r = plf::bench::random<T>(-10, 10);

  // Do not give r to the MPFR row through mpfr_add_d, whose 53-bit temporary takes the path of two precisions.
  // r2 and r3 hold the same reals, which the MPFR row reads as MPFR numbers of the precision of the type.
  std::vector<pf2_t> r2(r.begin(), r.end());
  std::vector<pf3_t> r3(r.begin(), r.end());

  {
    plf::bench::benchmark _("polyfloat<" + tts::as_text(tts::typename_<T>) + ", 2> add " +
                            tts::as_text(tts::typename_<T>));
    TTS_RUN_BENCHMARK_TPL(_, pf2_t, "plf::scalar", plf::add, x2, r);
    TTS_RUN_BENCHMARK_TPL(_, mpfr::mpreal, "MPFR", plf::bench::mpfr_call<pf2_t>(mpfr_add), x2, r2);
    TTS_RUN_BENCHMARK_TPL(_, eve::wide<pf2_t>, "plf::wide", plf::add, x2, r);
  }

  {
    plf::bench::benchmark _("polyfloat<" + tts::as_text(tts::typename_<T>) + ", 3> add " +
                            tts::as_text(tts::typename_<T>));
    TTS_RUN_BENCHMARK_TPL(_, pf3_t, "plf::scalar", plf::add, x3, r);
    TTS_RUN_BENCHMARK_TPL(_, mpfr::mpreal, "MPFR", plf::bench::mpfr_call<pf3_t>(mpfr_add), x3, r3);
    TTS_RUN_BENCHMARK_TPL(_, eve::wide<pf3_t>, "plf::wide", plf::add, x3, r);
  }

  TTS_PASS("Benchmarks - SUCCESS");
};
