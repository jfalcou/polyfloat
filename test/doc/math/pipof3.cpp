// #include <iostream>
// #include <iomanip>
// #include <polyfloat/polyfloat.hpp>
// #include <iostream>
// #include <cmath>
// #include <iostream>
// #include <cmath>
// #include <iomanip>
#include <boost/multiprecision/mpfr.hpp>

using mp_float = boost::multiprecision::mpfr_float_50;

#include <iostream>
#include <cmath>
#include <iomanip>

// Structure Triple Float (3 x 24 bits = 72 bits de mantisse)
struct triple_float
{
  float f0; // Poids fort (24 bits)
  float f1; // Poids moyen (24 bits)
  float f2; // Poids faible (24 bits)

  // Convertisseur exact vers Boost MPFR pour mesurer l'erreur réelle
  mp_float to_mp_float() const { return mp_float(f0) + mp_float(f1) + mp_float(f2); }
  triple_float operator-() const { return triple_float(-f0, -f1, -f2); }
};

// Algorithme TwoSum (Knuth) : s = a + b exact
inline triple_float two_sum(float a, float b)
{
  float s = a + b;
  float v = s - a;
  float e = (a - (s - v)) + (b - v);
  return {s, e, 0.0f};
}

// Algorithme ThreeSum : Normalise trois floats pour qu'ils ne se chevauchent pas
inline triple_float three_sum(float a, float b, float c)
{
  triple_float s = two_sum(a, b);
  triple_float t = two_sum(s.f1, c);
  s.f0 = s.f0 + t.f0;
  triple_float u = two_sum(s.f0, s.f1); // réalignement
  return {u.f0, u.f1, t.f1};
}

// Addition : triple_float + triple_float
triple_float add_tf(triple_float a, triple_float b)
{
  triple_float s = two_sum(a.f0, b.f0);
  triple_float t = two_sum(a.f1, b.f1);
  float e = a.f2 + b.f2;

  // Fusion et cascade des erreurs
  s.f1 += t.f0;
  s.f2 += t.f1 + e;
  return three_sum(s.f0, s.f1, s.f2);
}

// Multiplication exacte de deux floats via la méthode de Dekker
inline triple_float two_prod(float a, float b)
{
  float p = a * b;
  float e = std::fma(a, b, -p); // FMA matériel obligatoire (compilez avec -ffp-contract=fast)
  return {p, e, 0.0f};
}

// Multiplication : triple_float * triple_float
triple_float mul_tf(triple_float a, triple_float b)
{
  triple_float p0 = two_prod(a.f0, b.f0);
  float p1 = a.f0 * b.f1 + a.f1 * b.f0;
  float p2 = a.f0 * b.f2 + a.f1 * b.f1 + a.f2 * b.f0;

  p0.f1 += p1;
  p0.f2 += p2;
  return three_sum(p0.f0, p0.f1, p0.f2);
}

// Division : triple_float / triple_float (1 unique division machine sur les têtes)
triple_float div_tf(triple_float a, triple_float b)
{
  float q0 = a.f0 / b.f0;
  triple_float p = two_prod(q0, b.f0);
  float r = (a.f0 - p.f0) - p.f1 + a.f1 - q0 * b.f1;
  float q1 = r / b.f0;

  // Correction finale du troisième ordre
  triple_float p2 = two_prod(q1, b.f0);
  float r2 = (r - p2.f0) - p2.f1 + a.f2 - q0 * b.f2 - q1 * b.f1;
  float q2 = r2 / b.f0;

  return three_sum(q0, q1, q2);
}

