#include <iostream>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // A double, a double_real_t<double>, and a triple_real_t<double> in one expression.
  double x = 0.1;
  plf::double_real_t<double> y(1.0, 1.0e-20);
  plf::triple_real_t<double> z(1.0, 1.0e-20, 1.0e-40);

  auto r = x + y * z;

  std::cout << "x + y * z = " << r << "\n";
  std::cout << "dimension = " << plf::dimension_v<decltype(r)> << "\n";
}
