//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

#include <eve/eve.hpp>
#include <polyfloat/types/helpers.hpp>
#include <polyfloat/details/decorators.hpp>
#include <eve/as.hpp>
#include <bit>

namespace plf
{
  template<eve::floating_scalar_value Type, unsigned int N>
  requires(N > 1 && N <= _::MAX_N)
  struct polyfloat;
}

namespace plf::_
{
  // Force a type to be looked at as a wide so we can apply wide-like type preserving semantic in type computations
  template<typename T> struct sema
  {
    using type = T;
  };
  template<typename T> struct sema<eve::logical<T>> : sema<T>
  {
  };
  template<typename T, typename N> struct sema<eve::wide<T, N>>
  {
    using type = eve::wide<eve::underlying_type_t<T>>;
  };
  template<concepts::polyfloat T> struct sema<T>
  {
    using type = eve::wide<eve::underlying_type_t<T>>;
  };

  template<typename T> using sema_t = typename sema<T>::type;

  // Convert a Base type to a potential wide if any appear in T...
  template<typename Base, typename... T>
  using widen = std::conditional_t<std::max({eve::cardinal_v<T>...}) != 1ULL,
                                   eve::as_wide_t<Base, eve::fixed<std::max({eve::cardinal_v<T>...})>>,
                                   eve::element_type_t<Base>>;
}



namespace plf
{
  //====================================================================================================================
  //! @addtogroup traits
  //! @{
  //====================================================================================================================

  //====================================================================================================================
  //! @brief Obtains the rank containing a given type
  //!
  //! If `T` satisfies plf::concepts::polyfloat, evaluates to the number of parts of a
  //! poly-float.
  //!
  //! @tparam T Type to analyze.
  //====================================================================================================================

#if !defined(POLYFLOAT_DOXYGEN_INVOKED)
 template<typename T>
 inline constexpr unsigned int dimension_v = 1;
#else
 template<typename T>
 inline constexpr unsigned int dimension_v = *implementation - defined*;
#endif

  template<concepts::polyfloat T>
  inline constexpr auto dimension_v<T> = eve::element_type_t<std::remove_cvref_t<T>>::static_dimension;

  template<typename T> struct as_real_type
  {
    using type = T;
  };
  template<typename T, unsigned int Dim> struct as_real_type<polyfloat<T, Dim>>
  {
    using type = T;
  };
  template<typename T, typename N> struct as_real_type<eve::wide<T, N>>
  {
    using type = eve::wide<typename as_real_type<T>::type, N>;
  };

  //====================================================================================================================
  //! @brief Compute the real type associated to a Poly-Float-like type
  //!
  //! @tparam T Type to convert to a real type.
  //====================================================================================================================
  template<typename T> using as_real_type_t = typename as_real_type<T>::type;

  template<unsigned int Dim, typename... Ts> struct as_polyfloat_n;

  template<unsigned int Dim, typename... Ts>
  requires(Dim > 1 && requires(Ts... ts) { eve::add(std::declval<_::sema_t<Ts>>()...); })
  struct as_polyfloat_n<Dim, Ts...>
#if !defined(POLYFLOAT_DOXYGEN_INVOKED)
    : as_polyfloat_n<Dim, _::widen<decltype(eve::add(std::declval<_::sema_t<Ts>>()...)), Ts...>>
#endif
  {
  };

#if !defined(POLYFLOAT_DOXYGEN_INVOKED)
  template<unsigned int Dim, typename... Ts>
  requires(Dim > 1 && !requires(Ts... ts) { eve::add(std::declval<_::sema_t<Ts>>()...); })
  struct as_polyfloat_n<Dim, Ts...>
  {
  };

  template<unsigned int Dim, typename T>
  requires(Dim > 1)
  struct as_polyfloat_n<Dim, T>
  {
    static constexpr auto card = eve::cardinal_v<T>;
    using cd_t = polyfloat<eve::as_floating_point_t<eve::underlying_type_t<T>>, Dim>;
    using type = std::conditional_t<card != 1ULL, eve::wide<cd_t, eve::fixed<card>>, cd_t>;
  };

