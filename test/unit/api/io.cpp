//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#include "test.hpp"
#include <cmath>
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>

namespace
{
  template<typename V, typename... M> std::string text(V const& v, M... m)
  {
    std::ostringstream os;
    (os << ... << m) << v;
    return os.str();
  }

  struct comma : std::numpunct<char>
  {
    char do_decimal_point() const override { return ','; }
    char do_thousands_sep() const override { return '.'; }
    std::string do_grouping() const override { return "\3"; }
  };

  template<typename V> std::string localized(V const& v, std::ios_base::fmtflags flags)
  {
    std::ostringstream os;
    os.imbue(std::locale(std::locale::classic(), new comma));
    os.flags(flags);
    os << v;
    return os.str();
  }

  struct wide_comma : std::numpunct<wchar_t>
  {
    wchar_t do_decimal_point() const override { return L','; }
    wchar_t do_thousands_sep() const override { return L'.'; }
    std::string do_grouping() const override { return "\3"; }
  };

  template<typename V> std::wstring wide_localized(V const& v, std::ios_base::fmtflags flags)
  {
    std::wostringstream os;
    os.imbue(std::locale(std::locale::classic(), new wide_comma));
    os.flags(flags);
    os << std::setw(30) << v;
    return os.str();
  }

  std::string lanes(std::string const& v, std::ptrdiff_t n)
  {
    std::string s = "(" + v;
    for (std::ptrdiff_t i = 1; i < n; ++i) s += ", " + v;
    return s + ")";
  }
}

TTS_CASE_WITH("Check that a printed value reads back",
              plf::scalar_real_types,
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000),
              tts::randoms(-1000, 1000))
<typename T>(T const& a0, T const& a1, T const& a2)
{
  using pv3 = plf::polyfloat<T, 3>;
  pv3 x(a0, a1, a2);

  auto exact = text(x, std::hexfloat);
  TTS_EQUAL(text(plf::from_string(eve::as<pv3>(), exact), std::hexfloat), exact);
  TTS_EQUAL(text(plf::from_string(eve::as<pv3>(), text(x, std::setprecision(1200))), std::hexfloat), exact);
};

TTS_CASE_TPL("Check that a value a double holds prints as the double", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
  using pv2 = plf::polyfloat<T, 2>;
  using f = std::ios_base;
  double const nan = std::numeric_limits<double>::quiet_NaN();
  double const inf = std::numeric_limits<double>::infinity();

  for (double v : {1.25, -1234567.25, 0.0, -0.0, 1048576.0, 0x1p-15, 9.5, 99.5, inf, -inf, nan, -nan})
  {
    pv2 x(static_cast<T>(v));
    for (f::fmtflags flags : {f::fmtflags{}, f::showpoint, f::showpos, f::uppercase | f::showpos, f::fixed,
                              f::fixed | f::showpoint, f::scientific, f::scientific | f::uppercase | f::showpoint,
                              f::fixed | f::scientific, f::fixed | f::scientific | f::showpoint | f::uppercase})
    {
      for (int p : {-1, 0, 1, 6, 17})
        TTS_EQUAL(text(x, std::setiosflags(flags), std::setprecision(p)),
                  text(v, std::setiosflags(flags), std::setprecision(p)));
      for (auto adjust : {f::left, f::right, f::internal})
        TTS_EQUAL(text(x, std::setiosflags(flags | adjust), std::setw(24), std::setfill('*')),
                  text(v, std::setiosflags(flags | adjust), std::setw(24), std::setfill('*')));
      TTS_EQUAL(localized(x, flags), localized(v, flags));
      TTS_EXPECT(wide_localized(x, flags) == wide_localized(v, flags));
    }
  }
};

