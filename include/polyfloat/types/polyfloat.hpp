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
#include <bit>

namespace plf
{
  //====================================================================================================================
  //! @addtogroup types
  //! @{
  //====================================================================================================================

  //====================================================================================================================
  //! @class polyfloat
  //! @brief representing an extended precision floating point  by a sequence of standards ones
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

    /// Default Poly-Float constructor
    constexpr polyfloat() noexcept : contents{} {}

    /// Construct a Poly-Float from a real value of the base type
    constexpr polyfloat(Type v) noexcept : contents{}
    {
      kumi::get<0>(contents) = v;
    }

    /// Construct a Poly-Float from a real value of another type
    template<eve::floating_value T> constexpr polyfloat(T v) noexcept
      requires(eve::same_lanes_or_scalar<T, Type>)
       : contents{}
    {
      using elt_t =  eve::element_type_t<T>;
      using elt_type =  eve::element_type_t<Type>;
      if constexpr(sizeof(elt_t) <= sizeof(elt_type))
        kumi::get<0>(contents) =  v;
      else
      {
        auto h = eve::convert(v, eve::as<elt_type>());
        kumi::get<0>(contents) = h;
        auto hc = eve::convert(h, eve::as<elt_t>());
        auto m =  eve::convert(v-hc, eve::as<elt_type>());
        kumi::get<1>(contents) = m;
        if constexpr(N == 3)
        {
          auto l = eve::convert(v -(hc + eve::convert(m, eve::as<elt_t>())), eve::as<elt_type>());
          kumi::get<2>(contents) = l;
        }
      }
    }

    /// Construct a Poly-Float instance from a pair of real values
    template<std::convertible_to<Type> T0, std::convertible_to<Type> T1>
    requires(2 <= static_dimension)
    constexpr polyfloat(T0 v0, T1 v1) noexcept
    : contents(kumi::cat(eve::two_add(static_cast<Type>(v0), static_cast<Type>(v1)),  kumi::fill<(N - 2)>(Type{0})))
    {
    }

    /// Construct a Poly-Float instance from a triple of real values
    template<std::convertible_to<Type> T0, std::convertible_to<Type> T1, std::convertible_to<Type> T2>
    requires(2 <= static_dimension)
    constexpr polyfloat(T0 v0, T1 v1, T2 v2) noexcept
    : contents(kumi::cat(plf::_::three_add(static_cast<Type>(v0), static_cast<Type>(v1), static_cast<Type>(v2)),  kumi::fill<(N - 3)>(Type{0})))
    {
    }

    /// Construct a Poly-Float instance from 4 real values
    template<std::convertible_to<Type> T0, std::convertible_to<Type> T1, std::convertible_to<Type> T2, std::convertible_to<Type> T3>
    requires(3<= static_dimension)
    constexpr polyfloat(T0 v0, T1 v1, T2 v2, T3 v3) noexcept
    : contents(plf::_::four_add(static_cast<Type>(v0), static_cast<Type>(v1), static_cast<Type>(v2), static_cast<Type>(v3)))
    {
    }

    /// Construct a Poly-Float instance from a properly sized product_type supposed normalized
    constexpr polyfloat(eve::sized_product_type<N> auto const& vs) : contents{vs} {}

    /// Constructs a Poly-Float instance from an Poly-Float of smaller dimension
    template<unsigned int M>
    requires(M > 1 && M <= N)
    constexpr polyfloat(polyfloat<Type, M> const& a) noexcept
    requires(N > 1)
      : contents(kumi::cat(a.contents, kumi::fill<N-M>(Type{0})))
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
    POLYFLOAT_FORCEINLINE auto& operator++() noexcept{
      kumi::get<0>(contents)++;
      return *this;
    };

    //! Pre-decrementation operator
    POLYFLOAT_FORCEINLINE auto& operator--() noexcept
    {
      kumi::get<0>(contents)--;
      return *this;
    }

    //! Post-incrementation operator
    POLYFLOAT_FORCEINLINE auto operator++(int) noexcept
    {
      auto that(*this);
      this->operator++();
      return that;
    }

    //! Post-decrementation operator
    POLYFLOAT_FORCEINLINE auto operator--(int) noexcept
    {
      auto that(*this);
      this->operator--();
      return that;
    }

    //==================================================================================================================
    //  Tuple-like behavior
    //==================================================================================================================

    friend constexpr eve::as_logical_t<Type> operator==(polyfloat const& a, polyfloat const& b) noexcept
    {
      return a.contents == b.contents;
    }

    friend constexpr eve::as_logical_t<Type> operator!=(polyfloat const& a, polyfloat const& b) noexcept
    {
      return a.contents != b.contents;
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
  /// Deduction guide for constructing from product type
//   template<eve::product_type Tuple>
//   polyfloat(Tuple const&) -> polyfloat<kumi::element_t<0, Tuple>, kumi::size_v<Tuple>>;

  /// Deduction guide for constructing from one value
  template<typename T0, std::convertible_to<T0>... Ts>
  polyfloat(T0) -> polyfloat<T0, 2u>;
  /// Deduction guide for constructing from sequence of values
  template<typename T0, std::convertible_to<T0>... Ts>
  polyfloat(T0, Ts...) -> polyfloat<T0, 1 + sizeof...(Ts)>;
  //====================================================================================================================
  //! @}
  //====================================================================================================================
}

namespace plf::_
{
  template<typename T, unsigned int N> inline constexpr unsigned int rank<polyfloat<T, N>> = N;

  template<typename T, unsigned int N, typename L>
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
#include <polyfloat/types/twofloat.hpp>
#include <polyfloat/types/threefloat.hpp>
#include <polyfloat/types/io.hpp>
#include <polyfloat/types/compounds.hpp>
//#include <polyfloat/types/unary_ops.hpp>
// #include <polyfloat/types/operators.hpp>
