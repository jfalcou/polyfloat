#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  using plf::is_gtz;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-300, 0.0);
  std::cout << std::setprecision(15) << std::hexfloat;
  std::cout << "f  "<< f << std::endl;
  std::cout << "a  "<< a << std::endl;
  std::cout << "b  "<< b << std::endl;
  std::cout << "c  "<< c << std::endl;
  std::cout << "is_gtz(f) " << is_gtz(f) << std::endl;
  std::cout << "is_gtz(a) " << is_gtz(a) << std::endl;
  std::cout << "is_gtz(b) " << is_gtz(b) << std::endl;
  std::cout << "is_gtz(c) "<<  is_gtz(c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>, eve::fixed<2>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>, eve::fixed<2>>;
  pf2_t wb(b, 0.0 );
  pf3_t wc(c, 0.0 );
  std::cout << "wb          "<< wb << std::endl;
  std::cout << "wc          "<< wc << std::endl;
  std::cout << "is_gtz(wb) "<< is_gtz(wb) << std::endl;
  std::cout << "is_gtz(wc) "<< is_gtz(wc) << std::endl;

  return 0;
}
