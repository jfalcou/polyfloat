#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>

namespace zorro
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
template <eve::non_empty_product_type X, eve::non_empty_product_type Y>
using r_t = kumi::apply_traits_t<plf::as_polyfloat_like, kumi::result::cat_t<X, Y>>;

int main()
{
  using T = float;
  using pv_t  = plf::triple_real_t<T>;
  std::cout << plf::trapz(kumi::tuple{pv_t(2), pv_t(3)})<< std::endl; //compile
  std::cout << plf::trapz(kumi::tuple{pv_t(0), pv_t(1)}, kumi::tuple{pv_t(2), pv_t(3)})<< std::endl; //compile
  // std::cout << plf::trapz(kumi::tuple{T(0), T(1)}, kumi::tuple{pv_t(2), pv_t(3)})<< std::endl; //ne compile pas avec clang2O
  auto a = kumi::tuple{T(0), T(1)};
  auto b = kumi::tuple{pv_t(2), pv_t(3)};
  std::cout << zorro::typename_<r_t<decltype(a), decltype(b)>> << std::endl;//compile
  return 0;
}
