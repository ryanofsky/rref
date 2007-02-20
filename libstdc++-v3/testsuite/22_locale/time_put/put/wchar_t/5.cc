// 2001-09-17 Benjamin Kosnik  <bkoz@redhat.com>

// Copyright (C) 2001, 2002, 2003, 2004, 2005, 2006 Free Software Foundation
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

// 22.2.5.3.1 time_put members

// { dg-do run { xfail dummy_wcsftime } }

#include <locale>
#include <sstream>
#include <testsuite_hooks.h>

void test05()
{
  using namespace std;
  typedef ostreambuf_iterator<wchar_t> iterator_type;
  typedef char_traits<wchar_t> traits;

  bool test __attribute__((unused)) = true;

  // create "C" time objects
  const tm time1 = __gnu_test::test_tm(0, 0, 12, 4, 3, 71, 0, 93, 0);
  const wchar_t* date = L"%A, the second of %B";
  const wchar_t* date_ex = L"%Ex";

  // basic construction
  locale loc_c = locale::classic();

  // create an ostream-derived object, cache the time_put facet
  const wstring empty;
  wostringstream oss;
  oss.imbue(loc_c);
  const time_put<wchar_t>& tim_put = use_facet<time_put<wchar_t> >(oss.getloc()); 

  // 2
  oss.str(empty);
  iterator_type os_it05 = tim_put.put(oss.rdbuf(), oss, L'*', &time1, 
				      date, date + traits::length(date));
  wstring result5 = oss.str();
  VERIFY( result5 == L"Sunday, the second of April");
  iterator_type os_it06 = tim_put.put(oss.rdbuf(), oss, L'*', &time1, 
				      date_ex, date_ex + traits::length(date));
  wstring result6 = oss.str();
  VERIFY( result6 != result5 );
}

int main()
{
  test05();
  return 0;
}
