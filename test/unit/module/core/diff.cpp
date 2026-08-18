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
};

// TTS_CASE_WITH("Check behavior of diff on all types full range",
//               eve::test::scalar::ieee_reals,
//               tts::generate(tts::randoms(-100, 100),
//                             tts::randoms(-100, 100),
//                             tts::randoms(-100, 100),
//                             tts::randoms(-100, 100)))
//   <typename T>(T const& a0, T const& a1, T const& a2, T const& a3)
// {
//   using eve::diff;
//   {
//     auto d = diff((a0), (a1), (a2), (a3));
//     TTS_EQUAL(get<0>(d), a0-a1);
//     TTS_EQUAL(get<1>(d), a1-a2);
//     TTS_EQUAL(get<2>(d), a2-a3);
//   }
//   {
//     auto d = diff(kumi::index_t<1>(), (a0), (a1), (a2), (a3));
//     TTS_EQUAL(get<0>(d), a0-a1);
//     TTS_EQUAL(get<1>(d), a1-a2);
//     TTS_EQUAL(get<2>(d), a2-a3);
//     auto d2 = diff(kumi::index_t<2>(), (a0), (a1), (a2), (a3));
//     TTS_EQUAL(get<0>(d2), (a0-a1)-(a1-a2));
//     TTS_EQUAL(get<1>(d2), (a1-a2)-(a2-a3));
//   }
// };

// TTS_CASE_WITH("Check add two params",
//               plf::scalar_real_types,
//               tts::randoms(-1000, 1000),
//               tts::randoms(-1000, 1000),
//               tts::randoms(-1000, 1000),
//               tts::randoms(-1000, 1000),
//               tts::randoms(-1000, 1000),
//               tts::randoms(-1000, 1000)
//              )
//   <typename T>(T const& a0, T const& a1, T const& a2,
//                T const& a3, T const& a4, T const& a5)
// {
//   using  mpfr::mpreal;
//   using plf::add;
//   auto madd = [](auto a,  auto b){return a+b; };
//   {
//     using pv_t  = plf::polyfloat<T, 2>;
//     pv_t pa(a0, a1);
//     pv_t pb(a3, a4);
//     TTS_RELATIVE_EQUAL(add(pa, pb), tts::mpfr_exec(madd, pa, pb), tts::epsprec<pv_t>());
//     TTS_RELATIVE_EQUAL(add(a0, pa), add(pv_t(a0), pa), tts::epsprec<pv_t>());
//     TTS_RELATIVE_EQUAL(add(pa, a0), add(pa, pv_t(a0)), tts::epsprec<pv_t>());
//   }
//   {
//     using pv_t  = plf::polyfloat<T, 3>;
//     pv_t pa(a0, a1, a2);
//     pv_t pb(a3, a4, a5);
//     TTS_RELATIVE_EQUAL(add(pa, pb), tts::mpfr_exec(madd, pa, pb), tts::epsprec<pv_t>());
//     TTS_RELATIVE_EQUAL(add(a0, pa), add(pv_t(a0), pa), tts::epsprec<pv_t>());
//     TTS_RELATIVE_EQUAL(add(pa, a0), add(pa, pv_t(a0)), tts::epsprec<pv_t>());
//   }
// };

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
