//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"

//==================================================================================================
// Types tests
//==================================================================================================
TTS_CASE_TPL("Check constructors", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
  using pv_t = plf::polyfloat<T, 2>;
  using wpv_t = eve::wide<pv_t>;
  using wT = eve::wide<T>;
  TTS_EXPR_IS(wpv_t(), wpv_t);
  TTS_EXPR_IS(pv_t(), pv_t);
  TTS_EXPR_IS(plf::polyfloat(T()), pv_t);
  TTS_EXPR_IS(eve::wide<pv_t>(), wpv_t);
  TTS_EXPR_IS((plf::as_polyfloat_n_t<2, wT>()), wpv_t);

  auto parts = [](auto... v) { return plf::polyfloat<T, sizeof...(v)>(kumi::tuple{v...}); };
  auto const inf = eve::inf(eve::as<T>());
  auto const nan = eve::nan(eve::as<T>());
  auto const zero = eve::zero(eve::as<T>());
  auto const [s, e] = eve::two_add(T(1.0), T(0.1));

  TTS_IEEE_EQUAL(plf::double_real_t<T>(T(1)), parts(T(1), zero));
  TTS_IEEE_EQUAL(plf::double_real_t<wT>(wT(1)), wpv_t(parts(T(1), zero)));

  {
    pv_t a2(T(1.0), T(0.1));
    TTS_IEEE_EQUAL(a2, parts(s, e));
    using wT2 = eve::wide<T, 2>;
    using wpv_t2 = eve::wide<plf::polyfloat<T, 2>, 2>;
    wpv_t2 wa2(wT2(1.0), wT2(0.1));
    TTS_IEEE_EQUAL(wa2, wpv_t2(parts(s, e)));

    TTS_EXPECT(plf::is_pinf(pv_t(inf)));
    TTS_EXPECT(plf::is_nan(pv_t(nan)));
    TTS_EXPECT(eve::all(plf::is_pinf(wpv_t(inf))));
    TTS_EXPECT(eve::all(plf::is_nan(wpv_t(nan))));
    TTS_EXPECT(plf::is_pinf(pv_t(inf, zero)));
    TTS_EXPECT(plf::is_nan(pv_t(nan, zero)));
    TTS_EXPECT(eve::all(plf::is_pinf(wpv_t(wT(inf), wT(zero)))));
    TTS_EXPECT(eve::all(plf::is_nan(wpv_t(wT(nan), wT(zero)))));
    TTS_EXPECT(eve::all(plf::is_pinf(wpv_t(wT(inf), wT(inf)))));
  }
  {
    using pv_t3 = plf::polyfloat<T, 3>;
    using wpv_t3 = eve::wide<plf::polyfloat<T, 3>, 2>;
    using wT = eve::wide<T, 2>;
    wpv_t3 wa3(wT(1.0), wT(0.1));
    TTS_IEEE_EQUAL(wa3, wpv_t3(parts(s, e, zero)));

    TTS_EXPECT(plf::is_pinf(pv_t3(inf)));
    TTS_EXPECT(plf::is_nan(pv_t3(nan)));
    TTS_EXPECT(eve::all(plf::is_pinf(wpv_t3(inf))));
    TTS_EXPECT(eve::all(plf::is_nan(wpv_t3(nan))));
    TTS_EXPECT(plf::is_pinf(pv_t3(inf, zero)));
    TTS_EXPECT(plf::is_nan(pv_t3(nan, zero)));
    TTS_EXPECT(eve::all(plf::is_pinf(wpv_t3(wT(inf), wT(zero)))));
    TTS_EXPECT(eve::all(plf::is_nan(wpv_t3(wT(nan), wT(zero)))));
    TTS_EXPECT(eve::all(plf::is_pinf(wpv_t3(wT(inf), wT(inf)))));
  }
};

TTS_CASE_WITH("Check constructor for normalization",
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
  using plf::is_normalized;
  {
    using pv_t = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    TTS_EXPECT(is_normalized(pa));
    TTS_EXPECT(is_normalized(pb));
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t pb(a3, a4, a5);
    TTS_EXPECT(is_normalized(pa));
    TTS_EXPECT(is_normalized(pb));
  }
};
