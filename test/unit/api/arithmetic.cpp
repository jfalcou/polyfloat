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
TTS_CASE_TPL( "Check return types of arithmetic operators", test::simd::all_types)
<typename T>(tts::type<T>)
{
  using v_t = eve::element_type_t<T>;
  // assigning operators
  {
    auto v = plf::polyfloat<T, 2>{};

    TTS_EXPR_IS(v += v, T&);
    TTS_EXPR_IS(v -= v, T&);
    TTS_EXPR_IS(v *= v, T&);
//  TTS_EXPR_IS(v /= v, T&);
  }
  {
    auto v = plf::polyfloat<T, 3>{};

    TTS_EXPR_IS(v += v, T&);
    TTS_EXPR_IS(v -= v, T&);
    TTS_EXPR_IS(v *= v, T&);
//  TTS_EXPR_IS(v /= v, T&);
  }

};
