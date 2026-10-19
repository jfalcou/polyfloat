//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

TTS_CASE_WITH("Check atan2 ",
              plf::scalar_real_types,
              tts::randoms(0, 10),
              tts::randoms(0.0, 1.e-20),
              tts::randoms(0.0, 1.e-30),
              tts::randoms(0, 10),
              tts::randoms(0.0, 1.e-20),
              tts::randoms(0.0, 1.e-30))
<typename T>(T const& a0, T const& a1, T const& a2, T const& a3, T const& a4, T const& a5)
{
  using mpfr::mpreal;
  using plf::atan2;
  auto matan2 = [](auto a, auto b) { return mpfr::atan2(a, b); };
  {
    using pv_t = plf::polyfloat<T, 2>;
    pv_t pa(a0, a1);
    pv_t pb(a3, a4);
    TTS_RELATIVE_EQUAL(atan2(pa, pb), tts::mpfr_exec(matan2, pa, pb), 2 * tts::epsprec<pv_t>())
      << "pa " << pa << "pb " << pb << "\n";
    pv_t z = plf::zero(eve::as(a0));
    pv_t o = plf::one(eve::as(a0));
    pv_t inf = plf::inf(eve::as(a0));
    pv_t minf = plf::minf(eve::as(a0));
    pv_t nan = plf::nan(eve::as(a0));
    pv_t pi = plf::pi(eve::as<pv_t>());
    pv_t pio2 = plf::pio_2(eve::as<pv_t>());
    pv_t tp4 = plf::three_pio_4(eve::as<pv_t>());
    TTS_IEEE_EQUAL(plf::atan2(z, z), nan);
    TTS_IEEE_EQUAL(plf::atan2(o, o), plf::pio_4(eve::as(z)));
    TTS_IEEE_EQUAL(plf::atan2(inf, inf), nan);
    TTS_IEEE_EQUAL(plf::atan2(inf, minf), nan);
    TTS_IEEE_EQUAL(plf::atan2(minf, inf), nan);
    TTS_IEEE_EQUAL(plf::atan2(minf, minf), nan);
    TTS_IEEE_EQUAL(plf::atan2(z, -o), pi);
    TTS_IEEE_EQUAL(plf::atan2(z, o), z);
    TTS_IEEE_EQUAL(plf::atan2(inf, o), pio2);
    TTS_IEEE_EQUAL(plf::atan2(minf, o), -pio2);
    TTS_IEEE_EQUAL(plf::atan2(-o, z), -pio2);
    TTS_IEEE_EQUAL(plf::atan2(o, z), pio2);
    TTS_IEEE_EQUAL(plf::atan2(o, minf), pi);
    TTS_IEEE_EQUAL(plf::atan2(-o, minf), -pi);
    TTS_IEEE_EQUAL(plf::atan2(o, inf), z);
    TTS_IEEE_EQUAL(plf::atan2(-o, inf), -z);

    TTS_IEEE_EQUAL(plf::atan2[eve::pedantic](inf, inf), pi / 4);
    TTS_RELATIVE_EQUAL(plf::atan2[eve::pedantic](inf, minf), tp4, tts::epsprec<pv_t>());
    TTS_IEEE_EQUAL(plf::atan2[eve::pedantic](minf, inf), -pi / 4);
    TTS_RELATIVE_EQUAL(plf::atan2[eve::pedantic](minf, minf), -tp4, tts::epsprec<pv_t>());
    TTS_IEEE_EQUAL(plf::atan2[eve::pedantic](inf, z), pi / 2);
    TTS_IEEE_EQUAL(plf::atan2[eve::pedantic](inf, -z), pi / 2);
    TTS_IEEE_EQUAL(plf::atan2[eve::pedantic](minf, z), -pi / 2);
    TTS_IEEE_EQUAL(plf::atan2[eve::pedantic](minf, -z), -pi / 2);

    for (pv_t i = 0; i < 2.0; i += pv_t(0.01))
    {
      TTS_RELATIVE_EQUAL(plf::atan2(i, 2 - i), tts::mpfr_exec(matan2, i, 2 - i), 32 * tts::epsprec<pv_t>())
        << "i " << i << "\n";
    }
  }
  {
    using pv_t = plf::polyfloat<T, 3>;
    pv_t pa(a0, a1, a2);
    pv_t pb(a3, a4, a5);
    TTS_RELATIVE_EQUAL(atan2(pa, pb), tts::mpfr_exec(matan2, pa, pb), 2 * tts::epsprec<pv_t>())
      << "pa " << pa << "pb " << pb << "\n";
    pv_t z = plf::zero(eve::as(a0));
    pv_t o = plf::one(eve::as(a0));
    pv_t inf = plf::inf(eve::as(a0));
    pv_t minf = plf::minf(eve::as(a0));
    pv_t nan = plf::nan(eve::as(a0));
    pv_t pi = plf::pi(eve::as<pv_t>());
    pv_t pio2 = plf::pio_2(eve::as<pv_t>());
    pv_t tp4 = plf::three_pio_4(eve::as<pv_t>());
    TTS_IEEE_EQUAL(plf::atan2(z, z), nan);
    TTS_IEEE_EQUAL(plf::atan2(o, o), plf::pio_4(eve::as(z)));
    TTS_IEEE_EQUAL(plf::atan2(inf, inf), nan);
    TTS_IEEE_EQUAL(plf::atan2(inf, minf), nan);
    TTS_IEEE_EQUAL(plf::atan2(minf, inf), nan);
    TTS_IEEE_EQUAL(plf::atan2(minf, minf), nan);
    TTS_IEEE_EQUAL(plf::atan2(z, -o), pi);
    TTS_IEEE_EQUAL(plf::atan2(z, o), z);
    TTS_IEEE_EQUAL(plf::atan2(inf, o), pio2);
    TTS_IEEE_EQUAL(plf::atan2(minf, o), -pio2);
    TTS_IEEE_EQUAL(plf::atan2(-o, z), -pio2);
    TTS_IEEE_EQUAL(plf::atan2(o, z), pio2);
    TTS_IEEE_EQUAL(plf::atan2(o, minf), pi);
    TTS_IEEE_EQUAL(plf::atan2(-o, minf), -pi);
    TTS_IEEE_EQUAL(plf::atan2(o, inf), z);
    TTS_IEEE_EQUAL(plf::atan2(-o, inf), -z);
    std::cout << std::hexfloat;
    TTS_IEEE_EQUAL(plf::atan2[eve::pedantic](inf, inf), pi / 4);
    TTS_RELATIVE_EQUAL(plf::atan2[eve::pedantic](inf, minf), tp4, tts::epsprec<pv_t>());
    TTS_IEEE_EQUAL(plf::atan2[eve::pedantic](minf, inf), -pi / 4);
    TTS_RELATIVE_EQUAL(plf::atan2[eve::pedantic](minf, minf), -tp4, tts::epsprec<pv_t>());
    TTS_IEEE_EQUAL(plf::atan2[eve::pedantic](inf, z), pi / 2);
    TTS_IEEE_EQUAL(plf::atan2[eve::pedantic](inf, -z), pi / 2);
    TTS_IEEE_EQUAL(plf::atan2[eve::pedantic](minf, z), -pi / 2);
    TTS_IEEE_EQUAL(plf::atan2[eve::pedantic](minf, -z), -pi / 2);

    for (pv_t i = 0; i < 2.0; i += pv_t(0x2p-12))
    {
      TTS_RELATIVE_EQUAL(plf::atan2(i, 2 - i), tts::mpfr_exec(matan2, i, 2 - i), 32 * tts::epsprec<pv_t>())
        << "i " << i << " y/x " << (2 - i) / i << "\n";
    }
  }
};
