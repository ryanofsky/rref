/* { dg-do compile { target i?86-*-* x86_64-*-* } }
/* { dg-options "-msse2 -O2 -ftree-vectorize" } */

#define N 256
int b[N];

void test()
{  
  int i;

  for (i = 0; i < N; i++)
    b[i] = 0;
}

/* { dg-final { scan-assembler-times "pxor" 1 } } */
