#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>
#include <iostream>
#include <cmath>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <boost/multiprecision/mpfr.hpp>

using mp_float = boost::multiprecision::mpfr_float_50;

struct dd_t
{
  double h;
  double l;
};

// Algorithme TwoSum (Knuth)
inline dd_t two_sum(double a, double b)
{
  double s = a + b;
  double v = s - a;
  double e = (a - (s - v)) + (b - v);
  return {s, e};
}

// Multiplication exacte via FMA
inline dd_t two_prod(double a, double b)
{
  double p = a * b;
  double e = std::fma(a, b, -p);
  return {p, e};
}

dd_t sub_dd(dd_t a, dd_t b)
{
  dd_t s = two_sum(a.h, -b.h);
  s.l += (a.l - b.l);
  return two_sum(s.h, s.l);
}

dd_t add_dd(dd_t a, dd_t b)
{
  dd_t s = two_sum(a.h, b.h);
  s.l += (a.l + b.l);
  return two_sum(s.h, s.l);
}

dd_t mul_dd(dd_t a, dd_t b)
{
  dd_t p = two_prod(a.h, b.h);
  p.l += (a.h * b.l + a.l * b.h);
  return two_sum(p.h, p.l);
}

dd_t div_dd(dd_t a, dd_t b)
{
  double q1 = a.h / b.h;
  dd_t p = two_prod(q1, b.h);
  double r = (a.h - p.h) - p.l + a.l - q1 * b.l;
  double q2 = r / b.h;
  return two_sum(q1, q2);
}

// Fraction continue de Gauss (Rang 27)
dd_t remez_tan_106bits_strict(double x_val)
{
  dd_t x = {x_val, 0.0};
  dd_t x2 = mul_dd(x, x);
  dd_t a = {27.0, 0.0};

  for (int i = 25; i > 0; i -= 2)
  {
    dd_t div_step = div_dd(x2, a);
    a = sub_dd({static_cast<double>(i), 0.0}, div_step);
  }
  return div_dd(x, a);
}

int main()
{
  std::cout << std::scientific << std::setprecision(6);
  std::cout << "Validation de l'erreur absolue reelle (cible < 1.0e-32) :\n";
  std::cout << "--------------------------------------------------------\n";

  for (double i = 0.0; i < 0.75; i += 0.024)
  {
    dd_t res = remez_tan_106bits_strict(i);

    // Reconstruction de la valeur double-double en précision arbitraire
    mp_float res_106 = mp_float(res.h) + mp_float(res.l);

    // Référence absolue avec mpfr
    mp_float ref = boost::multiprecision::tan(mp_float(i));

    // Différence exacte
    mp_float diff = res_106 - ref;

    std::cout << "i = " << std::fixed << std::setprecision(3) << i << std::scientific << std::setprecision(4)
              << " -> Diff reelle: " << diff << std::endl;
  }
  return 0;
}
