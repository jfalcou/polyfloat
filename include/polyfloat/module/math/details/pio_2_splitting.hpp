//======================================================================================================================
/*
 POLYFLOAT - Extended precision floating points
 Copyright : POLYFLOAT Contributors & Maintainers
 SPDX-License-Identifier: BSL-1.0
*/
//======================================================================================================================
#pragma once

namespace plf::_
{
  template<typename T> EVE_FORCEINLINE constexpr auto pio_2_splitting(as<T> const&) noexcept
  {
    using u_t = eve::underlying_type_t<T>;
    //   using e_t =  eve::element_type_t<T>;
    if constexpr (dimension_v<T> == 1)
    {
      if constexpr (std::same_as<u_t, float>)
      {
        // cody waite constants for:
        // number of constants                                     : 24
        // total number of significand bit                         : 3
        // The constant definition                                 : 1.5707963267948966192313216916397514420985846996875529104874722961539082031431044993140174126710585339910740432566411533235469223047752911158626797040642405587251420513509692605527798223114744774651909822144054878329667230642378241168933915826356009545728242834617301743052271633241066968036301245706368
        // boundary for trailing zero bit number                   : 8
        // logarithm of max input for required precision           : 5.996890
        return kumi::tuple{float(0x1.9200000000000p+0), float(0x1.f000000000000p-12), float(0x1.6a88860000000p-17)};
      }
      else if constexpr (std::same_as<u_t, double>)
      {
        // cody waite constants for:
        // number of constants                                     : 53
        // total number of significand bit                         : 3
        // The constant definition                                 : 1.5707963267948966192313216916397514420985846996875529104874722961539082031431044993140174126710585339910740432566411533235469223047752911158626797040642405587251420513509692605527798223114744774651909822144054878329667230642378241168933915826356009545728242834617301743052271633241066968036301245706368
        //  boundary for trailing zero bit number                   : 18
        // logarithm of max input for required precision           : 12.928362
        return kumi::tuple{double(0x1.921f800000000p+0), double(0x1.aa22000000000p-19), double(0x1.68c234c4c6629p-39)};
      }
    }
    else if constexpr (dimension_v<T> == 2)
    {
      if constexpr (std::same_as<u_t, float>)
      {
        // cody waite constants for:
        //  number of constants                                     : 48
        //  total number of significand bit                         : 3
        //  The constant definition                                 : 1.5707963267948966192313216916397514420985846996875529104874722961539082031431044993140174126710585339910740432566411533235469223047752911158626797040642405587251420513509692605527798223114744774651909822144054878329667230642378241168933915826356009545728242834617301743052271633241066968036301245706368
        //  boundary for trailing zero bit number                   : 24
        //  logarithm of max input for required precision           : 17.087245

        return kumi::tuple{from_pair<float>(0x1.9210000000000p+0, 0x0.0p+0),
                           from_pair<float>(0x1.f6a0000000000p-13, 0x0.0p+0),
                           from_pair<float>(0x1.110b460000000p-26, 0x1.1a62640000000p-54)};
      }
      else if constexpr (std::same_as<u_t, double>)
      {
        // cody waite constants for:
        // number of constants                                     : 106
        // total number of significand bit                         : 3
        // The constant definition                                 : 1.5707963267948966192313216916397514420985846996875529104874722961539082031431044993140174126710585339910740432566411533235469223047752911158626797040642405587251420513509692605527798223114744774651909822144054878329667230642378241168933915826356009545728242834617301743052271633241066968036301245706368
        //  boundary for trailing zero bit number                  : 53
        // logarithm of max input for required precision           : 37.188513
        return kumi::tuple{from_pair<double>(0x1.921fb54000000p+0, 0x0.0p+0),
                           from_pair<double>(0x1.10b4600000000p-30, 0x0.0p+0),
                           from_pair<double>(0x1.1a62633145c07p-54, -0x1.f1976b7ed8fbcp-110)};
      }
    }
    else if constexpr (dimension_v<T> == 3)
    {
      if constexpr (std::same_as<u_t, float>)
      {
        // cody waite constants for:
        // number of constants                                     : 72
        // total number of significand bit                         : 3
        // The constant definition                                 : 1.5707963267948966192313216916397514420985846996875529104874722961539082031431044993140174126710585339910740432566411533235469223047752911158626797040642405587251420513509692605527798223114744774651909822144054878329667230642378241168933915826356009545728242834617301743052271633241066968036301245706368
        // boundary for trailing zero bit number                   : 18
        // logarithm of max input for required precision           : 12.928362
        return kumi::tuple{from_triple<float>(0x1.921fb60000000p+0, -0x1.8000000000000p-25, 0x0.0p+0),
                           from_triple<float>(0x1.10b4600000000p-30, 0x1.0000000000000p-54, 0x0.0p+0),
                           from_triple<float>(0x1.a626340000000p-58, -0x1.d747f20000000p-83, -0x1.f1976c0000000p-110)};
      }
      else if constexpr (std::same_as<u_t, double>)
      {
        // cody waite constants for:
        // number of constants                                     : 169
        // total number of significand bit                         : 3
        // The constant definition                                 : 1.5707963267948966192313216916397514420985846996875529104874722961539082031431044993140174126710585339910740432566411533235469223047752911158626797040642405587251420513509692605527798223114744774651909822144054878329667230642378241168933915826356009545728242834617301743052271633241066968036301245706368
        // boundary for trailing zero bit number                   : 24
        // logarithm of max input for required precision           : 17.087245
        return kumi::tuple{
          from_triple<double>(0x1.921fb54442d18p+0, 0x1.1a62400000000p-54, 0x0.0p+0),
          from_triple<double>(0x1.198a2e0370734p-73, 0x1.2902000000000p-127, 0x0.0p+0),
          from_triple<double>(0x1.3822299f31d01p-145, -0x1.f44159c4ec64ep-199, 0x1.28a5043cc71a0p-254)};
      }
    }
  }
}
