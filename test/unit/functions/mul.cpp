//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

template < typename T> auto mpfr_mul(T a,  T b)
{
  return tts::to_polyfloat(tts::to_mpreal(a)*tts::to_mpreal(b), eve::as<T>());
}

TTS_CASE_WITH("Check mul two params",
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
  {
    {
      using pv_t  = plf::polyfloat<T, 2>;
      pv_t pa(a0, a1);
      pv_t pb(a3, a4);
      pv_t pab = plf::mul(pa, pb);
      TTS_ULP_EQUAL(pab, mpfr_mul(pa, pb), 0.5);
    }
    {
      using pv_t  = plf::polyfloat<T, 3>;
      pv_t pa(a0, a1, a2);
      pv_t pb(a3, a4, a5);
      pv_t pab = plf::mul(pa, pb);
      TTS_ULP_EQUAL(pab, mpfr_mul(pa, pb), 0.5);
    }
  }
};
