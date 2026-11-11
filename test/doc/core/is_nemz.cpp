#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // Both zeros are tested beside non-zero values.
  using plf::is_nemz;
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
  std::cout << "is_nemz(f) = " << is_nemz(f) << std::endl;
  std::cout << "is_nemz(a) = " << is_nemz(a) << std::endl;
  std::cout << "is_nemz(b) = " << is_nemz(b) << std::endl;
  std::cout << "is_nemz(c) = " << is_nemz(c) << std::endl;
  std::cout << "is_nemz(z) = " << is_nemz(z) << std::endl;
  std::cout << "is_nemz(mz) = " << is_nemz(mz) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "is_nemz(wb) = " << is_nemz(wb) << std::endl;
  std::cout << "is_nemz(wc) = " << is_nemz(wc) << std::endl;
}
