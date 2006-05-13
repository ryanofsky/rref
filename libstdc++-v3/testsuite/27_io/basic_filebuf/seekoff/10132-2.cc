// 2003-04-24 bkoz

// Copyright (C) 2003, 2004, 2005 Free Software Foundation, Inc.
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

// 27.8.1.1 - Template class basic_filebuf 
// NB: This file is for testing basic_filebuf with NO OTHER INCLUDES.

#include <fstream>
#include <testsuite_hooks.h>
#include <testsuite_character.h>

// libstdc++/10132, add on
void test07()
{
  bool test __attribute__((unused)) = true;
  typedef std::basic_filebuf<__gnu_test::pod_ushort> gnu_filebuf;
  
  try
    { 
      // Need codecvt facet for width argument in seekoff.
      gnu_filebuf obj;
      obj.pubseekoff(2, std::ios_base::beg);
    }
  catch(std::exception& obj)
    { 
      test = false; 
      VERIFY( test );
    }
}

int main() 
{
  test07();
  return 0;
}



// more surf!!!
