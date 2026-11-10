#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // Three values of different magnitudes.
  using plf::three_add;
  std::cout << std::setprecision(17);
  double x = 1.0 / 3.0, y = 1.0e-17 / 7.0, z = -2.0 / 9.0;
  std::cout << "x  " << x << std::endl;
  std::cout << "y  " << y << std::endl;
  std::cout << "z  " << z << std::endl;
  auto [s, e1, e2] = three_add(x, y, z);
  std::cout << "s  " << s << std::endl;
  std::cout << "e1  " << e1 << std::endl;
  std::cout << "e2  " << e2 << std::endl;

  eve::wide<double> wx([](auto i, auto) { return 1.0 / (3.0 + i); });
  eve::wide<double> wy(y), wz(z);
  auto [ws, we1, we2] = three_add(wx, wy, wz);
  std::cout << "wx  " << wx << std::endl;
  std::cout << "ws  " << ws << std::endl;
  std::cout << "we1  " << we1 << std::endl;
  std::cout << "we2  " << we2 << std::endl;
}
