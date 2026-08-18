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

template<std::size_t N, typename... Ts>
struct result;

template < size_t N,  size_t SZ> static constexpr size_t sz = SZ > N ? SZ-N : 0;

template<std::size_t N, plf::concepts::polyfloat_like... Ts>
struct result<N,Ts...> : kumi::result::fill<sz<N, sizeof...(Ts)>, plf::as_polyfloat_like_t<Ts...>> {};

template<std::size_t N, eve::same_lanes_or_scalar_tuple Tup>
struct result<N, Tup> : kumi::result::fill<sz<N, kumi::size_v<Tup>>, kumi::apply_traits_t<plf::as_polyfloat_like, Tup>> {};




int main()
{
  using T = double;
  using Tup =  kumi::tuple<T, T, T>;
  using r1_t = typename result<1u, Tup>::type;
  using r2_t = typename result<2u, Tup>::type;
  using r3_t = typename result<3u, Tup>::type;
  std::cout << pipo::typename_<r1_t> << std::endl;
  std::cout << pipo::typename_<r2_t> << std::endl;
  std::cout << pipo::typename_<r3_t> << std::endl;


   using u_t2 = plf::double_real_t<double>;

//   std::cout <<  std::setprecision(15);
   using plf::diff;
  auto a = 1.0;
  auto b = u_t2(1.0, 1.0e-300);

  std::cout << "a " << a << std::endl;
  std::cout << "diff(kumi::make_tuple(a, a+1, a+3)) " << diff(kumi::make_tuple(a, a+1, a+3)) << std::endl;
  std::cout << "diff(a, a+1, a+3)                   " << diff(a, a+1, a+3)  << std::endl;
  std::cout << "b " << b << std::endl;
  std::cout << "diff(kumi::make_tuple(b, b+1, b+3)) " << diff(kumi::make_tuple(b, b+1, b+3)) << std::endl;
//   std::cout << "diff(f, f) " << diff(                 f, f)  << std::endl;
  {
    kumi::tuple tt{ u_t2(1.5000e-5), 2.2500, 3.3750, 5.0625, 7.0, 11.0, 17.0, 25.0};
    std::cout << " < - tt                        = " << tt << std::endl;
    std::cout << " -> diff(index_t<0>, tt)       = " << plf::diff(kumi::index_t<0>{}, tt) << std::endl;
    std::cout << " -> diff(tt)                   = " << plf::diff(tt) << std::endl;
    std::cout << " -> diff(index_t<1>, tt)       = " << plf::diff(kumi::index_t<1>{}, tt) << std::endl;
    std::cout << " -> diff(index_t<2>, tt)       = " << plf::diff(kumi::index_t<2>{}, tt) << std::endl;
    std::cout << " -> diff(index_t<7>, tt)       = " << plf::diff(kumi::index_t<7>{}, tt) << std::endl;
    std::cout << " -> diff(index_t<8>, tt)       = " << plf::diff(kumi::index_t<8>{}, tt) << std::endl;
  }
    return 0;
}