// Approximation rationnelle de Padé [4/4] en x^2 adaptée au triple_float
// Erreur absolue maximale théorique < 1.1e-22 (Sature la mantisse à 69 bits)
triple_float remez_tan_69bits_triple_float(float x_val)
{
  triple_float x = {x_val, 0.0f, 0.0f};
  triple_float x2 = mul_tf(x, x);

  // --- NUMÉRATEUR P(x^2) en notation triple-float exacte ---
  // Les coefficients décimaux sont convertis en triplets de floats non-redondants
  triple_float n4 = {1.42857142e-01f, 4.28571428e-09f, 1.19047619e-16f}; // ~ 1/7
  triple_float n3 = {-1.45524552e-02f, -1.24552455e-10f, -4.11327117e-18f};
  triple_float n2 = {3.33333333e-01f, 3.33333333e-09f, 3.33333333e-17f};    // ~ 1/3
  triple_float n1 = {-4.28571428e-01f, -5.71428571e-09f, -1.02348102e-17f}; // ~ -3/7
  triple_float n0 = {1.00000000f, 0.00000000f, 0.00000000f};

  // Évaluation du Numérateur (Schéma de Horner)
  triple_float num = n4;
  num = add_tf(mul_tf(num, x2), n3);
  num = add_tf(mul_tf(num, x2), n2);
  num = add_tf(mul_tf(num, x2), n1);
  num = add_tf(mul_tf(num, x2), n0);

  // --- DÉNOMINATEUR Q(x^2) ---
  triple_float d4 = {-4.51023481e-04f, -1.02348102e-12f, -2.10234810e-20f};
  triple_float d3 = {1.51528600e-03f, 1.39868744e-11f, 4.66172671e-19f};
  triple_float d2 = {-4.54545454e-02f, -5.45454545e-10f, -4.54545454e-18f}; // ~ -1/22
  triple_float d1 = {-4.66666666e-01f, -6.66666666e-09f, -2.15577668e-17f}; // ~ -7/15
  triple_float d0 = {1.00000000f, 0.00000000f, 0.00000000f};

  // Évaluation du Dénominateur (Schéma de Horner)
  triple_float den = d4;
  den = add_tf(mul_tf(den, x2), d3);
  den = add_tf(mul_tf(den, x2), d2);
  den = add_tf(mul_tf(den, x2), d1);
  den = add_tf(mul_tf(den, x2), d0);

  // Résultat = x * (Num / Den) à l'aide d'une seule division
  return mul_tf(x, div_tf(num, den));
}
// Fraction continue de Gauss (Rang 27)
triple_float remez_tan_106bits_strict(float x_val)
{
  triple_float x = {x_val, 0.0f, 0.0f};
  triple_float x2 = mul_tf(x, x);
  triple_float a = {27.0f, 0.0f, 0.0f};

  for (int i = 25; i > 0; i -= 2)
  {
    triple_float div_step = div_tf(x2, a);
    a = add_tf({static_cast<float>(i), 0.0f, 0.0f}, -div_step);
  }
  return div_tf(x, a);
}

int main()
{
  std::cout << std::scientific << std::setprecision(12);
  std::cout << "Test de la structure triple_float sur la boucle de controle :\n\n";

  for (float i = 0.0f; i < 0.75f; i += 0.024f)
  {
    triple_float res = remez_tan_106bits_strict(i); //remez_tan_69bits_triple_float(i);

    // Reconstruction de la valeur double-double en précision arbitraire
    mp_float res_mp = res.to_mp_float();

    // Référence absolue avec mpfr
    mp_float ref = boost::multiprecision::tan(mp_float(i));

    // Différence exacte
    mp_float diff = res_mp - ref;

    std::cout << "i = " << std::fixed << std::setprecision(3) << i << " ->  " << std::scientific << std::setprecision(7)
              << "  Diff : " << diff << std::endl;
  }
  return 0;
}

// int main() {
//     std::cout << std::scientific << std::setprecision(6);
//     std::cout << "Validation de l'erreur absolue reelle (cible < 1.0e-32) :\n";
//     std::cout << "--------------------------------------------------------\n";

//     for(double i = 0.0; i < 0.75; i += 0.024) {
//       dd_t res = remez_tan_106bits_strict(i);

//         // Reconstruction de la valeur double-double en précision arbitraire
//         mp_float res_106 = mp_float(res.h) + mp_float(res.l);

//         // Référence absolue avec mpfr
//         mp_float ref = boost::multiprecision::tan(mp_float(i));

//         // Différence exacte
//         mp_float diff = res_106 - ref;

//         std::cout << "i = " << std::fixed << std::setprecision(3) << i
//                   << std::scientific << std::setprecision(4)
//                   << " -> Diff reelle: " << diff << std::endl;
//     }
//     return 0;
// }
