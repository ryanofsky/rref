// Copyright (C) 2005 Free Software Foundation, Inc.
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
// Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307,
// USA.

// 25.2.4 replace_copy

#include <algorithm>
#include <testsuite_hooks.h>
#include <testsuite_iterators.h>

using __gnu_test::test_container;
using __gnu_test::input_iterator_wrapper;
using __gnu_test::output_iterator_wrapper;

typedef test_container<int, input_iterator_wrapper> Icontainer; 
typedef test_container<int, output_iterator_wrapper> Ocontainer;
int array[] = {0, 0, 0, 1, 0, 1};

void
test1()
{
  int out[1];
  Icontainer in_con(array, array);
  Ocontainer out_con(out, out);
  VERIFY(std::replace_copy(in_con.begin(), in_con.end(), 
	                   out_con.begin(), 1, 1).ptr == out);
}

void
test2()
{
  int out[1];
  Icontainer in_con(array, array + 1);
  Ocontainer out_con(out, out + 1);
  VERIFY(std::replace_copy(in_con.begin(), in_con.end(), 
			   out_con.begin(), 0, 1).ptr == out + 1);
  VERIFY(out[0] == 1);
}

void
test3()
{
  int out[6];
  Icontainer in_con(array, array + 6);
  Ocontainer out_con(out, out + 6);
  VERIFY(std::replace_copy(in_con.begin(), in_con.end(),
			   out_con.begin(), 1, 2).ptr == out + 6);
  VERIFY(out[0] == 0 && out[1] == 0 && out[2] == 0 &&
         out[3] == 2 && out[4] == 0 && out[5] == 2);
}

int 
main()
{
  test1();
  test2();
  test3();
}
