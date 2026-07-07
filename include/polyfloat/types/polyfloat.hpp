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
  //! @brief Poly-Float algebra main abstraction
  //! It is built so that all operation over C, Q and other such algebra can be done in a streamlined fashion
  //! based on the Cayley–Dickson construction.
  //====================================================================================================================
  template<eve::floating_scalar_value Type, unsigned int N>
  requires(N > 1 && std::has_single_bit(N))
  struct polyfloat
  {
    using underlying_type = Type;
    using is_polyfloat = void;

    static constexpr auto static_dimension = N;

    /// Default Poly-Float constructor
    constexpr polyfloat() noexcept : contents{} {}

    /// Construct a Poly-Float from a real value
    template<std::convertible_to<Type> T> constexpr polyfloat(T v) noexcept : contents{}
    {
      kumi::get<0>(contents) = v;
    }

    /// Construct a Poly-Float instance from a sequences of real values supposed normalized
    template<std::convertible_to<Type> T0, std::convertible_to<Type>... Ts>
    requires((1 + sizeof...(Ts)) <= static_dimension)
    constexpr polyfloat(T0 v0, Ts... vs) noexcept
      : contents(kumi::cat(kumi::tuple{static_cast<Type>(v0), static_cast<Type>(vs)...},
                           kumi::fill<(N - 1 - sizeof...(Ts))>(Type{0})))
    {
    }

    /// Construct a Poly-Float instance from a properly sized product_type supposed normalized
    constexpr polyfloat(eve::sized_product_type<N> auto const& vs) : contents{vs} {}

    /// Constructs a Poly-Float instance from an Poly-Float of smaller dimension
    template<unsigned int M>
    requires(M > 1 && M == N / 2)
    constexpr polyfloat(polyfloat<Type, M> const& a) noexcept
    requires(N > 1)
      : contents(kumi::cat(a.contents, kumi::fill<M>(Type{0})))
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

 //    //! Pre-incrementation operator
//     POLYFLOAT_FORCEINLINE auto& operator++() noexcept
//     {
//       kumi::get<0>(contents)++;
//       return *this;
//     }

//     //! Pre-decrementation operator
//     POLYFLOAT_FORCEINLINE auto& operator--() noexcept
//     {
//       kumi::get<0>(contents)--;
//       return *this;
//     }

//     //! Post-incrementation operator
//     POLYFLOAT_FORCEINLINE auto operator++(int) noexcept
//     {
//       auto that(*this);
//       this->operator++();
//       return that;
//     }

//     //! Post-decrementation operator
//     POLYFLOAT_FORCEINLINE auto operator--(int) noexcept
//     {
//       auto that(*this);
//       this->operator--();
//       return that;
//     }

    //==================================================================================================================
    //  Tuple-like behavior
    //==================================================================================================================
    using data_type = kumi::result::fill_t<static_dimension, Type>;

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
  template<eve::product_type Tuple>
  polyfloat(Tuple const&) -> polyfloat<kumi::element_t<0, Tuple>, kumi::size_v<Tuple>>;

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

#include <polyfloat/types/io.hpp>
// #include <polyfloat/types/compounds.hpp>
// #include <polyfloat/types/operators.hpp>
