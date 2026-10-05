#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>
#include <polyfloat/details/printing.hpp>

template<typename T> auto cody_split(T x)
{
  // Dekker's Splitting Algorithm for n-bit mantissa precision
  // Splits x into x_high and x_low such that x = x_high + x_low exactly,
  // where x_high holds the most significant 85 bits.

  auto n = plf::_::bitprec<T>();
  // Ensure working decimal precision is high enough to prevent rounding errors

  // C = 2^(s) + 1 where s = ceil(n / 2) = 85 bits
  auto C = plf::ldexp(T(1), plf::ceil(n / 2));

  // Perform the split
  auto x_prime = x * C;
  auto x_high = x_prime - (x_prime - x);
  auto x_low = x - x_high;

  return kumi::make_tuple(x_high, x_low);
}

int main()
{
  using plf::_::println;
  {
    using t1_t = double;
    using t2_t = plf::polyfloat<double, 2>;
    using t3_t = plf::polyfloat<double, 3>;

    {
      using T = t1_t;
      auto l2 = plf::log_2(eve::as<T>());
      auto [hl2, ll2] = dekker(l2);
      auto bitp = plf::_::bitprec<T>();
      auto decp = int(plf::_::bitprec<T>() / eve::log2(10.0));
      std::cout << "bitprec<T>()  " << bitp << std::endl;
      std::cout << "dec precision " << decp << std::endl;
      println("l2 ", l2);
      std::cout << "ll " << std::setprecision(int(bitp / eve::log2(10.0))) << mpfr::log(2) << std::endl;
      println("hl2 ", hl2);
      println("ll2 ", ll2);
      println("l2-ll2-hl2 ", l2 - ll2 - hl2);
      std::cout << std::hexfloat << "l2 " << l2 << std::endl;
      std::cout << std::hexfloat << "hl2 " << hl2 << std::endl;
      std::cout << std::hexfloat << "ll2 " << ll2 << std::endl;
    }
    {
      using T = t2_t;
      auto l2 = plf::log_2(eve::as<T>());
      auto [hl2, ll2] = dekker(l2);
      auto bitp = plf::_::bitprec<T>();
      auto decp = int(plf::_::bitprec<T>() / eve::log2(10.0));
      std::cout << "bitprec<T>()  " << bitp << std::endl;
      std::cout << "dec precision " << decp << std::endl;
      println("l2 ", l2);
      std::cout << "ll " << std::setprecision(int(bitp / eve::log2(10.0))) << mpfr::log(2) << std::endl;
      println("hl2 ", hl2);
      println("ll2 ", ll2);
      println("l2-ll2-hl2 ", l2 - ll2 - hl2);
      std::cout << std::hexfloat << "l2 " << l2 << std::endl;
      std::cout << std::hexfloat << "hl2 " << hl2 << std::endl;
      std::cout << std::hexfloat << "ll2 " << ll2 << std::endl;
    }
    {
      using T = t3_t;
      auto l2 = plf::log_2(eve::as<T>());
      auto [hl2, ll2] = dekker(l2);
      auto bitp = plf::_::bitprec<T>();
      auto decp = int(plf::_::bitprec<T>() / eve::log2(10.0));
      std::cout << "bitprec<T>()  " << bitp << std::endl;
      std::cout << "dec precision " << decp << std::endl;
      println("l2 ", l2);
      std::cout << "ll " << std::setprecision(int(bitp / eve::log2(10.0))) << mpfr::log(2) << std::endl;
      println("hl2 ", hl2);
      println("ll2 ", ll2);
      println("l2-ll2-hl2 ", l2 - ll2 - hl2);
      std::cout << std::hexfloat << "l2 " << l2 << std::endl;
      std::cout << std::hexfloat << "hl2 " << hl2 << std::endl;
      std::cout << std::hexfloat << "ll2 " << ll2 << std::endl;
    }
  }
}
