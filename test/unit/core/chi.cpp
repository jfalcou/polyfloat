//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check abs",
              plf::scalar_real_types,
              tts::randoms(eve::zero, 1000),
              tts::randoms(eve::zero, 1000),
              tts::randoms(eve::zero, 1000),
              tts::randoms(eve::zero, 1000),
              tts::randoms(eve::zero, 1000),
              tts::randoms(eve::zero, 1000),
              tts::randoms(eve::zero, 1000),
              tts::randoms(eve::zero, 1000),
              tts::randoms(eve::zero, 1000))
<typename T>(
  T const& a0, T const& a1, T const& a2, T const& a3, T const& a4, T const& a5, T const& a6, T const& a7, T const& a8)
{
  using plf::chi;
  {
    using pv_t = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    pv_t pc(a6, a7);
    pc += pb;
    TTS_EQUAL(chi(pa, pb, pc), plf::if_else((pa < pb) || (pa >= pc), pv_t(0), pv_t(1)));
    auto belong = [pb, pc](auto x) { return (x >= pb) && (x < pc); };
    TTS_EQUAL(chi(pa, belong), plf::if_else((pa >= pb) && (pa < pc), pv_t(1), pv_t(0)));
    TTS_EQUAL(chi(pa, pb, 2), plf::if_else((pa < pb) || (pa >= T(2)), pv_t(0), pv_t(1)));
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t pb(a3, a4, a5);
    pv_t pc(a6, a7, a8);
    pc += pb;
    TTS_EQUAL(chi(pa, pb, pc), plf::if_else((pa < pb) || (pa >= pc), pv_t(0), pv_t(1)));
    auto belong = [pb, pc](auto x) { return (x >= pb) && (x < pc); };
    TTS_EQUAL(chi(pa, belong), plf::if_else((pa >= pb) && (pa < pc), pv_t(1), pv_t(0)));
    TTS_EQUAL(chi(pa, pb, 2), plf::if_else((pa < pb) || (pa >= T(2)), pv_t(0), pv_t(1)));
  }
};
