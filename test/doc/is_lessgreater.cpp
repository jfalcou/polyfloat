#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  using plf::is_lessgreater;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-300, 0.0);
  std::cout << std::setprecision(15) << std::hexfloat;
  std::cout << "f  "<< f << std::endl;
  std::cout << "a  "<< a << std::endl;
  std::cout << "b  "<< b << std::endl;
  std::cout << "c  "<< c << std::endl;
  std::cout << "is_lessgreater(f, f) " << is_lessgreater(f, f) << std::endl;
  std::cout << "is_lessgreater(a, a) " << is_lessgreater(a, a) << std::endl;
  std::cout << "is_lessgreater(b, b) " << is_lessgreater(b, b) << std::endl;
  std::cout << "is_lessgreater(c, c) "<<  is_lessgreater(c, c) << std::endl;
  std::cout << "is_lessgreater(a, f) " << is_lessgreater(a, f) << std::endl;
  std::cout << "is_lessgreater(b, a) " << is_lessgreater(b, a) << std::endl;
  std::cout << "is_lessgreater(c, b) "<<  is_lessgreater(c, b) << std::endl;
  std::cout << "is_lessgreater(f, a) " << is_lessgreater(f, a) << std::endl;
  std::cout << "is_lessgreater(a, b) " << is_lessgreater(a, b) << std::endl;
  std::cout << "is_lessgreater(b, c) "<<  is_lessgreater(b, c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          "<< wb << std::endl;
  std::cout << "wc          "<< wc << std::endl;
  std::cout << "is_lessgreater(wb, wb) "<< is_lessgreater(wb, wb) << std::endl;
  std::cout << "is_lessgreater(wc, wc) "<< is_lessgreater(wc, wc) << std::endl;
  std::cout << "is_lessgreater(wc, wb) "<< is_lessgreater(wc, wb) << std::endl;
  std::cout << "is_lessgreater(wc, wb) "<<        (wc < wb ) << std::endl;

  return 0;
}