  template<typename... Ts> struct as_polyfloat_n<1, Ts...> : eve::common_value<_::sema_t<Ts>...>
  {
  };
#endif

  //====================================================================================================================
  //! @brief Computes a Poly-Float type of a given dimension
  //!
  //! @tparam Dim Dimension of the Poly-Float to use.
  //! @tparam Ts  Types used to compute the Poly-Float underlying type.
  //====================================================================================================================
  template<unsigned int Dim, typename... Ts>
  using as_polyfloat_n_t = typename as_polyfloat_n<Dim, Ts...>::type;

  template<typename... Ts>
  requires(requires(Ts... ts) { typename as_polyfloat_n<std::max({dimension_v<Ts>...}), Ts...>::type; })
  struct as_polyfloat : as_polyfloat_n<std::max({dimension_v<Ts>...}), Ts...>
  {
  };
}

namespace plf
{
  namespace _
  {
    template<typename T> using common_real = eve::as_floating_point_t<as_real_type_t<T>>;
  }

  //====================================================================================================================
  //! @brief Computes the best fitting Poly-Float type from a series of types.
  //!
  //! @tparam Ts  Types used to compute the Poly-Float underlying type.
  //====================================================================================================================
  template<typename... Ts> using as_polyfloat_t = typename as_polyfloat<Ts...>::type;

  template<auto Callable, typename... Ts>
  using expected_result_t =
    as_polyfloat_n_t<std::max({dimension_v<Ts>...}), decltype(Callable(std::declval<as_real_type_t<Ts>>()...))>;

  using eve::as;

  //====================================================================================================================
  //! @struct as_real
  //! @brief Lightweight type-wrapper of real value type
  //!
  //! Wraps the real type associated to `T` into a constexpr, trivially constructible empty class to optimize passing
  //! type parameters via object instead of via template parameters.
  //!
  //! @tparam T Type to wrap
  //====================================================================================================================
  template<typename T> struct as_real : as<as_real_type_t<T>>
  {
    constexpr as_real() noexcept {}
    explicit constexpr as_real(T const&) noexcept {}
  };
  //====================================================================================================================
  //!  @}
  //====================================================================================================================

  //====================================================================================================================
  //! @struct complexify
  //! @brief compute the cayley dickson type associated to a floating type or any other type.
  //!
  //! if the type is an eve::floating_value return the complex type associated else let the type as is.
  //!
  //! @tparam T Type to wrap
  //====================================================================================================================
  template<typename T> struct double_it
  {
    using type = T;
  };

  template<eve::floating_value T> struct double_it<T>
  {
    using type = plf::as_polyfloat_n_t<2, T>;
  };

  template<typename T> using double_it_t = typename double_it<T>::type;

  //====================================================================================================================
  //! @brief Compute the cayley_dickson_like type associated to a Poly-Float-like family of types
  //!
  //! @tparam Ts Types used to compute the Poly-Float_like common type.
  //====================================================================================================================

  template<typename... Ts> struct as_polyfloat_like : as_polyfloat<Ts...>
  {
  };

  template<typename T, typename Ts>
  struct as_polyfloat_like<T, coefficients<Ts>>
    : as_polyfloat_like<T, kumi::apply_traits_t<as_polyfloat_like, Ts>>
  {
  };

  template<typename T, typename Ts>
  struct as_polyfloat_like<T, nodes<Ts>>
    : as_polyfloat_like<T, kumi::apply_traits_t<as_polyfloat_like, Ts>>
  {
  };

  template<concepts::real... Ts> struct as_polyfloat_like<Ts...> : eve::common_value<Ts...>
  {
  };
  template<typename... Ts> using as_polyfloat_like_t = typename as_polyfloat_like<Ts...>::type;

  
}
