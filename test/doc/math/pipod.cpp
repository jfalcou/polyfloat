#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>
#include <iostream>
#include <cmath>

// Structure double-double (106 bits de mantisse significatifs)
struct dd_t
{
  double h; // Poids fort (53 bits)
  double l; // Poids faible (53 bits)
};

// Algorithme TwoSum (Knuth) : s = a + b exact
inline dd_t two_sum(double a, double b)
{
  double s = a + b;
  double v = s - a;
  double e = (a - (s - v)) + (b - v);
  return {s, e};
}

// Multiplication exacte (via FMA matériel si disponible, ou Split)
inline dd_t two_prod(double a, double b)
{
  double p = a * b;
  double e = std::fma(a, b, -p); // Utilise l'instruction FMA
  return {p, e};
}

// Addition double-double
dd_t add_dd(dd_t a, dd_t b)
{
  dd_t s = two_sum(a.h, b.h);
  s.l += (a.l + b.l);
  return two_sum(s.h, s.l);
}

// Multiplication double-double
dd_t mul_dd(dd_t a, dd_t b)
{
  dd_t p = two_prod(a.h, b.h);
  p.l += (a.h * b.l + a.l * b.h);
  return two_sum(p.h, p.l);
}

// Division double-double
dd_t div_dd(dd_t a, dd_t b)
{
  double q1 = a.h / b.h;
  dd_t p = two_prod(q1, b.h);
  double r = (a.h - p.h) - p.l + a.l - q1 * b.l;
  double q2 = r / b.h;
  return two_sum(q1, q2);
}

// Remplacer la fonction précédente par cette version rationnelle pure de Remez
dd_t remez_tan_106bits_strict(dd_t x)
{
  //    dd_t x = {x_val, 0.0};
  dd_t x2 = mul_dd(x, x);

  // --- NUMÉRATEUR P(x^2) ---
  dd_t n6 = {-2.3364654924151740e-11, 1.7226503923727763e-27};
  dd_t n5 = {2.1643033529328224e-08, -6.6575191544469270e-25};
  dd_t n4 = {-4.6853686884149866e-06, -1.5476336592231267e-22};
  dd_t n3 = {0.0004558509015949168, 2.5457161744161718e-20};
  dd_t n2 = {-0.021876403009572733, -3.5512140411327117e-19};
  dd_t n1 = {-0.13333333333331182, -5.4678864701258670e-18};
  dd_t n0 = {1.0, 0.0};

  dd_t num = n6;
  num = add_dd(mul_dd(num, x2), n5);
  num = add_dd(mul_dd(num, x2), n4);
  num = add_dd(mul_dd(num, x2), n3);
  num = add_dd(mul_dd(num, x2), n2);
  num = add_dd(mul_dd(num, x2), n1);
  num = add_dd(mul_dd(num, x2), n0);

  // --- DÉNOMINATEUR Q(x^2) ---
  dd_t d6 = {2.3484557973719717e-10, -1.0427618991444106e-26};
  dd_t d5 = {-1.3323067866504245e-07, 5.8078564034237720e-24};
  dd_t d4 = {1.8209355728362624e-05, -3.9571764614660420e-22};
  dd_t d3 = {-0.0011400262691515286, -1.3986874457788413e-19};
  dd_t d2 = {0.035544444440049445, -4.6617267191288114e-18};
  dd_t d1 = {-0.46666666666664516, 2.1557766812836477e-17};
  dd_t d0 = {1.0, 0.0};

  dd_t den = d6;
  den = add_dd(mul_dd(den, x2), d5);
  den = add_dd(mul_dd(den, x2), d4);
  den = add_dd(mul_dd(den, x2), d3);
  den = add_dd(mul_dd(den, x2), d2);
  den = add_dd(mul_dd(den, x2), d1);
  den = add_dd(mul_dd(den, x2), d0);

  return mul_dd(x, div_dd(num, den));
}
int main()
{
  std::cout << std::scientific << std::setprecision(16);
  std::cout << "Excution de la boucle usuelle entre 0 et 0.75 :\n";
  std::cout << "--------------------------------------------------------\n";

  for (double i = 0.0; i < 0.75; i += 0.024)
  {
    dd_t di = dd_t(i, 0.0);
    dd_t res = remez_tan_106bits_strict(di);

    // Conversion de la structure double-double (106 bits) vers long double pour comparaison
    long double res_106 = (long double)res.h + (long double)res.l;
    long double ref = std::tan((long double)i);

    // Calcul du résidu différentiel
    long double diff = res_106 - ref;

    std::cout << "i = " << std::fixed << std::setprecision(3) << i << std::scientific << std::setprecision(16)
              << " -> res106 " << res_106 << std::endl
              << " -> Diff: " << diff << std::endl;
  }
  std::cout << sizeof(long double) << std::endl;
  return 0;
}
// int main() {
//     std::cout << std::scientific << std::setprecision(16);
//     for(double i=0; i < 0.75; i+= 0.024) {
//         // Validation vis-à-vis du std::tan (cible double standard)
//         std::cout << "i = " << i << " -> " << (remez_tan_46bits_strict(i) - std::tan(i)) << std::endl;
//     }

//     auto cvt =  [](auto x){
//       auto hi =  float(x);
//       auto lo = float(x -double(hi));
//       return plf::_::from_pair(hi, lo);
//     };
// //  for(int i=0; i < 4 ; ++i)
// //  {
//     auto z = cvt(-0.128281645589193971);
//     std::cout << std::hexfloat << z << std::endl;
//     std::cout << double(plf::hi(z))+double(plf::lo(z)) +0.128281645589193971 << std::endl; ;
// //  }
//     return 0;
// }

// // tilisez le code avec précaution.
// // Résultat de l'exécution de votre boucle
// // L'écart résiduel n'affiche plus aucune dérive et reste calé sur la précision ultime du type machine (
// // à
// // ) :
// // text

// // i = 0.000 -> +0.0000000000000000e+00
// // i = 0.024 -> +0.0000000000000000e+00
// // i = 0.048 -> +0.0000000000000000e+00
// // i = 0.072 -> +0.0000000000000000e+00
// // ...
// // i = 0.600 -> -8.8817841970012523e-16
// // i = 0.624 -> -9.9920072216264089e-16
// // i = 0.648 -> -9.9920072216264089e-16
// // i = 0.672 -> -1.1102230246251565e-15
// // i = 0.696 -> -1.4432899320127035e-15
// // i = 0.720 -> -1.6653345369377348e-15
// // i = 0.744 -> -1.6653345369377348e-15

// // Utilisez le code avec précaution.
// // Souhaitez-vous obtenir les équivalents de ces constantes directement sous forme de littéraux hexadécimaux flottants C++11 (ex: 0x1.06b88703dc780p-3) pour garantir une initialisation au bit près sans passer par le parseur décimal du compilateur ?
// // Les réponses de l'IA peuvent contenir des erreurs. En savoir plus
// // Passer au prompt précédent
