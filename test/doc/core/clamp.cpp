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
  using wdd = eve::wide<dd, eve::fixed<4>>;
  eve::wide lo = {2.0, 4.0, -10.0, 0.0};
  eve::wide hi = {4.0, 8.0, 0.0, 5.0};
  dd x(2.0, 2.0e-25);
  wdd wlo(lo);
  wdd whi(hi);
  std::cout << " <- x                       = " << x << '\n';
  std::cout << " <- lo                      = " << lo << '\n';
  std::cout << " <- hi                      = " << hi << '\n';
  std::cout << " <- lo                      = " << wlo << '\n';
  std::cout << " <- hi                      = " << whi << '\n';
  std::cout << " -> clamp(x, wlo, whi)      = " << plf::clamp(x, wlo, whi) << '\n';
  std::cout << " -> clamp(x, lo, hi)        = " << plf::clamp(x, lo, hi) << '\n';
  return 0;
}
