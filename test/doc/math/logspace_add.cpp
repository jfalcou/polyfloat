#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

using pv_t = plf::triple_real_t<float>;

int main()
{

  pv_t xf = 10.0;
  pv_t yf = 1.0;
  pv_t zf = 11.0;
  using plf::hi;
  std::cout << "---- scalar" << '\n'
            << "<- xf                               = " << xf << '\n'
            << "<- yf                               = " << yf << '\n'
            << "<- zf                               = " << zf << '\n'
            << "-> logspace_add( xf, yf, zf)        = " << plf::logspace_add(xf, yf, zf) << '\n'
            << "-> logspace_add( xf, yf, zf)        = " << eve::logspace_add(hi(xf), hi(yf), hi(zf)) << '\n';

  return 0;
}
