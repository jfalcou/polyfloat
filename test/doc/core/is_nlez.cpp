#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // A negative value, both zeros, and NaN are tested beside positive values.
  using plf::is_nlez;
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
  auto m = -b;
  std::cout << "m  " << m << std::endl;
  auto z = plf::zero(eve::as<d2_t>());
  std::cout << "z  " << z << std::endl;
  auto mz = plf::mzero(eve::as<d2_t>());
  std::cout << "mz  " << mz << std::endl;
  auto n = plf::nan(eve::as<d2_t>());
  std::cout << "n  " << n << std::endl;
  std::cout << "is_nlez(f) = " << is_nlez(f) << std::endl;
  std::cout << "is_nlez(a) = " << is_nlez(a) << std::endl;
  std::cout << "is_nlez(b) = " << is_nlez(b) << std::endl;
  std::cout << "is_nlez(c) = " << is_nlez(c) << std::endl;
  std::cout << "is_nlez(m) = " << is_nlez(m) << std::endl;
  std::cout << "is_nlez(z) = " << is_nlez(z) << std::endl;
  std::cout << "is_nlez(mz) = " << is_nlez(mz) << std::endl;
  std::cout << "is_nlez(n) = " << is_nlez(n) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "is_nlez(wb) = " << is_nlez(wb) << std::endl;
  std::cout << "is_nlez(wc) = " << is_nlez(wc) << std::endl;
}
