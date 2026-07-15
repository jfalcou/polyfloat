//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>


TTS_CASE_WITH("Check ldexp",
              plf::scalar_real_types,
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax)
             )
  <typename T>(T const& a0, T const& a1, T const& a2)
{
  {
    using pv_t  = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    auto lpa = plf::ldexp(pa, T(2));
    TTS_EXPECT(plf::ulpdist(pa, plf::ldexp(lpa, -2)) <=  0.5);
  }
  {
    using pv_t  = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    auto lpa = plf::ldexp(pa, T(2));
    TTS_EXPECT(plf::ulpdist(pa, plf::ldexp(lpa, -2)) <=  0.5);
  }
};
