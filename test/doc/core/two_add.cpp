#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // Three thirds of an ulp apart, so the rounded sum has an error.
  using plf::two_add;
  std::cout << std::setprecision(17);
  double x = 1.0 / 3.0, y = 1.0e-17 / 7.0, z = -2.0 / 9.0;
  std::cout << "x  " << x << std::endl;
  std::cout << "y  " << y << std::endl;
  std::cout << "z  " << z << std::endl;
  auto [s, e] = two_add(x, y);
  std::cout << "s  " << s << std::endl;
  std::cout << "e  " << e << std::endl;

  eve::wide<double> wx([](auto i, auto) { return 1.0 / (3.0 + i); });
  eve::wide<double> wy(y);
  auto [ws, we] = two_add(wx, wy);
  std::cout << "wx  " << wx << std::endl;
  std::cout << "ws  " << ws << std::endl;
  std::cout << "we  " << we << std::endl;
}
