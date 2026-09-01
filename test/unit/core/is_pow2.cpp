//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check is_pow2 params",
              plf::scalar_real_types,
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax)

)
<typename T>(T const& a0, T const& a1, T const& a2)
{
  using mpfr::mpreal;
  using plf::is_pow2;
  {
    using pv_t = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    TTS_EXPECT(eve::all(!is_pow2(pa)));
    TTS_EXPECT(eve::all(is_pow2(pv_t(2))));
    TTS_EXPECT(eve::all(is_pow2(pv_t(0.5))));
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    TTS_EXPECT(eve::all(!is_pow2(pa)));
    TTS_EXPECT(eve::all(is_pow2(pv_t(2))));
    TTS_EXPECT(eve::all(is_pow2(pv_t(0.5))));
  }
};
