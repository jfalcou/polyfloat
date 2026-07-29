#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  std::cout <<  std::setprecision(15);
  using plf::clamp;
  using dd = plf::double_real_t<double>;
  eve::wide lo = {2.0, -4.0, -10.0, 0.0};
  eve::wide hi = {4.0, -1.0, 0.0, 5.0};
  dd x(2.0, 2.0e-25);

  std::cout << " <- x                       = " << x << '\n';
  std::cout << " <- lo                      = " << lo << '\n';
  std::cout << " <- hi                      = " << hi << '\n';
  std::cout << " -> clamp(x, lo, hi)          = " << plf::clamp(x, lo, hi) << '\n';
//  std::cout << " -> clamp[x > -2](x, lo, hi)  = " << plf::clamp[x > -2](x, lo, hi) << '\n';

  return 0;
}
