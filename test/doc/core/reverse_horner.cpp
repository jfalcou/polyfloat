#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  std::cout <<  std::setprecision(15);
//   using plf::abs;
  using w_t = eve::wide<plf::double_real_t<double>, eve::fixed<4>>;


  w_t xd = {-0.3, 0.5, 0.0, 2.0};
  w_t b  = {-2, 10.5, -4, 0.1};

  w_t x(0.2);
  kumi::tuple<float, float, float, float> v {1, -2, 3, -4};
  kumi::tuple<w_t, w_t, w_t> wv { w_t{1.5, 1, 2, 3}, w_t{4, 5, 6, 7}, w_t{8, 9, 10, 11} };
  auto t = kumi::tuple{1.5f,4.0f,8.0f};

  std::cout << "---- simd" << '\n'
            << "<- xd                                       = " << xd << '\n'
            << "<- x                                        = " << x  << '\n'
            << "<- l and v contain  {1, -2, 3, -4} "<< '\n'
            << "<- wv      contains { {1.5, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11} }"<< '\n'
            << "-> reverse_horner(xd, 1, -2, 3, -4)                 = " << plf::reverse_horner(xd, 1.0f, -2.0f, 3.0f, -4.0f) << '\n'
            << "-> reverse_horner(0.5, 1, b, 3, -4)                 = " << plf::reverse_horner(0.5, 1, b, 3, -4) << '\n'
            << "-> reverse_horner(x, 1, -2, 3, -4)                  = " << plf::reverse_horner(xd, 1.0, -2.0, 3.0, -4.0)  << '\n'
            << "-> reverse_horner(xd, eve::coefficients(v))         = " << plf::reverse_horner(xd, eve::coefficients(v))  << '\n'
            << "-> reverse_horner(xd, eve::coefficients(t))         = " << plf::reverse_horner(xd,eve::coefficients(t))   << '\n'
            << "-> reverse_horner(x, eve::coefficients(t))          = " << plf::reverse_horner(x, eve::coefficients(t))   << '\n'
            << "-> reverse_horner(x, eve::coefficients(wv))         = " << plf::reverse_horner(x, eve::coefficients(wv)) << '\n'
            << "-> reverse_horner(0.5, wv)                          = " << plf::reverse_horner(0.5, eve::coefficients(wv)) << '\n'
            << "-> reverse_horner(xd, wv)                           = " << plf::reverse_horner(xd,  eve::coefficients(wv)) << '\n'
            << "-> reverse_horner(1.0f, eve::coefficients(t))       = " << plf::reverse_horner(1.0f, eve::coefficients(t))   << '\n'
  ;

  using d2_t = plf::triple_real_t<double>;
  d2_t xs(2.0, 1.0e-30, 1.0e-54);
  std::cout << "---- scalar" << '\n'
            << "<- xs                          = " << xs << '\n'
            << "-> reverse_horner(xs, 1.5, 2.0, 4.0)   = " << plf::reverse_horner(xs, d2_t(1.5, 1.0e-18, 1.0e-40), d2_t(2.0), 4.0) << '\n'
            << "-> reverse_horner(xs, 1.5, 2.0, 4.0)   = " << plf::reverse_horner[eve::kahan](xs, d2_t(1.5, 1.0e-18, 1.0e-40), d2_t(2.0), 4.0) << '\n'
            << "-> reverse_horner(xs, kumi::tuple{1.5, 2.0, 4.0}) = " << plf::reverse_horner(xs,eve::coefficients( kumi::tuple{d2_t(1.5, 1.0e-18, 1.0e-40), d2_t(2.0), 4.0})) << '\n'
    ;


  return 0;
}
