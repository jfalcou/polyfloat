//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check is_odd",
              plf::scalar_real_types,
              tts::randoms(0, 1.0e30),
              tts::randoms(0, 1.0e15),
              tts::randoms(0, 19)
             )
  <typename T>(T const& a0, T const& a1, T const& a2)
{

  auto f = []<typename Z>(Z z){
    using plf::hi;
    using plf::lo;
    using plf::md;
    auto t = plf::is_flint(z);
    auto hiodd = eve::is_odd(hi(z));
    auto loodd = eve::is_odd(lo(z));
    auto loeqz = eve::is_eqz(lo(z));

    if constexpr(plf::dimension_v<Z> == 2)
    {
      return t && ((hiodd && loeqz) || (loodd && !loeqz));
    }
    else if constexpr(plf::dimension_v<Z> == 3)
    {
      auto mdeqz = eve::is_eqz(md(z));
      auto mdodd = eve::is_odd(md(z));
      auto t1 = loeqz && mdeqz;
      return t && ((t1 && hiodd) ||
                   (!mdeqz  && mdodd) ||
                   (!loeqz  && loodd));
    }
  };

  using plf::is_odd;
  using eve::trunc;
  {
    using pv_t  = plf::polyfloat<T, 2>;
    pv_t pa(trunc(a0), trunc(a1));
    TTS_EQUAL(is_odd(pa), f(pa));
  }
  {
    using pv_t  = plf::polyfloat<T, 3>;
    pv_t pa(trunc(a0), trunc(a1), trunc(a2));
    TTS_EQUAL(is_odd(pa), f(pa));
  }
};
