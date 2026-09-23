//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check neville params",
              plf::scalar_real_types,
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000))
<typename T>(
  T const& a0, T const& a1, T const& a2, T const& a3, T const& a4, T const& a5, T const& a6, T const& a7, T const& a8)
{
  using plf::horner;
  using plf::neville;
  {
    using pv_t = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    pv_t pc(a6, a7);
    pv_t o(1);
    auto y0 = plf::horner(pa, o, 2 * o, 3 * o);
    auto y1 = plf::horner(pb, o, 2 * o, 3 * o);
    auto y2 = plf::horner(pc, o, 2 * o, 3 * o);
    pv_t x(1.0);
    TTS_RELATIVE_EQUAL(neville(x, pa, pb, pc, y0, y1, y2), horner(x, o, 2 * o, 3 * o), 1000 * tts::epsprec<pv_t>());
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t pb(a3, a4, a5);
    pv_t pc(a6, a7, a8);
    pv_t o(1);
    auto y0 = plf::horner(pa, o, 2 * o, 3 * o);
    auto y1 = plf::horner(pb, o, 2 * o, 3 * o);
    auto y2 = plf::horner(pc, o, 2 * o, 3 * o);
    pv_t x(1.0);
    TTS_RELATIVE_EQUAL(neville(x, pa, pb, pc, y0, y1, y2), plf::horner(x, o, 2 * o, 3 * o),
                       1000 * tts::epsprec<pv_t>());
  }
};
