#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // A negative value is added to the usual ones, read as integers.
  using plf::sign_alternate;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::cout << std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  auto d = plf::polyfloat(-2.5, 1.0e-20);
  std::cout << "d  " << d << std::endl;
  std::cout << "sign_alternate(f) = " << sign_alternate(f) << std::endl;
  std::cout << "sign_alternate(a) = " << sign_alternate(a) << std::endl;
  std::cout << "sign_alternate(b) = " << sign_alternate(b) << std::endl;
  std::cout << "sign_alternate(c) = " << sign_alternate(c) << std::endl;
  std::cout << "sign_alternate(d) = " << sign_alternate(d) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "sign_alternate(wb) = " << sign_alternate(wb) << std::endl;
  std::cout << "sign_alternate(wc) = " << sign_alternate(wc) << std::endl;
}
