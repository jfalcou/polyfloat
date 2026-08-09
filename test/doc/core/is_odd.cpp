#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  using plf::is_odd;
  auto f = 1000.0;
  auto a = plf::polyfloat(13.0);
  auto b = plf::polyfloat(1.0e30, 2.0);
  auto c = plf::polyfloat(1.0e30, 1.0e15, 1.0);
  auto d = plf::polyfloat(100.0, 12.0, 1.0e-10);
  auto e = plf::polyfloat(100.0, 12.0);
  std::cout << std::setprecision(15);
  std::cout << "f  "<< f << std::endl;
  std::cout << "a  "<< a << std::endl;
  std::cout << "b  "<< b << std::endl;
  std::cout << "d  "<< c << std::endl;
  std::cout << "e  "<< d << std::endl;
  std::cout << "c  "<< e << std::endl;
  std::cout << "is_odd(f) " << is_odd(f) << std::endl;
  std::cout << "is_odd(a) " << is_odd(a) << std::endl;
  std::cout << "is_odd(b) " << is_odd(b) << std::endl;
  std::cout << "is_odd(c) "<<  is_odd(c) << std::endl;
  std::cout << "is_odd(d) " << is_odd(d) << std::endl;
  std::cout << "is_odd(e) "<<  is_odd(e) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>, eve::fixed<2>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>, eve::fixed<2>>;
  pf2_t wb(b, e );
  pf3_t wc(c, d );
  std::cout << "wb          "<< wb << std::endl;
  std::cout << "wc          "<< wc << std::endl;
  std::cout << "is_odd(wb) "<< is_odd(wb) << std::endl;
  std::cout << "is_odd(wc) "<< is_odd(wc) << std::endl;

  return 0;
}
