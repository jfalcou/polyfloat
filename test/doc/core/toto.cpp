#include <polyfloat/polyfloat.hpp>
// #include <cmath>
// #include <cstdio>
// #include <random>

// // Counts the triples of random values, half of them with spread exponents, that the constructor leaves unnormalized.
// template<typename T> int count(int n)
// {
//   std::mt19937 g(42);
//   std::uniform_real_distribution<T> u(-1000, 1000);
//   int bad = 0;
//   for (int k = 0; k < n; ++k)
//   {
//     T a0 = u(g), a1 = u(g), a2 = u(g);
//     if (k % 2)
//     {
//       a1 = std::ldexp(a1, -int(g() % 40));
//       a2 = std::ldexp(a2, -int(g() % 80));
//     }
//     bool normalized = plf::is_normalized(plf::polyfloat<T, 3>(a0, a1, a2));
//     bad += normalized ? 0 : 1;
//   }
//   return bad;
// }
// namespace plf::_
// {
//   template <typename T1, typename T>
//   POLYFLOAT_ABI T1 aa31(T1 self, T other) noexcept
//   {
//     auto [xhi, xmd, xlo] = self;
//     auto yhi = other;
//     auto [a, b] = eve::two_add(xhi, yhi);
//     auto aa = a;
//     auto c = xmd;
//     auto e = xlo;
//     fasttwoadd(a, c, a, c);
//     twoadd(b, c, b, c);
//     fasttwoadd(a, b, a, b);
//     fasttwoadd(b, c + e, b, c);
//     fasttwoadd(a, b, a, b);
//     fasttwoadd(b, c, b, c);
//     auto test = eve::is_not_finite(a + b + c);

//     self = plf::if_else(test, T1(aa), plf::_::from_triple(a, b, c));
//     EVE_ASSERT(eve::all(plf::is_normalized(self)), "output of += is not normalized");
//     return self;
//   }
// }

template<typename T> auto new_init1(T a, T b, T c)
{
  auto aa = plf::polyfloat<T, 3>(a);
  std::cout << std::hexfloat << "a " << a << " aa " << aa << std::endl;
  auto r = plf::_::a31(aa, b);
  return plf::_::a31(r, c);
  // return aa;
}

template<typename T> auto new_init2(T a, T b, T c)
{
  auto aa = plf::polyfloat<T, 3>(a);
  auto bb = plf::polyfloat<T, 3>(b);
  auto cc = plf::polyfloat<T, 3>(c);
  return aa += bb + cc;
}

// template<typename T> int count1(int n)
// {
//   std::mt19937 g(42);
//   std::uniform_real_distribution<T> u(-1000, 1000);
//   int bad = 0;
//   for (int k = 0; k < n; ++k)
//   {
//     T a0 = u(g), a1 = u(g), a2 = u(g);
//     if (k % 2)
//     {
//       a1 = std::ldexp(a1, -int(g() % 40));
//       a2 = std::ldexp(a2, -int(g() % 80));
//     }
//     bool normalized = plf::is_normalized(new_init(a0, a1, a2));
//     bad += normalized ? 0 : 1;
//   }
//   return bad;
// }

int main()
{
  plf::polyfloat<float, 3> x(-0x1.cea7bp+8f, -0x1.827142p+8f, -0x1.ddd0b4p-64f);
  std::cout << plf::is_normalized(x) << std::endl;

  //   plf::polyfloat<float, 3> xx = new_init1(-0x1.cea7bp+8f, -0x1.827142p+8f, -0x1.ddd0b4p-64f);
  //   std::cout << plf::is_normalized(xx) << std::endl;
  plf::polyfloat<float, 3> xxx = new_init2(-0x1.cea7bp+8f, -0x1.827142p+8f, -0x1.ddd0b4p-64f);
  //  std::cout << plf::is_normalized(xxx) << std::endl;
  std::cout << std::hexfloat << "x " << x << std::endl;
  //  std::cout << xx<< std::endl;
  std::cout << xxx << std::endl;
}
