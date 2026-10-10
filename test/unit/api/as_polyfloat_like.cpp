//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_TPL("Check as_polyfloat_like on product types", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
  using pv2_t = plf::polyfloat<T, 2>;
  using pv3_t = plf::polyfloat<T, 3>;
  using tup_t = kumi::tuple<pv2_t, pv2_t>;

  TTS_TYPE_IS((plf::as_polyfloat_like_t<tup_t>), tup_t);
  TTS_TYPE_IS((plf::as_polyfloat_like_t<T, kumi::tuple<T, pv2_t>>), pv2_t);
  TTS_TYPE_IS((plf::as_polyfloat_like_t<pv2_t, kumi::tuple<T, pv3_t>>), pv3_t);
  TTS_TYPE_IS((plf::as_polyfloat_like_t<T, eve::coefficients<kumi::tuple<T, pv2_t>>>), pv2_t);
  TTS_TYPE_IS((plf::as_polyfloat_like_t<T, eve::nodes<kumi::tuple<pv2_t, T>>>), pv2_t);
  TTS_TYPE_IS((plf::as_polyfloat_like_t<T, kumi::tuple<T, T>>), T);
};
