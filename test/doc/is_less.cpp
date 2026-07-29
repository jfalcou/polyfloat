#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
//   using plf::is_less;
//   auto f = 1.0;
//   auto a = plf::polyfloat(1.3);
//   auto b = plf::polyfloat(1.0, 1.0e-300);
//   auto c = plf::polyfloat(1.0, 1.0e-300, 0.0);
//   std::cout << std::setprecision(15) << std::hexfloat;
//   std::cout << "f  "<< f << std::endl;
//   std::cout << "a  "<< a << std::endl;
//   std::cout << "b  "<< b << std::endl;
//   std::cout << "c  "<< c << std::endl;
//   std::cout << "is_less(f, f) " << is_less(f, f) << std::endl;
//   std::cout << "is_less(a, a) " << is_less(a, a) << std::endl;
//   std::cout << "is_less(b, b) " << is_less(b, b) << std::endl;
//   std::cout << "is_less(c, c) "<<  is_less(c, c) << std::endl;
//   std::cout << "is_less(a, f) " << is_less(a, f) << std::endl;
//   std::cout << "is_less(b, a) " << is_less(b, a) << std::endl;
//   std::cout << "is_less(c, b) "<<  is_less(c, b) << std::endl;
//   std::cout << "is_less(f, a) " << is_less(f, a) << std::endl;
//   std::cout << "is_less(a, b) " << is_less(a, b) << std::endl;
//   std::cout << "is_less(b, c) "<<  is_less(b, c) << std::endl;

//   using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
//   using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
//   pf2_t wb(b);
//   pf3_t wc(c);
//   std::cout << "wb          "<< wb << std::endl;
//   std::cout << "wc          "<< wc << std::endl;
//   std::cout << "is_less(wb, wb) "<< is_less(wb, wb) << std::endl;
//   std::cout << "is_less(wc, wc) "<< is_less(wc, wc) << std::endl;
//   std::cout << "is_less(wc, wb) "<< is_less(wc, wb) << std::endl;


  std::cout <<  std::setprecision(15);
  using plf::clamp;
  using dd = plf::double_real_t<double>;
  using wdd = eve::wide<dd, eve::fixed<4>>;
  eve::wide lo = {2.0, -4.0, -10.0, 0.0};
  // eve::wide hi = {4.0, -1.0, 0.0, 5.0};
  dd x(2.0, 2.0e-25);
  wdd wx(x);
  std::cout << (wx < lo) << std::endl;

  return 0;
}
