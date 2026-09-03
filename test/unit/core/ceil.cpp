//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH(
  "Check ceil", plf::scalar_real_types, tts::randoms(-1000, 1000), tts::randoms(-1000, 1000), tts::randoms(-1000, 1000))
<typename T>(T const& a0, T const& a1, T const& a2)
{
  using mpfr::mpreal;
  using plf::ceil;
  {
    {
      using pv_t = plf::polyfloat<T, 2>;
      pv_t pa(a0, a1);
      pv_t cpa = plf::ceil(pa);
      TTS_EXPECT(pa <= cpa);
      TTS_EXPECT(plf::inc(pa) >= cpa);
      TTS_EXPECT(plf::is_flint(cpa));
    }
    {
      using pv_t = plf::polyfloat<T, 3>;
      pv_t pa(a0, a1, a2);
      pv_t cpa = plf::ceil(pa);
      TTS_EXPECT(pa <= cpa);
      TTS_EXPECT(plf::inc(pa) >= cpa);
      TTS_EXPECT(plf::is_flint(cpa));
    }
  }
};


TTS_CASE_WITH("Check ceil ",
              plf::scalar_real_types,
              tts::randoms(-1000,1000)
             )
  <typename T>(T const& )
{
  {
    using  dd_t = plf::double_real_t<T>;
    auto mx = eve::maxflint(eve::as<double>());
    dd_t x2(mx);
    auto cx2 = plf::ceil(x2);
    TTS_EQUAL(x2, cx2);

    auto hx2 = x2-dd_t(0.5);
    auto mphx2 = tts::to_mpreal(hx2);
    auto chx2 = plf::ceil(hx2);
    TTS_EQUAL(x2, chx2);
    auto px2 = plf::prev(x2);
    auto cpx2 = plf::ceil(px2);
    TTS_EQUAL(x2, cpx2);
  }
  {
    using  ddd_t = plf::triple_real_t<T>;
    auto mx = eve::maxflint(eve::as<double>());
    ddd_t x2(mx);
    auto cx2 = plf::ceil(x2);
    TTS_EQUAL(x2, cx2);

    auto hx2 = x2-ddd_t(0.5);
    auto mphx2 = tts::to_mpreal(hx2);
    auto chx2 = plf::ceil(hx2);
    TTS_EQUAL(x2, chx2);
    auto px2 = plf::prev(x2);
    auto cpx2 = plf::ceil(px2);
    TTS_EQUAL(x2, cpx2);
  }
};
