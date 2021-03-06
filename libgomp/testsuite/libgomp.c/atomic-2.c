/* { dg-do run } */
/* { dg-options "-O2 -mcx16" { target { { i?86-*-* x86_64-*-* } && lp64 } } } */

double d = 1.5;
long double ld = 3;
extern void abort (void);

void
test (void)
{
#pragma omp atomic
  d *= 1.25;
#pragma omp atomic
  ld /= 0.75;
  if (d != 1.875 || ld != 4.0L)
    abort ();
}

int
main (void)
{
#ifdef __x86_64__
# define bit_CX16 (1 << 13)
  unsigned int ax, bx, cx, dx;
  __asm__ ("cpuid" : "=a" (ax), "=b" (bx), "=c" (cx), "=d" (dx)
           : "0" (1) : "cc");
  if (!(cx & bit_CX16))
    return 0;
#endif
  test ();
  return 0;
}
