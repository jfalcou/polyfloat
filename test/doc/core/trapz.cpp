#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

namespace pipo
{
  template<typename T> struct typename_impl
  {
    static auto value() noexcept
    {
#if defined(_MSC_VER )
      std::string_view data(__FUNCSIG__);
      auto i = data.find('<') + 1,
        j = data.find(">::value");
      auto name = data.substr(i, j - i);
#else
      std::string_view data(__PRETTY_FUNCTION__);
      auto i = data.find('=') + 2,
        j = data.find_last_of(']');
      auto name = data.substr(i, j - i);
#endif
      return std::string(name.data(), name.size());
    }
  };

  template<typename T> inline auto const typename_ = typename_impl<T>::value();
  template<typename T> constexpr auto name(T const&){ return typename_<T>; }
}

template<typename T>
using return_type = T;

template<typename... Ts>
using result = kumi::result::fill_t<sizeof...(Ts), return_type< plf::as_polyfloat_like_t<Ts...>>>;

template<eve::product_type Tup>
using tuple_result = kumi::result::fill_t< Tup::size(), return_type<kumi::apply_traits_t<plf::as_polyfloat_like, Tup>>>;

template<eve::product_type Tup, typename X>
using pipo_t = kumi::result::push_back< Tup, X >;

int main()
{
  using u_t1 = double;
  using u_t2 = plf::double_real_t<double>;
  using Tup1 = kumi::tuple<u_t1, u_t1, u_t1>;
  using Tup2 = kumi::tuple<u_t2, u_t2, u_t2>;
  using t_t1 = tuple_result<Tup1>;
  using t_t2 = tuple_result<Tup2>;
  std::cout << pipo::typename_<t_t2> << std::endl;
  std::cout << pipo::typename_<t_t1> << std::endl;

  using tt_t1 = result<u_t1, u_t1, u_t1>;
  using tt_t2 = result<u_t2, u_t2, u_t2>;
  std::cout << pipo::typename_<tt_t2> << std::endl;
  std::cout << pipo::typename_<tt_t1> << std::endl;

  std::cout <<  std::setprecision(15);
   using plf::trapz;
  auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::setprecision(15);
  std::cout << "f  "<< f << std::endl;
  std::cout << "a  "<< a << std::endl;
  std::cout << "b  "<< b << std::endl;
  std::cout << "c  "<< c << std::endl;
  std::cout << "trapz(f, f)    " <<  plf::trapz(f, f)    << std::endl;
  std::cout << "trapz(f, f, f) " <<  plf::trapz(f, f, f) << std::endl;
  std::cout << "trapz(kumi::tuple{f, f}) " <<  plf::trapz(kumi::tuple{f, f}) << std::endl;
  std::cout << "trapz(kumi::tuple{b, b, b, b}) " <<  plf::trapz(kumi::tuple{b, b, b, b}) << std::endl;
  std::cout << "trapz(kumi::tuple{a, a, a}) " << trapz(kumi::tuple{a, a, a}) << std::endl;
  std::cout << "trapz(kumi::tuple{c, c, c}) " << trapz(kumi::tuple{c, c, c}) << std::endl;
  std::cout << "trapz(b, b, b, b)                " <<  plf::trapz(b, b, b, b)  << std::endl;
  std::cout << "trapz(kumi::tuple{1.0, 5.0}, kumi::tuple{f, f)" << trapz(kumi::tuple{1.0, 5.0}, kumi::tuple{f, f})<< std::endl;
  std::cout << "trapz(f/2, kumi::tuple{f, f}) " << plf:: trapz(f/2, kumi::tuple{f, f}) << std::endl;
  std::cout << "trapz(0.5, kumi::tuple{b, b, b)) " << trapz(0.5, kumi::tuple{b, b, b}) << std::endl;
  std::cout << "trapz(0.5, kumi::tuple{b, b, b)) " << trapz(u_t2(0.4), kumi::tuple{b, b, b}) << std::endl;
  std::cout << "trapz(kumi::make_tuple{1.0, 5.0, 12.0}, kumi::tuple{f, f, f}" << trapz(kumi::tuple{1.0, 5.0, 12.0}, kumi::tuple{f, f, f})<< std::endl;
  std::cout << "trapz(a, a) "<<  trapz(a, a)       << std::endl;
  std::cout << "trapz(c, c) "<<  trapz(c, c, c) << std::endl;
  std::cout << "trapz(a, f) " << trapz(a, f) << std::endl;
  std::cout << "trapz(b, a) " << trapz(b, a) << std::endl;
  std::cout << "trapz(c, b) "<<  trapz(c, b) << std::endl;
  std::cout << "trapz(f, a) " << trapz(f, a) << std::endl;
  std::cout << "trapz(a, b) " << trapz(a, b) << std::endl;
  std::cout << "trapz(b, c) "<<  trapz(b, c) << std::endl;


  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          "<< wb << std::endl;
  std::cout << "wc          "<< wc << std::endl;
  std::cout << "trapz(kumi::tuple{wb, wb, wb}) "<<  plf::trapz(kumi::tuple{wb, wb, wb}) << std::endl;
  std::cout << "trapz(kumi::tuple{wc, wb, b, b, c, 1}) "<< trapz(kumi::tuple{wc, wb, b, b, c, 1}) << std::endl;
  std::cout << "plf::trapz(plf::sqr, 0.0, 1.0, 2.0, 3.0, 4.0, 5.0) " << plf::trapz(plf::sqr, 0.0, 1.0, 2.0, 3.0, 4.0, 5.0) << std::endl;
  std::cout << "plf::trapz(plf::sqr, 0.0, 1.0, 2.0, 3.0, 4.0, 5.0) " << plf::trapz(plf::sqr, 0.0, 1.0, 2.0, 3.0, 4.0, 5.0) << std::endl;
  kumi::tuple t{ pf2_t(0.0),  pf2_t(1.0),  pf2_t(2.0), pf2_t(3.0), pf2_t(4.0), pf2_t(5.0)};
  std::cout << "plf::trapz(plf::sqr, t) " << plf::trapz(plf::sqr, t) << std::endl;
  return 0;
}
