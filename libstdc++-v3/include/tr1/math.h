// TR1 math.h -*- C++ -*-

// Copyright (C) 2006, 2007 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 2, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING.  If not, write to the Free
// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,
// USA.

// As a special exception, you may use this file as part of a free software
// library without restriction.  Specifically, if other files instantiate
// templates or use macros or inline functions from this file, or you compile
// this file and link it with other files to produce an executable, this
// file does not by itself cause the resulting executable to be covered by
// the GNU General Public License.  This exception does not however
// invalidate any other reasons why the executable file might be covered by
// the GNU General Public License.

/** @file tr1/math.h
 *  This is a TR1 C++ Library header. 
 */

#ifndef _TR1_MATH_H
#define _TR1_MATH_H 1

#include <tr1/cmath>

#if _GLIBCXX_USE_C99_MATH_TR1

using std::_GLIBCXX_TR1::acos;
using std::_GLIBCXX_TR1::acosh;
using std::_GLIBCXX_TR1::asin;
using std::_GLIBCXX_TR1::asinh;
using std::_GLIBCXX_TR1::atan;
using std::_GLIBCXX_TR1::atan2;
using std::_GLIBCXX_TR1::atanh;
using std::_GLIBCXX_TR1::cbrt;
using std::_GLIBCXX_TR1::ceil;
using std::_GLIBCXX_TR1::copysign;
using std::_GLIBCXX_TR1::cos;
using std::_GLIBCXX_TR1::cosh;
using std::_GLIBCXX_TR1::erf;
using std::_GLIBCXX_TR1::erfc;
using std::_GLIBCXX_TR1::exp;
using std::_GLIBCXX_TR1::exp2;
using std::_GLIBCXX_TR1::expm1;
using std::_GLIBCXX_TR1::fabs;
using std::_GLIBCXX_TR1::fdim;
using std::_GLIBCXX_TR1::floor;
using std::_GLIBCXX_TR1::fma;
using std::_GLIBCXX_TR1::fmax;
using std::_GLIBCXX_TR1::fmin;
using std::_GLIBCXX_TR1::fmod;
using std::_GLIBCXX_TR1::frexp;
using std::_GLIBCXX_TR1::hypot;
using std::_GLIBCXX_TR1::ilogb;
using std::_GLIBCXX_TR1::ldexp;
using std::_GLIBCXX_TR1::lgamma;
using std::_GLIBCXX_TR1::llrint;
using std::_GLIBCXX_TR1::llround;
using std::_GLIBCXX_TR1::log;
using std::_GLIBCXX_TR1::log10;
using std::_GLIBCXX_TR1::log1p;
using std::_GLIBCXX_TR1::log2;
using std::_GLIBCXX_TR1::logb;
using std::_GLIBCXX_TR1::lrint;
using std::_GLIBCXX_TR1::lround;
using std::_GLIBCXX_TR1::nearbyint;
using std::_GLIBCXX_TR1::nextafter;
using std::_GLIBCXX_TR1::nexttoward;
using std::_GLIBCXX_TR1::pow;
using std::_GLIBCXX_TR1::remainder;
using std::_GLIBCXX_TR1::remquo;
using std::_GLIBCXX_TR1::rint;
using std::_GLIBCXX_TR1::round;
using std::_GLIBCXX_TR1::scalbln;
using std::_GLIBCXX_TR1::scalbn;
using std::_GLIBCXX_TR1::sin;
using std::_GLIBCXX_TR1::sinh;
using std::_GLIBCXX_TR1::sqrt;
using std::_GLIBCXX_TR1::tan;
using std::_GLIBCXX_TR1::tanh;
using std::_GLIBCXX_TR1::tgamma;
using std::_GLIBCXX_TR1::trunc;

#endif

using std::_GLIBCXX_TR1::assoc_laguerref;
using std::_GLIBCXX_TR1::assoc_laguerre;
using std::_GLIBCXX_TR1::assoc_laguerrel;

