#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  std::cout << std::setprecision(15);
  using plf::ceil;
  auto f = -1.0;
  auto a = plf::polyfloat(-1.3);
  auto b = plf::polyfloat(1.0, -1.0e-300);
  auto c = plf::polyfloat(-1.0, 1.0e-10, -1.0e-300);
  std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "ceil(f) " << ceil(f) << std::endl;
  std::cout << "ceil(a) " << ceil(a) << std::endl;
  std::cout << "ceil(b) " << ceil(b) << std::endl;
  std::cout << "ceil(c) " << ceil(c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb      " << wb << std::endl;
  std::cout << "wc      " << wc << std::endl;
  std::cout << "ceil(wb) " << ceil(wb) << std::endl;
  std::cout << "ceil(wc) " << ceil(wc) << std::endl;

  using  dd_t = plf::double_real_t<double>;
  auto mx = eve::maxflint(eve::as<double>());
  dd_t x1(mx);
  std::cout << std::hexfloat << x1 << std::endl;
  std::cout << (x1-1)/2 << std::endl;
  std::cout << plf::ceil(x1) -x1 << std::endl;
  std::cout << plf::ceil((x1-1)/2) - (x1-1)/2<< std::endl;
  dd_t x2(mx, eve::ldexp(mx, 53));
  std::cout << std::hexfloat << x2 << std::endl;
  std::cout << plf::is_flint(x2) << std::endl;
  std::cout << (x2-1)/2 << std::endl;
  std::cout << plf::ceil(x2) -x2 << std::endl;
  std::cout << plf::ceil((x2-1)/2) - (x2-1)/2<< std::endl;

  dd_t x3(plf::next(x2));
  std::cout << plf::is_flint(x3) << std::endl;
  std::cout << std::hexfloat <<  std::setprecision(16) << x3 << std::endl;
  std::cout << (x3-1)/2 << std::endl;
  std::cout << plf::ceil(x3) -x3 << std::endl;
  std::cout << plf::ceil((x3-1)/2) - (x3-1)/2<< std::endl;

  return 0;
}
