//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

    template<typename T>
    constexpr POLYFLOAT_FORCEINLINE
    auto dekker_prod(T a, T b) noexcept
    {
      auto[ah, al] = plf::two_split(a);
      auto[bh, bl] = plf::two_split(b);
      auto abh = a*b;
      auto ahbh= ah*bh;
      auto ahbl= ah*bl;
      auto albh= al*bh;
      auto albl= al*bl;
      auto t1 = ahbh-abh;
      auto t2 = t1 + ahbl;
      auto t3 = t2 + albh;
      auto abl= t3 +albl;
      return eve::zip(abh, abl);
    }


TTS_CASE_WITH("Check dekker_prod params",
              plf::scalar_real_types,
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000)
             )
  <typename T>(T const& a0, T const& a1 , T const& ,
               T const& a3, T const& a4 , T const& )
{
  using  mpfr::mpreal;
//  using plf::dekker_prod;
  using plf::two_prod;
  {
    auto pa(a0);
    auto pb(a3);
    TTS_EQUAL(dekker_prod(pa, pb), two_prod(pa, pb));
  }
  {
    using pv_t  = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    auto [abh, abl] = two_prod(pa, pb);
    std::cout << abh << std::endl;
    std::cout << abl << std::endl;
//    std::cout << dekker_prod(pa, pb) << std::endl;
//    std::cout << two_prod(pa, pb)    << std::endl;   ;
//   TTS_EQUAL(dekker_prod(pa, pb), two_prod(pa, pb));
  }
//   {
//     using pv_t  = plf::polyfloat<T, 3>;
//     pv_t pa(a0, a1, a2);
//     pv_t pb(a3, a4, a5);
//     TTS_EQUAL(dekker_prod(pa, pb), two_prod(pa, pb));
//   }
};
