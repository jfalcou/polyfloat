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
  using pv_t = plf::polyfloat<T, 2>;
  using wpv_t = eve::wide<pv_t>;
  using wT = eve::wide<T>;

  TTS_EXPR_IS(plf::as_component_type_t<wpv_t>(), wT);
  TTS_EXPR_IS(plf::as_component_type_t<pv_t>(), T);
};
