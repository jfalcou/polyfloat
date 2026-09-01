//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check add two params",
              plf::scalar_real_types,
              tts::randoms(-1000, 1000),
              tts::randoms(-1e-30, 1e-30),
              tts::randoms(-1e-35, 1e-35),
              tts::randoms(-1000, 1000),
              tts::randoms(-1e-30, 1e-30),
              tts::randoms(-1e-35, 1e-35)

)
<typename T>(T const& a0, T const& a1, T const& a2, T const& a3, T const& a4, T const& a5)
{
  using mpfr::mpreal;
  using plf::add;
  {
    using pv_t = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    auto [s, e] = plf::two_add(pa, pb);
    std::cout << s << ",    " << e << std::endl;
    auto z0 = tts::to_mpreal(pa) + tts::to_mpreal(pb);
    auto z1 = tts::to_mpreal(s) + tts::to_mpreal(e);
    TTS_EQUAL(z0, z1);
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t pb(a3, a4, a5);
    auto [s, e] = plf::two_add(pa, pb);
    std::cout << s << " ,   " << e << std::endl;
    auto z0 = tts::to_mpreal(pa) + tts::to_mpreal(pb);
    auto z1 = tts::to_mpreal(s) + tts::to_mpreal(e);
    TTS_EQUAL(z0, z1);
  }
};

// TTS_CASE_WITH("Check add three params",
//               plf::scalar_real_types,
//               tts::randoms(-1000, 1000),
//               tts::randoms(-1000, 1000),
//               tts::randoms(-1000, 1000),
//               tts::randoms(-1000, 1000),
//               tts::randoms(-1000, 1000),
//               tts::randoms(-1000, 1000),
//               tts::randoms(-1000, 1000),
//               tts::randoms(-1000, 1000),
//               tts::randoms(-1000, 1000)
//              )
//   <typename T>(T const& a0, T const& a1, T const& a2,
//                T const& a3, T const& a4, T const& a5,
//                T const& a6, T const& a7, T const& a8)
// {
//   using  mpfr::mpreal;
//   using plf::add;
//   {
//     using pv_t  = plf::polyfloat<T, 2>;
//     pv_t pa(a0, a1);
//     pv_t pb(a3, a4);
//     pv_t pc(a6, a7);
//     TTS_EQUAL( tts::to_mpreal(add(pa, pb, pc)), (tts::to_mpreal(pa)+tts::to_mpreal(pb)+tts::to_mpreal(pc)));
//     TTS_RELATIVE_EQUAL(add(a0, pa, pc), add(pv_t(a0), pa, pc), tts::epsprec<pv_t>());
//     TTS_RELATIVE_EQUAL(add(pa, a0, pc), add(pa, pv_t(a0), pc), tts::epsprec<pv_t>());
//   }
//   {
//     using pv_t  = plf::polyfloat<T, 3>;
//     pv_t pa(a0, a1, a2);
//     pv_t pb(a3, a4, a5);
//     pv_t pc(a6, a7, a8);
//     TTS_EQUAL( tts::to_mpreal(add(pa, pb, pc)), (tts::to_mpreal(pa)+tts::to_mpreal(pb)+tts::to_mpreal(pc)));
//     TTS_RELATIVE_EQUAL(add(a0, pa, pc), add(pv_t(a0), pa, pc), tts::epsprec<pv_t>());
//     TTS_RELATIVE_EQUAL(add(pa, a0, pc), add(pa, pv_t(a0), pc), tts::epsprec<pv_t>());
//   }
// };
