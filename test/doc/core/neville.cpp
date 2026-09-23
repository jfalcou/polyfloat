#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  std::cout << std::setprecision(15);
  using w_t = eve::wide<plf::double_real_t<double>, eve::fixed<4>>;

  w_t xd = {-0.3, 0.5, 0.0, 2.0};
  w_t b = {-2, 10.5, -4, 0.1};

  w_t x(0.2);

  std::cout << "---- simd" << '\n'
            << "<- xd                                  = " << xd << '\n'
            << "<- x                                   = " << x << '\n'
            << "-> neville(xd, 1, -2, 3, -4)           = " << plf::neville(xd, 1.0f, -2.0f, 3.0f, -4.0f) << '\n'
            << "-> neville(0.5, 1, b, 3, -4)           = " << plf::neville(0.5, 1, b, 3, -4) << '\n'
            << "-> neville(x, 1, -2, 3, -4)            = " << plf::neville(x, 1.0, -2.0, 3.0, -4.0) << '\n';

  plf::double_real_t<float> dx(1.0f, 1.0e-10f);
  plf::triple_real_t<float> tx(1.0f, 1.0e-10f);
  std::cout << "---- scalar" << '\n'
            << "<- dx                                  = " << dx << '\n'
            << "<- tx                                  = " << tx << '\n'
            << "-> neville(dx, 1.0f, 2.0f, 3.0f, 10.0f)= " << plf::neville(dx, 1.0f, 2.0f, 3.0f, 10.0f) << '\n'
            << "-> neville(tx, 1.0f, 2.0f, 3.0f, 10.0f)= " << plf::neville(tx, 1.0f, 2.0f, 3.0f, 10.0f) << '\n';
  return 0;
}
