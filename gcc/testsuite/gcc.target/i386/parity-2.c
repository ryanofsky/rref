/* { dg-do compile { target i?86-*-* x86_64-*-* } } */
/* { dg-options "-O2" } */
/* { dg-final { scan-assembler "setnp" } } */

int foo(unsigned long long int x)
{
  return __builtin_parityll(x);
}
