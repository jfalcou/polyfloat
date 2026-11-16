//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <sstream>
#include <string>

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

  auto text = [](auto const& v) {
    std::ostringstream os;
    os << v;
    return os.str();
  };
  auto lanes = [](std::string const& v, std::ptrdiff_t n) {
    std::string s = "(" + v;
    for (std::ptrdiff_t i = 1; i < n; ++i) s += ", " + v;
    return s + ")";
  };
  auto const inf = eve::inf(eve::as<T>());
  auto const nan = eve::nan(eve::as<T>());
  auto const zero = eve::zero(eve::as<T>());

  TTS_EQUAL(text(plf::double_real_t<T>(T(1))), std::string("1"));
  TTS_EQUAL(text(plf::double_real_t<wT>(wT(1))), lanes("1", wT::size()));

  {
    pv_t a2(T(1.0), T(0.1));
    TTS_EQUAL(text(a2), std::string("1.1"));
    using wT2 = eve::wide<T, 2>;
    using wpv_t2 = eve::wide<plf::polyfloat<T, 2>, 2>;
    wpv_t2 wa2(wT2(1.0), wT2(0.1));
    TTS_EQUAL(text(wa2), lanes("1.1", 2));

    TTS_EQUAL(text(pv_t(inf)), std::string("inf"));
    TTS_EQUAL(text(pv_t(nan)), std::string("nan"));
    TTS_EQUAL(text(wpv_t(inf)), lanes("inf", wpv_t::size()));
    TTS_EQUAL(text(wpv_t(nan)), lanes("nan", wpv_t::size()));
    TTS_EQUAL(text(pv_t(inf, zero)), std::string("inf"));
    TTS_EQUAL(text(pv_t(nan, zero)), std::string("nan"));
    TTS_EQUAL(text(wpv_t(inf, zero)), lanes("inf", wpv_t::size()));
    TTS_EQUAL(text(wpv_t(nan, zero)), lanes("nan", wpv_t::size()));
    TTS_EQUAL(text(wpv_t(inf, inf)), lanes("inf", wpv_t::size()));
  }
  {
    using pv_t3 = plf::polyfloat<T, 3>;
    using wpv_t3 = eve::wide<plf::polyfloat<T, 3>, 2>;
    using wT = eve::wide<T, 2>;
    wpv_t3 wa3(wT(1.0), wT(0.1));
    TTS_EQUAL(text(wa3), lanes("1.1", 2));

    TTS_EQUAL(text(pv_t3(inf)), std::string("inf"));
    TTS_EQUAL(text(pv_t3(nan)), std::string("nan"));
    TTS_EQUAL(text(wpv_t3(inf)), lanes("inf", 2));
    TTS_EQUAL(text(wpv_t3(nan)), lanes("nan", 2));
    TTS_EQUAL(text(pv_t3(inf, zero)), std::string("inf"));
    TTS_EQUAL(text(pv_t3(nan, zero)), std::string("nan"));
    TTS_EQUAL(text(wpv_t3(inf, zero)), lanes("inf", 2));
    TTS_EQUAL(text(wpv_t3(nan, zero)), lanes("nan", 2));
    TTS_EQUAL(text(wpv_t3(inf, inf)), lanes("inf", 2));
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
