//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check trapz two params",
              plf::scalar_real_types,
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000)
             )
  <typename T>(T const& a0, T const& a1, T const& a2,
               T const& a3, T const& a4, T const& a5)
{
  using  mpfr::mpreal;
  using plf::trapz;
  using plf::sqr;
  auto mtrapz = [](auto a,  auto b){return (a+b)/2; };
  auto mtrapz2= [](auto a,  auto b){return (b-a)*(a*a+b*b)/2; };
  {
    using pv_t  = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    pv_t dx(a0, a5);
    TTS_EQUAL(trapz(pa, pb), tts::mpfr_exec(mtrapz, pa, pb));
    TTS_RELATIVE_EQUAL(trapz(a0, pa), trapz(pv_t(a0), pa), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(trapz(pa, a0), trapz(pa, pv_t(a0)), tts::epsprec<pv_t>());
    TTS_EQUAL(trapz(dx, kumi::tuple{pa, pb}), dx*tts::mpfr_exec(mtrapz, pa, pb));
    TTS_EQUAL(trapz(kumi::tuple{T(0), T(1)}, kumi::tuple{pa, pb}), tts::mpfr_exec(mtrapz, pa, pb));
    TTS_RELATIVE_EQUAL(trapz(sqr,  pa, pb), tts::mpfr_exec(mtrapz2, pa, pb), 2*tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(trapz(sqr, kumi::tuple{pa, pb}), tts::mpfr_exec(mtrapz2, pa, pb), 2*tts::epsprec<pv_t>());
  }
  {
    using pv_t  = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t pb(a3, a4, a5);
    pv_t dx(a0, a5, a2);
    TTS_EQUAL(trapz(pa, pb), tts::mpfr_exec(mtrapz, pa, pb));
    TTS_RELATIVE_EQUAL(trapz(a0, pa), trapz(pv_t(a0), pa), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(trapz(pa, a0), trapz(pa, pv_t(a0)), tts::epsprec<pv_t>());
    TTS_EQUAL(trapz(dx, kumi::tuple{pa, pb}), dx*tts::mpfr_exec(mtrapz, pa, pb));
    TTS_EQUAL(trapz(kumi::tuple{T(0), T(1)}, kumi::tuple{pa, pb}), tts::mpfr_exec(mtrapz, pa, pb));
    TTS_RELATIVE_EQUAL(trapz(sqr,  pa, pb), tts::mpfr_exec(mtrapz2, pa, pb), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(trapz(sqr, kumi::tuple{pa, pb}), tts::mpfr_exec(mtrapz2, pa, pb), tts::epsprec<pv_t>());
  }
};


TTS_CASE_WITH("Check trapz three params",
              plf::scalar_real_types,
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
               T const& a6, T const& a7, T const& a8)
{
  using  mpfr::mpreal;
  using plf::trapz;
  using plf::sqr;
  auto mtrapz = [](auto a,  auto b,  auto c){return a/2+b+c/2; };
  auto mtrapz2= [](auto a,  auto b,  auto c){return (b-a)*(a*a+b*b)/2+(c-b)*(c*c+b*b)/2; };
  {
    using pv_t  = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    pv_t pc(a6, a7);
    pv_t dx(a0, a5);
    TTS_RELATIVE_EQUAL(trapz(pa, pb, pc), tts::mpfr_exec(mtrapz, pa, pb, pc), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(trapz(a0, pa, pc), trapz(pv_t(a0), pa, pc), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(trapz(pa, a0, pc), trapz(pa, pv_t(a0), pc), tts::epsprec<pv_t>());
    TTS_EQUAL(trapz(dx, kumi::tuple{pa, pb, pc}), dx*tts::mpfr_exec(mtrapz, pa, pb, pc));
    TTS_EQUAL(trapz(kumi::tuple{T(0), T(1), T(2)}, kumi::tuple{pa, pb, pc}), tts::mpfr_exec(mtrapz, pa, pb, pc));
    TTS_RELATIVE_EQUAL(trapz(sqr,  pa, pb, pc), tts::mpfr_exec(mtrapz2, pa, pb, pc), 12*tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(trapz(sqr, kumi::tuple{pa, pb, pc}), tts::mpfr_exec(mtrapz2, pa, pb, pc), 12*tts::epsprec<pv_t>());
  }
  {
    using pv_t  = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t pb(a3, a4, a5);
    pv_t pc(a6, a7, a8);
    pv_t dx(a0, a5, a2);
    TTS_RELATIVE_EQUAL(trapz(pa, pb, pc), tts::mpfr_exec(mtrapz, pa, pb, pc), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(trapz(a0, pa, pc), trapz(pv_t(a0), pa, pc), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(trapz(pa, a0, pc), trapz(pa, pv_t(a0), pc), tts::epsprec<pv_t>());
    TTS_EQUAL(trapz(dx, kumi::tuple{pa, pb, pc}), dx*tts::mpfr_exec(mtrapz, pa, pb, pc));
    TTS_EQUAL(trapz(kumi::tuple{T(0), T(1), T(2)}, kumi::tuple{pa, pb, pc}), tts::mpfr_exec(mtrapz, pa, pb, pc));
    TTS_RELATIVE_EQUAL(trapz(sqr,  pa, pb, pc), tts::mpfr_exec(mtrapz2, pa, pb, pc), 2*tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(trapz(sqr, kumi::tuple{pa, pb, pc}), tts::mpfr_exec(mtrapz2, pa, pb, pc), 2*tts::epsprec<pv_t>());
  }
};
