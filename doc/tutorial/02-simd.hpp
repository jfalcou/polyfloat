#error This file is for documentation only - DO NOT INCLUDE
//! @page tutorial-simd Many values at once
//!
//! Every processor made in the last twenty years can add several numbers in the time it takes to
//! add one. The instruction exists, the register exists, and the only difficulty is expressing it.
//! **POLYFLOAT** is built on [EVE](https://github.com/jfalcou/eve), whose whole purpose is that
//! expression, so the facility comes for free.
//!
//! You do not need to know anything about SIMD to read this page. The idea is simply that a value
//! can hold several numbers at once, and that the code does not change.
//!
//! # A register of floating numbers
//!
//! `eve::wide<double>` holds as many `double` as the machine's registers allow. Arithmetic on it
//! reads exactly like arithmetic on one:
//!
//! @godbolt{doc/core/tut_simd_wide_floats.cpp}
//!
//! Two things to read in that output. The cardinal is not a constant of the library but of the
//! machine you compile for — two on a plain x86-64, four with AVX, eight with AVX-512 — and the
//! source never mentions it.
//!
//! # A register of polyfloats
//!
//! The interesting part is that this composes. A polyfloat number whose components are registers is
//! written by handing `plf::double_real_t` or `plf_triple_real_t` two or three `wide<double>` instead of
//! two or three `double`, and every function of the library then applies to all of them at once.
//!
//! @godbolt{doc/core/tut_simd_wide_plf.cpp}
//!
//! `eve::wide<double_real_t<double>>` holds as many `double_real_t<double>` as the machine's registers
//! allow for `double`. Arithmetic on it reads exactly like arithmetic on one:
//!
//! # Writing code that does not care
//!
//! Because the spelling is identical, a function template covers both. The same body, called once
//! on scalars and once on registers:
//!
//! @godbolt{doc/core/tut_simd_generic.cpp}
//!
//! This is the shape most **POLYFLOAT** code ends up taking: write the mathematics once, let the
//! caller decide whether it runs on one value or on a register of them.
//!
//! <div class="section_buttons">
//!
//! | Previous                              |                            Next |
//! |:--------------------------------------|--------------------------------:|
//! | [Polyfloat Numbers](@ref tutorial-basics) |  [Implementation precisions]( @ref implementation_precisions.md) |
//!
//! </div>
