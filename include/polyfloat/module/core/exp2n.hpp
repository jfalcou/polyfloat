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
#include <polyfloat/module/core/is_nan.hpp>
#include <polyfloat/module/core/is_minf.hpp>
#include <polyfloat/module/core/is_pinf.hpp>

namespace plf
{

  template<typename Options> struct exp2n_t : eve::callable<exp2n_t, Options, raw_option, pedantic_option>
  {
    template<concepts::polyfloat_like Z> POLYFLOAT_ABI constexpr Z operator()(Z n) const noexcept
    {
      return POLYFLOAT_CALL(n);
    }

    template<eve::integral_value N, concepts::polyfloat_like Target>
    POLYFLOAT_ABI constexpr Target operator()(N n, eve::as<Target>) const noexcept
    {
      return POLYFLOAT_CALL(n, eve::as<Target>());
    }

    POLYFLOAT_CALLABLE_OBJECT(exp2n_t, exp2n_);
  };
  //======================================================================================================================
  //! @addtogroup core
  //! @{
  //!   @var exp2n
  //!   @brief return \f$2^n\f$ where n is flint or integral.
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
  //!      template<polyfloat::concepts::polyfloat_like T>                        constexpr auto exp2n(T n) noexcept;            //1
  //!      template<eve::integral_value I, polyfloat::concepts::polyfloat_like U> constexpr auto exp2n(I n, eve::as<U>) noexcept;//2
  //!   }
  //!   @endcode
  //!
  //!   **Parameters**
  //!
  //!      `n`: flint exponent (if it is not flint it is truncated before use).
  //!
  //!   **Template Parameter**
  //!
  //!     * `U`: target type to convert to.
  //!
  //!   **Return value**
  //!
  //!       Returns  \f$2^\tilda{n}\f$. where \f$\tilda{n}\f$ is the truncature of \f$n\f$n in the type of N
  //!         if N inot integral and in the type of the target otherwise. This is faster than the general exp2
  //!         and does not uses math module.
  //!
  //!       * If n is a flint polyfloat or standard floating the same type is returned
  //!       * If n is integral you have to  choose a target
  //!
  //!  @note Mind the fact that n greater than maxexponent or less than than minexponent of the target; will
  //!        repectively return inf and zero values,  unless 'raww' options is used and then the result is undefined.
  //!
  //!  @groupheader{Example}
  //!
  //!  @godbolt{doc/core/exp2n.cpp}
  //======================================================================================================================

  inline constexpr auto exp2n = eve::functor<exp2n_t>;
  //======================================================================================================================
  //! @}
  //======================================================================================================================
}

namespace plf::_
{
  template<eve::integral_value N, typename Z, eve::callable_options O>
  constexpr auto exp2n_(POLYFLOAT_DELAY(), O const& o, N const& n, eve::as<Z>) noexcept
  {
    using c_t = as_component_type_t<Z>;
    using e_t = eve::element_type_t<Z>;
    using u_t = eve::underlying_type_t<e_t>;
    auto bits = (n + eve::maxexponent(eve::as<u_t>())) << eve::nbmantissabits(eve::as<u_t>());
    auto r = eve::bit_cast(bits, eve::as(c_t()));
    if constexpr (O::contains(eve::raw)) return Z(r);
    else
    {
      auto test1 = eve::minexponent(eve::as<u_t>()) > n;
      auto test2 = eve::maxexponent(eve::as<u_t>()) < n;
      return Z(eve::if_else(test1, eve::zero, eve::if_else(test2, eve::inf(eve::as<u_t>()), r)));
    }
  }

  template<typename N, eve::callable_options O>
  constexpr auto exp2n_(POLYFLOAT_DELAY(), O const& o, N n) noexcept
  requires(!eve::integral_value<N>)
  {
    using u_t = eve::underlying_type_t<N>;
    using i_t = eve::as_integer_t<u_t, signed>;
    auto test = plf::is_not_finite(n);
    auto nann = plf::is_nan(n);
    if constexpr (!O::contains(eve::raw))
    {
      if (eve::any(test))
      {
        n = plf::if_else(plf::is_pinf(n), N(eve::maxexponentp1(eve::as<u_t>())),
                         plf::if_else(plf::is_minf(n), N(-eve::maxexponentp1(eve::as<u_t>())),
                                      plf::if_else(nann, plf::zero(eve::as(n)), n)));
      }
    }
    auto in = eve::convert(plf::hi(n), eve::as<i_t>());
    auto r = exp2n[o](in, eve::as<N>());
    if constexpr (O::contains(eve::raw)) return r;
    else return plf::if_else(nann, nan(as<N>()), exp2n[o](in, eve::as<N>()));
  }
}