TTS_CASE_TPL("Check stream output", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
  using pv2 = plf::polyfloat<T, 2>;
  using pv3 = plf::polyfloat<T, 3>;
  auto r2 = plf::sqrt_2(eve::as<pv2>());
  auto r3 = plf::sqrt_2(eve::as<pv3>());

  if constexpr (std::same_as<T, double>)
  {
    TTS_EQUAL(text(r2, std::setprecision(32)), std::string("1.4142135623730950488016887242097"));
    TTS_EQUAL(text(r3, std::setprecision(48)), std::string("1.41421356237309504880168872420969807856967187538"));
    TTS_EQUAL(text(r2, std::hexfloat), std::string("0x1.6a09e667f3bcc908b2fb1366ea8p+0"));
    TTS_EQUAL(text(r3, std::hexfloat), std::string("0x1.6a09e667f3bcc908b2fb1366ea957d3e3adec175p+0"));
    TTS_EQUAL(text(r2, plf::showparts), std::string("1.41421 - 9.66729e-17"));
    TTS_EQUAL(text(r2, std::showpos, plf::showparts), std::string("+1.41421 - 9.66729e-17"));
    TTS_EQUAL(text(r2, std::fixed, std::setprecision(20)), std::string("1.41421356237309504880"));
    TTS_EQUAL(text(r2, std::scientific, std::setprecision(25)), std::string("1.4142135623730950488016887e+00"));
  }
  else
  {
    TTS_EQUAL(text(r2, std::setprecision(32)), std::string("1.4142135623730958116084366338328"));
    TTS_EQUAL(text(r3, std::setprecision(48)), std::string("1.41421356237309504880169279742146287714987806794"));
    TTS_EQUAL(text(r2, std::hexfloat), std::string("0x1.6a09e667f3bdp+0"));
    TTS_EQUAL(text(r3, std::hexfloat), std::string("0x1.6a09e667f3bcc908b3p+0"));
    TTS_EQUAL(text(r2, plf::showparts), std::string("1.41421 + 2.42032e-08"));
    TTS_EQUAL(text(r2, std::showpos, plf::showparts), std::string("+1.41421 + 2.42032e-08"));
    TTS_EQUAL(text(r2, std::fixed, std::setprecision(20)), std::string("1.41421356237309581161"));
    TTS_EQUAL(text(r2, std::scientific, std::setprecision(25)), std::string("1.4142135623730958116084366e+00"));
  }

  auto eps = eve::eps(eve::as<T>());
  pv2 below_one(T(1), -eps * eps);
  TTS_EQUAL(text(below_one, std::fixed, std::setprecision(3)), std::string("1.000"));
  TTS_EQUAL(text(below_one, std::scientific, std::setprecision(2)), std::string("1.00e+00"));
  TTS_EQUAL(text(below_one, std::setprecision(3)), std::string("1"));
  pv2 above_one(T(1), eps * eps);
  TTS_EQUAL(text(above_one), std::string("1"));
  TTS_EQUAL(text(above_one, std::showpoint), std::string("1.00000"));
  TTS_EQUAL(text(r2, std::scientific, std::showpoint, std::setprecision(0)), std::string("1.e+00"));

  auto grouped = [](auto x, std::string g, std::ios_base::fmtflags flags) {
    struct dot : std::numpunct<char>
    {
      std::string g;
      dot(std::string s) : g(s) {}
      char do_decimal_point() const override { return ','; }
      char do_thousands_sep() const override { return '.'; }
      std::string do_grouping() const override { return g; }
    };
    std::ostringstream os;
    os.imbue(std::locale(std::locale::classic(), new dot(g)));
    os.flags(flags);
    os.precision(2);
    os << x;
    return os.str();
  };
  TTS_EQUAL(grouped(pv2(T(1073741824)), std::string("\4\0", 2), std::ios_base::fixed), std::string("10.7374.1824,00"));
  TTS_EQUAL(grouped(pv2(T(1073741824)), std::string("\3\0\2", 3), std::ios_base::fixed),
            std::string("1.073.741.824,00"));
  TTS_EQUAL(grouped(pv2(T(1.5)), std::string("\1"), std::ios_base::fixed | std::ios_base::scientific),
            std::string("0.x.1,8p+0"));

  TTS_EQUAL(text(r2), std::string("1.41421"));
  TTS_EQUAL(text(r2, plf::showparts, plf::noshowparts), std::string("1.41421"));

  auto parts = text(r2, plf::showparts);
  TTS_EQUAL(text(r2, plf::showparts, std::setw(30), std::setfill('*')), std::string(30 - parts.size(), '*') + parts);

  std::wostringstream ws;
  ws << plf::from_string(eve::as<pv2>(), "0.1");
  TTS_EXPECT(ws.str() == L"0.1");
};

TTS_CASE("Check half precision")
{
  using pv2 = plf::polyfloat<eve::float16_t, 2>;
  auto x = plf::from_string(eve::as<pv2>(), "0.1");
  TTS_EQUAL(static_cast<double>(plf::hi(x)), 0x1.998p-4);
  TTS_EQUAL(static_cast<double>(plf::lo(x)), 0x1.9ap-16);
  TTS_EQUAL(text(x), std::string("0.1"));
  TTS_EQUAL(text(x, std::hexfloat), std::string("0x1.9999ap-4"));
  TTS_EQUAL(text(x, plf::showparts), std::string("0.0999756 + 2.44379e-05"));

  auto hi = [](char const* s) { return static_cast<double>(plf::hi(plf::from_string(eve::as<pv2>(), s))); };
  TTS_EQUAL(hi("0x1p-25"), 0.0);
  TTS_EQUAL(hi("0x1.8p-25"), 0x1p-24);
  TTS_EXPECT(std::isinf(hi("0x1.ffep15")));
  TTS_EQUAL(hi("65519"), 65504.0);
  TTS_EQUAL(static_cast<double>(plf::lo(plf::from_string(eve::as<pv2>(), "65519"))), 15.0);
};

TTS_CASE_TPL("Check stream output of a register", plf::scalar_real_types)
<typename T>(tts::type<T>)
{
  using pv2 = plf::polyfloat<T, 2>;
  eve::wide<pv2> w(pv2(T(1)));
  TTS_EQUAL(text(w), lanes("1", w.size()));
  TTS_EQUAL(text(w, plf::showparts), lanes("1 + 0", w.size()));
};
