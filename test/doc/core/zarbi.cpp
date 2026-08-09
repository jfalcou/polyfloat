#include <eve/wide.hpp>
#include <iostream>
#include <iomanip>
#include <polyfloat/polyfloat.hpp>
#include <mpreal.h>

   template<typename T>
   constexpr auto is_not_1or3_times_pow2(T x) noexcept
   {
//     const unsigned long Q = eve::ldexp(eve::one(eve::as(x)), eve::nbmantissabits(eve::as(x))-2);
     using u_t = eve::underlying_type_t<T>;
     constexpr unsigned long Q = 1ul << (eve::nbmantissabits(eve::as(u_t()))-2);
     constexpr unsigned long P = Q+1;
     auto l = P*x;
     auto r = Q*x;
     return plf::is_not_equal(l-r, x);
   }

int main()
{
  std::cout << std::defaultfloat << double(0x1p4) << std::endl;

  std::cout << std::defaultfloat << double(0x1.ap2) << std::endl;

  std::cout <<  is_not_1or3_times_pow2<float>(0x1p4) << std::endl;
  std::cout <<  is_not_1or3_times_pow2<float>(0x1p-6) << std::endl;
  std::cout <<  is_not_1or3_times_pow2<float>(0x1.ap2)<< std::endl;
  std::cout <<  is_not_1or3_times_pow2<float>(3*16.0f)<< std::endl;
  return 0;
}
