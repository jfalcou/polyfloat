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
TTS_CASE_TPL("Check return types of arithmetic operators", plf::scalar_real_types)
<typename T>(tts::type<T>){{using pv_t = plf::polyfloat<T, 2>;
using wpv_t = eve::wide<pv_t>;
using wT = eve::wide<T>;
using lwpv_t = eve::logical<wT>;
using lpv_t = eve::logical<T>;

TTS_EXPR_IS(wpv_t() == wpv_t(), lwpv_t);
TTS_EXPR_IS(wpv_t() != wpv_t(), lwpv_t);
TTS_EXPR_IS(wpv_t() < wpv_t(), lwpv_t);
TTS_EXPR_IS(wpv_t() > wpv_t(), lwpv_t);
TTS_EXPR_IS(wpv_t() == pv_t(), lwpv_t);
TTS_EXPR_IS(pv_t() == wpv_t(), lwpv_t);
TTS_EXPR_IS(wpv_t() != pv_t(), lwpv_t);
TTS_EXPR_IS(pv_t() != wpv_t(), lwpv_t);
TTS_EXPR_IS(wpv_t() < pv_t(), lwpv_t);
TTS_EXPR_IS(pv_t() < wpv_t(), lwpv_t);
TTS_EXPR_IS(wpv_t() > pv_t(), lwpv_t);
TTS_EXPR_IS(pv_t() > wpv_t(), lwpv_t);
TTS_EXPR_IS(pv_t() > pv_t(), lpv_t);
TTS_EXPR_IS(pv_t() < pv_t(), lpv_t);
TTS_EXPR_IS(pv_t() == pv_t(), lpv_t);
TTS_EXPR_IS(pv_t() != pv_t(), lpv_t);

TTS_EXPR_IS(wT() == wpv_t(), lwpv_t);
TTS_EXPR_IS(wT() != wpv_t(), lwpv_t);
TTS_EXPR_IS(wT() < wpv_t(), lwpv_t);
TTS_EXPR_IS(wT() > wpv_t(), lwpv_t);
TTS_EXPR_IS(wT() == pv_t(), lwpv_t);
TTS_EXPR_IS(T() == wpv_t(), lwpv_t);
TTS_EXPR_IS(wT() != pv_t(), lwpv_t);
TTS_EXPR_IS(T() != wpv_t(), lwpv_t);
TTS_EXPR_IS(wT() < pv_t(), lwpv_t);
TTS_EXPR_IS(T() < wpv_t(), lwpv_t);
TTS_EXPR_IS(wT() > pv_t(), lwpv_t);
TTS_EXPR_IS(T() > wpv_t(), lwpv_t);
TTS_EXPR_IS(T() > pv_t(), lpv_t);
TTS_EXPR_IS(T() < pv_t(), lpv_t);
TTS_EXPR_IS(T() == pv_t(), lpv_t);
TTS_EXPR_IS(T() != pv_t(), lpv_t);

TTS_EXPR_IS(wpv_t() == wT(), lwpv_t);
TTS_EXPR_IS(wpv_t() != wT(), lwpv_t);
TTS_EXPR_IS(wpv_t() < wT(), lwpv_t);
TTS_EXPR_IS(wpv_t() > wT(), lwpv_t);
TTS_EXPR_IS(wpv_t() == T(), lwpv_t);
TTS_EXPR_IS(pv_t() == wT(), lwpv_t);
TTS_EXPR_IS(wpv_t() != T(), lwpv_t);
TTS_EXPR_IS(pv_t() != wT(), lwpv_t);
TTS_EXPR_IS(wpv_t() < T(), lwpv_t);
TTS_EXPR_IS(pv_t() < wT(), lwpv_t);
TTS_EXPR_IS(wpv_t() > T(), lwpv_t);
TTS_EXPR_IS(pv_t() > wT(), lwpv_t);
TTS_EXPR_IS(pv_t() > T(), lpv_t);
TTS_EXPR_IS(pv_t() < T(), lpv_t);
TTS_EXPR_IS(pv_t() == T(), lpv_t);
TTS_EXPR_IS(pv_t() != T(), lpv_t);
}

{
  using pv_t = plf::polyfloat<T, 3>;
  using wpv_t = eve::wide<pv_t>;
  using wT = eve::wide<T>;
  using lwpv_t = eve::logical<wT>;
  using lpv_t = eve::logical<T>;
  TTS_EXPR_IS(wpv_t() == wpv_t(), lwpv_t);
  TTS_EXPR_IS(wpv_t() != wpv_t(), lwpv_t);
  TTS_EXPR_IS(wpv_t() < wpv_t(), lwpv_t);
  TTS_EXPR_IS(wpv_t() > wpv_t(), lwpv_t);
  TTS_EXPR_IS(wpv_t() == pv_t(), lwpv_t);
  TTS_EXPR_IS(pv_t() == wpv_t(), lwpv_t);
  TTS_EXPR_IS(wpv_t() != pv_t(), lwpv_t);
  TTS_EXPR_IS(pv_t() != wpv_t(), lwpv_t);
  TTS_EXPR_IS(wpv_t() < pv_t(), lwpv_t);
  TTS_EXPR_IS(pv_t() < wpv_t(), lwpv_t);
  TTS_EXPR_IS(wpv_t() > pv_t(), lwpv_t);
  TTS_EXPR_IS(pv_t() > wpv_t(), lwpv_t);
  TTS_EXPR_IS(pv_t() > pv_t(), lpv_t);
  TTS_EXPR_IS(pv_t() < pv_t(), lpv_t);
  TTS_EXPR_IS(pv_t() == pv_t(), lpv_t);
  TTS_EXPR_IS(pv_t() != pv_t(), lpv_t);

  TTS_EXPR_IS(wT() == wpv_t(), lwpv_t);
  TTS_EXPR_IS(wT() != wpv_t(), lwpv_t);
  TTS_EXPR_IS(wT() < wpv_t(), lwpv_t);
  TTS_EXPR_IS(wT() > wpv_t(), lwpv_t);
  TTS_EXPR_IS(wT() == pv_t(), lwpv_t);
  TTS_EXPR_IS(T() == wpv_t(), lwpv_t);
  TTS_EXPR_IS(wT() != pv_t(), lwpv_t);
  TTS_EXPR_IS(T() != wpv_t(), lwpv_t);
  TTS_EXPR_IS(wT() < pv_t(), lwpv_t);
  TTS_EXPR_IS(T() < wpv_t(), lwpv_t);
  TTS_EXPR_IS(wT() > pv_t(), lwpv_t);
  TTS_EXPR_IS(T() > wpv_t(), lwpv_t);
  TTS_EXPR_IS(T() > pv_t(), lpv_t);
  TTS_EXPR_IS(T() < pv_t(), lpv_t);
  TTS_EXPR_IS(T() == pv_t(), lpv_t);
  TTS_EXPR_IS(T() != pv_t(), lpv_t);

  TTS_EXPR_IS(wpv_t() == wT(), lwpv_t);
  TTS_EXPR_IS(wpv_t() != wT(), lwpv_t);
  TTS_EXPR_IS(wpv_t() < wT(), lwpv_t);
  TTS_EXPR_IS(wpv_t() > wT(), lwpv_t);
  TTS_EXPR_IS(wpv_t() == T(), lwpv_t);
  TTS_EXPR_IS(pv_t() == wT(), lwpv_t);
  TTS_EXPR_IS(wpv_t() != T(), lwpv_t);
  TTS_EXPR_IS(pv_t() != wT(), lwpv_t);
  TTS_EXPR_IS(wpv_t() < T(), lwpv_t);
  TTS_EXPR_IS(pv_t() < wT(), lwpv_t);
  TTS_EXPR_IS(wpv_t() > T(), lwpv_t);
  TTS_EXPR_IS(pv_t() > wT(), lwpv_t);
  TTS_EXPR_IS(pv_t() > T(), lpv_t);
  TTS_EXPR_IS(pv_t() < T(), lpv_t);
  TTS_EXPR_IS(pv_t() == T(), lpv_t);
  TTS_EXPR_IS(pv_t() != T(), lpv_t);
}
}
;
