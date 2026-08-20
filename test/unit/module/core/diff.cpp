//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check add three params",
              plf::scalar_real_types,
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000)
             )
  <typename T>(T const& a0, T const& a1, T const& a2,
               T const& a3, T const& a4, T const& a5,
               T const& a6, T const& a7, T const& a8,
               T const& a9, T const& a10, T const& a11)
{
  using plf::diff;
  {
    using pv_t  = plf::polyfloat<T, 2>;
    pv_t pa0(a0, a1);
    pv_t pa1(a3, a4);
    pv_t pa2(a6, a7);
    pv_t pa3(a9, a10);
    {
      auto d = diff((pa0), (pa1), (pa2), (pa3));
      TTS_EQUAL(get<0>(d), pa0-pa1);
      TTS_EQUAL(get<1>(d), pa1-pa2);
      TTS_EQUAL(get<2>(d), pa2-pa3);
    }
    {
      auto d = diff(kumi::index_t<1>(), (pa0), (pa1), (pa2), (pa3));
      TTS_EQUAL(get<0>(d), pa0-pa1);
      TTS_EQUAL(get<1>(d), pa1-pa2);
      TTS_EQUAL(get<2>(d), pa2-pa3);
      auto d2 = diff(kumi::index_t<2>(), (pa0), (pa1), (pa2), (pa3));
      TTS_EQUAL(get<0>(d2), (pa0-pa1)-(pa1-pa2));
      TTS_EQUAL(get<1>(d2), (pa1-pa2)-(pa2-pa3));
    }
  }
  {
    using pv_t  = plf::polyfloat<T, 3>;
    pv_t pa0(a0, a1, a2);
    pv_t pa1(a3, a4, a5);
    pv_t pa2(a6, a7, a8);
    pv_t pa3(a9, a10, a11);
    {
      auto d = diff((pa0), (pa1), (pa2), (pa3));
      TTS_EQUAL(get<0>(d), pa0-pa1);
      TTS_EQUAL(get<1>(d), pa1-pa2);
      TTS_EQUAL(get<2>(d), pa2-pa3);
    }
    {
      auto d = diff(kumi::index_t<1>(), (pa0), (pa1), (pa2), (pa3));
      TTS_EQUAL(get<0>(d), pa0-pa1);
      TTS_EQUAL(get<1>(d), pa1-pa2);
      TTS_EQUAL(get<2>(d), pa2-pa3);
      auto d2 = diff(kumi::index_t<2>(), (pa0), (pa1), (pa2), (pa3));
      TTS_EQUAL(get<0>(d2), (pa0-pa1)-(pa1-pa2));
      TTS_EQUAL(get<1>(d2), (pa1-pa2)-(pa2-pa3));
    }
  }

  {
    using pv_t  = plf::triple_real_t<eve::wide<T, eve::fixed<2>>>;
    pv_t pa0(a0, a1, a2);
    pv_t pa1(a3, a4, a5);
    pv_t pa2(a6, a7, a8);
    pv_t pa3(a9, a10, a11);
    {
      auto d = diff((pa0), (pa1), (pa2), (pa3));
      TTS_EQUAL(get<0>(d), pa0-pa1);
      TTS_EQUAL(get<1>(d), pa1-pa2);
      TTS_EQUAL(get<2>(d), pa2-pa3);
    }
    {
      auto d = diff(kumi::index_t<1>(), (pa0), (pa1), (pa2), (pa3));
      TTS_EQUAL(get<0>(d), pa0-pa1);
      TTS_EQUAL(get<1>(d), pa1-pa2);
      TTS_EQUAL(get<2>(d), pa2-pa3);
      auto d2 = diff(kumi::index_t<2>(), (pa0), (pa1), (pa2), (pa3));
      TTS_EQUAL(get<0>(d2), (pa0-pa1)-(pa1-pa2));
      TTS_EQUAL(get<1>(d2), (pa1-pa2)-(pa2-pa3));
    }
  }
};
