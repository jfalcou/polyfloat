#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  std::cout << std::setprecision(15);
  using plf::chi;
  using dd = plf::double_real_t<double>;
  eve::wide lo = {2.0, -4.0, -10.0, 0.0};
  eve::wide hi = {4.0, -1.0, 0.0, 5.0};
  dd x(2.0, 2.0e-25);
  auto belongs1 = [](auto v) { return v > dd(2.0, 2.0e-20); };
  auto belongs2 = [](auto v) { return v > dd(2.0, 2.0e-30); };

  std::cout << " <- x                       = " << x << '\n';
  std::cout << " <- lo                      = " << lo << '\n';
  std::cout << " <- hi                      = " << hi << '\n';
  std::cout << " -> chi(x, belongs1)         = " << plf::chi(x, belongs1) << '\n';
  std::cout << " -> chi(x, belongs2)         = " << plf::chi(x, belongs2) << '\n';
  std::cout << " -> chi(x, lo, hi)          = " << plf::chi(x, lo, hi) << '\n';
  std::cout << " -> chi[x > -2](x, lo, hi)  = " << plf::chi[x > -2](x, lo, hi) << '\n';

  return 0;
}
