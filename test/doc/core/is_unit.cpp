#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  using plf::is_unit;
  auto f = 1.0;
  auto a = plf::polyfloat(-1.0);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-300, 0.0);
  std::cout << std::setprecision(15);
  std::cout << "f  "<< f << std::endl;
  std::cout << "a  "<< a << std::endl;
  std::cout << "b  "<< b << std::endl;
  std::cout << "c  "<< c << std::endl;
  std::cout << "is_unit(f) " << is_unit(f) << std::endl;
  std::cout << "is_unit(a) " << is_unit(a) << std::endl;
  std::cout << "is_unit(b) " << is_unit(b) << std::endl;
  std::cout << "is_unit(c) "<<  is_unit(c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>, eve::fixed<2>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>, eve::fixed<2>>;
  pf2_t wb(b, 0.0 );
  pf3_t wc(c, 0.0 );
  std::cout << "wb          "<< wb << std::endl;
  std::cout << "wc          "<< wc << std::endl;
  std::cout << "is_unit(wb) "<< is_unit(wb) << std::endl;
  std::cout << "is_unit(wc) "<< is_unit(wc) << std::endl;

  return 0;
}
