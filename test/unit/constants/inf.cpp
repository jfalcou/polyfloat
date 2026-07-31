//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_TPL("Check inf",
              plf::scalar_real_types
             )
<typename T>(tts::type<T>)
{
  {
    using pv_t  = plf::polyfloat<T, 2>;
    TTS_EXPECT(eve::is_infinite(plf::hi(plf::inf(eve::as<pv_t>()))));
  }
  {
    using pv_t  = plf::polyfloat<T, 3>;
    TTS_EXPECT(eve::is_infinite(plf::hi(plf::inf(eve::as<pv_t>()))));
  }
};
