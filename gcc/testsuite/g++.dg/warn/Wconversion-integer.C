/* Test for diagnostics for implicit conversions between integer types
   C++ equivalent of gcc/testsuite/gcc.dg/Wconversion-integer.c  */

// { dg-do compile } 
// { dg-options "-fsigned-char -Wconversion" } 

#include <limits.h>

void fsc (signed char sc);
void fuc (unsigned char uc);
unsigned fui (unsigned int  ui);
void fsi (signed int ui);

void h (int x)
{
  unsigned int ui = 3;
  int   si = 3;
  unsigned char uc = 3;
  signed char   sc = 3;

  fuc (-1); /* { dg-warning "negative integer implicitly converted to unsigned type" } */
  uc = -1; /* { dg-warning "negative integer implicitly converted to unsigned type" } */
  fuc ('\xa0'); /* { dg-warning "negative integer implicitly converted to unsigned type" } */
  uc = '\xa0'; /* { dg-warning "negative integer implicitly converted to unsigned type" } */
  uc = x ? 1U : -1; /* { dg-warning "conversion" } */
  /* { dg-warning "negative integer implicitly converted to unsigned type" "" { target *-*-* } 25 } */
  uc = x ? SCHAR_MIN : 1U; /* { dg-warning "conversion" } */
  /* { dg-warning "negative integer implicitly converted to unsigned type" "" { target *-*-* } 27 } */

  uc = x ? 1 : -1; /* { dg-warning "conversion" } */

  uc = x ? SCHAR_MIN : 1; /* { dg-warning "conversion" } */

  fuc ('A');
  uc = 'A';
  uc = (unsigned char) -1;

  fui (-1); /* { dg-warning "negative integer implicitly converted to unsigned type" } */
  ui = -1; /* { dg-warning "negative integer implicitly converted to unsigned type" } */
  ui = x ? 1U : -1; /* { dg-warning "negative integer implicitly converted to unsigned type" } */
  ui = x ? INT_MIN : 1U; /* { dg-warning "negative integer implicitly converted to unsigned type" } */
  ui = ui ? SCHAR_MIN : 1U; /* { dg-warning "negative integer implicitly converted to unsigned type" } */
  ui = 1U * -1; /* { dg-warning "negative integer implicitly converted to unsigned type" } */
  ui = ui + INT_MIN; /* { dg-warning "negative integer implicitly converted to unsigned type" } */
  ui = x ? 1 : -1; /* { dg-warning "conversion" } */
  ui = ui ? SCHAR_MIN : 1; /* { dg-warning "conversion" } */

  ui = -1 * (1 * -1);
  ui = (unsigned) -1;

  fsc (uc); /* { dg-warning "conversion" } */
  sc = uc;  /* { dg-warning "conversion" } */
  fuc (sc); /* { dg-warning "conversion" } */
  uc = sc;  /* { dg-warning "conversion" } */
  fsi (ui); /* { dg-warning "conversion" } */
  si = ui;  /* { dg-warning "conversion" } */
  fui (si); /* { dg-warning "conversion" } */ 
  ui = si;  /* { dg-warning "conversion" } */ 
  fui (sc); /* { dg-warning "conversion" } */
  ui = sc;  /* { dg-warning "conversion" } */

  fui ('\xa0');/* { dg-warning "negative integer implicitly converted to unsigned type" } */
  ui = '\xa0'; /* { dg-warning "negative integer implicitly converted to unsigned type" } */

  fsi (si);
  fui (ui);
  fsi (uc);
  si = uc;
  fui (uc);
  ui = uc;
  fui ('A');
  ui = 'A';
  fsi ('A');
  si = 'A';
  

  fsi (UINT_MAX - 1);  /* { dg-warning "conversion" } */
  si = UINT_MAX - 1;   /* { dg-warning "conversion" } */
  fsi (UINT_MAX - 1U); /* { dg-warning "conversion" } */
  si = UINT_MAX - 1U;  /* { dg-warning "conversion" } */
  fsi (UINT_MAX/3U);
  si = UINT_MAX/3U;
  fsi (UINT_MAX/3);
  si = UINT_MAX/3;
  fui (UINT_MAX - 1);
  ui = UINT_MAX - 1;

  fsi (0x80000000); /* { dg-warning "conversion" } */
  si = 0x80000000;  /* { dg-warning "conversion" } */
}


unsigned fui (unsigned a) { return a + -1; } /* { dg-warning "negative integer implicitly converted to unsigned type" } */


