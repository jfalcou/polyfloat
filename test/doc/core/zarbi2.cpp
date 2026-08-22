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
  using t1_t = float;
  using wt1_t = eve::wide<t1_t, eve::fixed<2>>;
  using t2_t  = plf::double_real_t<t1_t>;
  using wt2_t = plf::double_real_t<wt1_t>;
  t1_t f11(2.3f);
  t1_t f12(1.2e-20);
  t1_t f13(4.37f);
  t1_t f14(-7.0001e-6f);
  t2_t f21(f11, f12);
  t2_t f22(f13, f14);
  wt2_t wf21{f21, f22};
  wt2_t wf22{f22, f21};
  std::cout << "f11 " << f11 << std::endl;
  std::cout << "f12 " << f12 << std::endl;
  std::cout << "f13 " << f13 << std::endl;
  std::cout << "f14 " << f14 << std::endl;

  std::cout << "f21 " << f21 << std::endl;
  std::cout << "f22 " << f22 << std::endl;
  std::cout << "wf21 " << wf21 << std::endl;
  std::cout << "wf22 " << wf22 << std::endl;

  std::cout << "f21*f22 "<< f21*f22 << std::endl;
  std::cout << "plf::cosine_similarity(f21, f22) "<< plf::cosine_similarity(f21, f22) << std::endl;

   std::cout << "wf21*wf22 "<< wf21*wf22 << std::endl;
   std::cout << "plf::sign(wf21*wf22) " << plf::sign(wf21*wf22) << std::endl;
//   std::cout << "plf::cosine_similarity(wf21, wf22) "<< plf::cosine_similarity(wf21, wf22) << std::endl;
   std::cout << "plf::sum_of_squares(kumi::tuple{wf21, wf22}) " << plf::sum_of_squares(kumi::tuple{wf21, wf22})<< std::endl;
   std::cout << "plf::sum_of_squares(            wf21, wf22 ) " << plf::sum_of_squares(            wf21, wf22 )<< std::endl;
  return 0;
}
