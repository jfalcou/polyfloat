#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // The three arguments mix the dimensions 1, 2, and 3.
  using plf::fam;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::cout << std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "fam(f, f, f) = " << fam(f, f, f) << std::endl;
  std::cout << "fam(a, b, c) = " << fam(a, b, c) << std::endl;
  std::cout << "fam(c, b, a) = " << fam(c, b, a) << std::endl;
  std::cout << "fam(f, a, b) = " << fam(f, a, b) << std::endl;
  std::cout << "fam(b, c, f) = " << fam(b, c, f) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "fam(wb, wc, wb) = " << fam(wb, wc, wb) << std::endl;
  std::cout << "fam(wc, wb, f) = " << fam(wc, wb, f) << std::endl;
}
