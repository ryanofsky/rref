// 2006-08-22  Paolo Carlini  <pcarlini@suse.de>
//
// Copyright (C) 2006 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 2, or (at your option)
// any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING.  If not, write to the Free
// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,
// USA.

// 5.1.4.4 class template subtract_with_carry_01 [tr.rand.eng.sub1]
// 5.1.1 Table 16 line 1 default ctor

#include <tr1/random>
#include <testsuite_hooks.h>

void
test01() 
{
  bool test __attribute__((unused)) = true;
  using namespace std::tr1;

  subtract_with_carry_01<float, 24, 10, 24> x;
  VERIFY( x.min() == 0.0 );
  VERIFY( x.max() == 1.0 );

#if _GLIBCXX_USE_C99_MATH_TR1
  VERIFY( x() == 15039276 * std::tr1::ldexp(float(1), -24) );
#else
  VERIFY( x() == 15039276 * std::pow(float(2), -24) );
#endif
}

int main()
{
  test01();
  return 0;
}
