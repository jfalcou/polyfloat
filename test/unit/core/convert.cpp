//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

//==================================================================================================
// Types tests
//==================================================================================================
TTS_CASE_TPL( "Check convert", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
   using pv_t2  = plf::polyfloat<T, 2>;
   using pv_t3  = plf::polyfloat<T, 3>;
   using wpv_t2 = eve::wide<pv_t2, eve::fixed<2>>;
   using wpv_t3 = eve::wide<pv_t3, eve::fixed<2>>;

   pv_t2 pva2(1.0, 1.0e-300);
   pv_t3 pva3(1.0, 1.0e-300, 0.0);
   wpv_t2 wpva2(pva2);
   wpv_t3 wpva3(pva3);
   TTS_EQUAL(pva3, plf::convert(pva2, eve::as<pv_t3>()));
   TTS_EQUAL(wpva3, plf::convert(wpva2, eve::as<pv_t3>()));
};
