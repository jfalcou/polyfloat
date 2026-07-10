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
TTS_CASE_TPL( "Check return types of arithmetic operators", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
  using namespace plf;
  using pv_t  = polyfloat<T, 2>;
  using wpv_t = eve::wide<pv_t>;
//  using wT    = eve::wide<T>;
  TTS_EXPR_IS( wpv_t()    + wpv_t()   , wpv_t);
  TTS_EXPR_IS( wpv_t()    - wpv_t()   , wpv_t);
  TTS_EXPR_IS( wpv_t()    * wpv_t()   , wpv_t);
  TTS_EXPR_IS( wpv_t()    / wpv_t()   , wpv_t);
  TTS_EXPR_IS( wpv_t()    + pv_t()    , wpv_t);
  TTS_EXPR_IS( pv_t()     + wpv_t()   , wpv_t);
  TTS_EXPR_IS( wpv_t()    - pv_t()    , wpv_t);
  TTS_EXPR_IS( pv_t()     - wpv_t()   , wpv_t);
  TTS_EXPR_IS( wpv_t()    * pv_t()    , wpv_t);
  TTS_EXPR_IS( pv_t()     * wpv_t()   , wpv_t);
  TTS_EXPR_IS( wpv_t()    / pv_t()    , wpv_t);
  TTS_EXPR_IS( pv_t()     / wpv_t()   , wpv_t);
  TTS_EXPR_IS( pv_t()     / pv_t()    ,  pv_t);
  TTS_EXPR_IS( pv_t()     * pv_t()    ,  pv_t);
  TTS_EXPR_IS( pv_t()     + pv_t()    ,  pv_t);
  TTS_EXPR_IS( pv_t()     - pv_t()    ,  pv_t);

//   TTS_EXPR_IS( wT()    + wpv_t()   , wpv_t);
//   TTS_EXPR_IS( wT()    - wpv_t()   , wpv_t);
//   TTS_EXPR_IS( wT()    * wpv_t()   , wpv_t);
//   TTS_EXPR_IS( wT()    / wpv_t()   , wpv_t);
//   TTS_EXPR_IS( wT()    + pv_t()    , wpv_t);
//   TTS_EXPR_IS( T()     + wpv_t()   , wpv_t);
//   TTS_EXPR_IS( wT()    - pv_t()    , wpv_t);
//   TTS_EXPR_IS( T()     - wpv_t()   , wpv_t);
//   TTS_EXPR_IS( wT()    * pv_t()    , wpv_t);
//   TTS_EXPR_IS( T()     * wpv_t()   , wpv_t);
//   TTS_EXPR_IS( wT()    / pv_t()    , wpv_t);
//   TTS_EXPR_IS( T()     / wpv_t()   , wpv_t);
//   TTS_EXPR_IS( T()     / pv_t()    ,  pv_t);
//   TTS_EXPR_IS( T()     * pv_t()    ,  pv_t);
//   TTS_EXPR_IS( T()     + pv_t()    ,  pv_t);
//   TTS_EXPR_IS( T()     - pv_t()    ,  pv_t);

//   TTS_EXPR_IS( wpv_t()    + wT()   , wpv_t);
//   TTS_EXPR_IS( wpv_t()    - wT()   , wpv_t);
//   TTS_EXPR_IS( wpv_t()    * wT()   , wpv_t);
//   TTS_EXPR_IS( wpv_t()    / wT()   , wpv_t);
//   TTS_EXPR_IS( wpv_t()    + T()    , wpv_t);
//   TTS_EXPR_IS( pv_t()     + wT()   , wpv_t);
//   TTS_EXPR_IS( wpv_t()    - T()    , wpv_t);
//   TTS_EXPR_IS( pv_t()     - wT()   , wpv_t);
//   TTS_EXPR_IS( wpv_t()    * T()    , wpv_t);
//   TTS_EXPR_IS( pv_t()     * wT()   , wpv_t);
//   TTS_EXPR_IS( wpv_t()    / T()    , wpv_t);
//   TTS_EXPR_IS( pv_t()     / wT()   , wpv_t);
//   TTS_EXPR_IS( pv_t()     / T()    ,  pv_t);
//   TTS_EXPR_IS( pv_t()     * T()    ,  pv_t);
//   TTS_EXPR_IS( pv_t()     + T()    ,  pv_t);
//   TTS_EXPR_IS( pv_t()     - T()    ,  pv_t);


  // assigning operators
  {
    auto v = plf::polyfloat<T, 2>{};
    T f{};

    TTS_EXPR_IS(v += v, (plf::polyfloat<T, 2>&) );
    TTS_EXPR_IS(v -= v, (plf::polyfloat<T, 2>&) );
    TTS_EXPR_IS(v *= v, (plf::polyfloat<T, 2>&) );
    TTS_EXPR_IS(v /= v, (plf::polyfloat<T, 2>&) );

    TTS_EXPR_IS(v += f, (plf::polyfloat<T, 2>&) );
    TTS_EXPR_IS(v -= f, (plf::polyfloat<T, 2>&) );
    TTS_EXPR_IS(v *= f, (plf::polyfloat<T, 2>&) );
    //   TTS_EXPR_IS(v /= f, (plf::polyfloat<T, 2>&) );
 }
  {
    auto v = plf::polyfloat<T, 3>{};

    TTS_EXPR_IS(v += v, (plf::polyfloat<T, 3>&) );
    TTS_EXPR_IS(v -= v, (plf::polyfloat<T, 3>&) );
    TTS_EXPR_IS(v *= v, (plf::polyfloat<T, 3>&) );
//    TTS_EXPR_IS(v /= v, (plf::polyfloat<T, 3>&) );
  }

};
