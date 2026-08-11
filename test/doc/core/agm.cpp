#include <eve/wide.hpp>
#include <eve/module/math.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>
#include <polyfloat/details/printing.hpp>
#include <mpreal.h>

  template <typename T> constexpr auto bitprec(){
    using u_t = decltype(plf::hi(T()));
    if constexpr(plf::dimension_v<T> == 1)
      return (sizeof(u_t) == 8 ? 53 : 24);
    if constexpr(plf::dimension_v<T> == 2)
      return (sizeof(u_t) == 8 ? 106 : 48);
    else if constexpr(plf::dimension_v<T> == 3)
      return (sizeof(u_t) == 8 ? 159 : 72);
  }
template <typename T> auto to_mpreal(T a)
  {
    using  mpfr::mpreal;
    mpfr::mpreal::set_default_prec(bitprec<T>()*10);
    if constexpr(plf::dimension_v<T>  == 1)
      return mpreal(a);
    else if constexpr(plf::dimension_v<T>  == 2)
      return mpreal(plf::hi(a))+mpreal(plf::lo(a));
    else if constexpr(plf::dimension_v<T>  == 3)
      return mpreal(plf::hi(a))+mpreal(plf::md(a))+mpreal(plf::lo(a));
 }

int main()
{
  std::cout <<  std::setprecision(15);
  using plf::agm;
  using plf::_::println;
  using plf2 = plf::double_real_t<double>;
  using plf3 = plf::triple_real_t<double>;
  {
    plf2 o(1.0);
    plf2 sqt2 = plf::sqrt_2(eve::as(o));
    std::setprecision(50);
    std::cout << "o    "<< o << std::endl;
    std::cout << "sqt2 "<< sqt2 << std::endl;
    std::cout << "agm(o, sqt2) " << 1.0f/agm(o, sqt2) << std::endl;
    std::cout << to_mpreal(1.0f/agm(o, sqt2)) << std::endl;
    println("lem ", 1.0f/agm(o, sqt2));
    std::cout << "0.8346268416740731862814297327990468089939930134903470024498273701036819927095264" << std::endl;
  }
  {
    plf3 o(1.0);
    plf3 sqt2 = plf::sqrt_2(eve::as(o));
    std::setprecision(50);
    std::cout << "o    "<< o << std::endl;
    std::cout << "sqt2 "<< sqt2 << std::endl;
    std::cout << "lemniscate constant " << 1.0f/agm(o, sqt2) << std::endl;
    std::cout << to_mpreal(1.0f/agm(o, sqt2)) << std::endl;
    println("lem ", 1.0f/agm(o, sqt2));
    std::cout << "lem "<< "0.8346268416740731862814297327990468089939930134903470024498273701036819927095264" << std::endl;

  }
  return 0;
}
