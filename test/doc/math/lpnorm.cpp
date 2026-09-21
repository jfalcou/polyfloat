#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

using pv_t = plf::triple_real_t<float>;

int main()
{

  pv_t xf = 10.0;
  pv_t yf = 1.0;
  pv_t zf = 111.0;
  pv_t pf = 2.0;

  std::cout << "---- scalar" << '\n'
            << "<- pf                               = " << pf << '\n'
            << "<- xf                               = " << xf << '\n'
            << "<- yf                               = " << yf << '\n'
            << "<- zf                               = " << zf << '\n'
            << "-> lpnorm(pf, xf, yf, zf)           = " << plf::lpnorm(pf, xf, yf, zf) << '\n'
            << "-> lpnorm[pedantic](pf, xf, yf, zf) = " << plf::lpnorm[plf::pedantic](pf, xf, yf, zf) << '\n';

  return 0;
}
