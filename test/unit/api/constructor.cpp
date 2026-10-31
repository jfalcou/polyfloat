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
TTS_CASE_TPL("Check constructors", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
  using pv_t = plf::polyfloat<T, 2>;
  using wpv_t = eve::wide<pv_t>;
  using wT = eve::wide<T>;
  TTS_EXPR_IS(wpv_t(), wpv_t);
  TTS_EXPR_IS(pv_t(), pv_t);
  TTS_EXPR_IS(plf::polyfloat(T()), pv_t);
  TTS_EXPR_IS(eve::wide<pv_t>(), wpv_t);
  TTS_EXPR_IS((plf::as_polyfloat_n_t<2, wT>()), wpv_t);

  auto a = plf::double_real_t<T>(T(1));
  std::cout << "a " << a << std::endl;
  auto b = plf::double_real_t<wT>(wT(1));
  std::cout << "b " << b << std::endl;

  {
    pv_t a2(T(1.0), T(0.1));
    std::cout << "a2 " << a2 << std::endl;
    using wT2 = eve::wide<T, 2>;
    using wpv_t2 = eve::wide<plf::polyfloat<T, 2>, 2>;
    wpv_t2 wa2(wT2(1.0), wT2(0.1));
    std::cout << "wa2 " << wa2 << std::endl;

    std::cout << pv_t(eve::inf(eve::as<T>())) << std::endl;
    std::cout << pv_t(eve::nan(eve::as<T>())) << std::endl;
    std::cout << wpv_t(eve::inf(eve::as<T>())) << std::endl;
    std::cout << wpv_t(eve::nan(eve::as<T>())) << std::endl;
    std::cout << pv_t(eve::inf(eve::as<T>()), eve::zero(eve::as<T>())) << std::endl;
    std::cout << pv_t(eve::nan(eve::as<T>()), eve::zero(eve::as<T>())) << std::endl;
    std::cout << wpv_t(eve::inf(eve::as<T>()), eve::zero(eve::as<T>())) << std::endl;
    std::cout << wpv_t(eve::nan(eve::as<T>()), eve::zero(eve::as<T>())) << std::endl;
    std::cout << wpv_t(eve::inf(eve::as<T>()), eve::inf(eve::as<T>())) << std::endl;
  }
  {
    using pv_t3 = plf::polyfloat<T, 3>;
    using wpv_t3 = eve::wide<plf::polyfloat<T, 3>, 2>;
    using wT = eve::wide<T, 2>;
    wpv_t3 wa3(wT(1.0), wT(0.1));
    std::cout << "wa3 " << wa3 << std::endl;

    std::cout << pv_t3(eve::inf(eve::as<T>())) << std::endl;
    std::cout << pv_t3(eve::nan(eve::as<T>())) << std::endl;
    std::cout << wpv_t3(eve::inf(eve::as<T>())) << std::endl;
    std::cout << wpv_t3(eve::nan(eve::as<T>())) << std::endl;
    std::cout << pv_t3(eve::inf(eve::as<T>()), eve::zero(eve::as<T>())) << std::endl;
    std::cout << pv_t3(eve::nan(eve::as<T>()), eve::zero(eve::as<T>())) << std::endl;
    std::cout << wpv_t3(eve::inf(eve::as<T>()), eve::zero(eve::as<T>())) << std::endl;
    std::cout << wpv_t3(eve::nan(eve::as<T>()), eve::zero(eve::as<T>())) << std::endl;
    std::cout << wpv_t3(eve::inf(eve::as<T>()), eve::inf(eve::as<T>())) << std::endl;
  }
};

TTS_CASE_WITH("Check constructor for normalization",
              plf::scalar_real_types,
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000))
<typename T>(T const& a0, T const& a1, T const& a2, T const& a3, T const& a4, T const& a5)
{
  using mpfr::mpreal;
  using plf::is_normalized;
  {
    using pv_t = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    TTS_EXPECT(is_normalized(pa));
    TTS_EXPECT(is_normalized(pb));
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t pb(a3, a4, a5);
    TTS_EXPECT(is_normalized(pa));
    TTS_EXPECT(is_normalized(pb));
  }
};
