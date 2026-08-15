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
  using plf::cumfun;
  using plf::max;
   auto f = 1.0;
  auto a = plf::polyfloat(1.3);
  auto b = plf::polyfloat(1.0, 1.0e-300);
  auto c = plf::polyfloat(1.0, 1.0e-10, 1.0e-300);
  std::setprecision(15);
  std::cout << "f  "<< f << std::endl;
  std::cout << "a  "<< a << std::endl;
  std::cout << "b  "<< b << std::endl;
  std::cout << "c  "<< c << std::endl;
   std::cout << "cumfun(max, f, f) " << cumfun(max, kumi::make_tuple(f, f)) << std::endl;
   std::cout << "cumfun(max, f, f) " << cumfun(max,                  f, f)  << std::endl;
  std::cout << "cumfun(max, a, a) " << cumfun(max, a, a) << std::endl;
  std::cout << "cumfun(max, b, b) " << cumfun(max, b, b) << std::endl;
  std::cout << "cumfun(max, c, c) "<<  cumfun(max, c, c) << std::endl;
  std::cout << "cumfun(max, a, f) " << cumfun(max, a, f) << std::endl;
  std::cout << "cumfun(max, b, a) " << cumfun(max, b, a) << std::endl;
  std::cout << "cumfun(max, c, b) "<<  cumfun(max, c, b) << std::endl;
  std::cout << "cumfun(max, f, a) " << cumfun(max, f, a) << std::endl;
  std::cout << "cumfun(max, a, b) " << cumfun(max, a, b) << std::endl;
  std::cout << "cumfun(max, b, c) "<<  cumfun(max, b, c) << std::endl;

  using pf3_t = eve::wide<plf::polyfloat<double, 3>>;
  using pf2_t = eve::wide<plf::polyfloat<double, 2>>;
  pf2_t wb(b);
  pf3_t wc(c);
  std::cout << "wb          "<< wb << std::endl;
  std::cout << "wc          "<< wc << std::endl;
  std::cout << "cumfun(max, wb, wb) "<< cumfun(max, wb, wb) << std::endl;
  std::cout << "cumfun(max, wc, wc) "<< cumfun(max, wc, wc) << std::endl;
  std::cout << "cumfun(max, wc, wb) "<< cumfun(max, wc, wb) << std::endl;
  std::cout << "cumfun(max, wc, wb, b) "<< cumfun(max, wb, wb, wb, b, c, 1) << std::endl;



  return 0;
}