using std::_GLIBCXX_TR1::assoc_legendref;
using std::_GLIBCXX_TR1::assoc_legendre;
using std::_GLIBCXX_TR1::assoc_legendrel;

using std::_GLIBCXX_TR1::betaf;
using std::_GLIBCXX_TR1::beta;
using std::_GLIBCXX_TR1::betal;

using std::_GLIBCXX_TR1::comp_ellint_1f;
using std::_GLIBCXX_TR1::comp_ellint_1;
using std::_GLIBCXX_TR1::comp_ellint_1l;

using std::_GLIBCXX_TR1::comp_ellint_2f;
using std::_GLIBCXX_TR1::comp_ellint_2;
using std::_GLIBCXX_TR1::comp_ellint_2l;

using std::_GLIBCXX_TR1::comp_ellint_3f;
using std::_GLIBCXX_TR1::comp_ellint_3;
using std::_GLIBCXX_TR1::comp_ellint_3l;

using std::_GLIBCXX_TR1::conf_hypergf;
using std::_GLIBCXX_TR1::conf_hyperg;
using std::_GLIBCXX_TR1::conf_hypergl;

using std::_GLIBCXX_TR1::cyl_bessel_if;
using std::_GLIBCXX_TR1::cyl_bessel_i;
using std::_GLIBCXX_TR1::cyl_bessel_il;

using std::_GLIBCXX_TR1::cyl_bessel_jf;
using std::_GLIBCXX_TR1::cyl_bessel_j;
using std::_GLIBCXX_TR1::cyl_bessel_jl;

using std::_GLIBCXX_TR1::cyl_bessel_kf;
using std::_GLIBCXX_TR1::cyl_bessel_k;
using std::_GLIBCXX_TR1::cyl_bessel_kl;

using std::_GLIBCXX_TR1::cyl_neumannf;
using std::_GLIBCXX_TR1::cyl_neumann;
using std::_GLIBCXX_TR1::cyl_neumannl;

using std::_GLIBCXX_TR1::ellint_1f;
using std::_GLIBCXX_TR1::ellint_1;
using std::_GLIBCXX_TR1::ellint_1l;

using std::_GLIBCXX_TR1::ellint_2f;
using std::_GLIBCXX_TR1::ellint_2;
using std::_GLIBCXX_TR1::ellint_2l;

using std::_GLIBCXX_TR1::ellint_3f;
using std::_GLIBCXX_TR1::ellint_3;
using std::_GLIBCXX_TR1::ellint_3l;

using std::_GLIBCXX_TR1::expintf;
using std::_GLIBCXX_TR1::expint;
using std::_GLIBCXX_TR1::expintl;

using std::_GLIBCXX_TR1::hermitef;
using std::_GLIBCXX_TR1::hermite;
using std::_GLIBCXX_TR1::hermitel;

using std::_GLIBCXX_TR1::hypergf;
using std::_GLIBCXX_TR1::hyperg;
using std::_GLIBCXX_TR1::hypergl;

using std::_GLIBCXX_TR1::laguerref;
using std::_GLIBCXX_TR1::laguerre;
using std::_GLIBCXX_TR1::laguerrel;

using std::_GLIBCXX_TR1::legendref;
using std::_GLIBCXX_TR1::legendre;
using std::_GLIBCXX_TR1::legendrel;

using std::_GLIBCXX_TR1::riemann_zetaf;
using std::_GLIBCXX_TR1::riemann_zeta;
using std::_GLIBCXX_TR1::riemann_zetal;

using std::_GLIBCXX_TR1::sph_besself;
using std::_GLIBCXX_TR1::sph_bessel;
using std::_GLIBCXX_TR1::sph_bessell;

using std::_GLIBCXX_TR1::sph_legendref;
using std::_GLIBCXX_TR1::sph_legendre;
using std::_GLIBCXX_TR1::sph_legendrel;

using std::_GLIBCXX_TR1::sph_neumannf;
using std::_GLIBCXX_TR1::sph_neumann;
using std::_GLIBCXX_TR1::sph_neumannl;

#endif
