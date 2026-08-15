//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>


 struct mmax{
   template < typename T> auto operator()(T a0)
   { return a0; }
   template < typename T> auto  operator()(T a0, T a1)
   { return mpfr::max(a0, a1); }
   template < typename T> auto  operator()(T a0, T a1, T a2)
   { return mpfr::max(mpfr::max(a0, a1), a2); }
 };

TTS_CASE_WITH("Check cumfun two params",
              plf::scalar_real_types,
              tts::randoms(-1000, 1000),
              tts::randoms(-1e-30, 1e-30),
              tts::randoms(-1e-35, 1e-35), 
              tts::randoms(-1000, 1000),
              tts::randoms(-1e-30, 1e-30),
              tts::randoms(-1e-35, 1e-35)
//                tts::randoms(-1000, 1000),
//               tts::randoms(-1000, 1000),
//               tts::randoms(-1000, 1000),
//               tts::randoms(-1000, 1000),
//               tts::randoms(-1000, 1000),
//               tts::randoms(-1000, 1000)
             )
  <typename T>(T const& a0, T const& a1, T const& a2,
               T const& a3, T const& a4, T const& a5)
{
  using  mpfr::mpreal;
  using plf::cumfun;
  using plf::max;
  auto mcs  = [](auto a0,  auto a1){return kumi::make_tuple(tts::mpfr_exec(mmax(), a0),
                                                            tts::mpfr_exec(mmax(), a0, a1)
                                                           ); };
  {
    using pv_t  = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    TTS_RELATIVE_EQUAL(kumi::get<0>(cumfun(max, pa, pb)), kumi::get<0>(mcs(pa, pb)), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(kumi::get<1>(cumfun(max, pa, pb)), kumi::get<1>(mcs(pa, pb)), tts::epsprec<pv_t>());
  }
  {
    using pv_t  = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t pb(a3, a4, a5);
    TTS_RELATIVE_EQUAL(kumi::get<0>(cumfun(max, pa, pb)), kumi::get<0>(mcs(pa, pb)), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(kumi::get<1>(cumfun(max, pa, pb)), kumi::get<1>(mcs(pa, pb)), tts::epsprec<pv_t>());
  }
};

TTS_CASE_WITH("Check cumfun three params",
              plf::scalar_real_types,
              tts::randoms(-1000, 1000),
              tts::randoms(-1e-30, 1e-30),
              tts::randoms(-1e-35, 1e-35), 
              tts::randoms(-1000, 1000),
              tts::randoms(-1e-30, 1e-30),
              tts::randoms(-1e-35, 1e-35), 
              tts::randoms(-1000, 1000),
              tts::randoms(-1e-30, 1e-30),
              tts::randoms(-1e-35, 1e-35)
              //              tts::randoms(-1000, 1000),
//               tts::randoms(-1000, 1000),
//               tts::randoms(-1000, 1000),
//               tts::randoms(-1000, 1000),
//               tts::randoms(-1000, 1000),
//               tts::randoms(-1000, 1000),
//               tts::randoms(-1000, 1000),
//               tts::randoms(-1000, 1000),
//               tts::randoms(-1000, 1000)
             )
  <typename T>(T const& a0, T const& a1, T const& a2,
               T const& a3, T const& a4, T const& a5,
               T const& a6, T const& a7, T const& a8)
{
  using  mpfr::mpreal;
  using plf::cumfun;
  using plf::max;
  auto mcs  = [](auto a0,  auto a1,  auto a2){return kumi::make_tuple(tts::mpfr_exec(mmax(), a0),
                                                                          tts::mpfr_exec(mmax(), a0, a1),
                                                                          tts::mpfr_exec(mmax(), a0, a1, a2)
                                                           ); };
  {
    using pv_t  = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    pv_t pc(a6, a7);
    TTS_RELATIVE_EQUAL(kumi::get<0>(cumfun(max, pa, pb, pc)), kumi::get<0>(mcs(pa, pb, pc)), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(kumi::get<1>(cumfun(max, pa, pb, pc)), kumi::get<1>(mcs(pa, pb, pc)), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(kumi::get<2>(cumfun(max, pa, pb, pc)), kumi::get<2>(mcs(pa, pb, pc)), tts::epsprec<pv_t>());
  }
  {
    using pv_t  = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t pb(a3, a4, a5);
    pv_t pc(a6, a7, a8);
    TTS_RELATIVE_EQUAL(kumi::get<0>(cumfun(max, pa, pb, pc)), kumi::get<0>(mcs(pa, pb, pc)), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(kumi::get<1>(cumfun(max, pa, pb, pc)), kumi::get<1>(mcs(pa, pb, pc)), tts::epsprec<pv_t>());
    TTS_RELATIVE_EQUAL(kumi::get<2>(cumfun(max, pa, pb, pc)), kumi::get<2>(mcs(pa, pb, pc)), tts::epsprec<pv_t>());
  }
};
