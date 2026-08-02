//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check lerp",
              plf::scalar_real_types,
              tts::randoms(eve::zero, 1000),
              tts::randoms(eve::zero, 1000),
              tts::randoms(eve::zero, 1000),
              tts::randoms(eve::zero, 1000),
              tts::randoms(eve::zero, 1000),
              tts::randoms(eve::zero, 1000),
              tts::randoms(eve::zero, 1),
              tts::randoms(eve::zero, 1),
              tts::randoms(eve::zero, 1)
             )
  <typename T>(T const& a0, T const& a1, T const& a2,
               T const& a3, T const& a4, T const& a5,
               T const& a6, T const& a7, T const& a8)
{
  using plf::lerp;
  {
    using pv_t  = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    pv_t t(a6, a7);
    TTS_ULP_EQUAL(lerp(pa, pb, t), pb*t+pa*(1-t), 0.5);
  }
  {
    using pv_t  = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t pb(a3, a4, a5);
    pv_t t(a6, a7, a8);
    TTS_ULP_EQUAL(lerp(pa, pb, t), pb*t+pa*(1-t), 0.5);
  }
};
