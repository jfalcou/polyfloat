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
TTS_CASE_TPL("Check types", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
  using wT = eve::wide<T>;
  TTS_EXPR_IS(plf::double_real_t<T>(), (plf::polyfloat<T, 2>));
  TTS_EXPR_IS(plf::triple_real_t<T>(), (plf::polyfloat<T, 3>));
  TTS_EXPR_IS(plf::double_real_t<T>(), (plf::as_polyfloat_n_t<2, T>));
  TTS_EXPR_IS(plf::triple_real_t<T>(), (plf::as_polyfloat_n_t<3, T>));
  TTS_EXPR_IS(plf::double_real_t<wT>(), (plf::as_polyfloat_n_t<2, wT>));
  TTS_EXPR_IS(plf::triple_real_t<wT>(), (plf::as_polyfloat_n_t<3, wT>));
  TTS_EXPR_IS((eve::wide<plf::polyfloat<T, 2>>()), (plf::double_real_t<wT>));
  TTS_EXPR_IS((eve::wide<plf::polyfloat<T, 3>>()), (plf::triple_real_t<wT>));
};
