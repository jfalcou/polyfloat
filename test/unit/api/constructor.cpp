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
  std::cout << "a " << a << std::endl;
  auto b = plf::twofloat_t<wT>(wT(1));
  std::cout << "b " << b << std::endl;


  pv_t a2(T(1.0), T(0.1));
  std::cout << "a2 " << a2 << std::endl;
  using wT2    = eve::wide<T, eve::fixed<2>>;
 using wpv_t2 = eve::wide<plf::polyfloat<T, 2>, eve::fixed<2>>;
  wpv_t2 wa2(wT2(1.0), wT2(0.1));
  std::cout << "wa2 " << wa2 << std::endl;

  std::cout << pv_t(eve::inf(eve::as<T>())) << std::endl;
  std::cout << pv_t(eve::nan(eve::as<T>())) << std::endl;
  std::cout << wpv_t(eve::inf(eve::as<T>())) << std::endl;
  std::cout << wpv_t(eve::nan(eve::as<T>())) << std::endl;
  std::cout << pv_t(eve::inf(eve::as<T>()), eve::zero(eve::as<T>())) << std::endl;
  std::cout << pv_t(eve::nan(eve::as<T>()), eve::zero(eve::as<T>())) << std::endl;
  std::cout << wpv_t(eve::inf(eve::as<T>()), eve::zero(eve::as<T>())) << std::endl;
  std::cout << wpv_t(eve::nan(eve::as<T>()), eve::zero(eve::as<T>())) << std::endl;
  std::cout << wpv_t(eve::inf(eve::as<T>()), eve::inf(eve::as<T>()))  << std::endl;


};
