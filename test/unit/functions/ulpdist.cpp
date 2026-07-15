//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>
#include <iomanip>

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
//     std::cout << "pa "<<  pa << std::endl;
//     std::cout << "pb "<<  pb << std::endl;
//     std::cout << "eve::dist(pa, pb) "<<  eve::dist(pa, pb) << std::endl;
//     std::cout << "eve::plf(pa, pb) "<<  plf::dist(pa, pb) << std::endl;
    TTS_EQUAL(plf::ulpdist(pa, pb), eve::ulpdist(pa, pb));
    TTS_EQUAL(plf::ulpdist(1.0, eve::next(1.0)), eve::ulpdist(1.0, eve::next(1.0)));
    TTS_EQUAL(plf::ulpdist(1.0, 2.0),            eve::ulpdist(1.0, 2.0));
  }
  {
    using pv_t  = plf::polyfloat<T, 2>;
    pv_t pa(a0);
    pv_t pna(a0, eve::next(eve::zero(eve::as(a0))));
    pv_t pnha(eve::next(a0));
    pv_t pna2((pa+pnha)*T(0.5));
    std::cout << std::setprecision(2*sizeof(T)+1);
    std::cout << "pa                                   "<<  pa <<  std::endl;
    std::cout << "pna                                  "<<  pna <<  std::endl;
    std::cout << "pnha                                 "<<  pnha <<  std::endl;
    std::cout << "pna2                                 "<<  pna2 <<  std::endl;
    std::cout << "plf::hi(plf::dist(eve::plf(pa, pna)) "<<  plf::hi(plf::dist(pa, pna)) << std::endl;
    std::cout << "plf::ulpdist(pa, pna)                " << plf::hi(plf::ulpdist(pa, pna)) << std::endl;
    std::cout << "plf::ulpdist(pa, pnha)               " << plf::hi(plf::ulpdist(pa, pnha)) << std::endl;
    std::cout << "plf::ulpdist(a0, eve::next(a0))      " << plf::hi(plf::ulpdist(a0, eve::next(a0))) << std::endl;
    std::cout << "plf::ulpdist(pa, pna2)               " << plf::hi(plf::ulpdist(pa, pna2)) << std::endl;

  }
//   {
//     using pv_t  = plf::polyfloat<T, 2>;
//     pv_t pa(a0, a1);
//     pv_t pb(a3, a4);
//     TTS_EQUAL(plf::ulpdist(pa, pb), plf::if_else(plf::is_less(pa, pb), pb, pa));
//   }
//   {
//     using pv_t  = plf::polyfloat<T, 3>;
//     pv_t pa(a0, a1, a2);
//     pv_t pb(a3, a4, a5);
//     TTS_EQUAL(plf::ulpdist(pa, pb), plf::if_else(plf::is_less(pa, pb), pb, pa));
//   }
};
