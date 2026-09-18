//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

#include <polyfloat/details/callable.hpp>
#include <polyfloat/types/concepts.hpp>
#include <polyfloat/types/traits.hpp>
#include <type_traits>
#include <polyfloat/module/math/nthroot.hpp>

namespace plf
{

  template<typename Options>
  struct kolmmean_t : eve::strict_tuple_callable<kolmmean_t, Options, raw_option, pedantic_option>
  {

    template<typename F, typename G, concepts::polyfloat_like... Zs>
    POLYFLOAT_FORCEINLINE constexpr as_polyfloat_like_t<Zs...> operator()(F f, G g, Zs... zs) const noexcept
    {
      return POLYFLOAT_CALL(f, g, zs...);
    }

    POLYFLOAT_CALLABLE_OBJECT(kolmmean_t, kolmmean_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var kolmmean
  //!   @brief  Callable object computing the  'Kolmogorov-Nagumo-de Finetti' mean of the inputs: \f$ \mathbf{g}(\sum \mathbf{f}(x_s)) \f$.
  //!
  //!   @groupheader{Header file}
  //!
  //!   @code
  //!   #include <polyfloat/core.hpp>
  //!   @endcode
  //!
  //!   @groupheader{Callable Signatures}
  //!
  //!   @code
  //!   namespace polyfloat
  //!   {
  //!      template<polyfloat::concepts::polyfloat_like ... Ts> constexpr auto kolmmean(auto f,  auto g, Ts ... ts) noexcept;
  //!   }
  //!   @endcode
  //!
  //! **Parameters**
  //!
  //!    * `f`, `g`: two functions that will be used to compute the mean (see note above).
  //!    * `ts`: polyfloat like] arguments.
  //!
  //!   **Return value**
  //!
  //!      The kolmogorov mean of the inputs is returned//!
  //!
  //!  @note For the result to be a proper kolmogorov mean, `f` must be mathematically continuous and injective and `g` be its inverse.
  //!        and **EVE** need them to be defined for a floating_value input, and returning the same type.
  //!        However \f$ \mathbf{g}(\sum \mathbf{f}(x_s, ...)) \f$ is returned if computable.
  //!
  //!  @groupheader{External references}
  //!   *  [wikipedia quasi-arithmetic mean](https://en.wikipedia.org/wiki/Quasi-arithmetic_mean)
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt_todo{doc/core/kolmmean.cpp}
  //======================================================================================================================

  inline constexpr auto kolmmean = eve::functor<kolmmean_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{

  template<typename F, typename G, typename T0, typename... Ts, eve::callable_options O>
  POLYFLOAT_FORCEINLINE constexpr auto kolmmean_(POLYFLOAT_DELAY(), O const& o, F f, G g, T0 t0, Ts... ts) noexcept
  {
    using r_t = as_polyfloat_like_t<T0, Ts...>;
    using e_t = eve::element_type_t<r_t>;
    auto cvt = [](auto a) { return plf::convert(a, as<e_t>()); };
    constexpr auto sz = sizeof...(Ts);
    if constexpr (sz == 0) return g(f(t0));
    else return g(plf::average[o](f(cvt(t0)), f(cvt(ts))...));
  }
}
