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

template<eve::value T1, eve::value T2>
requires(plf::concepts::polyfloat_like<T1> || plf::concepts::polyfloat_like<T2>)
  auto compless(T1 const& a, T2 const& b) noexcept
{
  using r_t = eve::common_logical_t<plf::as_component_type_t<T1>, plf::as_component_type_t<T2>>;
  using type = plf::as_polyfloat_t<T1, T2>;
  using plf::hi;
  using plf::md;
  using plf::lo;
  auto aa{plf::convert(a, eve::as<eve::element_type_t<type>>())};
  auto bb{plf::convert(b, eve::as<eve::element_type_t<type>>())};
  if constexpr(plf::dimension_v<type> == 1)
    return r_t( aa < bb);
  if constexpr(plf::dimension_v<type> == 2)
  {
    return r_t(hi(aa) < hi(bb)) || ((hi(aa) == hi(bb)) && (lo(aa) < lo(bb)));
  }
  else if constexpr(plf::dimension_v<type> == 3)
  {
    return r_t((hi(aa) < hi(bb)) ||
            ((hi(aa) == hi(bb)) && (md(aa) < md(bb))) ||
            ((hi(aa) == hi(bb)) && (md(aa) ==  md(bb)) && (lo(aa) < lo(bb)))
           );
  }
}

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

//   std::cout << "wf21 < wf22 "     << (wf21 < wf22) << std::endl;
//   std::cout << " hi(wf21)< hi(wf22) " << (plf::hi(wf21)< plf::hi(wf22)) << std::endl;
//  std::cout << "max(wf21, wf22) " << plf::max(wf21, wf21) << std::endl;
//   std::cout << "max(wf12)       " << plf::max(wf21)       << std::endl;

  std::cout << zorro::typename_<eve::common_logical_t<plf::as_component_type_t<wt1_t>,
                                                      plf::as_component_type_t<wt1_t>
                                                     >
                               > << std::endl; ;
  std::cout << zorro::typename_<eve::common_logical_t<plf::as_component_type_t<wt2_t>,
                                                      plf::as_component_type_t<wt2_t>
                                                     >
                               > << std::endl; ;

 std::cout << "wf21 < wf22 "     << compless(wf21, wf22) << std::endl;
 std::cout << "wf21 < wf22 "     <<         (wf21 <wf22) << std::endl;
  return 0;
}
