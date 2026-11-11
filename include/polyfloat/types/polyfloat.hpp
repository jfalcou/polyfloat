//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

#include <eve/eve.hpp>
#include <polyfloat/details/abi.hpp>
#include <polyfloat/details/helpers.hpp>
#include <polyfloat/types/concepts.hpp>
#include <polyfloat/types/traits.hpp>
#include <polyfloat/details/inner_graillat.hpp>

namespace plf
{
  //====================================================================================================================
  //! @addtogroup types
  //! @{
  //====================================================================================================================

  //====================================================================================================================
  //! @class polyfloat
  //! @brief Floating-point expansion of `N` values of type `Type`, of decreasing magnitude and without overlap.
  //====================================================================================================================
  template<eve::floating_scalar_value Type, unsigned int N>
  requires(N > 1 && N <= _::MAX_N)
  struct polyfloat
  {
    using underlying_type = Type;
    using is_polyfloat = void;
    using ptype_t = polyfloat<Type, N>;

    static constexpr auto static_dimension = N;
    using data_type = kumi::result::fill_t<static_dimension, Type>;

    /// Constructs zero, every part zero.
    constexpr polyfloat() noexcept : contents{} {}

    /// Constructs a value from a real of the base type, in the high part, the other parts zero.
    constexpr polyfloat(Type v) noexcept : contents{} { kumi::get<0>(contents) = v; }

    /// Constructs a value from a real of another floating-point type, split over the parts when it is wider.
    template<eve::floating_scalar_value T> constexpr polyfloat(T v) noexcept : contents{}
    {
      using elt_t = eve::element_type_t<T>;
      using elt_type = eve::element_type_t<Type>;
      if constexpr (sizeof(elt_t) <= sizeof(elt_type)) kumi::get<0>(contents) = v;
      else
      {
        auto h = eve::convert(v, eve::as<elt_type>());
        kumi::get<0>(contents) = h;
        auto hc = eve::convert(h, eve::as<elt_t>());
        auto m = eve::convert(v - hc, eve::as<elt_type>());
        kumi::get<1>(contents) = m;
        if constexpr (N == 3)
        {
          auto l = eve::convert(v - (hc + eve::convert(m, eve::as<elt_t>())), eve::as<elt_type>());
          kumi::get<2>(contents) = l;
        }
      }
    }

    /// Constructs a value from two reals converted to the base type, as their exact sum by 2Sum, the rest zero.
    template<std::convertible_to<Type> T0, std::convertible_to<Type> T1>
    requires(2 <= static_dimension)
    constexpr polyfloat(T0 v0, T1 v1) noexcept
      : contents(
          kumi::cat(eve::two_add[pedantic](static_cast<Type>(v0), static_cast<Type>(v1)), kumi::fill<(N - 2)>(Type{0})))
    {
    }

    /// Constructs a value of dimension 3 from three reals, each converted to the base type, as their normalized sum.
    template<std::convertible_to<Type> T0, std::convertible_to<Type> T1, std::convertible_to<Type> T2>
    requires(3 <= static_dimension)
    constexpr polyfloat(T0 v0, T1 v1, T2 v2) noexcept
      : contents(plf::_::inner_three_add(static_cast<Type>(v0), static_cast<Type>(v1), static_cast<Type>(v2)))
    {
    }

    /// Constructs a value from a product type of `N` parts, taken as they are, without normalization.
    constexpr polyfloat(eve::sized_product_type<N> auto const& vs) : contents{vs} {}

    /// Constructs a value from a polyfloat of the same base type and of dimension 2 to `N`, the missing parts zero.
    template<unsigned int M>
    requires(M > 1 && M <= N)
    constexpr polyfloat(polyfloat<Type, M> const& a) noexcept
    requires(N > 1)
      : contents(kumi::cat(a.contents, kumi::fill<N - M>(Type{0})))
    {
    }

    /// Assign a smaller Poly-Float to another
    template<concepts::polyfloat T>
    constexpr polyfloat& operator=(T const& a) noexcept
    requires(T::static_dimension < N)
    {
      return (*this = polyfloat{a});
    }

    //==================================================================================================================
    // ++/--
    //==================================================================================================================

    //! Pre-incrementation operator
    POLYFLOAT_ABI auto& operator++() noexcept
    {
      kumi::get<0>(contents)++;
      return *this;
    };

    //! Pre-decrementation operator
    POLYFLOAT_ABI auto& operator--() noexcept
    {
      kumi::get<0>(contents)--;
      return *this;
    }

    //! Post-incrementation operator
    POLYFLOAT_ABI auto operator++(int) noexcept
    {
      auto that(*this);
      this->operator++();
      return that;
    }

    //! Post-decrementation operator
    POLYFLOAT_ABI auto operator--(int) noexcept
    {
      auto that(*this);
      this->operator--();
      return that;
    }

    data_type contents;
  };

  //====================================================================================================================
  //! @}
  //====================================================================================================================

  template<std::size_t I, typename T, unsigned int N> constexpr auto& get(polyfloat<T, N>& c) noexcept
  {
    return kumi::get<I>(c.contents);
  }

  template<std::size_t I, typename T, unsigned int N> constexpr auto get(polyfloat<T, N> const& c) noexcept
  {
    return kumi::get<I>(c.contents);
  }

  //====================================================================================================================
  //! @name Deduction Guides
  //! @related polyfloat
  //! @{
  //====================================================================================================================
  // Deduction guide for constructing from a product type, disabled
  //   template<eve::product_type Tuple>
  //   polyfloat(Tuple const&) -> polyfloat<kumi::element_t<0, Tuple>, kumi::size_v<Tuple>>;

  /// Deduces dimension 2 from one value.
  template<typename T0, std::convertible_to<T0>... Ts> polyfloat(T0) -> polyfloat<T0, 2u>;
  /// Deduces the dimension from the number of values, two or three.
  template<typename T0, std::convertible_to<T0>... Ts> polyfloat(T0, Ts...) -> polyfloat<T0, 1 + sizeof...(Ts)>;
  //====================================================================================================================
  //! @}
  //====================================================================================================================
}

namespace plf::_
{
  template<typename T, unsigned int N> inline constexpr unsigned int rank<polyfloat<T, N>> = N;

  template<typename T, unsigned int N, eve::width_type L>
  inline constexpr unsigned int rank<eve::wide<polyfloat<T, N>, L>> = N;
}

#if !defined(POLYFLOAT_DOXYGEN_INVOKED)
// std::tuple adaptation
template<typename T, unsigned int N>
struct std::tuple_size<plf::polyfloat<T, N>> : std::integral_constant<std::size_t, N>
{
};

template<typename T, unsigned int N, std::size_t I> struct std::tuple_element<I, plf::polyfloat<T, N>>
{
  using type = T;
};

#endif
#include <polyfloat/types/double_real.hpp>
#include <polyfloat/types/triple_real.hpp>
#include <polyfloat/types/io.hpp>
#include <polyfloat/types/compounds.hpp>
