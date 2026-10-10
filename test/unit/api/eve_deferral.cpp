//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check that dimension 1 calls go to eve with their options",
              plf::real_types,
              tts::randoms(-10, 10),
              tts::randoms(-10, 10))
<typename T>(T const& a0, T const& a1)
{
  TTS_IEEE_EQUAL(plf::exp(a0), eve::exp(a0));
  TTS_IEEE_EQUAL(plf::abs[a0 > 0](a1), eve::abs[a0 > 0](a1));
  TTS_IEEE_EQUAL(plf::cos[eve::quarter_circle](a0), eve::cos[eve::quarter_circle](a0));

  TTS_IEEE_EQUAL(plf::hypot(a0, a1), eve::hypot(a0, a1));
  TTS_IEEE_EQUAL(plf::hypot[a0 > 0](a0, a1), eve::hypot[a0 > 0](a0, a1));
  TTS_IEEE_EQUAL(plf::hypot(kumi::tuple{a0, a1}), eve::hypot(a0, a1));

  TTS_IEEE_EQUAL(plf::ldexp(a0, 3), eve::ldexp(a0, 3));
  TTS_EQUAL(plf::is_less(a0, a1), eve::is_less(a0, a1));
  TTS_EQUAL(plf::is_greater_equal(a0, a1), eve::is_greater_equal(a0, a1));
};

TTS_CASE_TPL("Check that dimension 1 constants go to eve with their options", plf::real_types)
<typename T>(tts::type<T>)
{
  TTS_EQUAL(plf::pi(eve::as<T>()), eve::pi(eve::as<T>()));
  TTS_EQUAL(plf::pi[plf::lower](eve::as<T>()), eve::pi[eve::lower](eve::as<T>()));
  TTS_EQUAL(plf::pi[plf::upper](eve::as<T>()), eve::pi[eve::upper](eve::as<T>()));
};

TTS_CASE_TPL("Check that a tuple of polyfloats stays in polyfloat", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
  using pv_t = plf::polyfloat<T, 2>;
  pv_t a(T(3), T(0));
  pv_t b(T(4), T(0));

  TTS_EXPR_IS(plf::hypot(kumi::tuple{a, b}), pv_t);
  TTS_EQUAL(plf::hypot(kumi::tuple{a, b}), plf::hypot(a, b));
};
