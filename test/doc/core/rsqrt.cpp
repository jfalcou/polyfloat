#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>
namespace toto
{
  template<typename T> struct typename_impl
  {
    static auto value() noexcept
    {
#if defined(_MSC_VER)
      std::string_view data(__FUNCSIG__);
      auto i = data.find('<') + 1, j = data.find(">::value");
      auto name = data.substr(i, j - i);
#else
      std::string_view data(__PRETTY_FUNCTION__);
      auto i = data.find('=') + 2, j = data.find_last_of(']');
      auto name = data.substr(i, j - i);
#endif
      return std::string(name.data(), name.size());
    }
  };

  template<typename T> inline auto const typename_ = typename_impl<T>::value();
  template<typename T> constexpr auto name(T const&)
  {
    return typename_<T>;
  }
}
int main()
{
  std::cout << std::setprecision(15);
  using plf::rsqrt;
  //  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  //   auto b = plf::polyfloat(1.0, -1.0e-300);
  //   auto c = plf::polyfloat(2.0, 1.0e-10, -1.0e-300);
  //   std::setprecision(15);
  //   std::cout << "f  " << f << std::endl;
  //   std::cout << "a  " << a << std::endl;
  //   std::cout << "b  " << b << std::endl;
  //   std::cout << "c  " << c << std::endl;
  //   std::cout << "rsqrt(f) " << rsqrt(f) << std::endl;
  //   std::cout << "rsqrt(a) " << rsqrt(a) << std::endl;
  //   std::cout << "rsqrt(b) " << rsqrt(b) << std::endl;
  //   std::cout << "rsqrt(c) " << rsqrt(c) << std::endl;

  //   using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  //   using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  //   pf2_t wb(b);
  //   pf3_t wc(c);
  //   std::cout << "wb      " << wb << std::endl;
  //   std::cout << "wc      " << wc << std::endl;
  //   std::cout << "rsqrt(wb) " << rsqrt(wb) << std::endl;
  //   std::cout << "rsqrt(wc) " << rsqrt(wc) << std::endl;

  auto vlm = plf::valmax(eve::as(a));
  std::cout << "typename a " << toto::typename_<decltype(a)> << "\n";
  std::cout << "icitte " << vlm << std::endl;
  std::cout << "latte  " << plf::is_normalized(vlm) << std::endl;
  auto zz = plf::rsqrt(vlm);
  std::cout << "rsqrt(valmax) " << zz << std::endl;

  return 0;
}
