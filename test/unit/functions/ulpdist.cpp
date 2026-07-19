//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check ulpdist two params",
              plf::scalar_real_types,
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000)
            )
<typename T>(T const& a0, T const&  , T const& ,
             T const& a3, T const& , T const& )
{
  {
    using pv_t  = T;
    pv_t pa(a0);
    pv_t pb(a3);
    TTS_EQUAL(plf::ulpdist(pa, pb), eve::ulpdist(pa, pb));
    TTS_EQUAL(plf::ulpdist(1.0, eve::next(1.0)), eve::ulpdist(1.0, eve::next(1.0)));
    TTS_EQUAL(plf::ulpdist(1.0, 2.0),            eve::ulpdist(1.0, 2.0));
  }
};
