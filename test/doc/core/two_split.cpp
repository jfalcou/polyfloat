#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // A value whose significand uses every bit, split in two halves.
  using plf::two_split;
  std::cout << std::setprecision(17);
  double x = 1.0 / 3.0, y = 1.0e-17 / 7.0, z = -2.0 / 9.0;
  std::cout << "x  " << x << std::endl;
  std::cout << "y  " << y << std::endl;
  std::cout << "z  " << z << std::endl;
  auto [s, e] = two_split(x);
  std::cout << "s  " << s << std::endl;
  std::cout << "e  " << e << std::endl;

  eve::wide<double> wx([](auto i, auto) { return 1.0 / (3.0 + i); });
  auto [ws, we] = two_split(wx);
  std::cout << "wx  " << wx << std::endl;
  std::cout << "ws  " << ws << std::endl;
  std::cout << "we  " << we << std::endl;
}
