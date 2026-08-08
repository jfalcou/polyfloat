#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  using plf::is_infinite;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-300, 0.0);
  std::cout << std::setprecision(15) << std::hexfloat;
  std::cout << "f  "<< f << std::endl;
  std::cout << "a  "<< a << std::endl;
  std::cout << "b  "<< b << std::endl;
  std::cout << "c  "<< c << std::endl;
  std::cout << "is_infinite(f) " << is_infinite(f) << std::endl;
  std::cout << "is_infinite(a) " << is_infinite(a) << std::endl;
  std::cout << "is_infinite(b) " << is_infinite(b) << std::endl;
  std::cout << "is_infinite(c) "<<  is_infinite(c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>, eve::fixed<2>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>, eve::fixed<2>>;
  pf2_t wb(b, eve::inf(eve::as(f)) );
  pf3_t wc(c, eve::inf(eve::as(f)) );
  std::cout << "wb          "<< wb << std::endl;
  std::cout << "wc          "<< wc << std::endl;
  std::cout << "is_infinite(wb) "<< is_infinite(wb) << std::endl;
  std::cout << "is_infinite(wc) "<< is_infinite(wc) << std::endl;

  return 0;
}
