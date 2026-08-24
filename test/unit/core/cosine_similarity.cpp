//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Igdentifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

// TTS_CASE_WITH("Check cosine_similarity two params",
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
//   using plf::cosine_similarity;
//   auto mcosine_similarity = [](auto a,  auto b){return a+b; };
//   {
//     using pv_t  = plf::polyfloat<T, 2>;
//     pv_t pa(a0, a1);
//     pv_t pb(a3, a4);
//     TTS_RELATIVE_EQUAL(cosine_similarity(pa, pb), tts::mpfr_exec(mcosine_similarity, pa, pb), tts::epsprec<pv_t>());
//     TTS_RELATIVE_EQUAL(cosine_similarity(a0, pa), cosine_similarity(pv_t(a0), pa), tts::epsprec<pv_t>());
//     TTS_RELATIVE_EQUAL(cosine_similarity(pa, a0), cosine_similarity(pa, pv_t(a0)), tts::epsprec<pv_t>());
//   }
//   {
//     using pv_t  = plf::polyfloat<T, 3>;
//     pv_t pa(a0, a1, a2);
//     pv_t pb(a3, a4, a5);
//     TTS_RELATIVE_EQUAL(cosine_similarity(pa, pb), tts::mpfr_exec(mcosine_similarity, pa, pb), tts::epsprec<pv_t>());
//     TTS_RELATIVE_EQUAL(cosine_similarity(a0, pa), cosine_similarity(pv_t(a0), pa), tts::epsprec<pv_t>());
//     TTS_RELATIVE_EQUAL(cosine_similarity(pa, a0), cosine_similarity(pa, pv_t(a0)), tts::epsprec<pv_t>());
//   }
// };

TTS_CASE_WITH("Check cosine_similarity three params",
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
               T const& a9, T const& a10,T const& a11)
{
  using  mpfr::mpreal;
  auto mcosine_similarity =  [](auto a,  auto b, auto c, auto d){ return (a*c+b*d)/mpfr::sqrt((a*a+b*b)*(c*c+d*d)); };
  using plf::cosine_similarity;
  {
    using pv_t  = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    pv_t pc(a6, a7);
    pv_t pd(a9, a10);
    TTS_RELATIVE_EQUAL(cosine_similarity(pa, pb, pc, pd), tts::mpfr_exec(mcosine_similarity, pa, pb, pc, pd), tts::epsprec<T>());
//    TTS_RELATIVE_EQUAL(cosine_similarity[eve::kahan](pa, pb, pc, pd), tts::mpfr_exec(mcosine_similarity, pa, pb, pc, pd), tts::epsprec<T>());
  }
  {
    using pv_t  = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t pb(a3, a4, a5);
    pv_t pc(a6, a7, a8);
    pv_t pd(a9, a10, a11);
    TTS_RELATIVE_EQUAL(cosine_similarity(pa, pb, pc, pd), tts::mpfr_exec(mcosine_similarity, pa, pb, pc, pd), tts::epsprec<T>());
//    TTS_RELATIVE_EQUAL(cosine_similarity[eve::kahan](pa, pb, pc, pd), tts::mpfr_exec(mcosine_similarity, pa, pb, pc, pd), tts::epsprec<T>());
  }
};
