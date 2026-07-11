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
TTS_CASE_TPL( "Check constructors", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
  using pv_t  = plf::polyfloat<T, 2>;
  using wpv_t = eve::wide<pv_t>;
  using wT    = eve::wide<T>;
  TTS_EXPR_IS( wpv_t()  , wpv_t);
  TTS_EXPR_IS( pv_t()   , pv_t);
  TTS_EXPR_IS( plf::polyfloat(T()), pv_t);
  TTS_EXPR_IS( eve::wide<pv_t>(), wpv_t);
  TTS_EXPR_IS( (plf::as_polyfloat_n_t<2, wT>()), wpv_t);

  auto a = plf::twofloat_t<T>(T(1));
  std::cout << a << std::endl;
  auto b = plf::twofloat_t<wT>(wT(1));
  std::cout << b << std::endl;


};
