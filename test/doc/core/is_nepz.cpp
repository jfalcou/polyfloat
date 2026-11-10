#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // Both zeros are tested beside non-zero values.
  using plf::is_nepz;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::cout << std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  using d2_t = plf::polyfloat<double, 2>;
  auto z = plf::zero(eve::as<d2_t>());
  std::cout << "z  " << z << std::endl;
  auto mz = plf::mzero(eve::as<d2_t>());
  std::cout << "mz  " << mz << std::endl;
  std::cout << "is_nepz(f) = " << is_nepz(f) << std::endl;
  std::cout << "is_nepz(a) = " << is_nepz(a) << std::endl;
  std::cout << "is_nepz(b) = " << is_nepz(b) << std::endl;
  std::cout << "is_nepz(c) = " << is_nepz(c) << std::endl;
  std::cout << "is_nepz(z) = " << is_nepz(z) << std::endl;
  std::cout << "is_nepz(mz) = " << is_nepz(mz) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "is_nepz(wb) = " << is_nepz(wb) << std::endl;
  std::cout << "is_nepz(wc) = " << is_nepz(wc) << std::endl;
}
