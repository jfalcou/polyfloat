#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  using plf::is_ltz;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-300, 0.0);
  std::cout << std::setprecision(15) << std::hexfloat;
  std::cout << "f  "<< f << std::endl;
  std::cout << "a  "<< a << std::endl;
  std::cout << "b  "<< b << std::endl;
  std::cout << "c  "<< c << std::endl;
  std::cout << "is_ltz(f) " << is_ltz(f) << std::endl;
  std::cout << "is_ltz(a) " << is_ltz(a) << std::endl;
  std::cout << "is_ltz(b) " << is_ltz(b) << std::endl;
  std::cout << "is_ltz(c) "<<  is_ltz(c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>, eve::fixed<2>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>, eve::fixed<2>>;
  pf2_t wb(b, 0.0 );
  pf3_t wc(c, 0.0 );
  std::cout << "wb          "<< wb << std::endl;
  std::cout << "wc          "<< wc << std::endl;
  std::cout << "is_ltz(wb) "<< is_ltz(wb) << std::endl;
  std::cout << "is_ltz(wc) "<< is_ltz(wc) << std::endl;

  return 0;
}
