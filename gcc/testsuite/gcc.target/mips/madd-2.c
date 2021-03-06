/* { dg-do compile } */
/* { dg-mips-options "-O2 -march=vr5500 -mgp32" } */
/* { dg-final { scan-assembler-times "\tmadd\t" 3 } } */

long long
f1 (int x, int y, long long z)
{
  return (long long) x * y + z;
}

long long
f2 (int x, int y, long long z)
{
  return z + (long long) y * x;
}

long long
f3 (int x, int y, long long z)
{
  long long t = (long long) x * y;
  int temp = 5;
  if (temp == 5)
    z += t;
  return z;
}
