#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
   std::cout <<  std::setprecision(15);
//   using plf::abs;
//   using w_t = eve::wide<plf;; doublereal_t<double>;


//   w_t xd = {-0.3, 0.5, 0.0, 2.0};
//   w_t b  = {-2, 10.5, -4, 0.1};

//   w_t x(0.2);
//   kumi::tuple<float, float, float, float> v {1, -2, 3, -4};
//   kumi::tuple<w_t, w_t, w_t> wv { w_t{1.5, 1, 2, 3}, w_t{4, 5, 6, 7}, w_t{8, 9, 10, 11} };
//   auto t = kumi::tuple{1.5f,4.0f,8.0f};

//   std::cout << "---- simd" << '\n'
//             << "<- xd                                       = " << xd << '\n'
//             << "<- x                                        = " << x  << '\n'
//             << "<- l and v contain  {1, -2, 3, -4} "<< '\n'
//             << "<- wv      contains { {1.5, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11} }"<< '\n'
//             << "-> horner(xd, 1, -2, 3, -4)                 = " << plf::horner(xd, 1.0f, -2.0f, 3.0f, -4.0f) << '\n'
//             << "-> horner(0.5, 1, b, 3, -4)                 = " << plf::horner(0.5, 1, b, 3, -4) << '\n'
//             << "-> horner(x, 1, -2, 3, -4)                  = " << plf::horner(xd, 1, -2, 3, -4)  << '\n'
//             << "-> horner(xd, v)                            = " << plf::horner(xd, v)  << '\n'
//             << "-> horner(xd, t)                            = " << plf::horner(xd, t)   << '\n'
//             << "-> horner(x, t)                             = " << plf::horner(x, t)   << '\n'
//             << "-> horner(x, wv)                            = " << plf::horner(x, wv) << '\n'
//             << "-> horner(0.5f, wv)                         = " << plf::horner(0.5, wv) << '\n'
//             << "-> horner(xd, wv)                           = " << plf::horner(xd, wv) << '\n'
//             << "-> horner(1.0f, t)                          = " << plf::horner(1.0f, t) << '\n'
//  ;

  using d2_t = plf::triple_real_t<double>;
  d2_t xs(1.0, 1.0e-30, 1.0e-54);
//  double xs(1.0);
  std::cout << "---- scalar" << '\n'
            << "<- xs                          = " << xs << '\n'
            << "-> horner(xs, 1.5, 2.0, 4.0)   = " << plf::horner(xs, d2_t(1.5, 1.0e-18, 1.0e-40), d2_t(2.0), 4.0) << '\n'
            << "-> horner(xs, kumi::tuple{1.5, 2.0, 4.0}) = " << plf::horner(xs,eve::coefficients( kumi::tuple{d2_t(1.5, 1.0e-18, 1.0e-40), d2_t(2.0), 4.0})) << '\n'
  //= " << plf::horner(xs, kumi::tuple{1.5, 2.0, 4.0}) << '\n'
    ;


  return 0;
}
