#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  std::cout <<  std::setprecision(15);
  using plf::cumfun;
  using plf::max;
   auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::setprecision(15);
  std::cout << "f  "<< f << std::endl;
  std::cout << "a  "<< a << std::endl;
  std::cout << "b  "<< b << std::endl;
  std::cout << "c  "<< c << std::endl;
   std::cout << "cumfun(max, f, f) " << cumfun(max, kumi::make_tuple(f, f)) << std::endl;
   std::cout << "cumfun(max, f, f) " << cumfun(max,                  f, f)  << std::endl;
  std::cout << "cumfun(max, a, a) " << cumfun(max, a, a) << std::endl;
  std::cout << "cumfun(max, b, b) " << cumfun(max, b, b) << std::endl;
  std::cout << "cumfun(max, c, c) "<<  cumfun(max, c, c) << std::endl;
  std::cout << "cumfun(max, a, f) " << cumfun(max, a, f) << std::endl;
  std::cout << "cumfun(max, b, a) " << cumfun(max, b, a) << std::endl;
  std::cout << "cumfun(max, c, b) "<<  cumfun(max, c, b) << std::endl;
  std::cout << "cumfun(max, f, a) " << cumfun(max, f, a) << std::endl;
  std::cout << "cumfun(max, a, b) " << cumfun(max, a, b) << std::endl;
  std::cout << "cumfun(max, b, c) "<<  cumfun(max, b, c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          "<< wb << std::endl;
  std::cout << "wc          "<< wc << std::endl;
  std::cout << "cumfun(max, wb, wb) "<< cumfun(max, wb, wb) << std::endl;
  std::cout << "cumfun(max, wc, wc) "<< cumfun(max, wc, wc) << std::endl;
  std::cout << "cumfun(max, wc, wb) "<< cumfun(max, wc, wb) << std::endl;
  std::cout << "cumfun(max, wc, wb, b) "<< cumfun(max, wb, wb, wb, b, c, 1) << std::endl;



  return 0;
}
