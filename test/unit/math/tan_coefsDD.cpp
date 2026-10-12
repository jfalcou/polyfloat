//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <polyfloat/polyfloat.hpp>

double remez_tan_46bits(double x)
{
  double x2 = x * x;

  // Polynôme du numérateur P(x^2)
  double num = 1.0 - 0x1.06b85a53fd0c0p-3 * x2 + 0x1.6fbeed1495400p-9 * x2 * x2 - 0x1.f60fe02d00200p-18 * x2 * x2 * x2;

  // Polynôme du dénominateur Q(x^2)
  double den = 1.0 - 0x1.d8b1827f53d80p-2 * x2 + 0x1.7e77626bc5880p-6 * x2 * x2 - 0x1.b5132995f0240p-13 * x2 * x2 * x2;

  return x * (num / den); // Unique division machine
}

auto pade_tan_46bits(plf::double_real_t<float> x)
{
  double xx = double(plf::hi(x)) + double(plf::lo(x));
  auto x2 = xx * xx;
  using d2_t = plf::double_real_t<float>;
  return -(d2_t(63) * x * (2 * x2 * (d2_t(53) * x2 - d2_t(2805)) + d2_t(45045))) /
         (x2 * (x2 * (x2 * (x2 + d2_t(378)) - d2_t(61425)) + d2_t(1299375)) - d2_t(2837835));

  //      return x * (num / den);
}

//-(63 sqrt(x) (2 x (53 x - 2805) + 45045))/(x (x (x (x + 378) - 61425) + 1299375) - 2837835)

float pade_tanf_precise(float x)
{
  float x2 = x * x;
  //     float num = plf::reverse_horner(x2, 1.0f, -0.111111111f,  0.001058201f);
  //     float den = plf::reverse_horner(x2, 1.0f, -0.444444444f,  0.015873016f);
  float num = 1.0f - 0.11110803f * x2 + 0.00105762f * x2 * x2;
  float den = 1.0f - 0.44444137f * x2 + 0.01587148f * x2 * x2;
  return x * (num / den);
}

double tan_pade_exact(double x)
{
  if (x == 0.0) return 0.0;

  double t = x * x; // t = x^2

  // Évaluation du numérateur P(t)
  double num = plf::reverse_horner(t, 2027025.0, -270270.0, 6930.0, -36.0);
  double den = plf::reverse_horner(t, 2027025.0, -945945.0, 51975.0, -630.0, 1.0);
  return x * (num / den);
}

double tan_approx_pi4(double x)
{
  if (x == 0.0) return 0.0;

  double x2 = x * x;

  // Coefficients de Remez (proches du Padé analytique)
  double const P1 = 374.7005896465083;
  double const P2 = -17127.54844867066;
  double const P3 = 133506.9201002157;

  double const Q1 = 3150.0;   // Valeurs ajustées selon
  double const Q2 = -62370.0; // la structure choisie
  double const Q3 = 135135.0; // pour le dénominateur

  // Évaluation par la méthode de Horner
  double num = ((P1 * x2 + P2) * x2 + P3);
  double den = ((x2 + Q1) * x2 + Q2) * x2 + Q3;

  return x + (x * x2) * (num / den);
}

TTS_CASE_TPL("Check tan ", double)
<typename T>(tts::type<T>)
{
  //  using d2_t = plf::double_real_t<float>;

  auto cvt = [](auto x) {
    auto hi = float(x);
    auto lo = float(x - double(hi));
    return plf::_::from_pair(hi, lo);
  };

  std::array<double, 4> P{1.0, -0.128281645589193971, +0.002805714983767582, -0.000007481670018114};
  std::array<double, 4> Q{
    1.0,
    -0.461614978922522567,
    +0.023344041291215811,
    -0.000208418878432169,
  };

  for (int i = 0; i < 4; ++i)
  {
    std::cout << std::hexfloat << "plf::_::from_pair(" << cvt(P[i]) << "), " << std::endl;
  }

  for (int i = 0; i < 4; ++i)
  {
    std::cout << std::hexfloat << "plf::_::from_pair(" << cvt(Q[i]) << ", " << std::endl;
  }
  //  d2_t a =  cvt(-0x1.06b85a53fd0c0p-3);

  //  std::cout << std::hexfloat << a << std::endl;

  //   auto z = cvt(-0.128281645589193971);
  //   std::cout << std::hexfloat << z<< std::endl;

  //  auto f = [](){
  //     using d2_t = plf::double_real_t<float>;
  //     for(d2_t i=0; i < d2_t(0.75)  ; i+= d2_t(0.024))
  //     {
  //       auto ii =  double(plf::hi(i)+double(plf::lo(i)));
  //       std::cout << remez_tan_46bits(ii) - eve::tan(double(plf::hi(i)+double(plf::lo(i)))) << std::endl;
  //     }
  //     std::cout << "}\n";

  //     for(double i=0; i < 0.75  ; i+=  0.024)
  //     {
  //       std::cout << remez_tan_46bits(i) - eve::tan(i) << std::endl;
  //     }
  //     std::cout << "}\n";
  //  };

  //  f();
};
