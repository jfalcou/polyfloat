#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  std::cout <<  std::setprecision(15);
  using plf::fmod;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::setprecision(15);
  std::cout << "f  "<< f << std::endl;
  std::cout << "a  "<< a << std::endl;
  std::cout << "b  "<< b << std::endl;
  std::cout << "c  "<< c << std::endl;
  std::cout << "fmod(f, f) " << fmod(f, f) << std::endl;
  std::cout << "fmod(a, a) " << fmod(a, a) << std::endl;
  std::cout << "fmod(b, b) " << fmod(b, b) << std::endl;
  std::cout << "fmod(c, c) "<<  fmod(c, c) << std::endl;
  std::cout << "fmod(a, f) " << fmod(a, f) << std::endl;
  std::cout << "fmod(b, a) " << fmod(b, a) << std::endl;
  std::cout << "fmod(c, b) "<<  fmod(c, b) << std::endl;
  std::cout << "fmod(f, a) " << fmod(f, a) << std::endl;
  std::cout << "fmod(a, b) " << fmod(a, b) << std::endl;
  std::cout << "fmod(b, c) "<<  fmod(b, c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          "<< wb << std::endl;
  std::cout << "wc          "<< wc << std::endl;
  std::cout << "fmod(wb, wb) "<< fmod(wb, wb) << std::endl;
  std::cout << "fmod(wc, wc) "<< fmod(wc, wc) << std::endl;
  std::cout << "fmod(wc, wb) "<< fmod(wc, wb) << std::endl;

  return 0;
}
