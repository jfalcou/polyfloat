#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

int main()
{
  // The first half of the arguments is one vector, the second half the other.
  using plf::cosine_similarity;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::cout << std::setprecision(15);
  std::cout << "f  " << f << std::endl;
  std::cout << "a  " << a << std::endl;
  std::cout << "b  " << b << std::endl;
  std::cout << "c  " << c << std::endl;
  std::cout << "cosine_similarity(f, a, b, c) = " << cosine_similarity(f, a, b, c) << std::endl;
  std::cout << "cosine_similarity(a, b, a, b) = " << cosine_similarity(a, b, a, b) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          " << wb << std::endl;
  std::cout << "wc          " << wc << std::endl;
  std::cout << "cosine_similarity(wb, wb, wb, wb) = " << cosine_similarity(wb, wb, wb, wb) << std::endl;
}
