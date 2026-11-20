//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once
#include <eve/module/core.hpp>
#include <polyfloat/details/decimal/write.hpp>
#include <algorithm>
#include <climits>
#include <cmath>
#include <ios>
#include <limits>
#include <locale>
#include <ostream>
#include <sstream>
#include <string>

namespace plf
{
  namespace _
  {
    inline int showparts_index()
    {
      static int const index = std::ios_base::xalloc();
      return index;
    }

    // Writes a number laid out by to_text as std::num_put writes a double: the decimal point and the grouping of the
    // locale of os, then the fill up to its width, after the sign or 0x under std::internal.
    template<typename C, typename Ct>
    std::basic_ostream<C, Ct>& put_number(std::basic_ostream<C, Ct>& os, std::string const& text)
    {
      auto const& punct = std::use_facet<std::numpunct<C>>(os.getloc());
      auto const& ctype = std::use_facet<std::ctype<C>>(os.getloc());
      std::basic_string<C, Ct> out;
      for (char c : text) out.push_back(c == '.' ? punct.decimal_point() : ctype.widen(c));

      // As libstdc++ groups a double: the text after the sign and before the point, 0x included, or the whole text
      // when it has no point and its second and third characters are digits, which leaves 2e+20 alone. The groups
      // count from the right, the grouping ending at its first 0, its last size repeating, until a size below 1 or
      // CHAR_MAX.
      auto decimal = [](char c) { return c >= '0' && c <= '9'; };
      std::size_t first = text[0] == '-' || text[0] == '+' ? 1 : 0;
      std::size_t point = text.find('.');
      bool grouped = point != std::string::npos || text.size() < 3 || (decimal(text[1]) && decimal(text[2]));
      std::size_t end = std::min(point, text.size());
      std::string grouping = punct.grouping();
      grouping.erase(std::min(grouping.find('\0'), grouping.size()));
      for (std::size_t g = 0; grouped && g < grouping.size(); g = std::min(g + 1, grouping.size() - 1))
      {
        int size = grouping[g];
        if (size <= 0 || size == CHAR_MAX || end - first <= static_cast<std::size_t>(size)) break;
        end -= static_cast<std::size_t>(size);
        out.insert(end, 1, punct.thousands_sep());
      }

      if (auto width = static_cast<std::size_t>(std::max<std::streamsize>(os.width(), 0)); out.size() < width)
      {
        auto adjust = os.flags() & std::ios_base::adjustfield;
        // libstdc++ looks for 0x in the grouped text, where a separator after the 0 hides it.
        bool hex =
          out.size() > 1 && out[0] == ctype.widen('0') && (out[1] == ctype.widen('x') || out[1] == ctype.widen('X'));
        std::size_t at = adjust == std::ios_base::left       ? out.size()
                         : adjust != std::ios_base::internal ? 0
                         : first == 1                        ? 1
                         : hex                               ? 2
                                                             : 0;
        out.insert(at, width - out.size(), os.fill());
      }
      os.width(0);
      return os << out;
    }
  }

  //====================================================================================================================
  //! @name Streaming Operators
  //! @related polyfloat
  //! @{
  //====================================================================================================================

  /// Makes the stream show the parts of a polyfloat, the largest first, each with the precision of the stream.
  inline std::ios_base& showparts(std::ios_base& s)
  {
    s.iword(_::showparts_index()) = 1;
    return s;
  }

  /// Makes the stream show a polyfloat as one number, the default.
  inline std::ios_base& noshowparts(std::ios_base& s)
  {
    s.iword(_::showparts_index()) = 0;
    return s;
  }

  namespace _
  {
    // The text of finite parts as libstdc++ lays out a double under the flags of os, before its locale and width.
    template<typename C, typename Ct, std::size_t N>
    std::string decimal_text(std::basic_ostream<C, Ct>& os, std::array<double, N> const& parts)
    {
      auto flags = os.flags();
      auto field = flags & std::ios_base::floatfield;
      char conversion = field == std::ios_base::fixed                                 ? 'f'
                        : field == std::ios_base::scientific                          ? 'e'
                        : field == (std::ios_base::fixed | std::ios_base::scientific) ? 'a'
                                                                                      : 'g';
      // printf reads a negative precision as no precision, which is 6.
      auto precision = os.precision() < 0 ? 6 : os.precision();
      auto text = decimal::to_text(parts, conversion, precision, (flags & std::ios_base::showpoint) != 0);
      if ((flags & std::ios_base::showpos) && text[0] != '-') text.insert(0, 1, '+');
      if (flags & std::ios_base::uppercase)
        for (auto& c : text)
          if (c >= 'a' && c <= 'z') c = static_cast<char>(c - 'a' + 'A');
      return text;
    }

    template<typename C, typename Ct, typename CD> void put_polyfloat(std::basic_ostream<C, Ct>& os, CD const& z)
    {
      auto parts =
        kumi::apply([](auto... v) { return std::array<double, sizeof...(v)>{static_cast<double>(v)...}; }, z.contents);

      // As for std::complex, the parts go to a stream of the same format, then the whole text to os.
      if (os.iword(showparts_index()) != 0)
      {
        std::basic_ostringstream<C, Ct> s;
        s.flags(os.flags());
        s.imbue(os.getloc());
        s.precision(os.precision());
        for (std::size_t i = 0; i < parts.size(); ++i)
        {
          if (i == 0) s << parts[i] << std::noshowpos;
          else if (std::signbit(parts[i])) s << " - " << -parts[i];
          else s << " + " << parts[i];
        }
        os << s.str();
        return;
      }

      // An infinite or NaN high part prints as that double, plf::is_infinite and plf::is_nan reading the high part
      // alone. A lower part that is not finite leaves no finite sum, and prints as a NaN.
      if (!std::isfinite(parts[0])) os << parts[0];
      else if (!std::all_of(parts.begin(), parts.end(), [](double v) { return std::isfinite(v); }))
        os << std::numeric_limits<double>::quiet_NaN();
      else put_number(os, decimal_text(os, parts));
    }
  }

  /// Inserts the sum of the parts as one number, rounded to nearest, as a `double` is inserted: with the precision,
  /// the format flags, the locale, and the width of the stream. `std::setprecision(32)` shows 32 significant digits,
  /// and `std::hexfloat` shows the value exactly, a subnormal value as `0x1p-1074` rather than
  /// `0x0.0000000000001p-1022`. After plf::showparts, it inserts the parts, `1 - 1.2e-17` for instance, as one text
  /// the width applies to. A SIMD register shows its lanes in turn.
  template<typename C, typename Ct, concepts::scalar_polyfloat CD>
  auto& operator<<(std::basic_ostream<C, Ct>& os, CD const& z)
  {
    // A formatted output function: nothing on a failed stream, and an exception sets badbit, rethrown only when the
    // stream asks for it.
    typename std::basic_ostream<C, Ct>::sentry guard(os);
    if (!guard) return os;
    try
    {
      _::put_polyfloat(os, z);
    }
    catch (...)
    {
      try
      {
        os.setstate(std::ios_base::badbit);
      }
      catch (std::ios_base::failure const&)
      {
      }
      if (os.exceptions() & std::ios_base::badbit) throw;
    }
    return os;
  }

  //====================================================================================================================
  //! @}
  //====================================================================================================================
}
