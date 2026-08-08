#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  using plf::is_unordered;
  auto f = eve::nan(eve::as<double>());
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(f, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-300, 0.0);
  std::cout << std::setprecision(15) << std::hexfloat;
  std::cout << "f  "<< f << std::endl;
  std::cout << "a  "<< a << std::endl;
  std::cout << "b  "<< b << std::endl;
  std::cout << "c  "<< c << std::endl;
  std::cout << "is_unordered(f, f) " << is_unordered(f, f) << std::endl;
  std::cout << "is_unordered(a, a) " << is_unordered(a, a) << std::endl;
  std::cout << "is_unordered(b, b) " << is_unordered(b, b) << std::endl;
  std::cout << "is_unordered(c, c) "<<  is_unordered(c, c) << std::endl;
  std::cout << "is_unordered(a, f) " << is_unordered(a, f) << std::endl;
  std::cout << "is_unordered(b, a) " << is_unordered(b, a) << std::endl;
  std::cout << "is_unordered(c, b) "<<  is_unordered(c, b) << std::endl;
  std::cout << "is_unordered(f, a) " << is_unordered(f, a) << std::endl;
  std::cout << "is_unordered(a, b) " << is_unordered(a, b) << std::endl;
  std::cout << "is_unordered(b, c) "<<  is_unordered(b, c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          "<< wb << std::endl;
  std::cout << "wc          "<< wc << std::endl;
  std::cout << "is_unordered(wb, wb) "<< is_unordered(wb, wb) << std::endl;
  std::cout << "is_unordered(wc, wc) "<< is_unordered(wc, wc) << std::endl;
  std::cout << "is_unordered(wc, wb) "<< is_unordered(wc, wb) << std::endl;
  std::cout << "is_unordered(wc, wb) "<<        (wc < wb ) << std::endl;

  return 0;
}
