#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  std::cout << std::setprecision(15);
  using plf::epsilon;
  auto f = -1.0;
  auto a = plf::polyfloat(-1.3);
  auto b = plf::polyfloat(1.0, -1.0e-300);
  auto c = plf::polyfloat(-1.0, 1.0e-10, -1.0e-300);
  auto d = plf::polyfloat(-1.0, 1.0e-30, 0.0);
  auto e = plf::polyfloat(1.0, 0.0, 0.0);
  auto g = plf::polyfloat(1.0, 0.0);
  std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "d  " << d << std::endl;
  std::cout << "g  " << g << std::endl;
  std::cout << "epsilon(f) " << epsilon(f) << std::endl;
  std::cout << "epsilon(a) " << epsilon(a) << std::endl;
  std::cout << "epsilon(b) " << epsilon(b) << std::endl;
  std::cout << "epsilon(c) " << epsilon(c) << std::endl;
  std::cout << "epsilon(d) " << epsilon(d) << std::endl;
  std::cout << "epsilon(e) " << epsilon(e) << std::endl;
  std::cout << "epsilon(g) " << epsilon(g) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb      " << wb << std::endl;
  std::cout << "wc      " << wc << std::endl;
  std::cout << "epsilon(wb) " << epsilon(wb) << std::endl;
  std::cout << "epsilon(wc) " << epsilon(wc) << std::endl;

  return 0;
}
