#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  std::cout << std::setprecision(15);
  using plf::rat;
  auto a = 1.23456;
  auto b = plf::polyfloat(1.23456, 0.0);
  auto c = plf::polyfloat(1.23456, 0.0, 0.0);
  std::setprecision(15);
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  auto [na, da] = rat(a);
  std::cout << na << "  " << da << " -> " << na / da - a << std::endl;
  auto [nb, db] = rat(b); //, 1.0e-12);
  std::cout << nb << "  " << db << " -> " << nb / db - b << std::endl;
  auto [nc, dc] = rat(c);
  std::cout << nc << "  " << dc << " -> " << nc / dc - c << std::endl;

  //   std::cout << "rat(a) " << rat(a) << std::endl;
  //   std::cout << "rat(b) " << rat(b) << std::endl;
  //   std::cout << "rat(c) "<<  rat(c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>, eve::fixed<2>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>, eve::fixed<2>>;
  auto d = plf::polyfloat(70.0 / 3.0, 0.0);

  pf2_t wb(b, d);
  pf3_t wc(c);
  std::cout << "wb      " << wb << std::endl;
  std::cout << "wc      " << wc << std::endl;
  std::cout << "rat(wb) " << rat(wb) << std::endl;
  std::cout << "rat(wc) " << rat(wc) << std::endl;
  return 0;
}
