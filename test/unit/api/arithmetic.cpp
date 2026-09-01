//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"

//==================================================================================================
// Types tests
//==================================================================================================
TTS_CASE_TPL("Check return types of arithmetic operators", plf::scalar_real_types)
<typename T>(tts::type<T>){{using pv_t = plf::polyfloat<T, 2>;
using wpv_t = eve::wide<pv_t>;
using wT = eve::wide<T>;
TTS_EXPR_IS(wpv_t() + wpv_t(), wpv_t);
TTS_EXPR_IS(wpv_t() - wpv_t(), wpv_t);
TTS_EXPR_IS(wpv_t() * wpv_t(), wpv_t);
TTS_EXPR_IS(wpv_t() / wpv_t(), wpv_t);
TTS_EXPR_IS(wpv_t() + pv_t(), wpv_t);
TTS_EXPR_IS(pv_t() + wpv_t(), wpv_t);
TTS_EXPR_IS(wpv_t() - pv_t(), wpv_t);
TTS_EXPR_IS(pv_t() - wpv_t(), wpv_t);
TTS_EXPR_IS(wpv_t() * pv_t(), wpv_t);
TTS_EXPR_IS(pv_t() * wpv_t(), wpv_t);
TTS_EXPR_IS(wpv_t() / pv_t(), wpv_t);
TTS_EXPR_IS(pv_t() / wpv_t(), wpv_t);
TTS_EXPR_IS(pv_t() / pv_t(), pv_t);
TTS_EXPR_IS(pv_t() * pv_t(), pv_t);
TTS_EXPR_IS(pv_t() + pv_t(), pv_t);
TTS_EXPR_IS(pv_t() - pv_t(), pv_t);

TTS_EXPR_IS(wT() + wpv_t(), wpv_t);
TTS_EXPR_IS(wT() - wpv_t(), wpv_t);
TTS_EXPR_IS(wT() * wpv_t(), wpv_t);
TTS_EXPR_IS(wT() / wpv_t(), wpv_t);
TTS_EXPR_IS(wT() + pv_t(), wpv_t);
TTS_EXPR_IS(T() + wpv_t(), wpv_t);
TTS_EXPR_IS(wT() - pv_t(), wpv_t);
TTS_EXPR_IS(T() - wpv_t(), wpv_t);
TTS_EXPR_IS(wT() * pv_t(), wpv_t);
TTS_EXPR_IS(T() * wpv_t(), wpv_t);
TTS_EXPR_IS(wT() / pv_t(), wpv_t);
TTS_EXPR_IS(T() / wpv_t(), wpv_t);
TTS_EXPR_IS(T() / pv_t(), pv_t);
TTS_EXPR_IS(T() * pv_t(), pv_t);
TTS_EXPR_IS(T() + pv_t(), pv_t);
TTS_EXPR_IS(T() - pv_t(), pv_t);

TTS_EXPR_IS(wpv_t() + wT(), wpv_t);
TTS_EXPR_IS(wpv_t() - wT(), wpv_t);
TTS_EXPR_IS(wpv_t() * wT(), wpv_t);
TTS_EXPR_IS(wpv_t() / wT(), wpv_t);
TTS_EXPR_IS(wpv_t() + T(), wpv_t);
TTS_EXPR_IS(pv_t() + wT(), wpv_t);
TTS_EXPR_IS(wpv_t() - T(), wpv_t);
TTS_EXPR_IS(pv_t() - wT(), wpv_t);
TTS_EXPR_IS(wpv_t() * T(), wpv_t);
TTS_EXPR_IS(pv_t() * wT(), wpv_t);
TTS_EXPR_IS(wpv_t() / T(), wpv_t);
TTS_EXPR_IS(pv_t() / wT(), wpv_t);
TTS_EXPR_IS(pv_t() / T(), pv_t);
TTS_EXPR_IS(pv_t() * T(), pv_t);
TTS_EXPR_IS(pv_t() + T(), pv_t);
TTS_EXPR_IS(pv_t() - T(), pv_t);

// assigning operators
{
  auto v = pv_t{};
  auto w = wpv_t{};
  T f{};
  wT wf{};

  TTS_EXPR_IS(v += v, pv_t&);
  TTS_EXPR_IS(v -= v, pv_t&);
  TTS_EXPR_IS(v *= v, pv_t&);
  TTS_EXPR_IS(v /= v, pv_t&);

  TTS_EXPR_IS(v += f, pv_t&);
  TTS_EXPR_IS(v -= f, pv_t&);
  TTS_EXPR_IS(v *= f, pv_t&);
  TTS_EXPR_IS(v /= f, pv_t&);

  TTS_EXPR_IS(w += w, wpv_t&);
  TTS_EXPR_IS(w -= w, wpv_t&);
  TTS_EXPR_IS(w *= w, wpv_t&);
  TTS_EXPR_IS(w /= w, wpv_t&);

  TTS_EXPR_IS(w += v, wpv_t&);
  TTS_EXPR_IS(w -= v, wpv_t&);
  TTS_EXPR_IS(w *= v, wpv_t&);
  TTS_EXPR_IS(w /= v, wpv_t&);

  TTS_EXPR_IS(w += f, wpv_t&);
  TTS_EXPR_IS(w -= f, wpv_t&);
  TTS_EXPR_IS(w *= f, wpv_t&);
  TTS_EXPR_IS(w /= f, wpv_t&);

  TTS_EXPR_IS(w += wf, wpv_t&);
  TTS_EXPR_IS(w -= wf, wpv_t&);
  TTS_EXPR_IS(w *= wf, wpv_t&);
  TTS_EXPR_IS(w /= wf, wpv_t&);
}

{
  using pv_t = plf::polyfloat<T, 3>;
  using wpv_t = eve::wide<pv_t>;
  using wT = eve::wide<T>;
  TTS_EXPR_IS(wpv_t() + wpv_t(), wpv_t);
  TTS_EXPR_IS(wpv_t() - wpv_t(), wpv_t);
  TTS_EXPR_IS(wpv_t() * wpv_t(), wpv_t);
  TTS_EXPR_IS(wpv_t() / wpv_t(), wpv_t);
  TTS_EXPR_IS(wpv_t() + pv_t(), wpv_t);
  TTS_EXPR_IS(pv_t() + wpv_t(), wpv_t);
  TTS_EXPR_IS(wpv_t() - pv_t(), wpv_t);
  TTS_EXPR_IS(pv_t() - wpv_t(), wpv_t);
  TTS_EXPR_IS(wpv_t() * pv_t(), wpv_t);
  TTS_EXPR_IS(pv_t() * wpv_t(), wpv_t);
  TTS_EXPR_IS(wpv_t() / pv_t(), wpv_t);
  TTS_EXPR_IS(pv_t() / wpv_t(), wpv_t);
  TTS_EXPR_IS(pv_t() / pv_t(), pv_t);
  TTS_EXPR_IS(pv_t() * pv_t(), pv_t);
  TTS_EXPR_IS(pv_t() + pv_t(), pv_t);
  TTS_EXPR_IS(pv_t() - pv_t(), pv_t);

  TTS_EXPR_IS(wT() + wpv_t(), wpv_t);
  TTS_EXPR_IS(wT() - wpv_t(), wpv_t);
  TTS_EXPR_IS(wT() * wpv_t(), wpv_t);
  TTS_EXPR_IS(wT() / wpv_t(), wpv_t);
  TTS_EXPR_IS(wT() + pv_t(), wpv_t);
  TTS_EXPR_IS(T() + wpv_t(), wpv_t);
  TTS_EXPR_IS(wT() - pv_t(), wpv_t);
  TTS_EXPR_IS(T() - wpv_t(), wpv_t);
  TTS_EXPR_IS(wT() * pv_t(), wpv_t);
  TTS_EXPR_IS(T() * wpv_t(), wpv_t);
  TTS_EXPR_IS(wT() / pv_t(), wpv_t);
  TTS_EXPR_IS(T() / wpv_t(), wpv_t);
  TTS_EXPR_IS(T() / pv_t(), pv_t);
  TTS_EXPR_IS(T() * pv_t(), pv_t);
  TTS_EXPR_IS(T() + pv_t(), pv_t);
  TTS_EXPR_IS(T() - pv_t(), pv_t);

  TTS_EXPR_IS(wpv_t() + wT(), wpv_t);
  TTS_EXPR_IS(wpv_t() - wT(), wpv_t);
  TTS_EXPR_IS(wpv_t() * wT(), wpv_t);
  TTS_EXPR_IS(wpv_t() / wT(), wpv_t);
  TTS_EXPR_IS(wpv_t() + T(), wpv_t);
  TTS_EXPR_IS(pv_t() + wT(), wpv_t);
  TTS_EXPR_IS(wpv_t() - T(), wpv_t);
  TTS_EXPR_IS(pv_t() - wT(), wpv_t);
  TTS_EXPR_IS(wpv_t() * T(), wpv_t);
  TTS_EXPR_IS(pv_t() * wT(), wpv_t);
  TTS_EXPR_IS(wpv_t() / T(), wpv_t);
  TTS_EXPR_IS(pv_t() / wT(), wpv_t);
  TTS_EXPR_IS(pv_t() / T(), pv_t);
  TTS_EXPR_IS(pv_t() * T(), pv_t);
  TTS_EXPR_IS(pv_t() + T(), pv_t);
  TTS_EXPR_IS(pv_t() - T(), pv_t);

  // assigning operators
  {
    auto v = pv_t{};
    auto w = wpv_t{};
    T f{};
    wT wf{};

    TTS_EXPR_IS(v += v, pv_t&);
    TTS_EXPR_IS(v -= v, pv_t&);
    TTS_EXPR_IS(v *= v, pv_t&);
    TTS_EXPR_IS(v /= v, pv_t&);

    TTS_EXPR_IS(v += f, pv_t&);
    TTS_EXPR_IS(v -= f, pv_t&);
    TTS_EXPR_IS(v *= f, pv_t&);
    TTS_EXPR_IS(v /= f, pv_t&);

    TTS_EXPR_IS(w += w, wpv_t&);
    TTS_EXPR_IS(w -= w, wpv_t&);
    TTS_EXPR_IS(w *= w, wpv_t&);
    TTS_EXPR_IS(w /= w, wpv_t&);

    TTS_EXPR_IS(w += v, wpv_t&);
    TTS_EXPR_IS(w -= v, wpv_t&);
    TTS_EXPR_IS(w *= v, wpv_t&);
    TTS_EXPR_IS(w /= v, wpv_t&);

    TTS_EXPR_IS(w += f, wpv_t&);
    TTS_EXPR_IS(w -= f, wpv_t&);
    TTS_EXPR_IS(w *= f, wpv_t&);
    TTS_EXPR_IS(w /= f, wpv_t&);

    TTS_EXPR_IS(w += wf, wpv_t&);
    TTS_EXPR_IS(w -= wf, wpv_t&);
    TTS_EXPR_IS(w *= wf, wpv_t&);
    TTS_EXPR_IS(w /= wf, wpv_t&);
  }
}
}
}
;
