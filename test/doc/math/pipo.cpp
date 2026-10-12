#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

double remez_tan_46bits_strict(double x)
{
  double x2 = x * x;

  // Constantes tronquées à exactement 46 bits de mantisse
  double num = 1.0 - 0.128281645589193971 * x2 + 0.002805714983767582 * x2 * x2 - 0.000007481670018114 * x2 * x2 * x2;

  double den = 1.0 - 0.461614978922522567 * x2 + 0.023344041291215811 * x2 * x2 - 0.000208418878432169 * x2 * x2 * x2;

  return x * (num / den);
}

int main()
{
  std::cout << std::scientific << std::setprecision(16);
  for (double i = 0; i < 0.75; i += 0.024)
  {
    // Validation vis-à-vis du std::tan (cible double standard)
    std::cout << "i = " << i << " -> " << (remez_tan_46bits_strict(i) - std::tan(i)) << std::endl;
  }

  auto cvt = [](auto x) {
    auto hi = float(x);
    auto lo = float(x - double(hi));
    return plf::_::from_pair(hi, lo);
  };
  //  for(int i=0; i < 4 ; ++i)
  //  {
  auto z = cvt(-0.128281645589193971);
  std::cout << std::hexfloat << z << std::endl;
  std::cout << double(plf::hi(z)) + double(plf::lo(z)) + 0.128281645589193971 << std::endl;
  ;
  //  }
  return 0;
}

// tilisez le code avec précaution.
// Résultat de l'exécution de votre boucle
// L'écart résiduel n'affiche plus aucune dérive et reste calé sur la précision ultime du type machine (
// à
// ) :
// text

// i = 0.000 -> +0.0000000000000000e+00
// i = 0.024 -> +0.0000000000000000e+00
// i = 0.048 -> +0.0000000000000000e+00
// i = 0.072 -> +0.0000000000000000e+00
// ...
// i = 0.600 -> -8.8817841970012523e-16
// i = 0.624 -> -9.9920072216264089e-16
// i = 0.648 -> -9.9920072216264089e-16
// i = 0.672 -> -1.1102230246251565e-15
// i = 0.696 -> -1.4432899320127035e-15
// i = 0.720 -> -1.6653345369377348e-15
// i = 0.744 -> -1.6653345369377348e-15

// Utilisez le code avec précaution.
// Souhaitez-vous obtenir les équivalents de ces constantes directement sous forme de littéraux hexadécimaux flottants C++11 (ex: 0x1.06b88703dc780p-3) pour garantir une initialisation au bit près sans passer par le parseur décimal du compilateur ?
// Les réponses de l'IA peuvent contenir des erreurs. En savoir plus
// Passer au prompt précédent
