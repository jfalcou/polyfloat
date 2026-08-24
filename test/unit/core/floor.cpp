//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check floor",
              plf::scalar_real_types,
              tts::randoms(-1000,1000),
              tts::randoms(-1000,1000),
              tts::randoms(-1000,1000)
             )
  <typename T>(T const& a0, T const& a1, T const& a2)
{
  using  mpfr::mpreal;
  using plf::floor;
  {
    {
      using pv_t  = plf::polyfloat<T, 2>;
      pv_t pa(a0, a1);
      pv_t fpa = plf::floor(pa);
      TTS_EXPECT(pa >=  fpa);
      TTS_EXPECT(fpa >= plf::dec(pa));
      TTS_EXPECT(plf::is_flint(fpa));
    }
    {
      using pv_t  = plf::polyfloat<T, 3>;
      pv_t pa(a0, a1, a2);
      pv_t fpa = plf::floor(pa);
      TTS_EXPECT(pa >=  fpa);
      TTS_EXPECT(fpa >= plf::dec(pa));
      TTS_EXPECT(plf::is_flint(fpa));
    }
  }
};
