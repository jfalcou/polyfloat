//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH(
  "Check sqr", plf::scalar_real_types, tts::randoms(-1000, 1000), tts::randoms(-1000, 1000), tts::randoms(-1000, 1000))
<typename T>(T const& a0, T const& a1, T const& a2)
{
  using plf::sqr;
  {
    {
      using pv_t = plf::polyfloat<T, 2>;
      pv_t pa(a0, a1);
      TTS_RELATIVE_EQUAL(sqr(pa), pa * pa, tts::epsprec<pv_t>());
    }
    {
      using pv_t = plf::polyfloat<T, 3>;
      pv_t pa(a0, a1, a2);
      TTS_RELATIVE_EQUAL(sqr(pa), pa * pa, tts::epsprec<pv_t>());
    }
  }
};
