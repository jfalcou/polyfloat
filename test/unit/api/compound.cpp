//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

//==================================================================================================
// Types tests
//==================================================================================================
TTS_CASE_TPL( "Check return types of arithmetic operators", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
  using namespace plf;
  using pv_t  = polyfloat<T, 3>;
  using wpv_t = eve::wide<pv_t>;
  using wT    = eve::wide<T>;
  pv_t pv{};
  wpv_t wpv{};

  TTS_EXPR_IS( pv    += pv   , pv_t&);
  TTS_EXPR_IS( pv    -= pv   , pv_t&);
  TTS_EXPR_IS( pv    *= pv   , pv_t&);
  TTS_EXPR_IS( pv    /= pv   , pv_t&);
  TTS_EXPR_IS( pv    += T()   , pv_t&);
  TTS_EXPR_IS( pv    -= T()   , pv_t&);
  TTS_EXPR_IS( pv    *= T()   , pv_t&);
  TTS_EXPR_IS( pv    /= T()   , pv_t&);
  TTS_EXPR_IS( wpv    += wpv   , wpv_t&);
  TTS_EXPR_IS( wpv    -= wpv   , wpv_t&);
  TTS_EXPR_IS( wpv    *= wpv   , wpv_t&);
  TTS_EXPR_IS( wpv    /= wpv   , wpv_t&);


  TTS_EXPR_IS( wpv    += pv    , wpv_t&);
  TTS_EXPR_IS( wpv    -= pv    , wpv_t&);
  TTS_EXPR_IS( wpv    *= pv    , wpv_t&);
  TTS_EXPR_IS( wpv    /= pv    , wpv_t&);
  TTS_EXPR_IS( pv     /= pv    ,  pv_t&);
  TTS_EXPR_IS( pv     *= pv    ,  pv_t&);
  TTS_EXPR_IS( pv     += pv    ,  pv_t&);
  TTS_EXPR_IS( pv     -= pv    ,  pv_t&);

  TTS_EXPR_IS( wpv   += wT()   , wpv_t&);
  TTS_EXPR_IS( wpv   -= wT()   , wpv_t&);
  TTS_EXPR_IS( wpv   *= wT()   , wpv_t&);
  TTS_EXPR_IS( wpv   /= wT()   , wpv_t&);
  TTS_EXPR_IS( wpv   += T()    , wpv_t&);
  TTS_EXPR_IS( wpv   -= T()    , wpv_t&);
  TTS_EXPR_IS( wpv   *= T()    , wpv_t&);
  TTS_EXPR_IS( wpv   /= T()    , wpv_t&);
  TTS_EXPR_IS( pv    /= T()    ,  pv_t&);
  TTS_EXPR_IS( pv    *= T()    ,  pv_t&);
  TTS_EXPR_IS( pv    += T()    ,  pv_t&);
  TTS_EXPR_IS( pv    -= T()    ,  pv_t&);

};
