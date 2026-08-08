#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  using plf::is_negative;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(-1.0, 1.0e-300, 0.0);
  std::cout << std::setprecision(15);
  std::cout << "f  "<< f << std::endl;
  std::cout << "a  "<< a << std::endl;
  std::cout << "b  "<< b << std::endl;
  std::cout << "c  "<< c << std::endl;
  std::cout << "is_negative(f)  " << is_negative(f) << std::endl;
  std::cout << "is_negative(a)  " << is_negative(a) << std::endl;
  std::cout << "is_negative(b)  " << is_negative(b) << std::endl;
  std::cout << "is_negative(c)  "<<  is_negative(c) << std::endl;
  std::cout << "is_negative(-c) "<<  is_negative(-c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>, eve::fixed<2>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>, eve::fixed<2>>;
  pf2_t wb(b, 0.0 );
  pf3_t wc(c, -0.0 );
  std::cout << "wb          "<< wb << std::endl;
  std::cout << "wc          "<< wc << std::endl;
  std::cout << "-wc         "<< -wc << std::endl;
  std::cout << "is_negative(wb) "<< is_negative(wb) << std::endl;
  std::cout << "is_negative(wc) "<< is_negative(wc) << std::endl;
  std::cout << "is_negative(-wc) "<< is_negative(-wc) << std::endl;
  auto d = plf::polyfloat<double, 3>(-0.0);
  std::cout << "d  "<< d << std::endl;
  std::cout << "is_negative(d)  "<<  is_negative(d) << std::endl;
  std::cout << "-d  "<< -d << std::endl;

  return 0;
}
