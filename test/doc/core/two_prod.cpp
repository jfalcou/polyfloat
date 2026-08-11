#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

    template<typename T>
    constexpr POLYFLOAT_FORCEINLINE
    auto d_prod(T a, T b) noexcept
    {
      auto[ah, al] = plf::two_split(a);
      auto[bh, bl] = plf::two_split(b);
      auto abh = a*b;
      auto ahbh= ah*bh;
      auto ahbl= ah*bl;
      auto albh= al*bh;
      auto albl= al*bl;
      auto t1 = ahbh-abh;
      auto t2 = t1 + ahbl;
      auto t3 = t2 + albh;
      auto abl= t3 +albl;
      return eve::zip(abh, abl);
    }

int main()
{
  std::cout <<  std::setprecision(15);
  using plf::dekker_prod;
  auto f = -1.0;
  auto a = plf::polyfloat(-1.3);
  auto b = plf::polyfloat(1.0, -1.0e-55);
  auto c = plf::polyfloat(-1.0, 1.0e-10, -1.0e-50);
  std::setprecision(15);
  std::cout << "f  "<< f << std::endl;
  std::cout << "a  "<< a << std::endl;
  std::cout << "b  "<< b << std::endl;
  std::cout << "c  "<< c << std::endl;
  std::cout << "d_prod(f, f) " << d_prod(f, f) << std::endl;
  std::cout << "d_prod(a, a) " << d_prod(a, a) << std::endl;
  std::cout << "d_prod(b, b) " << d_prod(b, b) << std::endl;
  std::cout << "d_prod(c, c) "<<  d_prod(c, c) << std::endl;
  std::cout << "dekker_prod(f, f) " << dekker_prod(f, f) << std::endl;
  std::cout << "dekker_prod(a, a) " << dekker_prod(a, a) << std::endl;
  std::cout << "dekker_prod(b, b) " << dekker_prod(b, b) << std::endl;
  std::cout << "dekker_prod(c, c) "<<  dekker_prod(c, c) << std::endl;

//   using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
//   using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
//   pf2_t wb(b);
//   pf3_t wc(c);
//   std::cout << "wb      "<< wb << std::endl;
//   std::cout << "wc      "<< wc << std::endl;
//   std::cout << "d_prod(wb) "<< d_prod(wb) << std::endl;
//   std::cout << "d_prod(wc) "<< d_prod(wc) << std::endl;
  return 0;
}
