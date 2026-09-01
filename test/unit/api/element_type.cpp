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
TTS_CASE_TPL("Check as_component", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
  using wpf2_t = eve::wide<plf::polyfloat<T, 2>>;
  using pf2_t = plf::polyfloat<T, 2>;
  using wpf3_t = eve::wide<plf::polyfloat<T, 3>>;
  using pf3_t = plf::polyfloat<T, 3>;
  using wT = eve::wide<T>;

  TTS_EXPR_IS(eve::element_type_t<wpf3_t>(), pf3_t);
  TTS_EXPR_IS(eve::element_type_t<pf3_t>(), pf3_t);
  TTS_EXPR_IS(eve::element_type_t<wpf2_t>(), pf2_t);
  TTS_EXPR_IS(eve::element_type_t<pf2_t>(), pf2_t);
  TTS_EXPR_IS(decltype(plf::hi(wpf3_t()))(), wT);
  TTS_EXPR_IS(decltype(plf::hi(pf3_t()))(), T);
  TTS_EXPR_IS(decltype(plf::hi(wpf2_t()))(), wT);
  TTS_EXPR_IS(decltype(plf::hi(pf2_t()))(), T);
  TTS_EXPR_IS(eve::underlying_type_t<wpf3_t>(), T);
  TTS_EXPR_IS(eve::underlying_type_t<pf3_t>(), T);
  TTS_EXPR_IS(eve::underlying_type_t<wpf2_t>(), T);
  TTS_EXPR_IS(eve::underlying_type_t<pf2_t>(), T);
};
