//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_TPL("Check polyfloat types", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
  using u_t = T;
  using w_t = eve::wide<T>;
  using pl2_t = plf::double_real_t<T>;
  using pl3_t = plf::triple_real_t<T>;
  using wpl2_t = plf::double_real_t<eve::wide<T>>;
  using wpl3_t = plf::triple_real_t<eve::wide<T>>;
  using wpl2_4t = plf::double_real_t<eve::wide<T, eve::fixed<4>>>;
  using wpl3_4t = plf::triple_real_t<eve::wide<T, eve::fixed<4>>>;
  TTS_EXPR_IS(u_t(), T);
  TTS_EXPR_IS(w_t(), eve::wide<T>);
  TTS_EXPR_IS(pl2_t(), (plf::polyfloat<T, 2>));
  TTS_EXPR_IS(wpl2_t(), (eve::wide<plf::polyfloat<T, 2>>));
  TTS_EXPR_IS(wpl2_4t(), (eve::wide<plf::polyfloat<T, 2>, eve::fixed<4>>));
  TTS_EXPR_IS(pl3_t(), (plf::polyfloat<T, 3>));
  TTS_EXPR_IS(wpl3_t(), (eve::wide<plf::polyfloat<T, 3>>));
  TTS_EXPR_IS(wpl3_4t(), (eve::wide<plf::polyfloat<T, 3>, eve::fixed<4>>));

};
