//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0ld
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

template<typename Z, typename N> constexpr auto ldexpc(Z const& z, N const& n) noexcept
{
  std::cout << z << std::endl;
  std::cout << n << std::endl;
  if constexpr (eve::scalar_value<N>) return z * plf::exp2n(n, eve::as(z));
  else if constexpr (eve::scalar_value<Z>)
  {
    auto wz = eve::as_wide_as_t<N, Z>(z);
    return wz * plf::exp2n(n, eve::as(wz));
  }
  else
  {
    return z * plf::exp2n(n, eve::as(z));
  }
}

TTS_CASE_WITH("Check ldexpb",
              plf::scalar_real_types,
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax),
              tts::randoms(eve::valmin, eve::valmax))
<typename T>(T const& a0, T const& a1, T const& a2)
{
  using mpfr::mpreal;
  using plf::ldexpb;
  {
    using pv_t = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    std::cout << pa << std::endl;
    auto n = 2;
    std::cout << n << std::endl;
    std::cout << plf::exp2n(n, eve::as<pv_t>()) << std::endl;
    TTS_EQUAL(ldexpb(pa, n), pa * 4);
    using wpv_t = eve::wide<pv_t, 2>;
    wpv_t wpab(pa, pa);
    std::cout << ldexpb(wpab, n) << std::endl;
    TTS_RELATIVE_EQUAL(ldexpb(wpab, n), wpab * 4, tts::epsprec<T>());
    auto e = plf::exponent(wpab);
    std::cout << tts::typename_<decltype(e)> << std::endl;
    std::cout << tts::typename_<decltype(wpab)> << std::endl;
    std::cout << ldexpb(wpab, -e) << std::endl;
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    auto n = 2;
    TTS_EQUAL(ldexpb(pa, n), pa * 4);
  }
};
